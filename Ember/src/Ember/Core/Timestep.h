#pragma once

namespace Ember {
	class Timestep
	{
	public:
		Timestep(float time = 0.0f)
			: m_Time(time)
		{
		}

		operator float() const { return GetSeconds(); }

		float GetSeconds() const { return m_Time*0.001; }
		float GetMilliseconds() const { return m_Time; }
	private:
		float m_Time;
	};
}