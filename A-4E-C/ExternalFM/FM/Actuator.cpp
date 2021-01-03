#include "Actuator.h"
#include "Maths.h"
#include <cmath>

namespace Skyhawk
{ // start namespace

Actuator::Actuator() : m_actuatorPos{ 0.0 }, m_actuatorTargetPos{ 0.0 }
{

}

Actuator::~Actuator()
{

}

void Actuator::zeroInit()
{

}
void Actuator::coldInit()
{

}
void Actuator::hotInit()
{

}
void Actuator::airborneInit()
{

}

double Actuator::inputUpdate(double targetPosition, double dt)
{
	m_actuatorTargetPos = targetPosition;

	physicsUpdate(dt);

	return m_actuatorPos;
}

void Actuator::physicsUpdate(double dt)
{
	double speedToTarget = (m_actuatorTargetPos - m_actuatorPos)/dt;

	if (abs(speedToTarget) <= m_actuatorSpeed)
	{
		m_actuatorPos = m_actuatorTargetPos;
	}
	else
	{
		m_actuatorPos += copysign(1.0, speedToTarget) * m_actuatorSpeed * dt;
	}

	m_actuatorPos = clamp( m_actuatorPos, -1.0, 1.0 );
}

double Actuator::getPosition()
{
	return m_actuatorPos;
}

} // end namespace





























