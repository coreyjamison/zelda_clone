/*
 * entity_factory.cpp
 *
 *  Created on: Feb 19, 2015
 *      Author: Corey
 */

#include <string>
#include <iostream>
#include <fstream>

#include "entity_factory.hpp"

using namespace rapidjson;
Entity* EntityFactory::createEntity(const Value& config)
{
	Entity* e;
	if(config.HasMember("prototype"))
	{
		string proto = config["prototype"].GetString();
		if(_prototypeIds.find(proto) != _prototypeIds.end())
		{
			unsigned int id = _prototypeIds[proto];
			e = _prototypes[id]->clone();
		}
		else
		{
			e = new Entity();
		}
	}
	else
	{
		e = new Entity();
	}
	if(config.HasMember("components"))
	{
		const Value& components = config["components"];
		for(Value::ConstValueIterator itr = components.Begin(); itr != components.End(); ++itr)
		{
			const Value& component = *itr;
			if(component.HasMember("type") &&
					component.HasMember("config"))
			{
				string type = component["type"].GetString();
				const Value& config = component["config"];
				Component* c = _componentFactory.initComponent(type, config);
				if(c)
					e->addComponent(c);
			}
		}
	}
	return e;
}

Entity* EntityFactory::createEntity(const EntityConfig& config)
{
	Entity* e;
	if(_prototypeIds.find(config.prototype) != _prototypeIds.end())
	{
		unsigned int id = _prototypeIds[config.prototype];
		e = _prototypes[id]->clone();
	}
	else
	{
		cout << "Couldn't find prototype: '" << config.prototype << "'" << endl;
		e = new Entity();
	}
	PositionComponent* p = new PositionComponent{config.position};
	e->addComponent(p);

	for(Component* c : config.components)
		e->addComponent(c);

	return e;
}

EntityFactory& EntityFactory::createPrototypes(string prototypeConfigFile)
{
	ifstream fs(prototypeConfigFile);
	string content{ istreambuf_iterator<char>(fs),
					istreambuf_iterator<char>() };

	Document document;
	char buffer[content.length()];
	sprintf(buffer, "%s", content.c_str());
	if(document.ParseInsitu(buffer).HasParseError())
	{
		cout << "Error reading file: " << prototypeConfigFile << endl;
	}
	if(document.IsObject())
	{
		if(document.HasMember("prototypes"))
		{
			const Value& prototypes = document["prototypes"];
			for(Value::ConstValueIterator itr = prototypes.Begin(); itr != prototypes.End(); ++itr)
			{
				const Value& prototype = *itr;
				if(prototype.HasMember("name") &&
						prototype.HasMember("components"))
				{
					string name = prototype["name"].GetString();
					Entity* e = createEntity(prototype);
					_prototypeIds[name] = _nextPrototypeId;
					_prototypes[_nextPrototypeId++] = e;
				}
			}
		}
	}

	return *this;
}

EntityFactory& EntityFactory::populate(EcsManager* ecs, string entityFile)
{

	ifstream fs(entityFile);
	string content{ istreambuf_iterator<char>(fs),
					istreambuf_iterator<char>() };

	Document document;
	char buffer[content.length()];
	sprintf(buffer, "%s", content.c_str());
	if(document.ParseInsitu(buffer).HasParseError())
	{
		cout << "Error reading file: " << entityFile << endl;
	}
	if(document.IsObject())
	{
		if(document.HasMember("entities"))
		{
			const Value& entities = document["entities"];
			for(Value::ConstValueIterator itr = entities.Begin(); itr != entities.End(); ++itr)
			{
				const Value& entity = *itr;
				Entity* e = createEntity(entity);

				cout << "Adding entity!" << endl;

				vector<string> f;

				if(entity.HasMember("flags"))
				{
					cout << "have flags!" << endl;
					const Value& flags = entity["flags"];
					for(Value::ConstValueIterator itr = flags.Begin();
							itr != flags.End(); ++ itr)
					{
						const Value& flag = *itr;
						cout << "adding flag: " << flag.GetString() << endl;
						f.push_back(flag.GetString());
					}
				}

				unsigned int id = ecs->addEntity(e);
				ecs->checkNodes(e);
				ecs->flagEntity(id, f);
			}
		}
	}

	return *this;
}
