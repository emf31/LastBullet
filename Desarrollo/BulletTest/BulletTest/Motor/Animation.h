#pragma once
#include <unordered_map>


class Animation
{
public:
	Animation() {
		m_animations = std::unordered_map<std::string, frames>();
	}
	~Animation();
	void addAnimation(std::string name,int start,int end);
	void removeAnimation(std::string name);
	int getAnimationStart(std::string name);
	int getAnimationEnd(std::string name);
	std::string getActualAnimation() { return actualAnimation; };

private:

	struct frames {
		int start, end;
	};

	std::unordered_map<std::string, frames> m_animations;
	std::string actualAnimation;

};
