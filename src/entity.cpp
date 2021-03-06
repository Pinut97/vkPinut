
#include "entity.h"

#include "vk_engine.h"

Object::Object(glm::vec3 position, Mesh* mesh, Material* material) :
	material(material)
{
	prefab = new Prefab();
	prefab->_mesh = mesh;
	m_matrix = glm::translate(glm::mat4(1), position);
}

void Object::draw(VkCommandBuffer& cmd, VkPipelineLayout pipelineLayout, glm::mat4 model)
{
	if(prefab) 
	{
		prefab->draw(cmd, pipelineLayout, model);
	}
}

Light::Light(lightType type, glm::vec3 color /*white*/, glm::vec3 position/*0,0,0*/, float intensity/*1000*/, float maxDistance/*500*/, float radius/*1.0*/) :
	type{ type },
	color{ color },
	position{ position },
	intensity{ intensity },
	maxDistance{ maxDistance },
	radius{radius}
{
	this->m_matrix		= glm::translate(glm::mat4(1), position);
	this->m_selected	= false;
	this->m_visible		= true;
}

void Light::update()
{
	this->position = (glm::vec3)m_matrix[3];
}

void Light::setColor(glm::vec3 color) {
	color = color;
}