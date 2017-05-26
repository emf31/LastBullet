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
	ClippingZone* createClippingZone(Vec3<float> pos, Vec3<float> size, std::string name);
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

		/*CT3		Window		Ct2			PtoA		Mid2	Window2		Mid			Ct 			Conector	PtoA2	*/
		/*Ct3*/{ true, 	true,		true ,		 true ,		false,	false ,		false ,		true ,		false,		false },
		/*Window*/{ true, 	true,		false ,		 true ,		true,	true ,		true ,		true ,		true,		true },
		/*Ct2*/{ true, 	false,		true ,		 true ,		false,	false ,		true ,		true ,		true,		true },
		/*PtoA*/{ true, 	true,		true ,		 true ,		true,	true ,		true ,		true ,		true,		true },
		/*Mid2*/{ false, 	true,		false ,		 true ,		true,	false ,		true ,		true ,		true,		false },
		/*Window2*/{ false, 	true,		false ,		 true ,		false,	true ,		true ,		true ,		true,		true },
		/*Mid*/{ false, 	true,		true ,		 true ,		true,	true ,		true ,		true ,		true,		false },
		/*Ct*/{ true, 	true,		true ,		 true ,		true,	true ,		true ,		true ,		false,		true },
		/*Conector*/{ false, 	true,		true ,		 true ,		true,	true ,		true ,		false,		true,		true },
		/*PtoA2*/{ false, 	true,		true ,		 true ,		false,	true ,		false ,		true ,		true,		true }

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