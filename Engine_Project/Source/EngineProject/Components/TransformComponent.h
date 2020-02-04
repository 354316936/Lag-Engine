#include "SFML/Graphics/Transform.hpp"
#include "SFML/System/Vector2.hpp"
#ifndef __COMPONENT_TRANSFORM_COMPONENT_H__
#define __COMPONENT_TRANSFORM_COMPONENT_H__

#include "../Base/ActorComponent.h" 
class TransformComponent : public ActorComponent {
public:
	TransformComponent();
	TransformComponent(sf::Vector2<float> trans, float angle, sf::Vector2<float> scal);
	void Translate(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);
	sf::Transform transform;
private:
	sf::Transform m_translate;
	sf::Transform m_rotation;
	sf::Transform m_scale;
	void UpdateTransform();
};

#endif 
