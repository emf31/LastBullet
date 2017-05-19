#pragma once
#include <ClippingZone.h>

class ClippingManager
{
public:

	static ClippingManager& i() {
		static ClippingManager singleton;
		return singleton;
	}

	void addClippingZone(ClippingZone* zone);
	ClippingZone* createClippingZone(Vec3<float> pos, Vec3<float> size,std::string name);
	void update();
	void printZonesVisibility();
	void updateZoneOclusions(int id, std::vector<ClippingZone*> &zonesOclusionOut);
	bool getUpdateClipping() const;
	bool getUpdateOclusions() const;
	void setUpdateClipping(bool a);
	void setUpdateOclusions(bool a);

private:
	ClippingManager();
	std::vector<ClippingZone*> m_clippingZones;
	bool updateClipping;
	bool updateOclusions;

	bool oclusionMatrix[6][6]{

					/*Window	Ct2		PtoA	Window2		Mid		Ct*/	
		/*Window*/	{ true,		true,	true,	true,		true,	true },
		/*Ct2*/		{ true,		true,	true,	false,		true,	true },
		/*PtoA*/	{ true,		true,	true,	true,		true,	true},
		/*Window2*/	{ true,		false,	true,	true,		true,	true },
		/*Mid*/		{ true,		true,	true,	true,		true,	true },
		/*Ct*/		{ true,		true,	true,	true,		true,	true }

	};

	//	bool oclusionMatrix[6][6]{

	//				/*Window	Ct2		PtoA	Window2		Mid		Ct*/	
	//	/*Window*/	{ false,	false,	false,	false,		false,	false },
	//	/*Ct2*/		{ false,	false,	false,	false,		false,	false },
	//	/*PtoA*/	{ false,	false,	false,	false,		false,	false },
	//	/*Window2*/	{ false,	false,	false,	false,		false,	false },
	//	/*Mid*/		{ false,	false,	false,	false,		false,	false },
	//	/*Ct*/		{ true,		true,	false,	true,		true,	true }

	//};

};