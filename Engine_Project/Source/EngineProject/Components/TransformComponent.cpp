#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	m_translate.translate(0, 0);
	m_rotation.rotate(0);
	m_scale.scale(1, 1);
	UpdateTransform();
	componentID = "transform";
}

TransformComponent::TransformComponent(sf::Vector2<float> trans, float angle, sf::Vector2<float> scal)
{
	m_translate.translate(trans.x, trans.y);
	m_rotation.rotate(angle);
	m_scale.scale(scal.x, scal.y);
	UpdateTransform();
	componentID = "transform";
}
void TransformComponent::Translate(float x, float y)
{
	m_translate.translate(x, y);
	UpdateTransform();
}
void TransformComponent::Rotate(float angle)
{
	m_rotation.rotate(angle);
	UpdateTransform();
}
void TransformComponent::Scale(float x, float y)
{
	m_scale.scale(x, y);
	UpdateTransform();
}

void TransformComponent::UpdateTransform()
{
	transform = m_translate * m_rotation * m_scale;
}
