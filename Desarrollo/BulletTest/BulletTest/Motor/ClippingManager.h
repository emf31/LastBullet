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
	std::string mizona;

	bool oclusionMatrix[10][10]{

					/*PtoA2		CT3		Mid2	Conector	Window	Ct2		PtoA	Window2		Mid		Ct	*/	
		/*PtoA2*/	{ true,		false,	false,	true,		true,	true ,	 true ,		true ,	false ,	true },
		/*Ct3*/		{ false,	true,	false,	false,		true,	true ,	 true ,		false ,	false ,	true },
		/*Mid2*/	{ false,	false,	true,	true,		true,	false ,	 true ,		false ,	true ,	true },
		/*Conector*/{ true,		false,	true,	true,		true,	true ,	 true ,		true ,	true ,	false },
		/*Window*/	{ true,		true,	true,	true,		true,	false ,	 true ,		true ,	true ,	true },
		/*Ct2*/		{ true,		true,	false,	true,		false,	true ,	 true ,		false ,	true ,	true },
		/*PtoA*/	{ true, 	true,	true,	true,		true,	true ,	 true ,		true ,	true ,	true },
		/*Window2*/	{ true	,	false,	false,	true,		true,	false ,	 true ,		true ,	true ,	true },
		/*Mid*/		{ false,	false,	true,	true,		true,	true ,	 true ,		true ,	true ,	true },
		/*Ct*/		{ true,		true,	true,	false,		true,	true ,	 true ,		true ,	true ,	true }

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