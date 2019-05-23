/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Entity.h
 * Author: rafael.luiz.cancian
 *
 * Created on 21 de Junho de 2018, 16:30
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <map>

#include "Util.h"
#include "List.h"
#include "ModelElement.h"
#include "EntityType.h"

class Entity : public ModelElement {
public:
    Entity(ElementManager* elements);
    Entity(const Entity& orig);
    virtual ~Entity();
public:
    virtual std::string show();

public: // g & s
    void setEntityTypeName(std::string entityTypeName) throw(); // indirect access to EntityType
    std::string getEntityTypeName() const;
    void setEntityType(EntityType* entityType); // direct access to EntityType
    EntityType* getEntityType() const;
public:
    double getAttributeValue(std::string attributeName);
    void setAttributeValue(std::string attributeName, double value);
protected:
    virtual void _loadInstance(std::list<std::string> words);
    virtual std::list<std::string>* _saveInstance();
    virtual bool _check(std::string* errorMessage);

private:
    ElementManager* _elements;
    EntityType* _entityType = nullptr;
private: // 1::n
    List<double>* _attributeValues = new List<double>();
};

#endif /* ENTITY_H */

