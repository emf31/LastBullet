//Maya ASCII 2017 scene
//Name: ct - copia.ma
//Last modified: Sun, Mar 12, 2017 07:22:05 PM
//Codeset: 1252
requires maya "2017";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" "mtoa" "1.3.0.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2017";
fileInfo "version" "2017";
fileInfo "cutIdentifier" "201606150345-997974";
fileInfo "osv" "Microsoft Windows 8 Home Premium Edition, 64-bit  (Build 9200)\n";
fileInfo "license" "student";
createNode transform -s -n "persp";
	rename -uid "948900D5-42DB-556D-F241-75BC2852FE6C";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -137.94282637440361 74.454546315173246 67.624280622833581 ;
	setAttr ".r" -type "double3" -21.912175405995978 -75.231967093287551 -6.2386741980367091e-015 ;
	setAttr ".rp" -type "double3" -5.3290705182007514e-015 0 2.8421709430404007e-014 ;
	setAttr ".rpt" -type "double3" -6.1437048055023783e-014 -3.5420226301435855e-015 
		7.707901506848073e-014 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "322E42B5-478F-7FB6-F2B7-76B6EA9EBE3C";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999979;
	setAttr ".fcp" 1000;
	setAttr ".coi" 161.82879169725464;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" -4.9899997711181641 6.9399998188018799 35.85414981842041 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "9AD0074E-4D8D-1D3F-8BC2-E585F3347DBC";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 100.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "A1CEFB50-4BF4-CBAC-C9AB-808F3F453CC8";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".fcp" 1000;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "4F7B7452-47CB-E93A-A3CF-59A785ACF0E0";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "B241FA52-4AAC-6D65-9B11-8A867D32825C";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".fcp" 1000;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "68DF53C4-4CBE-062F-FAA9-408EB624D2E1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 100.1 0 0 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "4CF0B2C7-4F4C-7667-B223-B398B130598E";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".fcp" 1000;
	setAttr ".coi" 100.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "Script";
	rename -uid "C1B8E66B-4A61-CC3D-9369-AC9947D86F84";
	setAttr ".ro" 2;
createNode transform -n "Box" -p "Script";
	rename -uid "85DD2D81-4722-D911-1D46-868D995EB16B";
	setAttr ".t" -type "double3" 3.47 7.82 -3.25 ;
	setAttr ".r" -type "double3" 0 -310.2271 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_1" -p "Box";
	rename -uid "19C89995-4693-F642-2242-C9B2C1127F28";
	setAttr ".ro" 2;
createNode transform -n "transform28" -p "|Script|Box|Box_1";
	rename -uid "A3DD17E8-4041-9A8B-9704-30B3CF6D84A6";
	setAttr ".v" no;
createNode mesh -n "Box_1Shape" -p "transform28";
	rename -uid "F13201A8-46B0-4782-9175-999B4808ABEE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 10.78100014 -1.96990001 0.78759998 10.78100014 1.96990001
		 -0.78759998 10.78100014 1.96990001 -0.78759998 10.78100014 -1.96990001 -0.78759998 10.78100014 1.96990001
		 -0.78759998 -7.31099987 1.96990001 -0.78759998 -7.31099987 -1.96990001 -0.78759998 10.78100014 -1.96990001;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103
		 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_2" -p "Script";
	rename -uid "783461C6-4E5C-AD96-E307-F896D8B0692C";
	setAttr ".t" -type "double3" -3.34 0 18.97 ;
	setAttr ".ro" 2;
createNode transform -n "Box_3" -p "Box_2";
	rename -uid "EA24F540-49A9-4D6B-908B-4F8C1366FEE8";
	setAttr ".ro" 2;
createNode transform -n "transform19" -p "Box_3";
	rename -uid "52346FD2-41D3-86CD-BA12-9A86767B5AAA";
	setAttr ".v" no;
createNode mesh -n "Box_3Shape" -p "transform19";
	rename -uid "F4DBD045-40C8-2B06-BF4B-849ACCF61E36";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  5.53709984 0.76840001 -6.74840021 5.53709984 0.76840001 6.74840021
		 -5.53709984 0.76840001 6.74840021 -5.53709984 0.76840001 -6.74840021;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_4" -p "Script";
	rename -uid "B54942BD-4B49-2462-0C8B-45969B064058";
	setAttr ".t" -type "double3" -4.99 6.94 39.32 ;
	setAttr ".ro" 2;
createNode transform -n "Box_5" -p "Box_4";
	rename -uid "9390EBB5-4D67-1875-55F0-15B852067D23";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape2" -p "|Script|Box_4|Box_5";
	rename -uid "7FC70252-4F15-D20C-EEBF-A1A9C8958157";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -1.8441 8.0052995682 1 -1.8441 8.0052995682 -1
		 1.8441 8.0052995682 -1 1.8441 8.0052995682 1 -1.8441 -8.0052995682 1 -1.8441 8.0052995682 1
		 1.8441 8.0052995682 1 1.8441 -8.0052995682 1 1.8441 -8.0052995682 1 1.8441 8.0052995682 1
		 1.8441 8.0052995682 -1 1.8441 -8.0052995682 -1;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6
		f 3 -13 -12 -11
		mu 0 3 8 10 9
		f 3 -15 -14 12
		mu 0 3 8 11 10;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform11" -p "|Script|Box_4|Box_5";
	rename -uid "D75E06E8-4DEF-94E9-12EA-83AC1D0D7634";
	setAttr ".v" no;
createNode mesh -n "Box_5Shape" -p "transform11";
	rename -uid "F1F24F48-4B47-3B81-D0DD-92B96E0D56B7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_6" -p "Script";
	rename -uid "4D6B490E-49DC-8EEA-1B33-6D9DF463AE50";
	setAttr ".t" -type "double3" -8.36 7.63 17.29 ;
	setAttr ".ro" 2;
createNode transform -n "Box_7" -p "Box_6";
	rename -uid "294AB392-4E00-B7F4-CD6F-5E84737E0934";
	setAttr ".ro" 2;
createNode transform -n "transform20" -p "|Script|Box_6|Box_7";
	rename -uid "FFB6DF3C-42F4-7BFF-194B-FAAC6E116C65";
	setAttr ".v" no;
createNode mesh -n "Box_7Shape" -p "transform20";
	rename -uid "907C21A7-4F16-7465-7DB9-AF9EF2C530C8";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 3 ".pt[20:22]" -type "float3"  7.4505806e-009 0 0 7.4505806e-009 
		0 0 7.4505806e-009 0 0;
	setAttr -s 12 ".vt[0:11]"  0.58109999 7.29839993 -11.2116003 0.58109999 7.29839993 11.2116003
		 -0.58109999 7.29839993 11.2116003 -0.58109999 7.29839993 -11.2116003 0.58109999 7.29839993 -11.2116003
		 0.58109999 -7.29839993 -11.2116003 0.58109999 -7.29839993 11.2116003 0.58109999 7.29839993 11.2116003
		 -0.58109999 7.29839993 -11.2116003 -0.58109999 -7.29839993 -11.2116003 0.58109999 -7.29839993 -11.2116003
		 0.58109999 7.29839993 -11.2116003;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6
		f 3 -13 -12 -11
		mu 0 3 8 10 9
		f 3 -15 -14 12
		mu 0 3 8 11 10;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_8" -p "Script";
	rename -uid "58176630-4D9B-18AB-8EA6-8CA96B5B4EFD";
	setAttr ".t" -type "double3" -4.97 1.977 50.74 ;
	setAttr ".ro" 2;
createNode transform -n "Box_9" -p "Box_8";
	rename -uid "ACDD24D7-452B-85A9-5D7D-4C9D1EB638D1";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape3" -p "Box_9";
	rename -uid "71E8B51C-43A2-0411-4EB7-769E606DDAD7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  1.8441 1.70770001 -10.42160034 1.8441 1.70770001 10.42160034
		 -1.8441 1.70770001 10.42160034 -1.8441 1.70770001 -10.42160034 1.8441 1.70770001 -10.42160034
		 1.8441 -1.70770001 -10.42160034 1.8441 -1.70770001 10.42160034 1.8441 1.70770001 10.42160034;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform10" -p "Box_9";
	rename -uid "5C1A9231-4089-7707-FDD3-4AAEA69F3B68";
	setAttr ".v" no;
createNode mesh -n "Box_9Shape" -p "transform10";
	rename -uid "735EFF61-4943-D23F-E0ED-C7B1E51D0A4B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_10" -p "Script";
	rename -uid "6CD44C4D-4ABB-F540-77A0-9B9BE2C407BD";
	setAttr ".t" -type "double3" 1.77 1.47 51.35 ;
	setAttr ".r" -type "double3" 347.196 0 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_11" -p "Box_10";
	rename -uid "232843F0-4471-29CF-5E49-DA968205EBFD";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape10" -p "Box_11";
	rename -uid "73D6D74E-442B-0060-5666-6A8A08D6F5D9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  4.91750002 0.76840001 -6.59810019 4.91750002 0.76840001 6.59810019
		 -4.91750002 0.76840001 6.59810019 -4.91750002 0.76840001 -6.59810019;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 0.96592891 -0.25880769 0
		 0.96592891 -0.25880769 0 0.96592891 -0.25880769 0 0.96592891 -0.25880769 0 0.96592891
		 -0.25880769 0 0.96592891 -0.25880769;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform3" -p "Box_11";
	rename -uid "FEC3C535-407F-095B-B710-8492EE23D661";
	setAttr ".v" no;
createNode mesh -n "Box_11Shape" -p "transform3";
	rename -uid "9FF41F25-408B-553F-F25E-46BA1269719E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Cube" -p "Script";
	rename -uid "803F1F5D-4E41-0DF9-E66A-F9B5D48F8651";
	setAttr ".t" -type "double3" 0.3 -0.2 0.03 ;
	setAttr ".ro" 2;
createNode transform -n "initialShadingGroup_pCube" -p "Cube";
	rename -uid "A5F08E51-4391-9DDF-BB84-AFBEB3D54055";
	setAttr ".ro" 2;
createNode transform -n "transform25" -p "initialShadingGroup_pCube";
	rename -uid "8F079A6F-4ADC-2DFD-4C8E-EFA93ED70379";
	setAttr ".v" no;
createNode mesh -n "initialShadingGroup_pCubeShape" -p "transform25";
	rename -uid "10FF5E34-484B-E33C-5871-C584C5BD1BC2";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.75 0.125 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0.375 0.25 0.375
		 0.5 0.625 0.5 0.625 0.25 0.375 0.5 0.375 0.75 0.625 0.75 0.625 0.5 0.125 0 0.125
		 0.25 0.375 0.25 0.375 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -25.95070076 21.076919556 7.97007704 -25.95070076 21.076919556 6.044056892
		 -8.93142605 14.94054985 6.044056892 -8.93142605 14.94054985 7.97007704 -25.95070076 21.076919556 6.044056892
		 -25.95070076 3.52018189 6.044056892 -8.93142605 0.212207 6.044056892 -8.93142605 14.94054985 6.044056892
		 -25.95070076 3.52018189 6.044056892 -25.95070076 21.076919556 6.044056892 -25.95070076 21.076919556 7.97007704
		 -25.95070076 3.52018189 7.97007704;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0.3391811 0.94072121 0 0.3391811
		 0.94072121 0 0.3391811 0.94072121 0 0.3391811 0.94072121 0 0.3391811 0.94072121 0
		 0.3391811 0.94072121 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6
		f 3 -13 -12 -11
		mu 0 3 8 10 9
		f 3 -15 -14 12
		mu 0 3 8 11 10;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_12" -p "Script";
	rename -uid "9915E952-43E2-7948-542A-A59572A96A86";
	setAttr ".t" -type "double3" 1.78 0 38.7 ;
	setAttr ".ro" 2;
createNode transform -n "Box_13" -p "Box_12";
	rename -uid "3A5B7888-40F6-37FF-6776-81AF6A206232";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape9" -p "Box_13";
	rename -uid "848F91DD-4AB5-5A95-653B-7FA7BA1CC8E7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  4.91750002 0.76840001 -6.73869991 4.91750002 0.76840001 6.73869991
		 -4.91750002 0.76840001 6.73869991 -4.91750002 0.76840001 -6.73869991;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform4" -p "Box_13";
	rename -uid "82F9DFD4-4606-E584-6935-11AAE54D278F";
	setAttr ".v" no;
createNode mesh -n "Box_13Shape" -p "transform4";
	rename -uid "BE81C0A0-4CEB-3C03-84DA-3B8A1C1F4F9E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_14" -p "Script";
	rename -uid "01C123C4-4B71-05EA-17EB-C5ACD729E55D";
	setAttr ".t" -type "double3" 8.18 7.81 16.51 ;
	setAttr ".ro" 2;
createNode transform -n "Box_15" -p "Box_14";
	rename -uid "8BF66969-4263-94F7-E2E5-7F93E0811903";
	setAttr ".ro" 2;
createNode transform -n "transform12" -p "Box_15";
	rename -uid "2163DB8A-478D-B115-78A6-589CF13740AD";
	setAttr ".v" no;
createNode mesh -n "Box_15Shape" -p "transform12";
	rename -uid "A7DFDBD6-4854-B81C-ED80-F6BA1EE0DE4B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:65]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 96 ".uvst[0].uvsp[0:95]" -type "float2" 0.66670001 0.5 0.66670001
		 0.45469999 0.62959999 0.4698 0.59259999 0.4849 0.55559999 0.5 0.66670001 1 1 0 1
		 1 0.66670001 0 0.44440001 0.5 0.33329999 0.5 0.40740001 0.4844 0.37040001 0.4689
		 0.33329999 0.4533 0.33329999 1 0 1 0.33329999 0 0 0 0 0 0 0.33329999 1 1 1 0 0 0.66670001
		 0 1 0.55559999 0 0.44440001 0 0.44440001 0.25 0.55559999 0.25 0.66670001 0 0.61729997
		 0.49509999 0.65429997 0.48030001 0.66670001 0.45570001 0.55559999 0.5 0.55559999
		 0.25 0.55559999 0 0.44440001 0.25 0.44440001 0.5 0.33329999 0.4533 0.3457 0.47929999
		 0.3827 0.4948 0.44440001 0 0.33329999 0 1 1 1 0 0 0 0 1 0.55559999 0.5 0.55559999
		 0.5 0.44440001 0.5 0.44440001 0.5 0.33329999 0.4533 0.33329999 0.4533 0.33329999
		 0 0.33329999 0 0.37040001 0.4689 0.3457 0.47929999 0.44440001 0 0.44440001 0 0.44440001
		 0.25 0.44440001 0.25 0.44440001 0 0.44440001 0.25 0.55559999 0.5 0.55559999 0.5 0.59259999
		 0.4849 0.61729997 0.49509999 0.3827 0.4948 0.40740001 0.4844 0.44440001 0.5 0.44440001
		 0.5 0.66670001 0 0.66670001 0 0.66670001 0.45570001 0.66670001 0.45469999 0.65429997
		 0.48030001 0.62959999 0.4698 0.44440001 0.25 0.44440001 0.25 0.55559999 0.25 0.55559999
		 0.25 0.44440001 0.25 0.55559999 0.25 0.3457 0.47929999 0.37040001 0.4689 0.40740001
		 0.4844 0.3827 0.4948 0.55559999 0.25 0.55559999 0.25 0.55559999 0 0.55559999 0 0.55559999
		 0.25 0.55559999 0 0.61729997 0.49509999 0.59259999 0.4849 0.62959999 0.4698 0.65429997
		 0.48030001;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 3 ".pt[50:52]" -type "float3"  -4.6566129e-010 0 0 -4.6566129e-010 
		0 0 -4.6566129e-010 0 0;
	setAttr -s 96 ".vt[0:95]"  -0.58109999 4.61810017 7.70069981 -0.58109999 3.5388 7.70069981
		 -0.58109999 4.13840008 7.58319998 -0.58109999 4.49819994 7.23070002 -0.58109999 4.61810017 6.64330006
		 -0.58109999 10.79990005 7.70069981 -0.58109999 -7.29839993 11.2116003 -0.58109999 10.79990005 11.2116003
		 -0.58109999 -7.29839993 7.70069981 -0.58109999 4.61810017 -6.4137001 -0.58109999 4.61810017 -7.51569986
		 -0.58109999 4.49459982 -7.025899887 -0.58109999 4.12389994 -7.39319992 -0.58109999 3.50609994 -7.51569986
		 -0.58109999 10.79990005 -7.51569986 -0.58109999 10.79990005 -11.2116003 -0.58109999 -7.29839993 -7.51569986
		 -0.58109999 -7.29839993 -11.2116003 -0.58109999 10.79990005 11.2116003 -0.58109999 10.79990005 7.70069981
		 0.58109999 10.79990005 -11.2116003 0.58109999 10.79990005 11.2116003 -0.58109999 10.79990005 -7.51569986
		 -0.58109999 10.79990005 -11.2116003 0.21600001 -7.29839993 6.31160021 0.21600001 -7.29839993 -5.76270008
		 0.21600001 3.016499996 -5.76270008 0.21600001 3.016499996 6.31160021 -2.070300102 -7.56409979 7.70069981
		 -2.070300102 4.49819994 7.23070002 -2.070300102 4.13840008 7.58319998 -2.070300102 3.5388 7.70069981
		 -2.070300102 4.61810017 6.64330006 -2.070300102 3.39779997 6.64330006 -2.070300102 -7.56409979 6.64330006
		 -2.070300102 3.46679997 -6.4137001 -2.070300102 4.61810017 -6.4137001 -2.070300102 3.50609994 -7.51569986
		 -2.070300102 4.12389994 -7.39319992 -2.070300102 4.49459982 -7.025899887 -2.070300102 -7.29839993 -6.4137001
		 -2.070300102 -7.29839993 -7.51569986 0.58109999 10.79990005 11.2116003 0.58109999 -7.46210003 11.2116003
		 -0.58109999 -7.29839993 11.2116003 -0.58109999 10.79990005 11.2116003 -0.58109999 4.61810017 6.64330006
		 -2.070300102 4.61810017 6.64330006 -2.070300102 4.61810017 -6.4137001 -0.58109999 4.61810017 -6.4137001
		 -0.58109999 3.50609994 -7.51569986 -2.070300102 3.50609994 -7.51569986 -2.070300102 -7.29839993 -7.51569986
		 -0.58109999 -7.29839993 -7.51569986 -0.58109999 4.12389994 -7.39319992 -2.070300102 4.12389994 -7.39319992
		 -0.58109999 -7.29839993 -5.76270008 -2.070300102 -7.29839993 -6.4137001 -2.070300102 3.46679997 -6.4137001
		 -0.58109999 3.016499996 -5.76270008 0.21600001 -7.29839993 -5.76270008 0.21600001 3.016499996 -5.76270008
		 -2.070300102 4.61810017 6.64330006 -0.58109999 4.61810017 6.64330006 -0.58109999 4.49819994 7.23070002
		 -2.070300102 4.49819994 7.23070002 -2.070300102 4.49459982 -7.025899887 -0.58109999 4.49459982 -7.025899887
		 -0.58109999 4.61810017 -6.4137001 -2.070300102 4.61810017 -6.4137001 -0.58109999 -7.29839993 7.70069981
		 -2.070300102 -7.56409979 7.70069981 -2.070300102 3.5388 7.70069981 -0.58109999 3.5388 7.70069981
		 -2.070300102 4.13840008 7.58319998 -0.58109999 4.13840008 7.58319998 -0.58109999 3.016499996 -5.76270008
		 -2.070300102 3.46679997 -6.4137001 -2.070300102 3.39779997 6.64330006 -0.58109999 3.016499996 6.31160021
		 0.21600001 3.016499996 -5.76270008 0.21600001 3.016499996 6.31160021 -2.070300102 4.12389994 -7.39319992
		 -0.58109999 4.12389994 -7.39319992 -0.58109999 4.49459982 -7.025899887 -2.070300102 4.49459982 -7.025899887
		 -0.58109999 3.016499996 6.31160021 -2.070300102 3.39779997 6.64330006 -2.070300102 -7.56409979 6.64330006
		 -0.58109999 -7.29839993 6.31160021 0.21600001 3.016499996 6.31160021 0.21600001 -7.29839993 6.31160021
		 -2.070300102 4.49819994 7.23070002 -0.58109999 4.49819994 7.23070002 -0.58109999 4.13840008 7.58319998
		 -2.070300102 4.13840008 7.58319998;
	setAttr -s 147 ".ed[0:146]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 3 4 0 4 0 0
		 5 0 0 4 5 0 6 0 0 5 6 0 5 7 0 7 6 0 8 0 0 6 8 0 4 9 0 9 5 0 9 10 0 10 5 0 9 11 0
		 11 10 0 11 12 0 12 10 0 12 13 0 13 10 0 10 14 0 14 5 0 10 15 0 15 14 0 10 16 0 16 15 0
		 16 17 0 17 15 0 18 19 0 19 20 0 20 18 0 20 21 0 21 18 0 22 20 0 19 22 0 22 23 0 23 20 0
		 24 25 0 25 26 0 26 24 0 26 27 0 27 24 0 28 29 0 29 30 0 30 28 0 30 31 0 31 28 0 28 32 0
		 32 29 0 28 33 0 33 32 0 28 34 0 34 33 0 33 35 0 35 32 0 35 36 0 36 32 0 35 37 0 37 36 0
		 37 38 0 38 36 0 38 39 0 39 36 0 40 37 0 35 40 0 40 41 0 41 37 0 42 43 0 43 44 0 44 42 0
		 44 45 0 45 42 0 46 47 0 47 48 0 48 46 0 48 49 0 49 46 0 50 51 0 51 52 0 52 50 0 52 53 0
		 53 50 0 50 54 0 54 51 0 54 55 0 55 51 0 56 57 0 57 58 0 58 56 0 58 59 0 59 56 0 59 60 0
		 60 56 0 59 61 0 61 60 0 62 63 0 63 64 0 64 62 0 64 65 0 65 62 0 66 67 0 67 68 0 68 66 0
		 68 69 0 69 66 0 70 71 0 71 72 0 72 70 0 72 73 0 73 70 0 74 73 0 72 74 0 74 75 0 75 73 0
		 76 77 0 77 78 0 78 76 0 78 79 0 79 76 0 79 80 0 80 76 0 79 81 0 81 80 0 82 83 0 83 84 0
		 84 82 0 84 85 0 85 82 0 86 87 0 87 88 0 88 86 0 88 89 0 89 86 0 89 90 0 90 86 0 89 91 0
		 91 90 0 92 93 0 93 94 0 94 92 0 94 95 0 95 92 0;
	setAttr -s 198 ".n";
	setAttr ".n[0:165]" -type "float3"  -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 -0.2309902 0.97185868 0.04619804 -0.23099551
		 0.97188097 -0.045699101 -0.2309902 0.97185868 0.04619804 -0.2309902 0.97185868 0.04619804
		 -0.23099551 0.97188097 -0.045699101 -0.23099551 0.97188097 -0.045699101 0 0.097701557
		 -0.99521577 0 0 -1 0 0.097701557 -0.99521577 0 0.097701557 -0.99521577 0 0 -1 0 0
		 -1 0 0.097701557 -0.99521577 0 0.1944043 -0.98092151 0 0.097701557 -0.99521577 0
		 0.097701557 -0.99521577 0 0.1944043 -0.98092151 0 0.1944043 -0.98092151 -0.2046092
		 0 0.97884381 -0.40049881 0 0.91629732 -0.40049881 0 0.91629732 -0.2046092 0 0.97884381
		 -0.2208041 0 0.97531807 -0.40049881 0 0.91629732 -0.2208041 0 0.97531807 -0.2046092
		 0 0.97884381 0 0 1 -0.2208041 0 0.97531807 0 0 1 0 0 1 -0.2309915 0.96146452 0.14909451
		 0 0.97979611 0.1999992 -0.2309915 0.96146452 0.14909451 -0.2309915 0.96146452 0.14909451
		 0 0.97979611 0.1999992 0 0.97979611 0.1999992 0 0.9802407 -0.19780821 -0.23100179
		 0.96170759 -0.1475012 0 0.9802407 -0.19780821 0 0.9802407 -0.19780821 -0.23100179
		 0.96170759 -0.1475012 -0.23100179 0.96170759 -0.1475012 0 0 1 0 0.096602254 0.99532312
		 0 0 1 0 0 1 0 0.096602254 0.99532312 0 0.096602254 0.99532312 0 0.1923068 0.98133481
		 0 0.096602254 0.99532312 0 0.096602254 0.99532312 0 0.1923068 0.98133481 0 0.096602254
		 0.99532312 0 0.1923068 0.98133481 -0.15079451 -0.98856401 -0.0014999449 -0.26870531
		 -0.96321893 -0.002600051 -0.26870531 -0.96321893 -0.002600051 -0.15079451 -0.98856401
		 -0.0014999449;
	setAttr ".n[166:197]" -type "float3"  -0.1441925 -0.98954868 -0.001399927 -0.26870531
		 -0.96321893 -0.002600051 -0.1441925 -0.98954868 -0.001399927 -0.15079451 -0.98856401
		 -0.0014999449 0 -1 0 -0.1441925 -0.98954868 -0.001399927 0 -1 0 0 -1 0 0 0.7038995
		 -0.71029961 0 0.7038995 -0.71029961 0 0.7038995 -0.71029961 0 0.7038995 -0.71029961
		 0 0.7038995 -0.71029961 0 0.7038995 -0.71029961 -0.1172996 0 -0.99309647 -0.2173963
		 0 -0.9760834 -0.2173963 0 -0.9760834 -0.1172996 0 -0.99309647 -0.1149961 0 -0.99336588
		 -0.2173963 0 -0.9760834 -0.1149961 0 -0.99336588 -0.1172996 0 -0.99309647 0 0 -1
		 -0.1149961 0 -0.99336588 0 0 -1 0 0 -1 0 0.69981939 0.71431983 0 0.69981939 0.71431983
		 0 0.69981939 0.71431983 0 0.69981939 0.71431983 0 0.69981939 0.71431983 0 0.69981939
		 0.71431983;
	setAttr -s 66 -ch 198 ".fc[0:65]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 4 -7 -6
		mu 0 3 3 0 4
		f 3 -9 6 -8
		mu 0 3 5 4 0
		f 3 -11 7 -10
		mu 0 3 6 5 0
		f 3 -13 -12 10
		mu 0 3 6 7 5
		f 3 -15 9 -14
		mu 0 3 8 6 0
		f 3 -17 -16 8
		mu 0 3 5 9 4
		f 3 -19 -18 16
		mu 0 3 5 10 9
		f 3 17 -21 -20
		mu 0 3 9 10 11
		f 3 20 -23 -22
		mu 0 3 11 10 12
		f 3 -25 -24 22
		mu 0 3 10 13 12
		f 3 -27 -26 18
		mu 0 3 5 14 10
		f 3 -29 -28 25
		mu 0 3 14 15 10
		f 3 -31 -30 27
		mu 0 3 15 16 10
		f 3 -33 -32 30
		mu 0 3 15 17 16
		f 3 -36 -35 -34
		mu 0 3 18 20 19
		f 3 -38 -37 35
		mu 0 3 18 21 20
		f 3 -40 34 -39
		mu 0 3 22 19 20
		f 3 38 -42 -41
		mu 0 3 22 20 23
		f 3 -45 -44 -43
		mu 0 3 24 26 25
		f 3 -47 -46 44
		mu 0 3 24 27 26
		f 3 -50 -49 -48
		mu 0 3 28 30 29
		f 3 -52 -51 49
		mu 0 3 28 31 30
		f 3 47 -54 -53
		mu 0 3 28 29 32
		f 3 52 -56 -55
		mu 0 3 28 32 33
		f 3 54 -58 -57
		mu 0 3 28 33 34
		f 3 -60 -59 55
		mu 0 3 32 35 33
		f 3 -62 -61 59
		mu 0 3 32 36 35
		f 3 -64 -63 60
		mu 0 3 36 37 35
		f 3 -66 -65 63
		mu 0 3 36 38 37
		f 3 -68 -67 65
		mu 0 3 36 39 38
		f 3 -70 62 -69
		mu 0 3 40 35 37
		f 3 68 -72 -71
		mu 0 3 40 37 41
		f 3 -75 -74 -73
		mu 0 3 42 44 43
		f 3 -77 -76 74
		mu 0 3 42 45 44
		f 3 -80 -79 -78
		mu 0 3 46 48 47
		f 3 -82 -81 79
		mu 0 3 46 49 48
		f 3 -85 -84 -83
		mu 0 3 50 52 51
		f 3 -87 -86 84
		mu 0 3 50 53 52
		f 3 -89 -88 82
		mu 0 3 51 54 50
		f 3 -91 -90 88
		mu 0 3 51 55 54
		f 3 -94 -93 -92
		mu 0 3 56 58 57
		f 3 -96 -95 93
		mu 0 3 56 59 58
		f 3 95 -98 -97
		mu 0 3 59 56 60
		f 3 96 -100 -99
		mu 0 3 59 60 61
		f 3 -103 -102 -101
		mu 0 3 62 64 63
		f 3 -105 -104 102
		mu 0 3 62 65 64
		f 3 -108 -107 -106
		mu 0 3 66 68 67
		f 3 -110 -109 107
		mu 0 3 66 69 68
		f 3 -113 -112 -111
		mu 0 3 70 72 71
		f 3 -115 -114 112
		mu 0 3 70 73 72
		f 3 -117 113 -116
		mu 0 3 74 72 73
		f 3 115 -119 -118
		mu 0 3 74 73 75
		f 3 -122 -121 -120
		mu 0 3 76 78 77
		f 3 -124 -123 121
		mu 0 3 76 79 78
		f 3 123 -126 -125
		mu 0 3 79 76 80
		f 3 124 -128 -127
		mu 0 3 79 80 81
		f 3 -131 -130 -129
		mu 0 3 82 84 83
		f 3 -133 -132 130
		mu 0 3 82 85 84
		f 3 -136 -135 -134
		mu 0 3 86 88 87
		f 3 -138 -137 135
		mu 0 3 86 89 88
		f 3 137 -140 -139
		mu 0 3 89 86 90
		f 3 138 -142 -141
		mu 0 3 89 90 91
		f 3 -145 -144 -143
		mu 0 3 92 94 93
		f 3 -147 -146 144
		mu 0 3 92 95 94;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_16" -p "Script";
	rename -uid "28697E13-4CC8-461A-BAB9-12B8DC2B6273";
	setAttr ".t" -type "double3" 8.04 7.82 3.43 ;
	setAttr ".r" -type "double3" 0 -350.07 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_17" -p "Box_16";
	rename -uid "BF627350-4587-DF64-CC28-32BEC57AA79D";
	setAttr ".ro" 2;
createNode transform -n "transform21" -p "Box_17";
	rename -uid "C2234F41-416D-015F-4138-C3B7C5C3DC1B";
	setAttr ".v" no;
createNode mesh -n "Box_17Shape" -p "transform21";
	rename -uid "111939FF-4023-40A2-B61E-949670E26492";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 10.78100014 -1.96990001 0.78759998 10.78100014 1.96990001
		 -0.78759998 10.78100014 1.96990001 -0.78759998 10.78100014 -1.96990001 -0.78759998 10.78100014 1.96990001
		 -0.78759998 -7.31099987 1.96990001 -0.78759998 -7.31099987 -1.96990001 -0.78759998 10.78100014 -1.96990001;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103
		 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_18" -p "Script";
	rename -uid "C73AAB69-4DD6-5D7A-DCA0-7CAD2670A50B";
	setAttr ".t" -type "double3" -4.99 6.94 34.86 ;
	setAttr ".ro" 2;
createNode transform -n "Box_19" -p "Box_18";
	rename -uid "40CC567B-46E8-E5C2-AD28-02808D9B4221";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape12" -p "Box_19";
	rename -uid "F71E316E-4DFE-7695-8FE2-A3813F6003CE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -1.8441 8.0052995682 3.47169995 -1.8441 8.0052995682 -3.47169995
		 1.8441 8.0052995682 -3.47169995 1.8441 8.0052995682 3.47169995 1.8441 -8.0052995682 3.47169995
		 1.8441 8.0052995682 3.47169995 1.8441 8.0052995682 -3.47169995 1.8441 -8.0052995682 -3.47169995;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform1" -p "Box_19";
	rename -uid "8CC0D888-47BE-BF7C-F665-5EA6FFBD6761";
	setAttr ".v" no;
createNode mesh -n "Box_19Shape" -p "transform1";
	rename -uid "CEDDA712-4555-3FA6-E0E5-AE8CD7E3F2AA";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_20" -p "Script";
	rename -uid "F180A30C-4C6E-F796-F242-BCBB921393DC";
	setAttr ".t" -type "double3" 1.75 2.943 59.38 ;
	setAttr ".ro" 2;
createNode transform -n "Box_21" -p "Box_20";
	rename -uid "475C6825-486E-D43C-4DEB-C396614CE4E5";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape5" -p "Box_21";
	rename -uid "5F8FDB74-4500-6275-729B-4283B23930CE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  4.91750002 0.74220002 -1.78129995 4.91750002 0.74220002 1.78129995
		 -4.91750002 0.74220002 1.78129995 -4.91750002 0.74220002 -1.78129995;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform8" -p "Box_21";
	rename -uid "F4D0D6C5-4E96-A917-F055-C2A6C8A6FBA1";
	setAttr ".v" no;
createNode mesh -n "Box_21Shape" -p "transform8";
	rename -uid "8E62E143-4820-4BB0-2FE5-2E8DA432C5EE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_22" -p "Script";
	rename -uid "9CF43D21-45F7-936B-9970-8B8FBF171B5E";
	setAttr ".t" -type "double3" 5.3 0 18.94 ;
	setAttr ".ro" 2;
createNode transform -n "Box_23" -p "Box_22";
	rename -uid "70DA04BC-46F7-5ED8-2B6F-C3B3A0387AAC";
	setAttr ".ro" 2;
createNode transform -n "transform18" -p "Box_23";
	rename -uid "4E58B28F-4AE8-59E2-D7B3-F3BEA3F61A5D";
	setAttr ".v" no;
createNode mesh -n "Box_23Shape" -p "transform18";
	rename -uid "0C887C72-4D48-B062-F647-7FB04FF3951E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  3.1164999 0.76840001 -6.74840021 3.1164999 0.76840001 6.74840021
		 -3.1164999 0.76840001 6.74840021 -3.1164999 0.76840001 -6.74840021;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_24" -p "Script";
	rename -uid "811EE662-4F4E-8E11-FA12-7EB74366EA4D";
	setAttr ".t" -type "double3" 0.94 0 0.06 ;
	setAttr ".ro" 2;
createNode transform -n "Box_25" -p "Box_24";
	rename -uid "F0F24383-46DC-2066-43B3-2A935C61B1B2";
	setAttr ".ro" 2;
createNode transform -n "transform26" -p "Box_25";
	rename -uid "8DF7437A-471E-6C4D-7BFA-1490168A3E85";
	setAttr ".v" no;
createNode mesh -n "Box_25Shape" -p "transform26";
	rename -uid "1539481C-4D6D-937D-FEC9-708BE378511B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  8.60620022 0.76840001 -6.13670015 8.60620022 0.76840001 6.13670015
		 -8.60620022 0.76840001 6.13670015 -8.60620022 0.76840001 -6.13670015;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_26" -p "Script";
	rename -uid "A57A468B-46EC-5D40-2C4A-C6BE329ABE80";
	setAttr ".t" -type "double3" -7.74 2.909 51.95 ;
	setAttr ".ro" 2;
	setAttr ".s" -type "double3" 1 1 3.57 ;
createNode transform -n "Box_27" -p "Box_26";
	rename -uid "B16ECAAE-4F28-FF4A-3994-358257BA5CB5";
	setAttr ".t" -type "double3" 0.018 0 0 ;
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape4" -p "Box_27";
	rename -uid "4E4C4966-482E-EFF1-B60F-E19E6E4FD650";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  0.91589999 0.76840001 -1.22930002 0.91589999 0.76840001 1.22930002
		 -0.91579998 0.76840001 1.22930002 -0.91579998 0.76840001 -1.22930002;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform9" -p "Box_27";
	rename -uid "00709BE5-4C3E-B423-D477-70BBEBB8E323";
	setAttr ".v" no;
createNode mesh -n "Box_27Shape" -p "transform9";
	rename -uid "845276CC-49C7-642F-2A46-7AA8AC457DF5";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_28" -p "Script";
	rename -uid "FDA02A7A-46A7-1472-5B6A-2A946CF13AFE";
	setAttr ".t" -type "double3" -16.04 1.35 0.05 ;
	setAttr ".r" -type "double3" 0 0 -9.092026 ;
	setAttr ".ro" 2;
createNode transform -n "Box_29" -p "Box_28";
	rename -uid "EDFAFBFA-40E1-89B3-2C5C-788A9C4401A5";
	setAttr ".ro" 2;
createNode transform -n "transform27" -p "Box_29";
	rename -uid "538A2D8A-4E56-A0EE-29AF-D0847E6DBE78";
	setAttr ".v" no;
createNode mesh -n "Box_29Shape" -p "transform27";
	rename -uid "738C4AD7-42EF-220E-FF24-1693AC86570A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  8.45189953 0.76840001 -6.14330006 8.45189953 0.76840001 6.14330006
		 -9.87530041 0.76840001 6.14330006 -9.87530041 0.76840001 -6.14330006;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_30" -p "Script";
	rename -uid "36DBC229-4D5C-31A1-2426-B6983A2FFC2A";
	setAttr ".t" -type "double3" -6.83 6.94 30.04 ;
	setAttr ".r" -type "double3" 0 -318.1805 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_31" -p "Box_30";
	rename -uid "EB676F54-4770-C999-D28C-1DA369E3A143";
	setAttr ".ro" 2;
createNode transform -n "transform13" -p "Box_31";
	rename -uid "09E71BA0-4ED5-0546-B67B-2AA28F370740";
	setAttr ".v" no;
createNode mesh -n "Box_31Shape" -p "transform13";
	rename -uid "51C6A7B3-425A-6B53-D838-E2B5AABB54BE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -1.8441 8.0052995682 3.47169995 -1.8441 8.0052995682 -3.47169995
		 1.8441 8.0052995682 -3.47169995 1.8441 8.0052995682 3.47169995 1.8441 -8.0052995682 3.47169995
		 1.8441 8.0052995682 3.47169995 1.8441 8.0052995682 -3.47169995 1.8441 -8.0052995682 -3.47169995;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_32" -p "Script";
	rename -uid "81F2343F-4C2F-0E77-885B-AFA0627B754B";
	setAttr ".t" -type "double3" 6.31 7.82 -0.35 ;
	setAttr ".r" -type "double3" 0 -320.9792 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_33" -p "Box_32";
	rename -uid "AC023773-475A-E987-E0C1-CD96D70AB15C";
	setAttr ".ro" 2;
createNode transform -n "transform22" -p "Box_33";
	rename -uid "C1CA4194-4E0D-B834-AF8F-3C829994E44F";
	setAttr ".v" no;
createNode mesh -n "Box_33Shape" -p "transform22";
	rename -uid "0879C962-496B-519E-C455-FF86585C94CC";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 3 ".pt";
	setAttr ".pt[4]" -type "float3" 0 0 -1.8626451e-009 ;
	setAttr ".pt[6]" -type "float3" 0 0 -1.8626451e-009 ;
	setAttr ".pt[7]" -type "float3" 0 0 -1.8626451e-009 ;
	setAttr -s 8 ".vt[0:7]"  0.78759998 10.78100014 -1.96990001 0.78759998 10.78100014 1.96990001
		 -0.78759998 10.78100014 1.96990001 -0.78759998 10.78100014 -1.96990001 -0.78759998 10.78100014 1.96990001
		 -0.78759998 -7.31099987 1.96990001 -0.78759998 -7.31099987 -1.96990001 -0.78759998 10.78100014 -1.96990001;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103
		 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Cube_1" -p "Script";
	rename -uid "98E9FEBA-48AA-C9AF-8734-BF87EFF29B3D";
	setAttr ".t" -type "double3" 10.83 -2.39 -16.12 ;
	setAttr ".ro" 2;
	setAttr ".s" -type "double3" 1.4 1.4 1.4 ;
createNode transform -n "initialShadingGroup_pCube_1" -p "Cube_1";
	rename -uid "1550DCEE-4B89-7368-0606-78940D9729C2";
	setAttr ".ro" 2;
createNode transform -n "transform23" -p "initialShadingGroup_pCube_1";
	rename -uid "C73A3F21-467A-AEE6-ACEA-CFB8DE518A41";
	setAttr ".v" no;
createNode mesh -n "initialShadingGroup_pCube_1Shape" -p "transform23";
	rename -uid "C0CAD630-40C4-CD59-DAF3-F08DD3A013D7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.875 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0.375 0 0.375 0.25
		 0.625 0.25 0.625 0 0.375 0.25 0.375 0.5 0.625 0.5 0.625 0.25 0.125 0 0.125 0.25 0.375
		 0.25 0.375 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -25.95070076 3.52018189 7.97007704 -25.95070076 21.076919556 7.97007704
		 -8.93142605 14.94054985 7.97007704 -8.93142605 0.212207 7.97007704 -25.95070076 21.076919556 7.97007704
		 -25.95070076 21.076919556 6.044056892 -8.93142605 14.94054985 6.044056892 -8.93142605 14.94054985 7.97007704
		 -25.95070076 3.52018189 6.044056892 -25.95070076 21.076919556 6.044056892 -25.95070076 21.076919556 7.97007704
		 -25.95070076 3.52018189 7.97007704;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0 0 1 0 0 1 0 0 1 0 0 1 0 0
		 1 0 0 1 0.3391811 0.94072121 0 0.3391811 0.94072121 0 0.3391811 0.94072121 0 0.3391811
		 0.94072121 0 0.3391811 0.94072121 0 0.3391811 0.94072121 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6
		f 3 -13 -12 -11
		mu 0 3 8 10 9
		f 3 -15 -14 12
		mu 0 3 8 11 10;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_34" -p "Script";
	rename -uid "EB3427E3-4E66-3924-A07B-0D8542E3856C";
	setAttr ".t" -type "double3" 7.93 9.26 29.57 ;
	setAttr ".r" -type "double3" 0 -13.43977 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_35" -p "Box_34";
	rename -uid "7C1E2C31-4BBF-47FC-A04B-E7857C82CCA6";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape1" -p "Box_35";
	rename -uid "67782FF4-4EE7-2E5B-84A5-4A9D6546D9A1";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 1 0 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 9.4545002 -1.77719998 0.78759998 9.4545002 2.12820005
		 -0.78750002 9.4545002 2.12820005 -0.78750002 9.4545002 -1.77719998 -0.78750002 9.4545002 2.12820005
		 -0.78759998 -9.15200043 2.12420011 -0.78759998 -9.15200043 -1.78129995 -0.78750002 9.4545002 -1.77719998;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform14" -p "Box_35";
	rename -uid "3AB8D481-46D1-8211-A08A-8F9B03BBDC8C";
	setAttr ".v" no;
createNode mesh -n "Box_35Shape" -p "transform14";
	rename -uid "41F17AB1-4CD0-FCF9-AE0F-8BB396946C0D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 1 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".pt";
	setAttr ".pt[1]" -type "float3" 1.4901161e-008 0 0 ;
	setAttr ".pt[5]" -type "float3" 1.4901161e-008 0 0 ;
	setAttr ".pt[8]" -type "float3" -3.3378601e-006 0 -5.9604645e-007 ;
	setAttr ".pt[9]" -type "float3" -3.3378601e-006 0 -5.9604645e-007 ;
	setAttr ".dr" 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_36" -p "Script";
	rename -uid "7991B519-4F6D-CDBB-C4B9-A59F374E7D0B";
	setAttr ".t" -type "double3" -0.12 7.82 -5.24 ;
	setAttr ".r" -type "double3" 0 -287.2729 0 ;
	setAttr ".ro" 2;
createNode transform -n "Box_37" -p "Box_36";
	rename -uid "157BCAE6-42AA-03A5-8CC2-2C8C10BC49C3";
	setAttr ".ro" 2;
createNode transform -n "transform24" -p "Box_37";
	rename -uid "E5B548C3-42BE-3A55-EA4B-E1832B10EA5C";
	setAttr ".v" no;
createNode mesh -n "Box_37Shape" -p "transform24";
	rename -uid "ED20B50B-49BC-A2C9-63CE-D3A37C149A0A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 10.78100014 -1.96990001 0.78759998 10.78100014 1.96990001
		 -0.78759998 10.78100014 1.96990001 -0.78759998 10.78100014 -1.96990001 -0.78759998 10.78100014 1.96990001
		 -0.78759998 -7.31099987 1.96990001 -0.78759998 -7.31099987 -1.96990001 -0.78759998 10.78100014 -1.96990001;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103
		 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103 -0.86601913 0 0.50001103;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_38" -p "Script";
	rename -uid "AA38A1AD-4B9F-D059-FBA8-EB93999E38C5";
	setAttr ".t" -type "double3" -7.13 7.63 10.54 ;
	setAttr ".ro" 2;
createNode transform -n "Box_39" -p "Box_38";
	rename -uid "F0A879D3-49D3-2BDF-6977-A690D7A09310";
	setAttr ".ro" 2;
createNode transform -n "transform15" -p "Box_39";
	rename -uid "AE931209-4A8F-FE92-2040-B1B5BC59BC93";
	setAttr ".v" no;
createNode mesh -n "Box_39Shape" -p "transform15";
	rename -uid "D6F8DE98-4D88-05EF-0274-D4A3963ADAB0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:7]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 16 ".uvst[0].uvsp[0:15]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 16 ".vt[0:15]"  -0.89999998 7.31099987 4.45979977 -0.89999998 7.31099987 -4.45979977
		 0.89999998 7.31099987 -4.45979977 0.89999998 7.31099987 4.45979977 -0.89999998 -7.31099987 4.45979977
		 -0.89999998 7.31099987 4.45979977 0.89999998 7.31099987 4.45979977 0.89999998 -7.31099987 4.45979977
		 0.89999998 -7.31099987 4.45979977 0.89999998 7.31099987 4.45979977 0.89999998 7.31099987 -4.45979977
		 0.89999998 -7.31099987 -4.45979977 0.89999998 -7.31099987 -4.45979977 0.89999998 7.31099987 -4.45979977
		 -0.89999998 7.31099987 -4.45979977 -0.89999998 -7.31099987 -4.45979977;
	setAttr -s 20 ".ed[0:19]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0 12 13 0 13 14 0 14 12 0 14 15 0
		 15 12 0;
	setAttr -s 24 ".n[0:23]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0
		 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1;
	setAttr -s 8 -ch 24 ".fc[0:7]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6
		f 3 -13 -12 -11
		mu 0 3 8 10 9
		f 3 -15 -14 12
		mu 0 3 8 11 10
		f 3 -18 -17 -16
		mu 0 3 12 14 13
		f 3 -20 -19 17
		mu 0 3 12 15 14;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_40" -p "Script";
	rename -uid "C6D4895B-4D54-4E94-B1B7-4283AAB5F12A";
	setAttr ".t" -type "double3" 6.96 9.49 38.16 ;
	setAttr ".ro" 2;
createNode transform -n "Box_41" -p "Box_40";
	rename -uid "BFDC1904-4EF1-8F96-B1CB-BCAA47F9330C";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape7" -p "Box_41";
	rename -uid "BDA57C0B-4108-29E1-8265-9F884C44CD64";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 30 ".uvst[0].uvsp[0:29]" -type "float2" 0.66670001 0 0.66670001
		 0 0.66670001 1 0.66670001 1 0.66670001 1 0.66670001 1 0.33329999 1 0.33329999 1 0.33329999
		 1 0.33329999 1 0.33329999 0 0.33329999 0 0 0 0 0.33329999 1 1 1 0 0 0.66670001 0
		 1 0.66670001 0 0.33329999 0 0.33329999 1 0.66670001 1 1 0 0.66670001 0 0.66670001
		 1 1 1 0 1 0.33329999 1 0.33329999 0 0 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 30 ".vt[0:29]"  -0.2861 -9.23680019 4.99370003 -1.28910005 -9.23680019 4.99370003
		 -1.28910005 5.89379978 4.99370003 -0.2861 9.23680019 4.99469995 -0.2861 9.23680019 4.99469995
		 -1.28910005 5.89379978 4.99370003 -1.28910005 5.89379978 2.86220002 -0.2861 9.23680019 2.86319995
		 -0.2861 9.23680019 2.86319995 -1.28910005 5.89379978 2.86220002 -1.28910005 -9.23680019 2.86220002
		 -0.2861 -9.23680019 2.86220002 -0.2861 9.23680019 6.70779991 -0.2861 9.23680019 4.99469995
		 1.28910005 9.23680019 -6.70679998 1.28910005 9.23680019 6.70779991 -0.2861 9.23680019 2.86319995
		 -0.2861 9.23680019 -6.70679998 -1.28910005 -9.23680019 4.99370003 -1.28910005 -9.23680019 2.86220002
		 -1.28910005 5.89379978 2.86220002 -1.28910005 5.89379978 4.99370003 -0.2861 -9.23680019 6.70679998
		 -0.2861 -9.23680019 4.99370003 -0.2861 9.23680019 4.99469995 -0.2861 9.23680019 6.70779991
		 -0.2861 9.23680019 -6.70679998 -0.2861 9.23680019 2.86319995 -0.2861 -9.23680019 2.86220002
		 -0.2861 -9.23680019 -6.70779991;
	setAttr -s 39 ".ed[0:38]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0 12 13 0 13 14 0 14 12 0 14 15 0
		 15 12 0 16 14 0 13 16 0 16 17 0 17 14 0 18 19 0 19 20 0 20 18 0 20 21 0 21 18 0 22 23 0
		 23 24 0 24 22 0 24 25 0 25 22 0 26 27 0 27 28 0 28 26 0 28 29 0 29 26 0;
	setAttr -s 48 ".n[0:47]" -type "float3"  -0.00039999999 0 1 -0.00039999999
		 0 1 -0.00039999999 0 1 -0.00039999999 0 1 -0.00039999999 0 1 -0.00039999999 0 1 -0.95780969
		 0.2874029 0 -0.95780969 0.2874029 0 -0.95780969 0.2874029 0 -0.95780969 0.2874029
		 0 -0.95780969 0.2874029 0 -0.95780969 0.2874029 0 0.00039999999 0 -1 0.00039999999
		 0 -1 0.00039999999 0 -1 0.00039999999 0 -1 0.00039999999 0 -1 0.00039999999 0 -1
		 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 16 -ch 48 ".fc[0:15]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6
		f 3 -13 -12 -11
		mu 0 3 8 10 9
		f 3 -15 -14 12
		mu 0 3 8 11 10
		f 3 -18 -17 -16
		mu 0 3 12 14 13
		f 3 -20 -19 17
		mu 0 3 12 15 14
		f 3 -22 16 -21
		mu 0 3 16 13 14
		f 3 20 -24 -23
		mu 0 3 16 14 17
		f 3 -27 -26 -25
		mu 0 3 18 20 19
		f 3 -29 -28 26
		mu 0 3 18 21 20
		f 3 -32 -31 -30
		mu 0 3 22 24 23
		f 3 -34 -33 31
		mu 0 3 22 25 24
		f 3 -37 -36 -35
		mu 0 3 26 28 27
		f 3 -39 -38 36
		mu 0 3 26 29 28;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform6" -p "Box_41";
	rename -uid "FE9CEE27-4F2C-6DE6-D2B5-84822874BCF6";
	setAttr ".v" no;
createNode mesh -n "Box_41Shape" -p "transform6";
	rename -uid "C360E367-45FA-89CF-DFAD-90971018AB52";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_42" -p "Script";
	rename -uid "497D3C6D-46E6-B05D-F099-F39B8F331D6C";
	setAttr ".t" -type "double3" -0.2 0 28.82 ;
	setAttr ".ro" 2;
createNode transform -n "Box_43" -p "Box_42";
	rename -uid "DA4C1E2E-4CFB-84A6-86F7-40BD5FBDD3D3";
	setAttr ".ro" 2;
createNode transform -n "transform17" -p "Box_43";
	rename -uid "DA5B50BD-4DC5-22A6-CF1F-24A3794900BA";
	setAttr ".v" no;
createNode mesh -n "Box_43Shape" -p "transform17";
	rename -uid "52CA93FF-4BE0-59B3-186E-5180FCBD58F0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  8.6534996 0.76840001 -3.1415 8.6534996 0.76840001 3.1415
		 -8.6534996 0.76840001 3.1415 -8.6534996 0.76840001 -3.1415;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_44" -p "Script";
	rename -uid "BCC68D76-4080-3600-6316-8ABCE55BA805";
	setAttr ".t" -type "double3" 7.46 7.57 51.27 ;
	setAttr ".ro" 2;
createNode transform -n "Box_45" -p "Box_44";
	rename -uid "5E9B9397-4083-0B11-0C5D-8BB8E10133FF";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape6" -p "Box_45";
	rename -uid "F318BC5A-4EC0-1C33-29AA-90A8212494A7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 11.1626997 -6.40530014 0.78759998 11.1626997 6.40719986
		 -0.78750002 11.1626997 6.40719986 -0.78750002 11.1626997 -6.40530014 -0.78750002 11.1626997 6.40719986
		 -0.78759998 -7.31099987 6.40630007 -0.78759998 -7.31099987 -6.40630007 -0.78750002 11.1626997 -6.40530014;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform7" -p "Box_45";
	rename -uid "1FAC0B9E-436D-E59F-9EC6-1BB5C49A8429";
	setAttr ".v" no;
createNode mesh -n "Box_45Shape" -p "transform7";
	rename -uid "E3691A61-4157-5DBE-B643-F08D1A27C04C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_46" -p "Script";
	rename -uid "35DD1BB9-4CEC-E533-374A-DB9BFBAA0C8A";
	setAttr ".t" -type "double3" 0.47 0 9.19 ;
	setAttr ".ro" 2;
createNode transform -n "Box_47" -p "Box_46";
	rename -uid "A11D38B0-4233-5862-35C0-7080EE152F6E";
	setAttr ".ro" 2;
createNode transform -n "transform16" -p "Box_47";
	rename -uid "79F093AE-4304-3AE9-834C-0CB7B7657FCF";
	setAttr ".v" no;
createNode mesh -n "Box_47Shape" -p "transform16";
	rename -uid "5E70E6E2-4A6C-5A57-FD85-FEA8EB0A51F9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  7.97049999 0.76840001 -3.050199986 7.97049999 0.76840001 3.050199986
		 -7.97049999 0.76840001 3.050199986 -7.97049999 0.76840001 -3.050199986;
	setAttr -s 5 ".ed[0:4]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0;
	setAttr -s 6 ".n[0:5]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0;
	setAttr -s 2 -ch 6 ".fc[0:1]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_48" -p "Script";
	rename -uid "79AE958C-4A13-FA1F-69D8-939413B00274";
	setAttr ".t" -type "double3" 7.46 9.27 59.43 ;
	setAttr ".ro" 2;
createNode transform -n "Box_49" -p "Box_48";
	rename -uid "B5422947-4E50-BD76-C769-3893CFBB4C9D";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape11" -p "Box_49";
	rename -uid "FEAA6125-484E-0632-4C2C-2896FECD24DE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 9.4545002 -1.77719998 0.78759998 9.4545002 1.78530002
		 -0.78750002 9.4545002 1.78530002 -0.78750002 9.4545002 -1.77719998 -0.78750002 9.4545002 1.78530002
		 -0.78759998 -5.60370016 1.78129995 -0.78759998 -5.60370016 -1.78129995 -0.78750002 9.4545002 -1.77719998;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform2" -p "Box_49";
	rename -uid "27A9F8AE-47D8-6458-12EC-629CA7976B2E";
	setAttr ".v" no;
createNode mesh -n "Box_49Shape" -p "transform2";
	rename -uid "C6F6B8AD-423C-D0E7-F216-2F96B74AFF96";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_50" -p "Script";
	rename -uid "0DBBE4CA-499D-8831-C91E-C595D6F08566";
	setAttr ".t" -type "double3" 7.21 9.34 68.99 ;
	setAttr ".r" -type "double3" 0 -90 0 ;
	setAttr ".ro" 2;
	setAttr ".s" -type "double3" 1 0.86535830000000002 0.97378390000000004 ;
createNode transform -n "Box_51" -p "Box_50";
	rename -uid "502DCBCD-44E9-78CE-97E9-D88F83C6CDCE";
	setAttr ".t" -type "double3" -7.02 -0.25 7.17 ;
	setAttr ".ro" 2;
	setAttr ".s" -type "double3" 1 1 1.125966 ;
createNode mesh -n "polySurfaceShape8" -p "Box_51";
	rename -uid "D58C6BFE-4DD1-D521-5997-3D8DFE973F54";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 1 1 1 0 0 0 0 1 1
		 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  0.78759998 11.1626997 -6.40530014 0.78759998 11.1626997 6.40719986
		 -0.78750002 11.1626997 6.40719986 -0.78750002 11.1626997 -6.40530014 -0.78750002 11.1626997 6.40719986
		 -0.78759998 -7.31099987 6.40630007 -0.78759998 -7.31099987 -6.40630007 -0.78750002 11.1626997 -6.40530014;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 4 -ch 12 ".fc[0:3]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 -10 -9 7
		mu 0 3 4 7 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform5" -p "Box_51";
	rename -uid "C056C5ED-4EEF-5504-54E4-7C8EC412D8FF";
	setAttr ".v" no;
createNode mesh -n "Box_51Shape" -p "transform5";
	rename -uid "70B846E3-4F3A-77C6-027C-AAB9F43425BF";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_5";
	rename -uid "9F77C864-4704-4736-17E6-39BD82E38FAC";
	setAttr ".rp" -type "double3" -0.1943499622344973 8.8590478460543167 47.07295001387596 ;
	setAttr ".sp" -type "double3" -0.1943499622344973 8.8590478460543167 47.07295001387596 ;
createNode transform -n "polySurface1" -p "|Box_5";
	rename -uid "011028B4-4E06-C666-715F-938AE56F3CEC";
createNode transform -n "transform37" -p "polySurface1";
	rename -uid "37B86B81-4C8F-114D-48B5-338BF3E349BE";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape13" -p "transform37";
	rename -uid "2E8B62F6-4EF2-547A-30DE-0098012ADB7E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface2" -p "|Box_5";
	rename -uid "9E3C6DD0-4148-88C1-D304-AB9963B2644C";
createNode transform -n "transform38" -p "polySurface2";
	rename -uid "F8FDA0A6-40E1-C826-A66D-43A44D0738C0";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape14" -p "transform38";
	rename -uid "80F30B07-4821-A72A-60CB-D18F85415CE4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface3" -p "|Box_5";
	rename -uid "D28F36A5-4963-EF11-68DD-8B9031426B0D";
createNode transform -n "transform39" -p "polySurface3";
	rename -uid "02580B42-4F61-B0B2-201C-1CAC11934CD7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape15" -p "transform39";
	rename -uid "1682C4C2-4FD5-FBD3-47F3-8D9D938EDD3F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface4" -p "|Box_5";
	rename -uid "92CE7C47-4AE1-6C37-D463-2C9A7A4F21C2";
createNode transform -n "transform40" -p "polySurface4";
	rename -uid "D6EEE034-44AD-6B6B-8C82-2E92DE20BE43";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape16" -p "transform40";
	rename -uid "7DACDA10-4B63-BA92-B97E-1990444DAEB5";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface5" -p "|Box_5";
	rename -uid "1D72171E-4437-1E21-A458-B9AC113AF6C6";
createNode transform -n "transform41" -p "polySurface5";
	rename -uid "25A4AEB4-469D-97A0-9919-D29A30723EA8";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape17" -p "transform41";
	rename -uid "65C81682-4448-F279-0952-05ABBB7BB439";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface6" -p "|Box_5";
	rename -uid "3CAC62F2-48DC-BC87-50FD-DE88524031E4";
createNode transform -n "transform42" -p "polySurface6";
	rename -uid "7BD7ACEC-45DA-39C1-CDCA-FFA7AAB61AF4";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape18" -p "transform42";
	rename -uid "DA507960-4113-47E7-DA39-CAA2DC66C52D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface7" -p "|Box_5";
	rename -uid "13452424-4DD2-F9CD-6817-E9B86F4A7A8E";
createNode transform -n "transform31" -p "polySurface7";
	rename -uid "FBB2E223-4017-B03B-7D71-9FA5643E4431";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape19" -p "transform31";
	rename -uid "3562D28D-4EB3-218A-7F65-438FC1C1A898";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface8" -p "|Box_5";
	rename -uid "26D1A655-43A6-5A76-98B3-6394B8C400CA";
createNode transform -n "transform46" -p "polySurface8";
	rename -uid "A8439B0C-4E65-052A-0ABE-228939A71745";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape20" -p "transform46";
	rename -uid "2D3D68BD-4DE1-F09C-523D-20AF0A6180B8";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface9" -p "|Box_5";
	rename -uid "3479AD8C-4925-C133-88A6-B79A8B6D5C2B";
createNode transform -n "transform47" -p "polySurface9";
	rename -uid "8F1E34AA-4DD4-CDF9-93C0-08A68E4F9E4F";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape21" -p "transform47";
	rename -uid "EABBB121-4AB7-245F-DEE8-629A25924127";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface10" -p "|Box_5";
	rename -uid "B33B1A38-492B-10F6-881A-7EB14428907F";
createNode transform -n "transform48" -p "polySurface10";
	rename -uid "74D2AD93-4C20-47E8-24DD-A4AA1422E6D6";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape22" -p "transform48";
	rename -uid "AD27C0D5-4EE5-763C-7752-BCA0558CE4BE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface11" -p "|Box_5";
	rename -uid "69D290A8-4839-F11D-6D4B-D2834F5C5C1C";
createNode transform -n "transform43" -p "polySurface11";
	rename -uid "1267A953-40EF-0F9F-546E-0A835F8669E5";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape23" -p "transform43";
	rename -uid "8AFF3838-4F93-1587-1112-41ADFB5D0874";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface12" -p "|Box_5";
	rename -uid "6490C15A-4F7D-DF36-1F62-58B5B33BE621";
createNode transform -n "transform44" -p "polySurface12";
	rename -uid "9923E80B-4454-1963-F290-2197EE0E5F04";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape24" -p "transform44";
	rename -uid "1D66030B-4A55-7243-058D-7CBC20AA0898";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface13" -p "|Box_5";
	rename -uid "D9BC2826-4CF6-B8C0-BC46-30BB58A61CA8";
createNode transform -n "transform45" -p "polySurface13";
	rename -uid "92559079-42D2-1D8D-F959-89976101A9CB";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape25" -p "transform45";
	rename -uid "4C8FDB18-49BB-1044-4999-20BCF4F32677";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface14" -p "|Box_5";
	rename -uid "64B40045-4532-E758-5263-74AC8960EE0A";
createNode transform -n "transform51" -p "polySurface14";
	rename -uid "435D26B7-44A5-6F27-9676-6CA9101084B7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape26" -p "transform51";
	rename -uid "5FE8327A-47AD-7027-D3C9-53BB77D2261F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface15" -p "|Box_5";
	rename -uid "06762948-4E88-664F-1AE1-4FB48F7D5E30";
createNode transform -n "transform52" -p "polySurface15";
	rename -uid "FFC70195-4D8F-4857-59FC-CFA72A12CE46";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape27" -p "transform52";
	rename -uid "1F1CA69B-481B-CD83-F978-8190E234109D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface16" -p "|Box_5";
	rename -uid "1015F8FE-441F-81E6-15CD-449D20554C24";
createNode transform -n "transform53" -p "polySurface16";
	rename -uid "2DFDD5CB-4C40-25C1-73F8-00A6C9C3B078";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape28" -p "transform53";
	rename -uid "C4DA6CB1-424C-2BC3-A439-0B85733766B9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface17" -p "|Box_5";
	rename -uid "3F08F622-4F5E-044F-A8C4-D981D1C84B69";
createNode transform -n "transform49" -p "polySurface17";
	rename -uid "40CC5AB6-417B-AB83-03F0-F0B48EB6D50A";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape29" -p "transform49";
	rename -uid "56459FBC-46ED-34F3-3700-02A286272F5A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface18" -p "|Box_5";
	rename -uid "6C85F48E-4878-6BCD-AD5A-A390400F6F1C";
createNode transform -n "transform50" -p "polySurface18";
	rename -uid "5A60FEFB-42CA-FBFB-96B2-25B21F479871";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape30" -p "transform50";
	rename -uid "D7E928F4-4541-EF88-C555-409C348C7815";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface19" -p "|Box_5";
	rename -uid "011D2DA9-4F82-FAE8-C994-2F8EE9716765";
createNode transform -n "transform30" -p "polySurface19";
	rename -uid "5000B82F-4FC8-3E56-FA1F-8E852D29E687";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape31" -p "transform30";
	rename -uid "314529DB-4ABA-9475-03BF-39875C411A34";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface20" -p "|Box_5";
	rename -uid "65EF4069-4BFC-3184-C0C9-6CB7E7CA9186";
createNode transform -n "transform32" -p "|Box_5|polySurface20";
	rename -uid "913D903A-468C-CB9F-2E31-20B945853F87";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape32" -p "transform32";
	rename -uid "42CBFE77-4374-EBAC-ED9B-83BA9DB100EB";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface21" -p "|Box_5";
	rename -uid "703D8D1C-49FE-F896-572F-88887CAF7C66";
createNode transform -n "transform35" -p "polySurface21";
	rename -uid "644B87DD-46A3-D5EB-14F5-F9804729D77B";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape33" -p "transform35";
	rename -uid "2336000F-4786-395F-3D91-C8A065CF136B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface22" -p "|Box_5";
	rename -uid "AEE8D791-4543-E4C5-C80D-6CBA68672E09";
createNode transform -n "transform36" -p "polySurface22";
	rename -uid "E7447AF4-4D0F-B49F-2C02-B2B99E3EA8AA";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape34" -p "transform36";
	rename -uid "1E9920EC-4816-FB09-6AA7-C985877BAD20";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface23" -p "|Box_5";
	rename -uid "805A5E04-4581-E7C3-2E20-52A534776943";
createNode transform -n "transform33" -p "polySurface23";
	rename -uid "D7228671-40FB-7923-E931-EE93C7704979";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape35" -p "transform33";
	rename -uid "31B21E87-4D07-D10D-F168-5191303F57EB";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface24" -p "|Box_5";
	rename -uid "5F381563-4376-94AC-F528-CAAD8C197EC3";
createNode transform -n "transform34" -p "polySurface24";
	rename -uid "17B88D25-4E3B-6D0D-7234-32B1507940D7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape36" -p "transform34";
	rename -uid "313FAF87-41B6-DADC-F67A-089B5C5EE334";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform29" -p "|Box_5";
	rename -uid "62ACC366-4229-2D8A-595F-2995A184B43C";
	setAttr ".v" no;
createNode mesh -n "Box_5Shape" -p "transform29";
	rename -uid "9FEBFB7E-4449-9BB1-D92B-B8890FC1AB1A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_7";
	rename -uid "42DC7E33-4205-B2E9-2F93-5B89F75CF422";
	setAttr ".rp" -type "double3" -0.70457478225429959 8.8246003150939938 19.577650662946169 ;
	setAttr ".sp" -type "double3" -0.70457478225429959 8.8246003150939938 19.577650662946169 ;
createNode transform -n "polySurface50" -p "|Box_7";
	rename -uid "A9CD8E68-4274-65C4-C72D-668F3225BF27";
createNode transform -n "transform85" -p "polySurface50";
	rename -uid "607B791D-4352-F38E-DF6F-EAA3B9395DC5";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape61" -p "transform85";
	rename -uid "320643CB-4AA6-157C-887B-759908110788";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface51" -p "|Box_7";
	rename -uid "30E4B362-4242-27D2-C891-40834307B0C9";
createNode transform -n "transform86" -p "|Box_7|polySurface51";
	rename -uid "118D9D23-4366-ECF7-B6FC-0D942B22747F";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape62" -p "transform86";
	rename -uid "3F34C510-43D7-6491-FC23-D29007B1596B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface52" -p "|Box_7";
	rename -uid "363EE731-4C8B-AED2-8030-84B41E666BDA";
createNode mesh -n "polySurfaceShape63" -p "polySurface52";
	rename -uid "807751FE-4BBC-3C44-D072-4CB5F25F68E9";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface53" -p "|Box_7";
	rename -uid "8889B014-4032-6EAF-B20F-09A321018713";
createNode transform -n "transform79" -p "polySurface53";
	rename -uid "D1286AD3-4567-F1D4-0D2E-AA9F651C7479";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape64" -p "transform79";
	rename -uid "2038288A-45E2-4DE7-09DB-0382FF7630E2";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface54" -p "|Box_7";
	rename -uid "08A0E66E-4F1D-5600-BD70-5D834DF6F426";
createNode transform -n "transform78" -p "polySurface54";
	rename -uid "ECB746EA-4BD2-A093-0021-06A9DD098A9C";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape65" -p "transform78";
	rename -uid "D43B26AB-45D3-5AF7-FD3B-16850BD11C30";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface55" -p "|Box_7";
	rename -uid "814898FD-432A-0C24-FFDD-3496CE787874";
createNode transform -n "transform77" -p "polySurface55";
	rename -uid "9945B29D-48D0-2CF8-7AA3-BB8C44017C19";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape66" -p "transform77";
	rename -uid "2423B5B7-4BFC-5A09-1C11-4380F1415E5C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface56" -p "|Box_7";
	rename -uid "BFCF7E25-48D8-1A56-FF6F-26BDF90333B6";
createNode transform -n "transform80" -p "|Box_7|polySurface56";
	rename -uid "40B628EF-4ECF-C5D6-7E4E-4DAACEE3DC97";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape67" -p "transform80";
	rename -uid "840217BC-4CF5-F0DA-B6D6-49AE9B24B9DC";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface57" -p "|Box_7";
	rename -uid "82A6FB72-484F-BF24-644F-44B3900BBABE";
createNode transform -n "transform84" -p "polySurface57";
	rename -uid "EE0D73F9-412B-51E6-F57D-839A99C62F16";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape68" -p "transform84";
	rename -uid "19D4987D-41C2-EA8C-FEC1-F9A2B72E4A49";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface58" -p "|Box_7";
	rename -uid "0209EEE0-4B53-A48B-6EE6-D09548E833D4";
createNode transform -n "transform81" -p "polySurface58";
	rename -uid "FEBFFCDF-4937-DC29-5833-8C831DD63A5C";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape69" -p "transform81";
	rename -uid "CB30084C-4189-DC82-725C-DCAF684D8ED1";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface59" -p "|Box_7";
	rename -uid "04B2427D-4994-96F5-BFEA-8CB4253829B8";
createNode transform -n "transform83" -p "polySurface59";
	rename -uid "73108710-44F6-E1E2-9E48-C89F4F38194A";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape70" -p "transform83";
	rename -uid "BBDC8A44-4873-5CBC-88A3-4698C6D36BD3";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface60" -p "|Box_7";
	rename -uid "5774FC47-492D-B59B-3CE9-FB81ECB9B2BE";
createNode transform -n "transform82" -p "polySurface60";
	rename -uid "B2A3233D-49D9-C0D9-96D7-7FA8E20D8A76";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape71" -p "transform82";
	rename -uid "2C2BE757-4513-1F26-89AD-0B9BC4BF451A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface61" -p "|Box_7";
	rename -uid "C4A4376C-48AE-D2D6-160D-42A28120CB16";
createNode transform -n "transform87" -p "polySurface61";
	rename -uid "EF49719F-4AD4-D844-2D02-43850E0E75C1";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape72" -p "transform87";
	rename -uid "A9637398-492D-4263-7AD6-7D94C252321B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface62" -p "|Box_7";
	rename -uid "191A80E2-4895-D976-251B-A9A3B5140688";
createNode transform -n "transform88" -p "|Box_7|polySurface62";
	rename -uid "D1FCC43E-4690-7AFF-38B9-8E9FCDE632C7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape73" -p "transform88";
	rename -uid "DBA56803-4B71-944E-2406-CF969401AC8E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface63" -p "|Box_7";
	rename -uid "8135BC1E-40FB-3E31-C76A-23A4A4A751A7";
createNode transform -n "transform116" -p "polySurface63";
	rename -uid "F57FBFF6-4EB0-A7A7-6F7C-24A382C927E7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape74" -p "transform116";
	rename -uid "B880FD1C-4CC7-761B-D232-2F8A887B6ED0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface64" -p "|Box_7";
	rename -uid "AD9C4B27-4746-3ADF-A487-6897BBEA4E04";
createNode transform -n "transform117" -p "|Box_7|polySurface64";
	rename -uid "1A187C55-45FE-6A2C-D34F-6DBE444146FE";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape75" -p "transform117";
	rename -uid "E904B5B0-4CEE-6580-8BD7-87B23798896C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface65" -p "|Box_7";
	rename -uid "979627F4-45AB-E2F0-1DF6-6FB7EF465B2B";
createNode transform -n "transform89" -p "polySurface65";
	rename -uid "60EE1387-41D2-6A01-11C9-10BBBBC7B76F";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape76" -p "transform89";
	rename -uid "BCE26C02-40D7-F097-91B9-CF8B4E659BA0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface66" -p "|Box_7";
	rename -uid "14A1AAA1-4692-786A-080E-469B16C2AE32";
createNode transform -n "transform90" -p "polySurface66";
	rename -uid "011984EE-4636-B95C-2256-0A80A28AF56C";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape77" -p "transform90";
	rename -uid "3E70D34D-43D4-7ADC-ECC7-72AD18F7FCED";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface67" -p "|Box_7";
	rename -uid "6D60CAD4-42DE-0F04-F779-EBAF1CC6F2D7";
createNode mesh -n "polySurfaceShape78" -p "polySurface67";
	rename -uid "5B49E406-4DEF-00B8-EB41-5CB9E33CCE3F";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface68" -p "|Box_7";
	rename -uid "157F5E33-47F7-0BF7-D30E-ACB8FF275605";
createNode mesh -n "polySurfaceShape79" -p "polySurface68";
	rename -uid "EDEC2A88-46BA-8097-D63E-5F99C7D48972";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface69" -p "|Box_7";
	rename -uid "934862D9-4F07-6843-927D-07B0A1A04ED9";
createNode transform -n "transform91" -p "|Box_7|polySurface69";
	rename -uid "0E077EA1-4EF6-027A-A51B-C9A33CCE2082";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape80" -p "transform91";
	rename -uid "ADB13C51-4593-9E82-57A0-29931C10FD88";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface70" -p "|Box_7";
	rename -uid "06A72270-4B2E-0646-4865-C196846AAACA";
createNode transform -n "transform96" -p "|Box_7|polySurface70";
	rename -uid "EF061EAD-492A-5655-7C83-D0A24AFBB5D0";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape81" -p "transform96";
	rename -uid "F9C849E8-4676-4DC9-55A1-2EBDF04BBFDE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface71" -p "|Box_7";
	rename -uid "5AD35510-45D9-29CB-D845-4382B91B80A1";
createNode transform -n "transform97" -p "polySurface71";
	rename -uid "5DAB333A-49CD-C1D6-999F-FE8C1551CBF1";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape82" -p "transform97";
	rename -uid "79859E0C-4B39-298E-2F17-73B5D5DBE0DC";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface72" -p "|Box_7";
	rename -uid "0BBD63D2-46A5-FB84-D0C0-0E9B85B65853";
createNode transform -n "transform98" -p "|Box_7|polySurface72";
	rename -uid "66AC0596-4AAF-5861-48FF-85AC1E2B906B";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape83" -p "transform98";
	rename -uid "178C9D4C-44D3-B829-07C5-14AD5D9B5C60";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface73" -p "|Box_7";
	rename -uid "7553AB4E-4644-7787-5C5A-989F84D09633";
createNode transform -n "transform95" -p "polySurface73";
	rename -uid "AB7C5C05-41CD-4F8A-4826-EE922A345F96";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape84" -p "transform95";
	rename -uid "6ECE9934-45A5-F108-671E-AE946A13C139";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface74" -p "|Box_7";
	rename -uid "81D8F40C-4213-143D-70E6-42A30EFE6230";
createNode transform -n "transform93" -p "polySurface74";
	rename -uid "89ECAA6A-45F5-B2E7-1FEA-C89ACC1F592C";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape85" -p "transform93";
	rename -uid "8DC935D4-41CC-578A-45D4-06A2F6A24319";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface75" -p "|Box_7";
	rename -uid "6768E7AE-4DE0-2D40-D439-3884B7B9B7D8";
createNode transform -n "transform99" -p "polySurface75";
	rename -uid "5B4FA0C3-4D0C-984D-DFC4-448A909F4B44";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape86" -p "transform99";
	rename -uid "EDCEBE1B-4176-72E1-0B77-32937C04B0A5";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface76" -p "|Box_7";
	rename -uid "6B28F064-4AC6-4B2F-B9A7-648BC876EE04";
createNode mesh -n "polySurfaceShape87" -p "polySurface76";
	rename -uid "050A5037-4EDE-1BC4-5CA4-CFA6F784FFE4";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface77" -p "|Box_7";
	rename -uid "357051AB-43D0-9BA6-66BA-728BC3EB3978";
createNode transform -n "transform92" -p "polySurface77";
	rename -uid "798B3DCC-436C-CB5C-B744-B086C3F4D2A0";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape88" -p "transform92";
	rename -uid "7EC54786-427C-F6C6-79C4-5BB1E7ACCCE0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface78" -p "|Box_7";
	rename -uid "083F24E2-4A35-4901-85EC-4BB9E9795514";
createNode transform -n "transform100" -p "|Box_7|polySurface78";
	rename -uid "8FC11D80-4845-143A-D3DF-9B9FB63E83AB";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape89" -p "transform100";
	rename -uid "84B247E9-406E-3390-CE40-BAA5B938A9FA";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface79" -p "|Box_7";
	rename -uid "A084B4CE-46C0-47E4-E105-5D85EA8133F4";
createNode transform -n "transform94" -p "polySurface79";
	rename -uid "75FDDF64-4DAA-18CA-4942-87A771A9B1F6";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape90" -p "transform94";
	rename -uid "6531E212-40DD-42B4-0B0B-FA8FDA5DCAEC";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform72" -p "|Box_7";
	rename -uid "5B86EC38-4974-0575-A4A4-EDB5A0C66745";
	setAttr ".v" no;
createNode mesh -n "Box_7Shape" -p "transform72";
	rename -uid "6FD12D38-4C80-076F-B38D-C58992C97EDA";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.50000001955777407 0.48351326090050861 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt";
	setAttr ".pt[49]" -type "float3" 0 -4.4703484e-008 0 ;
	setAttr ".pt[51]" -type "float3" 0 4.4703484e-008 0 ;
	setAttr ".pt[52]" -type "float3" 0 4.4703484e-008 0 ;
	setAttr ".pt[53]" -type "float3" 0 4.4703484e-008 0 ;
	setAttr ".dr" 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "Box_1";
	rename -uid "5A7F1458-41E5-BF79-36E1-C0B2E5EBB0D8";
	setAttr ".rp" -type "double3" -8.0618009788377876 12.512388592064379 0.17087834358215215 ;
	setAttr ".sp" -type "double3" -8.0618009788377876 12.512388592064379 0.17087834358215215 ;
createNode transform -n "polySurface80" -p "|Box_1";
	rename -uid "F9FCE946-4FDB-EDCF-2330-7EBCFFE5050A";
createNode transform -n "transform110" -p "polySurface80";
	rename -uid "8FB77577-472B-B1E2-80F1-56A1F591D3EC";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape91" -p "transform110";
	rename -uid "62DB7271-4655-DF64-D1EA-CABC698F6F0D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface81" -p "|Box_1";
	rename -uid "7A7EBB0B-4231-660F-9A4D-55B852B0E631";
createNode transform -n "transform111" -p "|Box_1|polySurface81";
	rename -uid "CC03299B-42DE-EADD-8758-D89A881A29DD";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape92" -p "transform111";
	rename -uid "9CCBC699-4AC2-B6A5-9B2B-3F8D64A936E0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface82" -p "|Box_1";
	rename -uid "D6F2F3C0-4268-0F80-44F7-45A3B2FDF763";
createNode mesh -n "polySurfaceShape93" -p "polySurface82";
	rename -uid "B94E8376-425E-5379-A8A4-9A8DA1BFC18B";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface83" -p "|Box_1";
	rename -uid "2A5DF0BC-4B00-96FC-BEEE-F1AB139AB85F";
createNode mesh -n "polySurfaceShape94" -p "polySurface83";
	rename -uid "574CBCF1-44FE-A0D0-FF37-D3A86348303C";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface84" -p "|Box_1";
	rename -uid "075D941B-420F-FC22-3319-0182D5D362E7";
createNode transform -n "transform104" -p "|Box_1|polySurface84";
	rename -uid "BD496C82-4CFA-F2B1-F4F3-8390BFA3843F";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape95" -p "transform104";
	rename -uid "279C4C09-4CC6-AE6E-D7CE-4DB0CB3C137E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface85" -p "|Box_1";
	rename -uid "4739856F-47C2-CB4B-372C-F890B9E97F9A";
createNode transform -n "transform102" -p "polySurface85";
	rename -uid "8BA551DF-412F-C881-6901-5592E023D6E9";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape96" -p "transform102";
	rename -uid "B26B22AF-4BE9-F401-823F-4195F19AE460";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface86" -p "|Box_1";
	rename -uid "4FEE215E-46EA-9812-D9A8-66A2639CF46C";
createNode transform -n "transform103" -p "polySurface86";
	rename -uid "0D415CCF-4985-67F0-E0C8-828688FFC84A";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape97" -p "transform103";
	rename -uid "EE5C7A6D-412A-15A0-4544-94897A4BA415";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface87" -p "|Box_1";
	rename -uid "A600F1F3-4494-C49C-E8D8-56BCD2F7D157";
createNode transform -n "transform108" -p "polySurface87";
	rename -uid "FE697163-4BEC-02F5-16AE-A69E8641C90D";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape98" -p "transform108";
	rename -uid "841FD106-449E-3618-88BB-9391C5A1CBCA";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface88" -p "|Box_1";
	rename -uid "2657C92A-4A09-DD65-5FAD-B090EFABD6A0";
createNode transform -n "transform109" -p "|Box_1|polySurface88";
	rename -uid "70269847-438B-5F5C-DC2E-C7A2370B354B";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape99" -p "transform109";
	rename -uid "009AB440-4E8A-D84C-5E6B-36BB5955C749";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface89" -p "|Box_1";
	rename -uid "8A497692-4A3D-536E-A2B9-D4832831E10B";
createNode transform -n "transform107" -p "|Box_1|polySurface89";
	rename -uid "63EEA730-49D0-D766-12B2-6884C9185D60";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape100" -p "transform107";
	rename -uid "FBED9CC6-4A1A-76C5-DA7D-E39A1F9D2FBA";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface90" -p "|Box_1";
	rename -uid "A75845D9-43C4-ABF8-3776-999D289A2ECE";
createNode transform -n "transform106" -p "polySurface90";
	rename -uid "44ABFBE7-4C40-00C5-A4D7-C8B081CFD096";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape101" -p "transform106";
	rename -uid "4F565973-4A54-CC3D-2CF5-77A6204A8511";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface91" -p "|Box_1";
	rename -uid "7BF60CEF-4822-3CAC-04F5-57855F30F5D5";
createNode transform -n "transform105" -p "polySurface91";
	rename -uid "0C7C339B-425D-D442-70EC-E1B4E6DC83A7";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape102" -p "transform105";
	rename -uid "6BE790D7-445A-FA00-0061-5C8476D8367E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface92" -p "|Box_1";
	rename -uid "59FB8A7C-4869-528F-C6DE-E1A1B7DEF47A";
createNode transform -n "transform113" -p "|Box_1|polySurface92";
	rename -uid "73D73A1D-4A0E-D2DC-7098-3B8FDB79CC03";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape103" -p "transform113";
	rename -uid "00C5F588-4C2A-FF65-AC17-F1B966839E0E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface93" -p "|Box_1";
	rename -uid "52093CBB-4DC4-FF1D-8860-3D86C63451F7";
createNode transform -n "transform112" -p "polySurface93";
	rename -uid "62ADDFD3-48FE-5BAD-EBF9-8CB7BC331410";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape104" -p "transform112";
	rename -uid "2709EB87-4974-F7D6-6729-3D88696ED56C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface94" -p "|Box_1";
	rename -uid "573EC6B9-4123-1F16-B246-A288280B3974";
createNode transform -n "transform114" -p "polySurface94";
	rename -uid "2AFE1EB7-4CF4-A4A0-1315-8D975AB1548C";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape105" -p "transform114";
	rename -uid "1B2CF077-494B-1EC0-67DA-BC8C7678DD6A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface95" -p "|Box_1";
	rename -uid "58832B0F-463B-A444-047F-978180E50D88";
createNode transform -n "transform115" -p "|Box_1|polySurface95";
	rename -uid "803837D5-4279-2324-4CA6-3588E26A73BA";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape106" -p "transform115";
	rename -uid "AA02C9EC-4864-1364-BEE7-6C8EA771A87C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform101" -p "|Box_1";
	rename -uid "0008201E-4BA2-C487-BADD-03B9C2A33FE6";
	setAttr ".v" no;
createNode mesh -n "Box_1Shape" -p "transform101";
	rename -uid "14BD54A2-4635-A7CA-E867-35B8FDF25B35";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.49296784587204456 0.4959735949523747 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface20";
	rename -uid "AA028AEC-4166-4F8E-328A-B49AE7F5A36E";
	setAttr ".rp" -type "double3" 1.7650001049041748 2.2211223542690277 46.561300277709961 ;
	setAttr ".sp" -type "double3" 1.7650001049041748 2.2211223542690277 46.561300277709961 ;
createNode transform -n "transform54" -p "|polySurface20";
	rename -uid "E5D3FCF7-477A-7177-AA9F-C49D2DBD5F60";
	setAttr ".v" no;
createNode mesh -n "polySurface20Shape" -p "transform54";
	rename -uid "9ADC67E8-4F30-78A6-014E-AC872793F5F3";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr -av ".iog[0].og[1].gid";
	setAttr -av ".iog[0].og[2].gid";
	setAttr -av ".iog[0].og[3].gid";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.16464202472707257 0.72018228471279144 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".dr" 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface25";
	rename -uid "33548484-4F0C-D6D3-E03F-579977405D64";
	setAttr ".rp" -type "double3" -0.19435024261474609 8.8590471744537354 47.072951316833496 ;
	setAttr ".sp" -type "double3" -0.19435024261474609 8.8590471744537354 47.072951316833496 ;
createNode transform -n "polySurface26" -p "polySurface25";
	rename -uid "04511F51-4DAA-F5A2-E66F-099917E6942A";
createNode mesh -n "polySurfaceShape37" -p "polySurface26";
	rename -uid "3C44E8AF-4BBE-9AA1-7BD5-A09C66650BCF";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface27" -p "polySurface25";
	rename -uid "C9168F66-4944-3F8F-1C36-9BA481E216BE";
createNode mesh -n "polySurfaceShape38" -p "polySurface27";
	rename -uid "2331C31C-4871-4F40-A605-4595ED55785F";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface28" -p "polySurface25";
	rename -uid "73D0F62B-4437-942D-C76C-5E8D7B0CDDEC";
createNode mesh -n "polySurfaceShape39" -p "polySurface28";
	rename -uid "32EDC6F6-4ECF-9B46-1B14-C7A274288A66";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface29" -p "polySurface25";
	rename -uid "C9069A26-43AC-B015-20A7-6DA7CBAB6738";
createNode transform -n "transform61" -p "polySurface29";
	rename -uid "54AE6479-40E7-5890-0F1D-69822330EDDB";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape40" -p "transform61";
	rename -uid "16BE49A0-4C9A-E12A-8EB8-A8BFFCD3E1CD";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface30" -p "polySurface25";
	rename -uid "129F27F4-44E4-52BF-C22C-689727CF4981";
createNode transform -n "transform60" -p "polySurface30";
	rename -uid "B13E56CB-4F11-BDBC-FAA8-EAAAFB4CB595";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape41" -p "transform60";
	rename -uid "40748E3E-453E-EC99-1993-8AB0EF19EA47";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface31" -p "polySurface25";
	rename -uid "A51012BE-4AF8-EE96-AFAB-2288D9454C16";
createNode transform -n "transform68" -p "polySurface31";
	rename -uid "80F9B657-4250-A3E6-DACC-629C405672BA";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape42" -p "transform68";
	rename -uid "4E34FFA0-4ECB-1572-ECE1-979269684244";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface32" -p "polySurface25";
	rename -uid "0600DFEE-4500-372E-3FAA-B697605E83A8";
createNode transform -n "transform71" -p "|polySurface25|polySurface32";
	rename -uid "5EB57D18-4359-D647-F3D8-DAB2F2C8727B";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape43" -p "transform71";
	rename -uid "81A7CB5B-41A5-119C-3A2B-9E9F1F13D87C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface33" -p "polySurface25";
	rename -uid "8823C97E-4BC3-0609-0575-AAA636B39EED";
createNode transform -n "transform70" -p "polySurface33";
	rename -uid "1BE8EE52-47F8-1AC8-2C03-71BCD3ABC845";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape44" -p "transform70";
	rename -uid "D8A2427B-4873-F1ED-8083-2DA618722DCC";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface34" -p "polySurface25";
	rename -uid "CA25D4CE-4314-4881-34BB-E9A1F350E099";
createNode transform -n "transform67" -p "polySurface34";
	rename -uid "A7392186-40ED-4980-CDC8-48A7F3382B0F";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape45" -p "transform67";
	rename -uid "6DE0B983-42AD-6E25-E0ED-C5BC537EA423";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface35" -p "polySurface25";
	rename -uid "F7CDE3D6-4922-A865-08E1-10AD06CB2131";
createNode transform -n "transform65" -p "|polySurface25|polySurface35";
	rename -uid "4E5772ED-4DC5-2EF6-ED54-63BF2EB1D82E";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape46" -p "transform65";
	rename -uid "264AB3BD-4BE3-974F-2361-699C7549DE0E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface36" -p "polySurface25";
	rename -uid "3BD518BA-4E80-0D91-8D5A-8CB9227A9D39";
createNode transform -n "transform62" -p "polySurface36";
	rename -uid "38EAEB5D-48DD-B943-8C5A-DCBEB32D3083";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape47" -p "transform62";
	rename -uid "96FCBE7C-479B-7775-3D2C-6B92A56D9D6F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface37" -p "polySurface25";
	rename -uid "6C32844F-4266-5946-FE12-A7BE1DFC8598";
createNode transform -n "transform59" -p "polySurface37";
	rename -uid "DF5B8E1F-4676-7575-904B-338C18879F1E";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape48" -p "transform59";
	rename -uid "8191821C-4350-D5E0-94F0-958D297EB5BF";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface38" -p "polySurface25";
	rename -uid "2CCB646D-4454-E58F-04A5-7BB9F4A14712";
createNode transform -n "transform66" -p "polySurface38";
	rename -uid "5544D94C-4789-FB33-1926-8787EAFCE37C";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape49" -p "transform66";
	rename -uid "AECFC4CD-47B5-0CAC-E5B6-F4B12CA47546";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface39" -p "polySurface25";
	rename -uid "86573D98-4DCF-2DEB-D712-5B993A8FE9DB";
createNode transform -n "transform69" -p "|polySurface25|polySurface39";
	rename -uid "4D907BF2-4AB2-4AA0-7B50-DC860A91D459";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape50" -p "transform69";
	rename -uid "5C44F39F-4C3E-0ADE-237E-069239402103";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface40" -p "polySurface25";
	rename -uid "19778D05-4BF3-02B7-E3B6-BB889B2373CB";
createNode transform -n "transform58" -p "|polySurface25|polySurface40";
	rename -uid "1C68AF3D-4474-AB2B-7B23-7980C1FDBFE9";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape51" -p "transform58";
	rename -uid "53AB1CF0-49EB-DE43-2441-91B5B6795AD5";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface41" -p "polySurface25";
	rename -uid "207CCA6B-4CD7-D59D-6EE1-DAB5AE878105";
createNode transform -n "transform56" -p "polySurface41";
	rename -uid "BFF3D83B-4DA8-E3CB-8E2F-9EA685373CD1";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape52" -p "transform56";
	rename -uid "0D7657D0-4FB4-F83B-F05D-3CB79FCB1034";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface42" -p "polySurface25";
	rename -uid "8228B87E-4010-60D5-6B58-1B9CD62225A6";
createNode transform -n "transform57" -p "polySurface42";
	rename -uid "88741236-4335-2BEC-EF88-1FB111CA2397";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape53" -p "transform57";
	rename -uid "5A479F74-45C4-2679-8814-5F9B7B1930C1";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface43" -p "polySurface25";
	rename -uid "F490E34D-4DA4-B608-3FE7-B0A82E87BDEC";
createNode mesh -n "polySurfaceShape54" -p "polySurface43";
	rename -uid "EE335C37-456A-759E-3DA5-6E95DB8C8C8C";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface44" -p "polySurface25";
	rename -uid "6A601830-4252-C24E-91CC-0B88752F81E1";
createNode transform -n "transform75" -p "polySurface44";
	rename -uid "F87A2E05-49AB-6151-F8D6-EBACF4480EF9";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape55" -p "transform75";
	rename -uid "EDD6687F-4763-EC49-A422-A4978EE7A31D";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface45" -p "polySurface25";
	rename -uid "90084AE7-4F1B-B4BE-CFAE-0AA6C2204845";
createNode transform -n "transform74" -p "polySurface45";
	rename -uid "34872BB3-4A87-078C-328B-CCBC5F88571A";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape56" -p "transform74";
	rename -uid "ED2DB84F-440B-5582-7ABB-AC81108B2ACB";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface46" -p "polySurface25";
	rename -uid "93474248-4C98-AF99-3DD5-BB94220EBD43";
createNode transform -n "transform64" -p "polySurface46";
	rename -uid "6AADA6F0-4046-3954-7F23-12883A77DEB6";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape57" -p "transform64";
	rename -uid "80AAEF85-4E2A-6306-E6E1-DBA1A97199BD";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface47" -p "polySurface25";
	rename -uid "1CFAB776-4CBF-74E9-6D66-E9A10A74A1A9";
createNode transform -n "transform63" -p "polySurface47";
	rename -uid "0A96D68D-4368-D5A1-2C6F-A2832A7EEA3D";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape58" -p "transform63";
	rename -uid "AF1F4E1E-4021-8775-1514-AFB704DC47B4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface48" -p "polySurface25";
	rename -uid "7D7D91F0-451C-3A61-41FA-7C8EF8095C82";
createNode transform -n "transform73" -p "polySurface48";
	rename -uid "1E9DB9EC-4382-90E4-8B9D-3D8D796A325E";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape59" -p "transform73";
	rename -uid "5860CE85-46CB-EED4-99E9-B6ADED003037";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface49" -p "polySurface25";
	rename -uid "2650707D-443E-C789-F5C5-629BBB008D4A";
createNode transform -n "transform76" -p "|polySurface25|polySurface49";
	rename -uid "CB1FA1CD-4E6C-5A08-26EB-CCADE11E78F3";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape60" -p "transform76";
	rename -uid "29316CB4-4D6F-B66F-84C5-29A0E2F853FF";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform55" -p "polySurface25";
	rename -uid "310B0D7A-4EE2-0B12-74A4-04AC81899589";
	setAttr ".v" no;
createNode mesh -n "polySurface20Shape" -p "transform55";
	rename -uid "3867C5D7-42D0-FDC9-E3B9-8F8140AAFFA6";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.04388388292863965 0.86198386549949646 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface40";
	rename -uid "D2F28C9E-4B09-F03E-A139-58905CABF055";
	setAttr ".rp" -type "double3" -5.881850004196167 1.9769999980926514 50.740001678466797 ;
	setAttr ".sp" -type "double3" -5.881850004196167 1.9769999980926514 50.740001678466797 ;
createNode mesh -n "polySurface40Shape" -p "|polySurface40";
	rename -uid "2A4CFF9D-4F93-401B-7CAF-729DD150B432";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface35";
	rename -uid "673A0841-49C1-DE7B-94CB-11AAE3E8B038";
	setAttr ".rp" -type "double3" 7.4607498645782471 9.4929499626159668 46.33375072479248 ;
	setAttr ".sp" -type "double3" 7.4607498645782471 9.4929499626159668 46.33375072479248 ;
createNode mesh -n "polySurface35Shape" -p "|polySurface35";
	rename -uid "60EA4612-44B5-DF36-AFD2-5FB2B823EA72";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface39";
	rename -uid "00F8E1AB-4DB2-2215-3F5C-668DA41232FB";
	setAttr ".rp" -type "double3" 6.1723999977111816 9.4899992942810059 42.088451385498047 ;
	setAttr ".sp" -type "double3" 6.1723999977111816 9.4899992942810059 42.088451385498047 ;
createNode mesh -n "polySurface39Shape" -p "|polySurface39";
	rename -uid "729ACBAB-4A21-4165-FE1E-B285099236E2";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface32";
	rename -uid "CEF5283E-4F2E-1DFC-C0F1-CA9684CBCA5F";
	setAttr ".rp" -type "double3" 0.22747635841369629 10.790209770202637 61.970001220703125 ;
	setAttr ".sp" -type "double3" 0.22747635841369629 10.790209770202637 61.970001220703125 ;
createNode mesh -n "polySurface32Shape" -p "|polySurface32";
	rename -uid "8DAFEDEF-4740-D7F2-823F-0789255E62B1";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface49";
	rename -uid "A7BA2AE6-48A4-8304-FE37-E59D3D82E8DB";
	setAttr ".rp" -type "double3" -4.9899997711181641 6.9399998188018799 35.85414981842041 ;
	setAttr ".sp" -type "double3" -4.9899997711181641 6.9399998188018799 35.85414981842041 ;
createNode mesh -n "polySurface49Shape" -p "|polySurface49";
	rename -uid "0C69E8C6-44D7-1929-8998-8EA2DF9064D3";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface56";
	rename -uid "49448855-4F58-FFB7-8E8B-BEA3A4182CAC";
	setAttr ".rp" -type "double3" -0.21180009841918945 0.76840001344680786 19.050649881362915 ;
	setAttr ".sp" -type "double3" -0.21180009841918945 0.76840001344680786 19.050649881362915 ;
createNode mesh -n "polySurface56Shape" -p "|polySurface56";
	rename -uid "E351B6C1-4E14-5941-1780-9998C1C6457D";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface51";
	rename -uid "1FC45A02-4C1E-0205-1BFC-CFA8F5D07767";
	setAttr ".rp" -type "double3" -7.5855495929718018 7.630000114440918 17.290001392364502 ;
	setAttr ".sp" -type "double3" -7.5855495929718018 7.630000114440918 17.290001392364502 ;
createNode mesh -n "polySurface51Shape" -p "|polySurface51";
	rename -uid "6D76CAE2-49AE-C951-E484-2B98D31FB19F";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface62";
	rename -uid "FB273F21-46A4-3E6A-AD95-29BBEB6B43B7";
	setAttr ".rp" -type "double3" 7.8892571926116943 9.4112500920891762 29.73869800567627 ;
	setAttr ".sp" -type "double3" 7.8892571926116943 9.4112500920891762 29.73869800567627 ;
createNode mesh -n "polySurface62Shape" -p "|polySurface62";
	rename -uid "1F45F5A6-48B1-6E88-AC03-A9A869FBEBE7";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface69";
	rename -uid "D798919F-49BD-E108-CF70-229F3BE9FF51";
	setAttr ".rp" -type "double3" 8.1800005435943604 9.4788997173309326 16.509999752044678 ;
	setAttr ".sp" -type "double3" 8.1800005435943604 9.4788997173309326 16.509999752044678 ;
createNode mesh -n "polySurface69Shape" -p "|polySurface69";
	rename -uid "9D7CB0FF-4713-D2FD-68C1-E9A0B4127886";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface70";
	rename -uid "C483C887-4A54-6876-3D9C-E6975E2752BE";
	setAttr ".rp" -type "double3" 6.8543002605438232 12.181000232696533 16.605000495910645 ;
	setAttr ".sp" -type "double3" 6.8543002605438232 12.181000232696533 16.605000495910645 ;
createNode mesh -n "polySurface70Shape" -p "|polySurface70";
	rename -uid "22C634C9-4BE4-DD3C-455A-B2ACA78AD7ED";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface72";
	rename -uid "329A66A5-4931-A285-D15E-FD862BDA04DC";
	setAttr ".rp" -type "double3" 7.2528500556945801 6.2227499485015869 9.8708004951477051 ;
	setAttr ".sp" -type "double3" 7.2528500556945801 6.2227499485015869 9.8708004951477051 ;
createNode mesh -n "polySurface72Shape" -p "|polySurface72";
	rename -uid "268E5A37-43B2-7FD8-5A08-B2B6B4BF76FC";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface78";
	rename -uid "63013A59-4A97-1A25-A79E-9CB225BAA9B9";
	setAttr ".rp" -type "double3" 7.2528500556945801 6.0971503257751465 23.51615047454834 ;
	setAttr ".sp" -type "double3" 7.2528500556945801 6.0971503257751465 23.51615047454834 ;
createNode mesh -n "polySurface78Shape" -p "|polySurface78";
	rename -uid "F692589A-46EB-9566-4932-55AE2D18193D";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface84";
	rename -uid "3E43A532-49BF-509C-DFB5-A3BE6E86CE50";
	setAttr ".rp" -type "double3" -17.141063690185547 10.444562897086143 7.037067174911499 ;
	setAttr ".sp" -type "double3" -17.141063690185547 10.444562897086143 7.037067174911499 ;
createNode mesh -n "polySurface84Shape" -p "|polySurface84";
	rename -uid "7099C45D-4D4D-8C7F-054D-388B3C8F01C7";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface89";
	rename -uid "5A52ED0D-4275-E3A0-A25B-248522B40461";
	setAttr ".rp" -type "double3" -13.587489128112793 12.512388467788696 -6.3101072311401367 ;
	setAttr ".sp" -type "double3" -13.587489128112793 12.512388467788696 -6.3101072311401367 ;
createNode mesh -n "polySurface89Shape" -p "|polySurface89";
	rename -uid "FA4E8694-4136-F500-E1FB-779389825E4B";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface88";
	rename -uid "94D4D988-4A55-C3D5-0502-D69D9CC99F24";
	setAttr ".rp" -type "double3" -0.11999994516372681 9.5550000667572021 -5.2399997711181641 ;
	setAttr ".sp" -type "double3" -0.11999994516372681 9.5550000667572021 -5.2399997711181641 ;
createNode mesh -n "polySurface88Shape" -p "|polySurface88";
	rename -uid "6549B064-4A91-7B7E-1167-E39A2F2A8445";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface81";
	rename -uid "33E0D1BD-4A10-B75F-8D2B-AD95E919CFCB";
	setAttr ".rp" -type "double3" 3.4699999094009399 9.5550000667572021 -3.2499998807907104 ;
	setAttr ".sp" -type "double3" 3.4699999094009399 9.5550000667572021 -3.2499998807907104 ;
createNode mesh -n "polySurface81Shape" -p "|polySurface81";
	rename -uid "4B1E1B46-4926-C611-480A-73B7345B13C9";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface92";
	rename -uid "A6563CCA-4E7A-5427-40A0-A69704152603";
	setAttr ".rp" -type "double3" 6.309999942779541 9.5550000667572021 -0.34999996423721313 ;
	setAttr ".sp" -type "double3" 6.309999942779541 9.5550000667572021 -0.34999996423721313 ;
createNode mesh -n "polySurface92Shape" -p "|polySurface92";
	rename -uid "62390C1D-4CD5-2B16-6F1D-6F91A5F10A88";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface95";
	rename -uid "934EDE16-461A-3309-9C82-E998F5FA70B4";
	setAttr ".rp" -type "double3" 8.0399999618530273 9.5550000667572021 3.4300000667572021 ;
	setAttr ".sp" -type "double3" 8.0399999618530273 9.5550000667572021 3.4300000667572021 ;
createNode mesh -n "polySurface95Shape" -p "|polySurface95";
	rename -uid "41AF648F-4CF3-89C0-7A35-B9A09DDCBEF4";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface64";
	rename -uid "F2099925-4EE9-6CB3-FF7B-568385A6223E";
	setAttr ".rp" -type "double3" -6.8300001621246338 6.9399998188018799 30.040000915527344 ;
	setAttr ".sp" -type "double3" -6.8300001621246338 6.9399998188018799 30.040000915527344 ;
createNode mesh -n "polySurface64Shape" -p "|polySurface64";
	rename -uid "D43D08B0-4CE2-E869-FA4A-3CBFE41CDD50";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode displayLayerManager -n "layerManager";
	rename -uid "EA77CD1A-49B4-2688-DFBA-AFADA7ED4668";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "470D3016-44A5-A799-5609-48B473A8706B";
	setAttr -s 27 ".lnk";
	setAttr -s 27 ".slnk";
createNode blinn -n "Box063Mat";
	rename -uid "20AA40BC-43CF-964B-7013-AF80C9156703";
createNode shadingEngine -n "Box063MatSG";
	rename -uid "A12AB761-4D5B-37A5-781A-5BB1A8FE9DD0";
	setAttr ".ihi" 0;
	setAttr -s 8 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 8 ".gn";
createNode materialInfo -n "materialInfo0";
	rename -uid "094C8664-4E41-DC40-C784-07A081811CDD";
createNode blinn -n "Box004Mat";
	rename -uid "FF29BF33-4C16-084E-9E45-94B2AE28F0C3";
createNode shadingEngine -n "Box004MatSG";
	rename -uid "E0A57F38-409A-337C-8584-3CB38FE6433F";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo1";
	rename -uid "FECC68EE-4548-7C96-F1CF-D18ED0E67C7A";
createNode blinn -n "Box085Mat";
	rename -uid "B75CCD38-49FF-AC78-7410-83BC9F8BC6ED";
createNode shadingEngine -n "Box085MatSG";
	rename -uid "87C84A04-4539-D3EE-867C-F5AC5874169B";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo2";
	rename -uid "0487E2EB-49BC-D4AE-8723-62A0AE5037C9";
createNode blinn -n "Box061Mat";
	rename -uid "FEDC4353-4684-D4AC-DD76-E88D32753FF7";
createNode shadingEngine -n "Box061MatSG";
	rename -uid "23D5EF9A-441C-012F-FC2E-0FBC941C2AF4";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo3";
	rename -uid "6A92F2B7-4B38-3BBD-2025-C09C7B46F308";
createNode blinn -n "Box054Mat";
	rename -uid "C6BBF512-477E-3BD1-7E11-BE94C9304F41";
createNode shadingEngine -n "Box054MatSG";
	rename -uid "36F1D946-472F-1A54-5948-A585C96EAAF0";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo4";
	rename -uid "B3CFC63A-4F74-ED3E-5F82-C8A8E86514B6";
createNode blinn -n "Box007Mat";
	rename -uid "90034683-4B13-19DE-F775-26A5C74DC2FE";
createNode shadingEngine -n "Box007MatSG";
	rename -uid "5FAF4708-43D9-E846-D574-FB94D3EA66E6";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo5";
	rename -uid "34041089-461A-D00A-B90D-6E89E3321B5D";
createNode blinn -n "initialShadingGroup_pCube13Mat";
	rename -uid "618DB31E-43B1-2838-46E8-BBAD7819220E";
createNode shadingEngine -n "initialShadingGroup_pCube13MatSG";
	rename -uid "DEDEBB60-4A9A-1DF6-BB15-ADBBB8744480";
	setAttr ".ihi" 0;
	setAttr -s 4 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 4 ".gn";
createNode materialInfo -n "materialInfo6";
	rename -uid "E8AEB567-40B2-A5FA-6A3C-889BC6EE8528";
createNode blinn -n "Box006Mat";
	rename -uid "3EEACA63-4681-23FD-107E-3A884A6316FA";
createNode shadingEngine -n "Box006MatSG";
	rename -uid "70CD2B55-41E9-62F1-43B1-AD9208DD29DD";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo7";
	rename -uid "C15B24AA-4671-C94A-3771-BE85985F9143";
createNode blinn -n "Box100Mat";
	rename -uid "E4DFDD69-4F9A-6018-7D90-3B9D0E000E55";
createNode shadingEngine -n "Box100MatSG";
	rename -uid "05135540-46CF-6060-37D1-D48E7E2F7D0B";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo8";
	rename -uid "E8132618-4B12-31D7-A2A4-8B83203B6DA6";
createNode blinn -n "Box086Mat";
	rename -uid "694B2C69-4911-09F5-3B46-5A9231EABE14";
createNode shadingEngine -n "Box086MatSG";
	rename -uid "98E329D2-466F-AC6F-6A55-BC8F7F3AFDC1";
	setAttr ".ihi" 0;
	setAttr -s 4 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 4 ".gn";
createNode materialInfo -n "materialInfo9";
	rename -uid "F7A343F6-4E5F-9F9C-D170-81AA3347FB9B";
createNode blinn -n "Box055Mat";
	rename -uid "24EDEB8E-407A-9290-FF87-A1A5B9894EF7";
createNode shadingEngine -n "Box055MatSG";
	rename -uid "4543225C-4996-B547-1FAC-4EBBE27BA5BD";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo10";
	rename -uid "4EADD135-4C78-D40C-D812-F08E151B87CC";
createNode blinn -n "Box062Mat";
	rename -uid "4776B80D-4C73-937B-E10B-29870F1B7BE2";
createNode shadingEngine -n "Box062MatSG";
	rename -uid "B03ACB4B-4264-887B-DD25-488E90C05483";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo11";
	rename -uid "9C55FF35-4724-4657-4A4B-5291AE5BC289";
createNode blinn -n "Box002Mat";
	rename -uid "A4B3F2D9-412A-661F-E438-68A5B5D74B98";
createNode shadingEngine -n "Box002MatSG";
	rename -uid "BBD3FCC1-4A81-0427-4BAF-AB9D91052DE4";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo12";
	rename -uid "44F523C9-4B16-64FF-6E7F-93902DAF4583";
createNode blinn -n "Box053Mat";
	rename -uid "09F724A6-4CEB-60FE-18C2-23B8BEB71B3B";
createNode shadingEngine -n "Box053MatSG";
	rename -uid "628A77C9-41A8-407F-21AC-1DA2A266AA9B";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo13";
	rename -uid "352F3CEE-483E-44E3-67EE-5F9904FABEFE";
createNode blinn -n "Box001Mat";
	rename -uid "A1479F50-4CF9-8573-3A8C-49B28EBEA70D";
createNode shadingEngine -n "Box001MatSG";
	rename -uid "A137DFA3-4316-BE1E-0D3A-2CB89C331ACD";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo14";
	rename -uid "E0959602-4899-3E08-0460-0F8A9EDFAA4E";
createNode blinn -n "Box101Mat";
	rename -uid "AA18E5CF-4605-0F4E-3B65-339C0A40DAC4";
createNode shadingEngine -n "Box101MatSG";
	rename -uid "429FC309-46E2-D2F1-2DA7-5F9D710D0CCB";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo15";
	rename -uid "0A20D6E4-4168-0FF0-82AB-AA92395D4CDF";
createNode blinn -n "Box087Mat";
	rename -uid "2F863B20-47E7-E415-28A5-F6B6AD83EDEE";
createNode shadingEngine -n "Box087MatSG";
	rename -uid "1A509469-450C-E307-5E9C-879C6C61B591";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo16";
	rename -uid "5D2A510B-46A7-E79A-C49B-B5A956EA0379";
createNode blinn -n "Box099Mat";
	rename -uid "8D1AFF94-4D76-2D86-6D10-9DBAC4705C38";
createNode shadingEngine -n "Box099MatSG";
	rename -uid "F3453B7F-4BED-26D6-EFC3-C0B46EE1CC81";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo17";
	rename -uid "D0EDD753-4EDE-A1D2-1BD1-DBBCB4317536";
createNode blinn -n "Box005Mat";
	rename -uid "81EABF3E-4B0C-CC4A-1B0C-D6A8E2103352";
createNode shadingEngine -n "Box005MatSG";
	rename -uid "1ED814D3-4183-DED0-847F-0AB229DED4D5";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo18";
	rename -uid "CB2B3020-4121-2316-90F4-2EAFE1E00FF2";
createNode blinn -n "Box058Mat";
	rename -uid "2E0F5172-40EA-29A9-D803-51BB2ECCDBF2";
createNode shadingEngine -n "Box058MatSG";
	rename -uid "0BA4AF6B-4076-0AC1-BB54-B7B973AFD2D1";
	setAttr ".ihi" 0;
	setAttr -s 4 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 4 ".gn";
createNode materialInfo -n "materialInfo19";
	rename -uid "FB90A59C-4950-AC66-CBE2-248A09BC1B9E";
createNode blinn -n "Box003Mat";
	rename -uid "1D538727-4E3F-5B62-5E4B-15A290EFDF4B";
createNode shadingEngine -n "Box003MatSG";
	rename -uid "DE0D324D-43CA-6B67-E0F3-24B3F552994C";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo20";
	rename -uid "B7CB7FEC-469F-6672-D013-7E9E78788EBF";
createNode blinn -n "Box057Mat";
	rename -uid "755304AB-4C35-9FD7-35E7-CA8D04D0B674";
createNode shadingEngine -n "Box057MatSG";
	rename -uid "007DAEF6-40FD-513E-9C17-B09D751C4FA5";
	setAttr ".ihi" 0;
	setAttr -s 2 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 2 ".gn";
createNode materialInfo -n "materialInfo21";
	rename -uid "9C33F653-4ABF-16F3-9E42-96A12B43CA94";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "559FE3A2-4280-3633-8E98-8F8784DA0B43";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "0F2A2F73-4210-0B7B-CA4F-DC9F726E9FF5";
createNode displayLayer -n "defaultLayer";
	rename -uid "0BF82FAD-45DF-3F8C-5ED4-D4BA7AD1C5BA";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "CA949363-4B1F-279E-37A4-A997E22FB0CC";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "0BD9F219-452F-CA2A-FB5A-06855038054A";
	setAttr ".g" yes;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "5BA2201A-42F7-8E01-4A0B-8080DFFC900D";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 1024\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n"
		+ "                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n"
		+ "                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 767\n                -height 336\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n"
		+ "                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n"
		+ "            -textureMaxSize 1024\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n"
		+ "            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 767\n            -height 336\n            -sceneRenderFilter 0\n            $editorName;\n"
		+ "        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n"
		+ "                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 1024\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n"
		+ "                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n"
		+ "                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 767\n                -height 335\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n"
		+ "            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 1024\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n"
		+ "            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n"
		+ "            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 767\n            -height 335\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 1024\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n"
		+ "                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n"
		+ "                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n"
		+ "                -width 767\n                -height 335\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n"
		+ "            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 1024\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n"
		+ "            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n"
		+ "            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 767\n            -height 335\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n"
		+ "                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 1\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 1024\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n"
		+ "                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n"
		+ "                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 1388\n                -height 716\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n"
		+ "\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 1024\n            -fogging 0\n            -fogSource \"fragment\" \n"
		+ "            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n"
		+ "            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1388\n            -height 716\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n"
		+ "            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n                -showShapes 0\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 1\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n"
		+ "                -showContainerContents 1\n                -ignoreDagHierarchy 0\n                -expandConnections 0\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -isSet 0\n                -isSetMember 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n"
		+ "                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 0\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                -renderFilterIndex 0\n                -selectionOrder \"chronological\" \n                -expandAttribute 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n"
		+ "            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n"
		+ "            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `outlinerPanel -unParent -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            outlinerEditor -e \n"
		+ "                -showShapes 0\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 0\n                -showConnected 0\n                -showAnimCurvesOnly 0\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 1\n                -showAssets 1\n                -showContainedOnly 1\n                -showPublishedAsConnected 0\n                -showContainerContents 1\n                -ignoreDagHierarchy 0\n                -expandConnections 0\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 0\n                -highlightActive 1\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n"
		+ "                -transmitFilters 0\n                -setFilter \"defaultSetFilter\" \n                -showSetMembers 1\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 0\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n"
		+ "            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n"
		+ "\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"graphEditor\" -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n"
		+ "                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n"
		+ "                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 1\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -showCurveNames 0\n                -showActiveCurveNames 0\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n"
		+ "                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                -valueLinesToggle 1\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n"
		+ "                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n"
		+ "                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 1\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 1\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showResults \"off\" \n                -showBufferCurves \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -showCurveNames 0\n"
		+ "                -showActiveCurveNames 0\n                -stackedCurves 0\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -displayNormalized 0\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -classicMode 1\n                -valueLinesToggle 1\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dopeSheetPanel\" -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n"
		+ "                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n"
		+ "                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n"
		+ "                -displayValues 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n"
		+ "                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n"
		+ "                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayKeys 1\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n"
		+ "                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"timeEditorPanel\" -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"clipEditorPanel\" -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n"
		+ "                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"sequenceEditorPanel\" -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayKeys 0\n                -displayTangents 0\n                -displayActiveKeys 0\n                -displayActiveKeyTangents 0\n                -displayInfinities 0\n                -displayValues 0\n                -autoFit 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperGraphPanel\" -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n"
		+ "            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n"
		+ "                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n"
		+ "                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"visorPanel\" -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n"
		+ "\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"createNodePanel\" -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"polyTexturePlacementPanel\" -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n"
		+ "\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"renderWindowPanel\" -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tshapePanel -unParent -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels ;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\tposePanel -unParent -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels ;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynRelEdPanel\" -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"relationshipPanel\" -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"referenceEditorPanel\" -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"componentEditorPanel\" -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"dynPaintScriptedPanelType\" -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"scriptEditorPanel\" -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"profilerPanel\" -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"contentBrowserPanel\" -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"hyperShadePanel\" -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels `;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n"
		+ "\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -activeTab -1\n                -editorMode \"default\" \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -activeTab -1\n                -editorMode \"default\" \n"
		+ "                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 1024\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1388\\n    -height 716\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 1024\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1388\\n    -height 716\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "FD9ECCFE-4B43-B43D-1A8A-D18D029F3E41";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode polyConnectComponents -n "polyConnectComponents1";
	rename -uid "97826B75-4200-1847-C7B3-4DA3BD02307B";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "vtx[1]" "vtx[5]";
createNode polyBridgeEdge -n "polyBridgeEdge1";
	rename -uid "8F6946B5-4332-A460-3925-89A0B6558440";
	setAttr ".ics" -type "componentList" 2 "e[1]" "e[5]";
	setAttr ".ix" -type "matrix" 0.97261478361877396 0 0.2324230683176812 0 0 1 0 0 -0.2324230683176812 0 0.97261478361877396 0
		 7.9299999999999997 9.2599999999999998 29.57 1;
	setAttr ".c[0]"  0 1 1;
	setAttr ".dv" 0;
	setAttr ".sv1" 1;
	setAttr ".sv2" 4;
	setAttr ".d" 1;
	setAttr ".td" 1;
createNode polyExtrudeEdge -n "polyExtrudeEdge1";
	rename -uid "F783963B-4EE6-91BD-D42C-83A65B0781EA";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[6]";
	setAttr ".ix" -type "matrix" 0.97261478361877396 0 0.2324230683176812 0 0 1 0 0 -0.2324230683176812 0 0.97261478361877396 0
		 7.9299999999999997 9.2599999999999998 29.57 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 7.1241193 0.10799957 29.553698 ;
	setAttr ".rs" 59991;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 6.6702552641045312 0.10799957275390604 27.654423299727988 ;
	setAttr ".cbx" -type "double3" 7.5779836531745879 0.10799957275390604 31.452970737856052 ;
createNode deleteComponent -n "deleteComponent1";
	rename -uid "388E312B-4ADA-5243-4CB1-8B9B03EED61A";
	setAttr ".dc" -type "componentList" 1 "e[6]";
createNode deleteComponent -n "deleteComponent2";
	rename -uid "58E91815-46FD-97F6-6B6F-5881C64FB2F7";
	setAttr ".dc" -type "componentList" 1 "e[13]";
createNode polyDelEdge -n "polyDelEdge1";
	rename -uid "62DA77E7-4837-8C80-CA38-35B41FD480BF";
	setAttr ".ics" -type "componentList" 1 "e[13]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "polyDelEdge2";
	rename -uid "2929F00F-44BD-C7E8-AB03-DE9A49EC74B0";
	setAttr ".ics" -type "componentList" 1 "e[13]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "polyDelEdge3";
	rename -uid "06A58597-4955-FF67-395A-2C971EBFE8D9";
	setAttr ".ics" -type "componentList" 1 "e[13]";
	setAttr ".cv" yes;
createNode polyDelEdge -n "polyDelEdge4";
	rename -uid "99C4AD62-4B27-5C44-159A-B3A56F8B2D02";
	setAttr ".ics" -type "componentList" 1 "e[10]";
	setAttr ".cv" yes;
createNode deleteComponent -n "deleteComponent3";
	rename -uid "3D39D5B0-49BB-6243-75F0-F5AC5CE50C06";
	setAttr ".dc" -type "componentList" 1 "e[10]";
createNode deleteComponent -n "deleteComponent4";
	rename -uid "695C88D8-4B08-F3F5-4909-B4B960A2813E";
	setAttr ".dc" -type "componentList" 1 "e[13]";
createNode polyDelEdge -n "polyDelEdge5";
	rename -uid "FD508075-4D3E-D2E1-A3AF-FB9FFA6C41DF";
	setAttr ".ics" -type "componentList" 1 "e[13]";
	setAttr ".cv" yes;
createNode deleteComponent -n "deleteComponent5";
	rename -uid "A6E10CFE-4139-5080-18CA-A48E86C259DE";
	setAttr ".dc" -type "componentList" 1 "f[3]";
createNode polyAutoProj -n "polyAutoProj1";
	rename -uid "8B00CDDF-4D40-3BE8-2D99-9C80F18B0DA4";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:5]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 -4.9900000000000002 6.9400000000000004 39.32 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj2";
	rename -uid "A9A63FBD-4356-8885-AB7E-92B530CABD0F";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:3]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 -4.9699999999999998 1.9770000000000001 50.740000000000002 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj3";
	rename -uid "5CA9C823-4754-6D18-88A2-298678F9F912";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:1]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 3.5699999999999998 0 -7.7220000000000004 2.9089999999999998 51.950000000000003 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj4";
	rename -uid "E98DBB0E-464B-D612-CEE6-5AB724AC1040";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:1]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 1.75 2.9430000000000001 59.380000000000003 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj5";
	rename -uid "9440590A-4E65-E120-AF5E-D7B20DEE3182";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:3]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 7.46 7.5700000000000003 51.270000000000003 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj6";
	rename -uid "AC3583CC-463C-473F-F0D2-0FADBEC4CA8D";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:15]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 6.96 9.4900000000000002 38.159999999999997 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj7";
	rename -uid "58381124-498F-3E8C-9881-788480F72789";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:3]";
	setAttr ".ix" -type "matrix" 2.2204460492503131e-016 0 1 0 0 0.86535830000000002 0 0
		 -1.0964475627474 0 2.434602658912599e-016 0 0.22796943699999783 9.1236604250000006 61.969999999999999 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj8";
	rename -uid "506DAC51-4205-123B-8AC5-0997AB778BF3";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:1]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 1.78 0 38.700000000000003 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj9";
	rename -uid "AF7017D3-46C5-33D5-31E1-98AA7916233B";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:1]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.97513388492625086 -0.22161657534723656 0
		 0 0.22161657534723656 0.97513388492625086 0 1.77 1.47 51.350000000000001 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj10";
	rename -uid "E108481D-4322-669E-8FF8-25972201681C";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:3]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 7.46 9.2699999999999996 59.43 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj11";
	rename -uid "1A2F74D0-4A19-C894-3CB5-0CA0699F9A06";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:3]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 -4.9900000000000002 6.9400000000000004 34.859999999999999 1;
	setAttr ".s" -type "double3" 31.369299933910369 31.369299933910369 31.369299933910369 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyUnite -n "polyUnite1";
	rename -uid "A0EF15E2-4A60-DB23-1205-518274113E70";
	setAttr -s 11 ".ip";
	setAttr -s 11 ".im";
createNode groupId -n "groupId1";
	rename -uid "11845A98-487B-4ABB-1517-41AC6292281F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts1";
	rename -uid "47834D01-4435-0A27-9068-92AD2B5C3C40";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:5]";
createNode groupId -n "groupId2";
	rename -uid "8732036D-4FAF-C6CC-BBF1-FD86929C2B76";
	setAttr ".ihi" 0;
createNode groupId -n "groupId3";
	rename -uid "3DE89DF8-4F37-67AB-40CC-2BB9D1030635";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts2";
	rename -uid "92C14DEA-43B6-AE8E-573D-F4A752814F30";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode groupId -n "groupId4";
	rename -uid "746E2901-4C9C-149B-98FF-C3B2B1722101";
	setAttr ".ihi" 0;
createNode groupId -n "groupId5";
	rename -uid "1D5940AC-4751-EA90-A1C6-089687E1B2FA";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts3";
	rename -uid "6E6FE3FE-462B-DA66-D230-4DBE9760C094";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:1]";
createNode groupId -n "groupId6";
	rename -uid "084C0CA7-4D42-E056-0B54-23A2E679C688";
	setAttr ".ihi" 0;
createNode groupId -n "groupId7";
	rename -uid "E85210BB-4D50-4F83-FC29-8998865A50AA";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts4";
	rename -uid "0344C787-4150-3CDB-2F5E-11A192668247";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:1]";
createNode groupId -n "groupId8";
	rename -uid "B28CCD00-4B42-2FCA-FA2B-19B088DF3428";
	setAttr ".ihi" 0;
createNode groupId -n "groupId9";
	rename -uid "F5C66200-42EC-566A-9234-3E82C5BF57A7";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts5";
	rename -uid "7671EF4F-4234-3012-14FF-E59661FC8096";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode groupId -n "groupId10";
	rename -uid "400BED8A-41B7-D95F-037D-A4A19AC28DB4";
	setAttr ".ihi" 0;
createNode groupId -n "groupId11";
	rename -uid "C9D7C91C-4462-1ADA-01BC-04BF87F91EC7";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts6";
	rename -uid "4050AC98-4511-4FA1-CC2D-83A0235690E4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:15]";
createNode groupId -n "groupId12";
	rename -uid "3B589ADF-4734-BE74-B0B9-D5899A63AA8F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId13";
	rename -uid "90B4FA48-46C5-7871-BB50-0CA31D448855";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts7";
	rename -uid "7DEA5820-4AAB-058C-4BA5-1EBB29762CFC";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode groupId -n "groupId14";
	rename -uid "E5C5DDD4-409C-0B24-71B9-C9984DEC44B0";
	setAttr ".ihi" 0;
createNode groupId -n "groupId15";
	rename -uid "58B52C3D-4BC6-925F-3A4E-8EABF3EBDE94";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts8";
	rename -uid "925A30F4-4F33-3118-55BE-3291206ECE64";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:1]";
createNode groupId -n "groupId16";
	rename -uid "BC629E18-466F-E13F-3498-C6A5F9939699";
	setAttr ".ihi" 0;
createNode groupId -n "groupId17";
	rename -uid "CE66B830-4356-489D-8F81-9AAB19A7794C";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts9";
	rename -uid "581CC1D1-41E9-9DB5-AD23-C5A6B8F8CF50";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:1]";
createNode groupId -n "groupId18";
	rename -uid "2CF25DDE-49D3-07F5-4582-79B3D5A700D7";
	setAttr ".ihi" 0;
createNode groupId -n "groupId19";
	rename -uid "733DB798-4820-D8AA-9698-938CA844519D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts10";
	rename -uid "274CE9A4-489E-BF71-61A1-EFBC2DB5BD7C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode groupId -n "groupId20";
	rename -uid "3B241F15-41C6-6E3E-A5D6-31B78B0703AC";
	setAttr ".ihi" 0;
createNode groupId -n "groupId21";
	rename -uid "51A930A1-45AF-D765-896D-A099DA1CE4AD";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts11";
	rename -uid "0DC6E283-4AF6-7EF4-4233-FA965BD7E498";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode groupId -n "groupId22";
	rename -uid "59C4D0F6-49A1-9857-2D46-4AA888711722";
	setAttr ".ihi" 0;
createNode polyAutoProj -n "polyAutoProj12";
	rename -uid "E65FC78A-4171-0DD2-B3EB-248A3C7A8E96";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:49]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 31.369302749633789 31.369302749633789 31.369302749633789 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyUnite -n "polyUnite2";
	rename -uid "717BD67A-4682-8DF7-B33E-7E8CF4350497";
	setAttr -s 9 ".ip";
	setAttr -s 9 ".im";
createNode groupId -n "groupId33";
	rename -uid "9A0AA439-4AFA-E171-286E-E99D57CB4953";
	setAttr ".ihi" 0;
createNode groupId -n "groupId34";
	rename -uid "EBB6E42B-40BE-17C0-083C-19896A8123C8";
	setAttr ".ihi" 0;
createNode groupId -n "groupId35";
	rename -uid "6E264F26-4706-09B0-F5FA-798106A3F970";
	setAttr ".ihi" 0;
createNode groupId -n "groupId36";
	rename -uid "9BAC6A75-4120-8D62-7C8B-B0B31AE027A3";
	setAttr ".ihi" 0;
createNode groupId -n "groupId37";
	rename -uid "463B3A74-4883-E6E7-2BAC-9FBA4DDC646F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId38";
	rename -uid "5C002F94-45C7-FFEC-244A-3CB2CA06513F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId39";
	rename -uid "D2ACB7E5-4E14-A517-16F4-65AF08F6FFBE";
	setAttr ".ihi" 0;
createNode groupId -n "groupId40";
	rename -uid "6496B7A2-4D8C-F043-8442-BD87339EB1E4";
	setAttr ".ihi" 0;
createNode groupId -n "groupId41";
	rename -uid "2987FC62-43B1-3112-5476-D6B8863D8B22";
	setAttr ".ihi" 0;
createNode groupId -n "groupId42";
	rename -uid "DF9BDC4A-4E48-345B-D321-F397BB13BA48";
	setAttr ".ihi" 0;
createNode groupId -n "groupId43";
	rename -uid "0EBEDF30-41F0-72AE-322F-1EB717D080DE";
	setAttr ".ihi" 0;
createNode groupId -n "groupId44";
	rename -uid "D706428F-4705-F67F-FF70-D78531145811";
	setAttr ".ihi" 0;
createNode groupId -n "groupId45";
	rename -uid "32DBFF54-4102-1296-6F32-80BF58220856";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts22";
	rename -uid "615C651B-44D1-C13D-B49E-BC961B5B1489";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode groupId -n "groupId46";
	rename -uid "37C6F669-4527-C2A9-901B-0CB4385A7EAA";
	setAttr ".ihi" 0;
createNode groupId -n "groupId47";
	rename -uid "08C3927F-4D87-A0E5-CEB6-BB9C276E69E1";
	setAttr ".ihi" 0;
createNode groupId -n "groupId48";
	rename -uid "34A0F294-41C8-433A-5597-59930DC7718D";
	setAttr ".ihi" 0;
createNode groupId -n "groupId49";
	rename -uid "BA2F04E1-45DB-E7A5-B007-D49E5D7F4F3A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId50";
	rename -uid "895B72C4-45F3-76B2-09AD-0F85FAF147DB";
	setAttr ".ihi" 0;
createNode polyAutoProj -n "polyAutoProj13";
	rename -uid "7C5A51F5-49C8-2259-3993-89A3EC35D198";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:95]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 28.558503150939941 28.558503150939941 28.558503150939941 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyTweakUV -n "polyTweakUV1";
	rename -uid "5AB61937-410C-5E0F-3BFA-CBBD86C48752";
	setAttr ".uopa" yes;
	setAttr -s 158 ".uvtk[0:157]" -type "float2" 0 9.4296411e-009 -7.4505806e-009
		 0 -7.4505806e-009 9.4296411e-009 0 0 0 0 0 0 0 0 0 0 0.00084519386 -0.0033608079
		 -0.00017994642 -0.0032587647 -0.00067961216 0.0017066862 -0.00067925453 0.0017034743
		 0.00034356117 0.0016047001 0.00035005808 0.001604691 -5.9604645e-008 2.2351742e-008
		 0 1.4901161e-008 0 3.7252903e-008 -5.9604645e-008 1.4901161e-008 -5.9604645e-008
		 7.4505806e-009 -5.9604645e-008 -7.4505806e-009 0 -2.9802322e-008 -2.9802322e-008
		 6.1700121e-008 0 -2.9802322e-008 -5.9604645e-008 -2.4912879e-008 0 7.4505806e-008
		 0 -5.9604645e-008 5.9604645e-008 -2.9802322e-008 0 -2.9802322e-008 5.9604645e-008
		 2.9802322e-008 5.9604645e-008 -2.9802322e-008 5.9604645e-008 0 5.9604645e-008 0 1.4901161e-008
		 0 0 0 1.4901161e-008 0 0 0 0 2.9802322e-008 5.9604645e-008 -2.9802322e-008 0 0 5.9604645e-008
		 0 0 0 0 0 0 0 0 5.9604645e-008 -5.9604645e-008 0 -5.9604645e-008 0 0 0 0 0 -5.9604645e-008
		 0 0 0 -1.8626451e-009 0 1.3969839e-009 -1.3387762e-008 0 -1.3271347e-008 0 0 -1.4901161e-008
		 0 1.3038516e-008 -2.9802322e-008 -1.4901161e-008 -2.9802322e-008 1.3038516e-008 0
		 -7.4505806e-009 0 1.0477379e-008 0 -7.4505806e-009 0 1.0477379e-008 0 0 1.4901161e-008
		 0 -2.9802322e-008 0 1.4901161e-008 0 -2.9802322e-008 0 -2.9802322e-008 0 0 0 -2.9802322e-008
		 0 0 0 5.9604645e-008 0 -5.9604645e-008 0 -5.9604645e-008 0 5.9604645e-008 -0.15600333
		 0.1378656 -0.14066468 0.12845421 -0.13969074 0.13474682 -0.157267 0.13088322 0.0080995522
		 0.18263602 -0.089661375 0.10653757 -0.036621228 0.082782798 -0.044940546 0.20639086
		 0 -1.0582153e-007 0 1.1920929e-007 0 -5.9604645e-008 0 -1.0512304e-007 0 5.9604645e-008
		 0 1.1920929e-007 0 0 0 0 0 0 0 0 5.8233738e-005 -0.00014615059 -5.8233738e-005 0.00014615059
		 5.8233738e-005 0.00014615059 -5.8233738e-005 -0.00014615059 5.9306622e-005 -0.00014281273
		 -5.9306622e-005 0.00014281273 5.9306622e-005 0.00014281273 -5.9306622e-005 -0.00014281273
		 0.00027754903 0.0014435053 -0.00021782517 -0.0015317798 -0.00063590705 0.0015920401
		 0.00034098327 -0.0014661551 8.5666776e-005 0.0014359951 0.00014953315 -0.0014736056
		 0 -2.9802322e-008 0 0 0 0 0 -2.9802322e-008 0 5.9604645e-008 0 -5.9604645e-008 0
		 -5.9604645e-008 0 5.9604645e-008 0 -5.9604645e-008 0 5.9604645e-008 0 5.9604645e-008
		 0 -5.9604645e-008 5.9604645e-008 -1.4901161e-007 -5.9604645e-008 1.4202669e-007 -5.9604645e-008
		 1.4703255e-007 5.9604645e-008 -1.4901161e-007 0.00010493398 0.00013673306 -0.00023835897
		 -2.2768974e-005 0.00012013316 8.7320805e-005 -0.00025355816 2.6643276e-005 0.00012582541
		 -8.9287758e-005 0.00014102459 -0.00013870001 0.00046145916 0.0028890371 -0.00072783232
		 -0.0030018687 -0.0012671351 0.0029704571 0.00097823143 -0.002833426 1.92523e-005
		 0.002849102 0.00053596497 -0.0028733611 -7.1227551e-006 -3.2186508e-006 7.1227551e-006
		 -0.00010633469 7.0631504e-006 -7.1525574e-007 -7.0631504e-006 -0.00010633469 7.1227551e-006
		 0.00010830164 -7.0631504e-006 0.00010830164 0.00015342236 0.00078946352 -0.00022569299
		 -0.00082731247 -0.00032025576 0.00086146593 0.00024241209 -0.00079965591 3.0577183e-005
		 0.00078254938 0.00011956692 -0.00080651045 -0.0079203844 0.021155894 0.0079203844
		 -0.021155894 -0.0079203844 -0.021155894 0.0079203844 0.021155894 0.00066560507 -0.0023523569
		 -0.00066560507 0.0023523569 0.00066560507 0.0023523569 -0.00066560507 -0.0023523569
		 0.0006814599 -0.0023179054 -0.0006814599 0.0023179054 0.0006814599 0.0023179054 -0.0006814599
		 -0.0023179054;
createNode polyUnite -n "polyUnite3";
	rename -uid "353A551C-4D0A-2737-CA29-C9BA1B3E525B";
	setAttr -s 8 ".ip";
	setAttr -s 8 ".im";
createNode groupId -n "groupId60";
	rename -uid "9FD9DDF8-4D68-7D57-DC0D-46B0DF64018D";
	setAttr ".ihi" 0;
createNode groupId -n "groupId61";
	rename -uid "F5A721D1-47BF-0544-2171-6C82C649B211";
	setAttr ".ihi" 0;
createNode groupId -n "groupId62";
	rename -uid "E9E536F9-45AF-3071-8563-D5B52A787DE5";
	setAttr ".ihi" 0;
createNode groupId -n "groupId63";
	rename -uid "D2DEE3DF-408B-DC05-692D-43BEED05A792";
	setAttr ".ihi" 0;
createNode groupId -n "groupId64";
	rename -uid "832F4047-4F6A-A19A-BDEE-C7849D2A56AF";
	setAttr ".ihi" 0;
createNode groupId -n "groupId65";
	rename -uid "CCA8FB0D-4A63-0BFD-5DEA-7F8AE5FF13F3";
	setAttr ".ihi" 0;
createNode groupId -n "groupId66";
	rename -uid "F8D5E4E9-4DF1-3708-8A32-39BC71404739";
	setAttr ".ihi" 0;
createNode groupId -n "groupId67";
	rename -uid "1454368A-423D-3151-8EE4-9F862C97B42A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId68";
	rename -uid "FD672343-4DF7-CFCA-0058-35A307AD4FE7";
	setAttr ".ihi" 0;
createNode groupId -n "groupId69";
	rename -uid "65EAD6D6-4D45-2576-2D9B-CEA6111E08D5";
	setAttr ".ihi" 0;
createNode groupId -n "groupId70";
	rename -uid "6589CAC4-4BC0-4A11-8B31-09911A2CF839";
	setAttr ".ihi" 0;
createNode groupId -n "groupId71";
	rename -uid "206E6AC4-41D5-49EE-F66F-C5BD08EB9A2C";
	setAttr ".ihi" 0;
createNode groupId -n "groupId72";
	rename -uid "CE7CA5D7-44B0-C02E-411E-BCA6F769B6CC";
	setAttr ".ihi" 0;
createNode groupId -n "groupId73";
	rename -uid "37F8B18F-4234-AFE6-DA4D-D7876555190F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId74";
	rename -uid "698BCD47-444A-E680-5C0F-B18DB3365365";
	setAttr ".ihi" 0;
createNode groupId -n "groupId75";
	rename -uid "65583673-4DDD-AD21-64D9-25BA506554E8";
	setAttr ".ihi" 0;
createNode polyAutoProj -n "polyAutoProj14";
	rename -uid "0EFB8296-40F8-E939-4DCD-C78939A2FADB";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:31]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 35.21600341796875 35.21600341796875 35.21600341796875 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyTweakUV -n "polyTweakUV2";
	rename -uid "538660EC-4612-CBBC-60F6-9F83B9FD6771";
	setAttr ".uopa" yes;
	setAttr -s 61 ".uvtk";
	setAttr ".uvtk[4]" -type "float2" 0 2.4912879e-008 ;
	setAttr ".uvtk[5]" -type "float2" 0 -2.9802322e-008 ;
	setAttr ".uvtk[6]" -type "float2" 0 -2.9802322e-008 ;
	setAttr ".uvtk[7]" -type "float2" 0 2.4912879e-008 ;
	setAttr ".uvtk[8]" -type "float2" 0.00028902292 -0.0013372898 ;
	setAttr ".uvtk[9]" -type "float2" -0.00028902292 0.0013372898 ;
	setAttr ".uvtk[10]" -type "float2" 0.00028902292 0.0013372898 ;
	setAttr ".uvtk[11]" -type "float2" -0.00028902292 -0.0013372898 ;
	setAttr ".uvtk[12]" -type "float2" -0.021212921 0.019105792 ;
	setAttr ".uvtk[13]" -type "float2" 0.021212898 -0.019105852 ;
	setAttr ".uvtk[14]" -type "float2" 0.028537787 0.0007853508 ;
	setAttr ".uvtk[15]" -type "float2" -0.02853772 -0.0007854104 ;
	setAttr ".uvtk[16]" -type "float2" -0.00076121092 -0.0011282861 ;
	setAttr ".uvtk[17]" -type "float2" 0.00076121092 0.0011283159 ;
	setAttr ".uvtk[18]" -type "float2" 0.00076121092 -0.0011282861 ;
	setAttr ".uvtk[19]" -type "float2" -0.00076121092 0.0011283159 ;
	setAttr ".uvtk[20]" -type "float2" -2.9802322e-008 0 ;
	setAttr ".uvtk[21]" -type "float2" 1.4901161e-008 0 ;
	setAttr ".uvtk[22]" -type "float2" 1.4901161e-008 0 ;
	setAttr ".uvtk[23]" -type "float2" -2.9802322e-008 0 ;
	setAttr ".uvtk[24]" -type "float2" 0.0005697906 0.0051912069 ;
	setAttr ".uvtk[25]" -type "float2" -0.0005697906 -0.0051912069 ;
	setAttr ".uvtk[26]" -type "float2" -0.0005697906 0.0051912069 ;
	setAttr ".uvtk[27]" -type "float2" 0.0005697906 -0.0051912069 ;
	setAttr ".uvtk[28]" -type "float2" -0.06823653 0.10720687 ;
	setAttr ".uvtk[29]" -type "float2" -0.048102088 0.095121078 ;
	setAttr ".uvtk[30]" -type "float2" -0.046710953 0.10372739 ;
	setAttr ".uvtk[31]" -type "float2" -0.069627665 0.098600619 ;
	setAttr ".uvtk[32]" -type "float2" 0.00079768896 0.0072675645 ;
	setAttr ".uvtk[33]" -type "float2" -0.00079768896 -0.0072675436 ;
	setAttr ".uvtk[34]" -type "float2" -0.00079768896 0.0072675645 ;
	setAttr ".uvtk[35]" -type "float2" 0.00079768896 -0.0072675436 ;
	setAttr ".uvtk[36]" -type "float2" 0.0066486467 0.24354798 ;
	setAttr ".uvtk[37]" -type "float2" -0.052172404 0.24709743 ;
	setAttr ".uvtk[38]" -type "float2" -0.045289114 0.22633182 ;
	setAttr ".uvtk[39]" -type "float2" -0.0002346423 0.26431358 ;
	setAttr ".uvtk[40]" -type "float2" -0.0093050338 0.22490042 ;
	setAttr ".uvtk[41]" -type "float2" -0.026102334 0.23033762 ;
	setAttr ".uvtk[42]" -type "float2" -0.025661606 0.22379798 ;
	setAttr ".uvtk[43]" -type "float2" -0.0097458046 0.23144001 ;
	setAttr ".uvtk[44]" -type "float2" 0 -2.8638169e-008 ;
	setAttr ".uvtk[45]" -type "float2" 0 2.9802322e-008 ;
	setAttr ".uvtk[46]" -type "float2" 5.9604645e-008 2.9802322e-008 ;
	setAttr ".uvtk[47]" -type "float2" 0 -1.4901161e-008 ;
	setAttr ".uvtk[48]" -type "float2" 0.00086331367 -0.0040568709 ;
	setAttr ".uvtk[49]" -type "float2" -0.00086331367 0.0040568709 ;
	setAttr ".uvtk[50]" -type "float2" 0.00086331367 0.0040568709 ;
	setAttr ".uvtk[51]" -type "float2" -0.00086331367 -0.0040568709 ;
	setAttr ".uvtk[52]" -type "float2" -2.0721927e-008 2.2351742e-008 ;
	setAttr ".uvtk[53]" -type "float2" 0 2.9802322e-008 ;
	setAttr ".uvtk[54]" -type "float2" 2.0721927e-008 -5.9604645e-008 ;
	setAttr ".uvtk[55]" -type "float2" -2.9802322e-008 -9.3132257e-009 ;
	setAttr ".uvtk[56]" -type "float2" 0.0061122775 -0.034926951 ;
	setAttr ".uvtk[57]" -type "float2" -0.0061122775 0.034926951 ;
	setAttr ".uvtk[58]" -type "float2" 0.0061122775 0.034926951 ;
	setAttr ".uvtk[59]" -type "float2" -0.0061122775 -0.034926951 ;
	setAttr ".uvtk[60]" -type "float2" 0.0040479302 -0.021089196 ;
	setAttr ".uvtk[61]" -type "float2" -0.0040479302 0.021089196 ;
	setAttr ".uvtk[62]" -type "float2" 0.0040479302 0.021089196 ;
	setAttr ".uvtk[63]" -type "float2" -0.0040479302 -0.021089196 ;
createNode blinn -n "CT2Window";
	rename -uid "5E5C505B-48B5-CD75-4A7F-A0B6FF045AFB";
createNode shadingEngine -n "blinn1SG";
	rename -uid "02740D9E-40A0-FF0E-90FA-2CBB39EA9F04";
	setAttr ".ihi" 0;
	setAttr -s 57 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 57 ".gn";
createNode materialInfo -n "materialInfo22";
	rename -uid "DE0EC977-4E80-B6C1-A651-EDBA29C53AE1";
createNode blinn -n "CTMid";
	rename -uid "4270464A-48A9-3FB0-B76F-CEBBB7D1983A";
createNode shadingEngine -n "blinn2SG";
	rename -uid "C1361746-4C11-D6F8-188B-D19F82EC9939";
	setAttr ".ihi" 0;
	setAttr -s 40 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 40 ".gn";
createNode materialInfo -n "materialInfo23";
	rename -uid "D84155BE-4298-1A6C-03D3-F58C46B0A4A3";
createNode blinn -n "CT2A";
	rename -uid "079EEC87-4F98-534F-9FE2-D19CDD5808C6";
createNode shadingEngine -n "blinn3SG";
	rename -uid "8CC22493-4831-EA4C-1182-549346EAF1CC";
	setAttr ".ihi" 0;
	setAttr -s 24 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 24 ".gn";
createNode materialInfo -n "materialInfo24";
	rename -uid "FC5FAEEE-45E0-82FB-3A55-0EB726261BBC";
createNode polyAutoProj -n "polyAutoProj15";
	rename -uid "6FC1FB32-43C8-FC85-AFFE-9FAE730559ED";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:95]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 28.558503150939941 28.558503150939941 28.558503150939941 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode deleteComponent -n "deleteComponent6";
	rename -uid "29F93F70-4E7B-E320-8FAB-17A5A0D2C15D";
	setAttr ".dc" -type "componentList" 1 "e[66]";
createNode deleteComponent -n "deleteComponent7";
	rename -uid "2E53DD45-4D2D-5F02-2047-3392DEE0D381";
	setAttr ".dc" -type "componentList" 1 "vtx[49]";
createNode polyMergeVert -n "polyMergeVert1";
	rename -uid "3D14B6C0-4A7B-8727-45B9-68B6332D35CE";
	setAttr ".ics" -type "componentList" 2 "vtx[49]" "vtx[52]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".am" yes;
createNode polyAutoProj -n "polyAutoProj16";
	rename -uid "C2995E33-47D5-43AE-E3D3-829BAB2F0A67";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:95]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 28.558503150939941 28.558503150939941 28.558503150939941 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polySeparate -n "polySeparate1";
	rename -uid "B1F83865-4F44-8AFB-F8BA-00832712A7D7";
	setAttr ".ic" 24;
	setAttr -s 24 ".out";
createNode groupId -n "groupId76";
	rename -uid "3968F1DC-482E-01EE-9724-938834E79C9D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts23";
	rename -uid "D5B6F295-4797-0DAB-6BFF-C4B32B3E2E3C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId77";
	rename -uid "C6852F06-4A97-BF9E-D5E4-73B47F449A37";
	setAttr ".ihi" 0;
createNode groupId -n "groupId78";
	rename -uid "6F66E7C4-450C-30B3-9547-929748947845";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts24";
	rename -uid "1B755898-4015-80EE-DBDC-9F8225026BC4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId79";
	rename -uid "6D8774D5-492A-AE02-141B-27B921756B42";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts25";
	rename -uid "BBE2DE49-4FE7-EE2B-FE63-6B8A4A70400D";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId80";
	rename -uid "5DD09634-460E-6757-6234-709120C08793";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts26";
	rename -uid "1F2C733B-4FF4-D106-D2B3-B19FA5F793D4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId81";
	rename -uid "2625ABD4-4651-4DE2-A937-E7872B0F0D40";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts27";
	rename -uid "74DD1203-43C1-A1CC-DFD3-8F88711A3E19";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId82";
	rename -uid "ACFE7E03-4819-AB58-A29B-49B62D093467";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts28";
	rename -uid "268BBE1E-4EE4-1778-BBFD-95B29C612741";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId83";
	rename -uid "FDCC51EA-4D4E-E29E-C9CF-87AADAAF403A";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts29";
	rename -uid "E8735327-4A5C-C0E5-ECFB-46AB1AA185C6";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId84";
	rename -uid "4FB3A19C-4EC1-4696-4BF0-BCA8ADF31E2F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts30";
	rename -uid "6FED76F8-48EC-C42F-7335-41B11893B2B2";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId85";
	rename -uid "ADC99360-47FC-C0A5-4AF1-A18BB415E6B5";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts31";
	rename -uid "B0E326D3-499E-2CE2-9821-8CB1BD8782DA";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId86";
	rename -uid "65154C23-4F13-8735-0534-1DB66E055802";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts32";
	rename -uid "4DA536CF-4A42-4E8A-2892-97A5536414AE";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId87";
	rename -uid "C16CA94D-4799-E12F-00FA-0AB55E81BE39";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts33";
	rename -uid "162EAF3F-432F-5079-2B52-3D9E825B6CC2";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId88";
	rename -uid "24B87B6A-4641-0378-005B-64ABD1E61A04";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts34";
	rename -uid "391E5A41-4857-3EC7-A177-AE8704299DEC";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId89";
	rename -uid "83F500BB-4E45-E3B2-E992-EEAE69B1B370";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts35";
	rename -uid "FEFE360D-41BA-4EBA-060B-7E837F573B67";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId90";
	rename -uid "7658E4E0-4653-51F8-BCC7-FEB215EB90B5";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts36";
	rename -uid "D659AC88-4C40-F91F-20F2-52A50EBE797A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId91";
	rename -uid "D5379CC0-42AB-592D-E277-DB9B18A3D9CF";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts37";
	rename -uid "BCAD2E94-4400-ADDD-1BEB-2892A23E9C52";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId92";
	rename -uid "484B01E9-4CF9-C283-9606-6887EBDE7D47";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts38";
	rename -uid "55E26B9A-4400-E44D-8711-0193CAA5697C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId93";
	rename -uid "DDDE5613-4ADB-A0CB-8BCA-EF8B29ED0A4F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts39";
	rename -uid "02584B9C-47DA-5B90-197C-64B58143E2DC";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId94";
	rename -uid "46E7B721-4016-9305-52B4-0986280A5748";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts40";
	rename -uid "A95BDCC5-4825-EF8A-9329-97B54F99BD0C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId95";
	rename -uid "50AD3F6B-4605-96D5-9B9E-C5974AFB47DD";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts41";
	rename -uid "548C8007-4BCA-CB55-67B5-7DA4F5B3C2D2";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId96";
	rename -uid "DED4671C-4315-6B9A-9D44-D29E5C25E82E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts42";
	rename -uid "3DF87E78-40B1-8E9C-7E08-DFA85EE1DD12";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId97";
	rename -uid "E1560700-45FF-5435-6EF5-84B76E438B7A";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts43";
	rename -uid "453A8A88-46EE-B9BC-EA5E-76B4F3981E3E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId98";
	rename -uid "1A15E678-4467-4492-1BFF-2393DFB9B858";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts44";
	rename -uid "4997EE9A-4E04-B72D-5612-F5AAD996C078";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId99";
	rename -uid "90BD0FAA-4812-0F6D-BD3C-2FAA60134C7D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts45";
	rename -uid "40427EDE-4C8F-1398-8ED4-7FA8D1427843";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId100";
	rename -uid "22CF356D-4FAD-C19F-ADAA-799081A33B9D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts46";
	rename -uid "8282E777-4A7C-7517-92E1-63A0A66AB97E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId101";
	rename -uid "5CB1E23C-4C19-1E6D-0022-86AB822A8E61";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts47";
	rename -uid "B4B67079-4125-49A9-686F-EC914CF21F86";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode polyUnite -n "polyUnite4";
	rename -uid "86B77673-49F1-814E-4E0F-609614E8B0F3";
	setAttr -s 3 ".ip";
	setAttr -s 3 ".im";
createNode groupId -n "groupId102";
	rename -uid "B09EF6ED-4A5F-730F-5CF1-41948A62BB1D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts48";
	rename -uid "1A8A1938-4807-E3B9-9EBB-C2928087F6D4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:5]";
createNode deleteComponent -n "deleteComponent8";
	rename -uid "E886B3F4-4C9D-D9B4-67F5-37AC6C370F53";
	setAttr ".dc" -type "componentList" 1 "e[7]";
createNode deleteComponent -n "deleteComponent9";
	rename -uid "452581E2-4973-B32B-B9FA-5296E61550F4";
	setAttr ".dc" -type "componentList" 1 "e[2]";
createNode deleteComponent -n "deleteComponent10";
	rename -uid "ED2B81A4-4538-1E12-BFC9-E08D1978A8AA";
	setAttr ".dc" -type "componentList" 1 "e[10]";
createNode polySplitRing -n "polySplitRing1";
	rename -uid "54BAEE83-4A94-D153-A0C8-E8893386C4BA";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[5]" "e[7]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".wt" 0.17876999080181122;
	setAttr ".re" 5;
	setAttr ".sma" 29.999999999999996;
	setAttr ".p[0]"  0 0 1;
	setAttr ".fq" yes;
createNode polySplitRing -n "polySplitRing2";
	rename -uid "F6F51D29-4B11-4592-3013-ED87B28F57A3";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[1]" "e[3]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".wt" 0.18401408195495605;
	setAttr ".re" 1;
	setAttr ".sma" 29.999999999999996;
	setAttr ".p[0]"  0 0 1;
	setAttr ".fq" yes;
createNode polySplitRing -n "polySplitRing3";
	rename -uid "5656B7F6-4DCA-04C6-AD54-4E868D6F95F0";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 2 "e[9]" "e[11]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".wt" 0.8206140398979187;
	setAttr ".dr" no;
	setAttr ".re" 11;
	setAttr ".sma" 29.999999999999996;
	setAttr ".p[0]"  0 0 1;
	setAttr ".fq" yes;
createNode polyExtrudeFace -n "polyExtrudeFace1";
	rename -uid "14D24A6F-40F4-7521-BAFC-A297D33FD705";
	setAttr ".ics" -type "componentList" 1 "f[2:4]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".pvt" -type "float3" 5.8661356 2.2211223 46.561302 ;
	setAttr ".rs" 58129;
	setAttr ".lt" -type "double3" 0 -1.0391358309213321e-014 0.47084760813765281 ;
	setAttr ".c[0]"  0 1 1;
	setAttr ".cbn" -type "double3" 5.0347690582275391 0.75704449415206909 31.961299896240234 ;
	setAttr ".cbx" -type "double3" 6.6975021362304687 3.6852002143859863 61.161300659179688 ;
createNode polyTweak -n "polyTweak1";
	rename -uid "D97634B3-4600-2616-4968-9E8B4F9F456A";
	setAttr ".uopa" yes;
	setAttr -s 16 ".tk";
	setAttr ".tk[0]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[2]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[3]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[4]" -type "float3" 1.9073486e-006 -2.3841858e-007 3.7252903e-008 ;
	setAttr ".tk[5]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[6]" -type "float3" 1.9073486e-006 -2.3841858e-007 3.7252903e-008 ;
	setAttr ".tk[7]" -type "float3" 1.9073486e-006 -2.3841858e-007 3.7252903e-008 ;
	setAttr ".tk[8]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[10]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[11]" -type "float3" 1.9073486e-006 1.1920929e-007 3.7252903e-008 ;
	setAttr ".tk[12]" -type "float3" 0.12547252 0 0 ;
	setAttr ".tk[13]" -type "float3" 0.12547252 0 0 ;
	setAttr ".tk[14]" -type "float3" 0.15704782 0 0 ;
	setAttr ".tk[15]" -type "float3" 0.15704782 0 0 ;
	setAttr ".tk[16]" -type "float3" 0.10152993 0 0 ;
	setAttr ".tk[17]" -type "float3" 0.10152993 0 0 ;
createNode polyBevel3 -n "polyBevel1";
	rename -uid "79A59444-4E4D-8591-F5C9-EAA483DB0BBF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[25]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".oaf" yes;
	setAttr ".at" 180;
	setAttr ".sn" yes;
	setAttr ".mv" yes;
	setAttr ".mvt" 0.0001;
	setAttr ".sa" 30;
createNode polyBevel3 -n "polyBevel2";
	rename -uid "6EAF2CF5-472D-351E-481A-ADACC8B13BF6";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[39]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".oaf" yes;
	setAttr ".at" 180;
	setAttr ".sn" yes;
	setAttr ".mv" yes;
	setAttr ".mvt" 0.0001;
	setAttr ".sa" 30;
createNode polyTweak -n "polyTweak2";
	rename -uid "8C7376C5-4F22-3A65-03FE-4E8528A52969";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[28:31]" -type "float3"  -0.15600595 0 0 3.7252903e-009
		 0.11780527 0 -0.15600595 0 0 3.7252903e-009 0.11780527 0;
createNode polyBevel3 -n "polyBevel3";
	rename -uid "E00FDCAB-43CE-177D-ED0F-FE8EA7014012";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[31]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
	setAttr ".oaf" yes;
	setAttr ".at" 180;
	setAttr ".sn" yes;
	setAttr ".mv" yes;
	setAttr ".mvt" 0.0001;
	setAttr ".sa" 30;
createNode polyTweak -n "polyTweak3";
	rename -uid "43E533A9-46B8-A237-659C-448898039014";
	setAttr ".uopa" yes;
	setAttr -s 4 ".tk[30:33]" -type "float3"  -0.16522519 0 0 -0.010134767
		 0.062227126 0 -0.16522519 0 0 -0.010134767 0.062227126 0;
createNode polyTweak -n "polyTweak4";
	rename -uid "A9DDEC22-42DF-C682-B542-5B80DF5DED53";
	setAttr ".uopa" yes;
	setAttr -s 7 ".tk";
	setAttr ".tk[23]" -type "float3" 0 0.018708089 0.09153451 ;
	setAttr ".tk[30]" -type "float3" 0 0.018708089 0.09153451 ;
	setAttr ".tk[31]" -type "float3" 0.018601997 0.026376659 0.040522683 ;
	setAttr ".tk[32]" -type "float3" -0.15129843 0 0 ;
	setAttr ".tk[33]" -type "float3" 0 0.086303845 0 ;
	setAttr ".tk[34]" -type "float3" -0.15129843 0 0 ;
	setAttr ".tk[35]" -type "float3" 0 0.086303845 0 ;
createNode deleteComponent -n "deleteComponent11";
	rename -uid "B8FFBCB8-4AF5-19C7-70AF-B08BA576360E";
	setAttr ".dc" -type "componentList" 1 "f[14]";
createNode deleteComponent -n "deleteComponent12";
	rename -uid "ADAC9C32-483F-EC18-85DD-09A5A71E64CA";
	setAttr ".dc" -type "componentList" 1 "f[8]";
createNode deleteComponent -n "deleteComponent13";
	rename -uid "9EDCEB2E-4BAC-CDB0-F346-00A62A4071F0";
	setAttr ".dc" -type "componentList" 1 "f[14]";
createNode deleteComponent -n "deleteComponent14";
	rename -uid "DA30CE9C-4695-ACF7-AD13-9DBBEC5AFC3A";
	setAttr ".dc" -type "componentList" 1 "f[9]";
createNode deleteComponent -n "deleteComponent15";
	rename -uid "68C14CAD-419D-9139-5759-B9B69C7659F3";
	setAttr ".dc" -type "componentList" 3 "f[8]" "f[10:11]" "f[13]";
createNode polyTriangulate -n "polyTriangulate1";
	rename -uid "EA4FE576-46BC-1282-43B5-BAA874697D19";
	setAttr ".ics" -type "componentList" 1 "f[*]";
createNode polyQuad -n "polyQuad1";
	rename -uid "9F8EE568-4033-AB74-3310-6988587C9084";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[*]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".ws" yes;
createNode polyTriangulate -n "polyTriangulate2";
	rename -uid "BE033B49-4E69-F594-7A4C-84A5908FAA6D";
	setAttr ".ics" -type "componentList" 1 "f[*]";
createNode polyUnite -n "polyUnite5";
	rename -uid "7E7C69EC-447A-FF76-DB8F-DA90434D5C14";
	setAttr -s 22 ".ip";
	setAttr -s 22 ".im";
createNode groupId -n "groupId103";
	rename -uid "D3AF7A91-4B91-E44D-1647-6981600DD185";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts49";
	rename -uid "71FBF727-4363-6141-E51D-17931C0E4E3E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode polyAutoProj -n "polyAutoProj17";
	rename -uid "04A5B72B-46F7-27C3-5129-61B7918AF721";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:70]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 31.369302749633789 31.369302749633789 31.369302749633789 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polyAutoProj -n "polyAutoProj18";
	rename -uid "3F1FCDA3-40A2-F9EB-51F9-7DB744AC076F";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:31]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 35.21600341796875 35.21600341796875 35.21600341796875 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
createNode polySoftEdge -n "polySoftEdge1";
	rename -uid "DB89EBFB-4CE0-6839-8B80-EC88773918DF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[42]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode polySoftEdge -n "polySoftEdge2";
	rename -uid "0DBFB4F6-4352-89E8-E5DD-B6B90D12F0FF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[*]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode polySoftEdge -n "polySoftEdge3";
	rename -uid "B3692280-486F-70C7-FC6E-51B46343E4B9";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[0:163]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode polySoftEdge -n "polySoftEdge4";
	rename -uid "126E69EF-42FC-EB7A-4CE2-3083CC2BEAFF";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "e[35]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 180;
createNode polySeparate -n "polySeparate2";
	rename -uid "A775C7E2-42DF-994A-9A06-0EA1F8DD9F05";
	setAttr ".ic" 24;
	setAttr -s 24 ".out";
createNode groupId -n "groupId104";
	rename -uid "4C7BE7D8-4C10-1AA2-FD40-DFAA1C443FBC";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts50";
	rename -uid "AD93AD13-4EDB-DDF7-6D11-FF8E340F8D3F";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId105";
	rename -uid "A39898F0-4FA0-9CD0-4536-7EBEDA099838";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts51";
	rename -uid "FAF3987B-4598-A846-C3EE-13A8748471CD";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId106";
	rename -uid "C3703FA4-499E-438B-3450-25AA70D7FB57";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts52";
	rename -uid "586DC2F2-483A-3C31-DA61-0FBF401FA2B8";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId107";
	rename -uid "50153593-4C4E-F6C5-7B3D-BB928EDC823B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts53";
	rename -uid "8F5808A4-4CD3-909C-B737-1E8D9C559BB5";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId108";
	rename -uid "BECE7BDF-4639-E79F-F569-EDBE93C2EB13";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts54";
	rename -uid "7C0A47E3-4A8E-0FFD-C27F-A1A76B4B4DD6";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId109";
	rename -uid "6A062BB0-489B-27F4-68A1-BD81BEDA4E34";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts55";
	rename -uid "C827378B-4657-2627-079F-3EAA3A088B00";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId110";
	rename -uid "2CA801F0-49A9-91A3-815B-FD86476A21CC";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts56";
	rename -uid "4A7D103D-4272-F828-568E-BF91FDFA0FFE";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId111";
	rename -uid "34F963B2-4254-C47A-4341-2E9CD5B6F8C3";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts57";
	rename -uid "58F05C45-4138-E523-88BB-BE9C3B49163C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId112";
	rename -uid "0E60D869-4780-D9CD-034E-159FA23014E2";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts58";
	rename -uid "9199B751-4039-2246-A168-C5A940449B1E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId113";
	rename -uid "78774C79-4AB2-1493-BED6-9CAAE5F1C378";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts59";
	rename -uid "903443AF-426D-71DD-A31E-18A646F1AAC5";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId114";
	rename -uid "E437FC65-4C5D-76F6-BEAA-CE923D918A7D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts60";
	rename -uid "706C2EBB-4686-39E5-E3BD-498B3215755E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId115";
	rename -uid "81BB8866-453E-C1F7-5354-E68488989B3A";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts61";
	rename -uid "93677C2B-44E4-F501-A84D-B4BEA926A183";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId116";
	rename -uid "13F24493-44AD-86E0-CF79-5B8F2A776BAA";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts62";
	rename -uid "09D794E8-445C-D72B-D0F3-D2812C28E31B";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId117";
	rename -uid "6BE5BC67-4A8F-0865-D291-088F62CA7E4D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts63";
	rename -uid "2B1C6F44-400B-A70D-68A4-41B74B75E172";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId118";
	rename -uid "267F9B37-416F-2B96-F3DA-D6945D807F91";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts64";
	rename -uid "98CA7F1C-4F80-8AD3-139C-B6828C836ACC";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId119";
	rename -uid "406C4602-4725-64BA-0CAB-8BBBB0258D1E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts65";
	rename -uid "DAFBADEB-4D65-4533-7F58-7982A7A5CDDD";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId120";
	rename -uid "58DE2981-4085-BB0B-EE6B-20A1255B459A";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts66";
	rename -uid "62CC5C8A-4F01-4844-7DDF-73B7121BC5FC";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId121";
	rename -uid "6D44FE5B-4509-A412-2EE8-C2AA96336FB1";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts67";
	rename -uid "364FC917-4A34-855B-F764-DEB8F5E546F7";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId122";
	rename -uid "3BF4D9E4-4108-25D5-AED4-D2B8CF2F32D1";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts68";
	rename -uid "8F6253CC-4436-4A50-89A8-B2AB124E778E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId123";
	rename -uid "B8251023-42D8-AA50-C4B9-6D90DB86FAB0";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts69";
	rename -uid "77AA48C8-4080-0212-4B20-6B98AABC1A1A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId124";
	rename -uid "E03F3304-4685-433E-0BF7-E5BC64C2140F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts70";
	rename -uid "7ADE6F62-4C8C-B413-0EFC-BFA6877265D7";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId125";
	rename -uid "F73ACACD-4574-4E89-5614-B4A1BAF64754";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts71";
	rename -uid "081BF34A-4AFA-CA33-3D76-5796A6156256";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId126";
	rename -uid "4F98ED07-4303-9B45-DEC2-EB91D12EF7C5";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts72";
	rename -uid "CC787A6D-4C24-3A0C-9BBB-B8AF200CAFE8";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode groupId -n "groupId127";
	rename -uid "FF722C46-432F-5710-1B59-48BB6362D97B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts73";
	rename -uid "D79BF12F-415B-FAD3-E3D7-26A2B6C612B1";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:70]";
createNode polyUnite -n "polyUnite6";
	rename -uid "0F1224BB-46E9-4DAC-DF73-24AFB68BFB12";
	setAttr -s 3 ".ip";
	setAttr -s 3 ".im";
createNode groupId -n "groupId128";
	rename -uid "E99E70B3-49E9-A4F0-6979-5FB001582809";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts74";
	rename -uid "CF266579-4AB0-44F0-1A32-7B9F55504961";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:5]";
createNode polyUnite -n "polyUnite7";
	rename -uid "E3D51816-450C-B5E7-06D3-07BD3F06A07D";
	setAttr -s 7 ".ip";
	setAttr -s 7 ".im";
createNode groupId -n "groupId129";
	rename -uid "65EF5253-4F9B-B775-148F-B89F4B97FBCD";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts75";
	rename -uid "EBADC784-49DC-0020-67E7-B892E7FC2820";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:15]";
createNode polyUnite -n "polyUnite8";
	rename -uid "60A45A28-4BC5-858E-F88D-099F2F9750F9";
	setAttr -s 4 ".ip";
	setAttr -s 4 ".im";
createNode groupId -n "groupId130";
	rename -uid "973B25E1-4F48-BFB6-3F48-3096F36ED90B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts76";
	rename -uid "46AAD398-42E6-871F-AC32-ABAADFC55B98";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:7]";
createNode polyUnite -n "polyUnite9";
	rename -uid "C2E29C77-4AB5-3C19-2463-ACBC846978DE";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId131";
	rename -uid "FF5AD706-45F9-BB00-F1A6-86AB4747513E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts77";
	rename -uid "F4BF642A-4A64-28CD-E2DF-F6B20B3E3477";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode polySeparate -n "polySeparate3";
	rename -uid "BFA2FEB9-43CE-F0F2-9397-27AFE1142C54";
	setAttr ".ic" 30;
	setAttr -s 30 ".out";
createNode groupId -n "groupId132";
	rename -uid "8659FAA5-49D4-9588-5221-D6A36CBEE61C";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts78";
	rename -uid "0522F647-4982-FE54-241F-CAA62794BF6A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId133";
	rename -uid "5064A362-4FD6-CC33-304A-72B510C5CEFA";
	setAttr ".ihi" 0;
createNode groupId -n "groupId134";
	rename -uid "44C72031-41E9-442C-59AC-B6B884D8102B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts79";
	rename -uid "12CB2367-4330-2E7F-8D92-60A775137953";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId135";
	rename -uid "E97B4B13-4638-0A15-2984-B4B358B513F9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts80";
	rename -uid "59F368F2-452C-E7E0-C45A-809821A294D3";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId136";
	rename -uid "53B146B3-4573-DD1F-7F31-879A4C68EBA8";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts81";
	rename -uid "6AA758CE-4798-38B6-8B04-138EBC72CA87";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId137";
	rename -uid "CC0D325C-46E0-2F10-4F7E-798EF77D0AEF";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts82";
	rename -uid "7979AF12-49F3-7C6D-41FA-DB83C96133A5";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId138";
	rename -uid "1596712E-4ACE-FEE1-088F-829287F9469D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts83";
	rename -uid "7E9A04FC-4045-170C-AEF4-69A3092514D5";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId139";
	rename -uid "28B656FB-427D-58A8-1AD8-83BD01579FC9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts84";
	rename -uid "314A2B59-4487-1198-E2E5-A4ACE54989DE";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId140";
	rename -uid "93FFD39F-4EE7-9335-5B12-26A0010EF38E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts85";
	rename -uid "913DF90B-4594-8E9B-54A3-99A40E3EE479";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId141";
	rename -uid "5D5F37BA-4B08-1631-1CE7-87A7E4592D2D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts86";
	rename -uid "08483A26-472F-27BF-3A27-2E976D7250DD";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId142";
	rename -uid "2F8A6EF9-48A9-06C7-2D68-00844D42E1F9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts87";
	rename -uid "1B5ED35A-4036-650D-5A11-2E888FD29664";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId143";
	rename -uid "A2AA592D-45B5-B604-B14F-D58A33B4F4E9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts88";
	rename -uid "9F483FEF-4BC7-604F-2513-3993C69700D9";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId144";
	rename -uid "A5D9BD6A-4978-34A2-7CB1-D7A10ACF65D7";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts89";
	rename -uid "46343457-4FC3-9AF4-4482-80B5569E21C4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId145";
	rename -uid "6DDB177B-4B81-FFA1-D728-6387D6876E3E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts90";
	rename -uid "8FFDED3F-4491-8DC5-299B-12B7DBA1F576";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId146";
	rename -uid "9F941C1F-4521-D73B-2B35-49B7E44BA1CE";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts91";
	rename -uid "EF689274-45BF-1EC7-B6FA-73B44BA3D983";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId147";
	rename -uid "68E65E2A-41AD-2C6E-EA06-E1961786DCEE";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts92";
	rename -uid "65FFEFA6-408B-3B7F-A836-238C3C7FF981";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId148";
	rename -uid "7FE1701F-4FFA-BE5D-0B2F-E89287E56B7F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts93";
	rename -uid "7CBE3504-4EA3-3696-6756-FF8BD1474AF7";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId149";
	rename -uid "D1DC56C8-46A1-316A-1135-759031A9B62E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts94";
	rename -uid "A3ABF921-4E32-A6DC-FC37-7B8501EE9DDC";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId150";
	rename -uid "D814D355-4ED8-A529-527B-82B8385018BA";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts95";
	rename -uid "3BEBD06B-41C4-BD1A-41D4-75944ED4622B";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId151";
	rename -uid "1D8659FF-4511-5F69-B99F-A9A161D96ADA";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts96";
	rename -uid "27D8702A-4703-92D4-A7CC-70B6A443462E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId152";
	rename -uid "E07466A8-4DD8-5B22-64F1-87A0FADC5B6E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts97";
	rename -uid "06CE9926-490A-E3A5-5233-8B94D77581AF";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId153";
	rename -uid "866E4886-4797-1E28-8E3D-7CB3079FE3F3";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts98";
	rename -uid "AB8B3C3A-47FC-50A3-AF7A-DD889AE22FCF";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId154";
	rename -uid "A1EBE442-479F-CB46-C249-8EA580DA7E5D";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts99";
	rename -uid "B3A1F07B-4B54-5512-54E4-2E8B46538064";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId155";
	rename -uid "ECC473EA-4B7E-EAF8-8D8E-F5B2825477D1";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts100";
	rename -uid "BD7F69C6-4E2C-9E5E-58BC-4CA336296AC1";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId156";
	rename -uid "16A19594-45E9-FCEE-ABF3-6590DC6CA257";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts101";
	rename -uid "7075A631-4FF9-A647-CCA8-EE9F8B2D247B";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId157";
	rename -uid "EA481F41-4AD1-E0CD-5AF1-C38F3F886D87";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts102";
	rename -uid "8DD3EDE3-4104-9A0F-98D9-66AB6688A93E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId158";
	rename -uid "36693428-4146-C185-2F74-86BD9C95CF54";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts103";
	rename -uid "CBB6B091-4797-9158-FE83-07ADF85D321C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId159";
	rename -uid "13B47A22-48F4-25BE-F097-48996785EA5F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts104";
	rename -uid "B3137742-4CFD-DB1E-4E03-40BEEABB8B5C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId160";
	rename -uid "A67CBD1E-4076-B51B-0EAD-78A534A86B41";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts105";
	rename -uid "B6FA0167-4381-C487-C8BF-C2B684E06211";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId161";
	rename -uid "AC68390E-45CD-3EC6-7740-D0896AD82746";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts106";
	rename -uid "6AB01C94-4F14-3A94-8911-A7871C2E368C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId162";
	rename -uid "FD6C8627-4A07-C9E1-AE70-81B453C74B72";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts107";
	rename -uid "FB1156A1-4EA5-F8A3-B047-5498E153D0B6";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode groupId -n "groupId163";
	rename -uid "AAC14391-46D3-C08B-1D9D-78907220A229";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts108";
	rename -uid "1A2D3E9A-4751-4CB4-2D22-32B509BB314F";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:95]";
createNode polyUnite -n "polyUnite10";
	rename -uid "7E8E13A5-4AD0-FEB3-6144-EE8D18ACC797";
	setAttr -s 4 ".ip";
	setAttr -s 4 ".im";
createNode groupId -n "groupId164";
	rename -uid "A932D766-40CE-B917-8704-8A955C4929F1";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts109";
	rename -uid "F4F96252-4C90-65FB-DB50-3DA48EB383A3";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:7]";
createNode polyUnite -n "polyUnite11";
	rename -uid "55CF0E6F-4223-5E78-A399-069FB2080563";
	setAttr -s 4 ".ip";
	setAttr -s 4 ".im";
createNode groupId -n "groupId165";
	rename -uid "E216A067-47F2-68CD-8F66-5BB58800B90B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts110";
	rename -uid "41CFA40E-4E1B-4B3B-5C6F-91B730061AAF";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:7]";
createNode polyUnite -n "polyUnite12";
	rename -uid "7BEE3E4D-4A5D-1FF5-1CB0-108EA632BD3B";
	setAttr -s 6 ".ip";
	setAttr -s 6 ".im";
createNode groupId -n "groupId166";
	rename -uid "AD671AC4-4B2D-3166-4904-139273CD7C04";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts111";
	rename -uid "98173C56-4E46-CE1C-694E-86A402491C1A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:11]";
createNode polyUnite -n "polyUnite13";
	rename -uid "8E840BB6-4E6E-2862-7FBB-8EAE54355F07";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId167";
	rename -uid "F85D3956-4052-5BEC-4A7E-FE9BCA0EBB27";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts112";
	rename -uid "8A806A2E-4650-8AA9-D9E4-6AB16EF3D738";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode polyUnite -n "polyUnite14";
	rename -uid "B3E073DB-46D8-9DE1-53B4-058447EB4E36";
	setAttr -s 3 ".ip";
	setAttr -s 3 ".im";
createNode groupId -n "groupId168";
	rename -uid "46BD254C-4BC8-1C9C-2117-01A1BB84FCEF";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts113";
	rename -uid "8C953ACE-4D91-F57B-3DC8-B799D90DEBE4";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:21]";
createNode polyUnite -n "polyUnite15";
	rename -uid "5ECD9399-4DCD-22F1-8830-C597475AAFB5";
	setAttr -s 5 ".ip";
	setAttr -s 5 ".im";
createNode groupId -n "groupId169";
	rename -uid "503FE6D4-4996-C8E9-E1EA-DC9D9D4AD394";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts114";
	rename -uid "4950CB50-45EB-6E1F-589E-EBAC8C5B904C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:9]";
createNode polyUnite -n "polyUnite16";
	rename -uid "7F518B20-4674-7BC9-7A4C-508A032231C8";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId170";
	rename -uid "4C3FCCAF-4224-6814-0A0B-1FA730F9CACE";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts115";
	rename -uid "1D22B9A8-4D63-7815-A1C0-DA8FC6E1E939";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:7]";
createNode polyUnite -n "polyUnite17";
	rename -uid "EA969A98-405E-0D68-BCF0-47983AD92F8A";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId171";
	rename -uid "33A5EBD0-4D89-E714-1181-E790E12771DC";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts116";
	rename -uid "EBBD92DF-4277-5CB3-CE27-68B37F6CD1EF";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:7]";
createNode polySeparate -n "polySeparate4";
	rename -uid "89C5A038-46F4-A639-8EEE-2B947AC09372";
	setAttr ".ic" 16;
	setAttr -s 16 ".out";
createNode groupId -n "groupId172";
	rename -uid "C2A68423-46DD-D5EA-0B17-6282CE9841B5";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts117";
	rename -uid "F290BA6E-49C6-9B37-CEAB-2BAF879C3355";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId173";
	rename -uid "60CA6799-401F-0870-B5CA-52B42AC2184F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId174";
	rename -uid "DD002FB0-4FC7-1483-92A2-9EBDF678AB15";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts118";
	rename -uid "DC488B73-4604-AC95-7516-30BD9A4DB793";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId175";
	rename -uid "F006B8A7-47DB-61E2-93CF-5C92E018784F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts119";
	rename -uid "511E47D6-403F-D1F4-DA19-22AF11787DA9";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId176";
	rename -uid "B3FF7E65-4BFF-858B-7C8B-A6902C487767";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts120";
	rename -uid "74392BE1-408A-A860-409A-DA9BE5DF58A2";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId177";
	rename -uid "FBC34FAF-48A9-FD77-79D8-699C115C644B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts121";
	rename -uid "BC79C01F-4A2C-2713-0FF7-099715A0B153";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId178";
	rename -uid "A96416A1-4B01-BCD7-71C3-2CAAACB5F798";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts122";
	rename -uid "EC709FF5-4731-9974-7757-46BB8CC89593";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId179";
	rename -uid "2683C32F-4C61-80B8-544C-D4B567FAE0E9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts123";
	rename -uid "5745287E-41DF-4AFB-3696-14AB65B2D1D1";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId180";
	rename -uid "A2240E75-457F-418E-1B08-AAA80C4C23E2";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts124";
	rename -uid "EA814BF8-49B3-660D-9FD3-1AB854200757";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId181";
	rename -uid "26D35260-432E-0EFB-44A2-7A8108881E0B";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts125";
	rename -uid "6BA9D9AA-4480-D69A-D787-76941195CEFA";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId182";
	rename -uid "026AF3B1-4611-8758-3093-DEA9888DB7B6";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts126";
	rename -uid "640DCED1-4AAC-D6C6-300E-B9865439BA6A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId183";
	rename -uid "6FC103F4-4991-84D6-5375-639A277EC522";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts127";
	rename -uid "917004BB-4C6D-1A9A-2D53-0B998DE78034";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId184";
	rename -uid "E53CC8E9-44C0-C83B-D45D-E0B156F1DC42";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts128";
	rename -uid "36B7C6E5-4691-CE15-D019-E991102B08C3";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId185";
	rename -uid "35384B20-4CD4-982F-56AC-8CBB06C6C751";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts129";
	rename -uid "13866FAF-4AA5-CB16-6D8C-2EA63A3AF1EE";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId186";
	rename -uid "9EB9306B-44FA-8CE7-9D3D-56BB060E30FE";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts130";
	rename -uid "28C656B4-4FB1-7182-413F-A88A1C42447B";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId187";
	rename -uid "A3A112C1-4FAE-3C8A-9080-9D83524EE294";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts131";
	rename -uid "37E2F1C3-4336-570F-BFEC-EAADDDD2D175";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId188";
	rename -uid "F1FEE6BF-4A12-A440-036F-40916D571790";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts132";
	rename -uid "C5A1D794-40FF-983F-6379-4B937E32C17D";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode groupId -n "groupId189";
	rename -uid "6EDDFC34-49D4-400B-2DD8-5A925FB118BF";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts133";
	rename -uid "27FA0A71-46D0-82EA-ECBF-7CAC485F2F16";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:31]";
createNode polyUnite -n "polyUnite18";
	rename -uid "947383BD-4DDD-957E-2C3D-168C7F8EB2EF";
	setAttr -s 3 ".ip";
	setAttr -s 3 ".im";
createNode groupId -n "groupId190";
	rename -uid "12DE8C83-4686-A1DC-F211-8F89A6D9BAB9";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts134";
	rename -uid "0E5C8C1B-4259-F9BA-DDB7-C89F57737E04";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:5]";
createNode polyUnite -n "polyUnite19";
	rename -uid "AF3A0556-4B32-B04B-9196-5AA917698F5D";
	setAttr -s 3 ".ip";
	setAttr -s 3 ".im";
createNode groupId -n "groupId191";
	rename -uid "231864FA-48F8-A3AC-96E2-8C9A5971026A";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts135";
	rename -uid "ADA3E6AA-4181-4E56-FFA1-A08018DF0C72";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:5]";
createNode polyUnite -n "polyUnite20";
	rename -uid "CBDF32F2-4C42-17D0-F60A-4FB4E05B2254";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId192";
	rename -uid "4EB6BD9E-4F0F-00DD-6B27-82841FDE874F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts136";
	rename -uid "B3375E58-4EAE-2CC9-95A2-FF8D4817675D";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode polyUnite -n "polyUnite21";
	rename -uid "1E2180E9-4E4B-3B34-0E1E-2AA557E4DCA6";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId193";
	rename -uid "54F85313-40A6-FB82-06D8-E7B167DDFFAE";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts137";
	rename -uid "6433CF91-4FA1-9853-063B-1491FD43051A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode polyUnite -n "polyUnite22";
	rename -uid "5A8A90A0-4C71-44A7-9962-B3BD72DEA508";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId194";
	rename -uid "2CA44FA1-4E50-40E8-924C-2E93F2CEC08F";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts138";
	rename -uid "7F88F5D6-4AF1-20C9-4192-518BED5367B2";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode polyUnite -n "polyUnite23";
	rename -uid "2181C896-4611-EE97-B134-E3946C7C74BE";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId195";
	rename -uid "245301C3-4FD4-66ED-07FC-EA93D3FB5D0A";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts139";
	rename -uid "BCCFF250-4AFC-9E4F-C5A4-ED87CCBBAC6A";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode polyUnite -n "polyUnite24";
	rename -uid "5835A2D7-4216-93E3-CB1A-ED9A6F3D3BE5";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId196";
	rename -uid "DC07B5BD-42ED-FD10-5CBC-79A8812756FC";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts140";
	rename -uid "3B6B6127-4D30-1DFB-CAD7-09A0DDBCB727";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:3]";
createNode file -n "ChannelCT2ADiffuse_1";
	rename -uid "1D619435-46A7-E242-DE68-E1A8746FFEFD";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCT2ADiffuse.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture1";
	rename -uid "E8393EBB-4A8C-D4FF-93C2-63AD575396A7";
createNode file -n "ChannelCT2ASpecular_1";
	rename -uid "A942C653-4BD8-52B1-F92B-CEABB47BA8B2";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCT2ASpecular.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture2";
	rename -uid "87E7DEFE-4E30-8857-AFA9-FEAE43E9FBCA";
createNode file -n "ChannelCT2WindowDiffuse_1";
	rename -uid "AF69A8CD-4CD2-FC1E-4DAB-E18F0CB6D446";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCT2WindowDiffuse.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture3";
	rename -uid "A1815031-497F-C46D-3CC8-F6BFF7E6A7D6";
createNode file -n "ChannelCT2WindowNormalMap_1";
	rename -uid "F8DEDC65-44CC-4BE4-6898-058C129B4BD5";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCT2WindowNormalMap.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture4";
	rename -uid "35508C90-44D3-212D-B7F1-68B5952172CA";
createNode file -n "ChannelCT2WindowSpecular_1";
	rename -uid "741396C9-425E-E5CF-55EA-C9A1D4818FC3";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCT2WindowSpecular.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture5";
	rename -uid "9ECCB86E-4F0A-3C2C-DEF8-259BEB6331D6";
createNode file -n "ChannelCTMidDiffuse_1";
	rename -uid "5916C4CF-4565-6773-1E1D-769C3060FBBE";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCTMidDiffuse.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture6";
	rename -uid "5F4791C7-4D50-BE92-D55E-369417133B9A";
createNode file -n "ChannelCTMidNormalMap_1";
	rename -uid "CEE6974C-4196-7A3A-C34C-5EBAD9C01AD0";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCTMidNormalMap.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture7";
	rename -uid "2D11AE19-4FB4-CCA6-A7E8-3B909F8F7A6D";
createNode file -n "ChannelCTMidSpecular_1";
	rename -uid "ABC53993-41ED-3EE9-1872-20BB2DFE5C6F";
	setAttr ".ftn" -type "string" "D:/UA/CUARTO/ABP/TBA/Modelos nuestros/Texturizado/CT/Export/ChannelCTMidSpecular.tif";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture8";
	rename -uid "9865A6E8-4462-5A5D-EC64-319694D5D27D";
createNode aiOptions -s -n "defaultArnoldRenderOptions";
	rename -uid "492C8ACE-441F-1759-8F1C-2A88155DF04E";
	setAttr ".version" -type "string" "1.3.0.0";
createNode aiAOVFilter -s -n "defaultArnoldFilter";
	rename -uid "7F4AAF87-43EB-1FB9-1273-F1937C042C7A";
	setAttr ".ai_translator" -type "string" "gaussian";
createNode aiAOVDriver -s -n "defaultArnoldDriver";
	rename -uid "3FC92A48-42BD-10B3-B559-A2980D99A4C7";
	setAttr ".ai_translator" -type "string" "exr";
createNode aiAOVDriver -s -n "defaultArnoldDisplayDriver";
	rename -uid "B99C7A7E-46F5-F344-6875-F1B5639E701A";
	setAttr ".output_mode" 0;
	setAttr ".ai_translator" -type "string" "maya";
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "D7D7EA46-4F8F-554C-48C6-F7B106EA44E2";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" 1112.2815043322873 -533.11038798242328 ;
	setAttr ".tgi[0].vh" -type "double2" 1695.174032035115 27.909999844125611 ;
	setAttr -s 22 ".tgi[0].ni";
	setAttr ".tgi[0].ni[0].x" -409.62875366210937;
	setAttr ".tgi[0].ni[0].y" -947.703369140625;
	setAttr ".tgi[0].ni[0].nvs" 1923;
	setAttr ".tgi[0].ni[1].x" 1892.64794921875;
	setAttr ".tgi[0].ni[1].y" -74.695243835449219;
	setAttr ".tgi[0].ni[1].nvs" 1923;
	setAttr ".tgi[0].ni[2].x" -646.2503662109375;
	setAttr ".tgi[0].ni[2].y" -1159.53857421875;
	setAttr ".tgi[0].ni[2].nvs" 1923;
	setAttr ".tgi[0].ni[3].x" 1104.6070556640625;
	setAttr ".tgi[0].ni[3].y" -213.80642700195312;
	setAttr ".tgi[0].ni[3].nvs" 1923;
	setAttr ".tgi[0].ni[4].x" -287.4761962890625;
	setAttr ".tgi[0].ni[4].y" -227.46360778808594;
	setAttr ".tgi[0].ni[4].nvs" 1923;
	setAttr ".tgi[0].ni[5].x" -1329.596923828125;
	setAttr ".tgi[0].ni[5].y" -53.452587127685547;
	setAttr ".tgi[0].ni[5].nvs" 1923;
	setAttr ".tgi[0].ni[6].x" 158.1484375;
	setAttr ".tgi[0].ni[6].y" -183.29632568359375;
	setAttr ".tgi[0].ni[6].nvs" 1923;
	setAttr ".tgi[0].ni[7].x" 1326.03564453125;
	setAttr ".tgi[0].ni[7].y" -213.80642700195312;
	setAttr ".tgi[0].ni[7].nvs" 1923;
	setAttr ".tgi[0].ni[8].x" -424.82177734375;
	setAttr ".tgi[0].ni[8].y" -1159.53857421875;
	setAttr ".tgi[0].ni[8].nvs" 1923;
	setAttr ".tgi[0].ni[9].x" -303.11492919921875;
	setAttr ".tgi[0].ni[9].y" -382.71990966796875;
	setAttr ".tgi[0].ni[9].nvs" 1923;
	setAttr ".tgi[0].ni[10].x" -1551.0255126953125;
	setAttr ".tgi[0].ni[10].y" -53.452587127685547;
	setAttr ".tgi[0].ni[10].nvs" 1923;
	setAttr ".tgi[0].ni[11].x" -820.69366455078125;
	setAttr ".tgi[0].ni[11].y" -63.094444274902344;
	setAttr ".tgi[0].ni[11].nvs" 1923;
	setAttr ".tgi[0].ni[12].x" 1026.0782470703125;
	setAttr ".tgi[0].ni[12].y" 15.390872955322266;
	setAttr ".tgi[0].ni[12].nvs" 1923;
	setAttr ".tgi[0].ni[13].x" -1591.0970458984375;
	setAttr ".tgi[0].ni[13].y" -199.40122985839844;
	setAttr ".tgi[0].ni[13].nvs" 1923;
	setAttr ".tgi[0].ni[14].x" -1067.8084716796875;
	setAttr ".tgi[0].ni[14].y" -23.319421768188477;
	setAttr ".tgi[0].ni[14].nvs" 1923;
	setAttr ".tgi[0].ni[15].x" 1595.0289306640625;
	setAttr ".tgi[0].ni[15].y" -54.457141876220703;
	setAttr ".tgi[0].ni[15].nvs" 1923;
	setAttr ".tgi[0].ni[16].x" -1369.66845703125;
	setAttr ".tgi[0].ni[16].y" -199.40122985839844;
	setAttr ".tgi[0].ni[16].nvs" 1923;
	setAttr ".tgi[0].ni[17].x" -631.05731201171875;
	setAttr ".tgi[0].ni[17].y" -947.703369140625;
	setAttr ".tgi[0].ni[17].nvs" 1923;
	setAttr ".tgi[0].ni[18].x" -66.047615051269531;
	setAttr ".tgi[0].ni[18].y" -227.46360778808594;
	setAttr ".tgi[0].ni[18].nvs" 1923;
	setAttr ".tgi[0].ni[19].x" 410.83432006835937;
	setAttr ".tgi[0].ni[19].y" -182.35804748535156;
	setAttr ".tgi[0].ni[19].nvs" 1923;
	setAttr ".tgi[0].ni[20].x" -81.68634033203125;
	setAttr ".tgi[0].ni[20].y" -382.71990966796875;
	setAttr ".tgi[0].ni[20].nvs" 1923;
	setAttr ".tgi[0].ni[21].x" 1247.5067138671875;
	setAttr ".tgi[0].ni[21].y" 15.390872955322266;
	setAttr ".tgi[0].ni[21].nvs" 1923;
select -ne :time1;
	setAttr ".o" 0;
select -ne :renderPartition;
	setAttr -s 27 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 29 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 8 ".u";
select -ne :defaultRenderingList1;
select -ne :defaultTextureList1;
	setAttr -s 8 ".tx";
select -ne :defaultRenderGlobals;
	setAttr ".ren" -type "string" "arnold";
	setAttr ".outf" 51;
	setAttr ".imfkey" -type "string" "exr";
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :defaultColorMgtGlobals;
	setAttr ".cme" no;
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "groupId60.id" "|Script|Box|Box_1|transform28|Box_1Shape.iog.og[0].gid"
		;
connectAttr "Box063MatSG.mwc" "|Script|Box|Box_1|transform28|Box_1Shape.iog.og[0].gco"
		;
connectAttr "groupId61.id" "|Script|Box|Box_1|transform28|Box_1Shape.ciog.cog[0].cgid"
		;
connectAttr "groupId35.id" "Box_3Shape.iog.og[0].gid";
connectAttr "Box004MatSG.mwc" "Box_3Shape.iog.og[0].gco";
connectAttr "groupId36.id" "Box_3Shape.ciog.cog[0].cgid";
connectAttr "groupId1.id" "|Script|Box_4|Box_5|transform11|Box_5Shape.iog.og[0].gid"
		;
connectAttr "Box085MatSG.mwc" "|Script|Box_4|Box_5|transform11|Box_5Shape.iog.og[0].gco"
		;
connectAttr "groupParts1.og" "|Script|Box_4|Box_5|transform11|Box_5Shape.i";
connectAttr "groupId2.id" "|Script|Box_4|Box_5|transform11|Box_5Shape.ciog.cog[0].cgid"
		;
connectAttr "groupId33.id" "|Script|Box_6|Box_7|transform20|Box_7Shape.iog.og[0].gid"
		;
connectAttr "Box061MatSG.mwc" "|Script|Box_6|Box_7|transform20|Box_7Shape.iog.og[0].gco"
		;
connectAttr "groupId34.id" "|Script|Box_6|Box_7|transform20|Box_7Shape.ciog.cog[0].cgid"
		;
connectAttr "groupId3.id" "Box_9Shape.iog.og[0].gid";
connectAttr "Box054MatSG.mwc" "Box_9Shape.iog.og[0].gco";
connectAttr "groupParts2.og" "Box_9Shape.i";
connectAttr "groupId4.id" "Box_9Shape.ciog.cog[0].cgid";
connectAttr "groupId17.id" "Box_11Shape.iog.og[0].gid";
connectAttr "Box007MatSG.mwc" "Box_11Shape.iog.og[0].gco";
connectAttr "groupParts9.og" "Box_11Shape.i";
connectAttr "groupId18.id" "Box_11Shape.ciog.cog[0].cgid";
connectAttr "groupId66.id" "initialShadingGroup_pCubeShape.iog.og[0].gid";
connectAttr "initialShadingGroup_pCube13MatSG.mwc" "initialShadingGroup_pCubeShape.iog.og[0].gco"
		;
connectAttr "groupId67.id" "initialShadingGroup_pCubeShape.ciog.cog[0].cgid";
connectAttr "groupId15.id" "Box_13Shape.iog.og[0].gid";
connectAttr "Box006MatSG.mwc" "Box_13Shape.iog.og[0].gco";
connectAttr "groupParts8.og" "Box_13Shape.i";
connectAttr "groupId16.id" "Box_13Shape.ciog.cog[0].cgid";
connectAttr "groupId49.id" "Box_15Shape.iog.og[0].gid";
connectAttr "Box100MatSG.mwc" "Box_15Shape.iog.og[0].gco";
connectAttr "groupId50.id" "Box_15Shape.ciog.cog[0].cgid";
connectAttr "groupId74.id" "Box_17Shape.iog.og[0].gid";
connectAttr "Box063MatSG.mwc" "Box_17Shape.iog.og[0].gco";
connectAttr "groupId75.id" "Box_17Shape.ciog.cog[0].cgid";
connectAttr "groupId21.id" "Box_19Shape.iog.og[0].gid";
connectAttr "Box086MatSG.mwc" "Box_19Shape.iog.og[0].gco";
connectAttr "groupParts11.og" "Box_19Shape.i";
connectAttr "groupId22.id" "Box_19Shape.ciog.cog[0].cgid";
connectAttr "groupId7.id" "Box_21Shape.iog.og[0].gid";
connectAttr "Box055MatSG.mwc" "Box_21Shape.iog.og[0].gco";
connectAttr "groupParts4.og" "Box_21Shape.i";
connectAttr "groupId8.id" "Box_21Shape.ciog.cog[0].cgid";
connectAttr "groupId37.id" "Box_23Shape.iog.og[0].gid";
connectAttr "Box062MatSG.mwc" "Box_23Shape.iog.og[0].gco";
connectAttr "groupId38.id" "Box_23Shape.ciog.cog[0].cgid";
connectAttr "groupId64.id" "Box_25Shape.iog.og[0].gid";
connectAttr "Box002MatSG.mwc" "Box_25Shape.iog.og[0].gco";
connectAttr "groupId65.id" "Box_25Shape.ciog.cog[0].cgid";
connectAttr "groupId5.id" "Box_27Shape.iog.og[0].gid";
connectAttr "Box053MatSG.mwc" "Box_27Shape.iog.og[0].gco";
connectAttr "groupParts3.og" "Box_27Shape.i";
connectAttr "groupId6.id" "Box_27Shape.ciog.cog[0].cgid";
connectAttr "groupId62.id" "Box_29Shape.iog.og[0].gid";
connectAttr "Box001MatSG.mwc" "Box_29Shape.iog.og[0].gco";
connectAttr "groupId63.id" "Box_29Shape.ciog.cog[0].cgid";
connectAttr "groupId47.id" "Box_31Shape.iog.og[0].gid";
connectAttr "Box086MatSG.mwc" "Box_31Shape.iog.og[0].gco";
connectAttr "groupId48.id" "Box_31Shape.ciog.cog[0].cgid";
connectAttr "groupId72.id" "Box_33Shape.iog.og[0].gid";
connectAttr "Box063MatSG.mwc" "Box_33Shape.iog.og[0].gco";
connectAttr "groupId73.id" "Box_33Shape.ciog.cog[0].cgid";
connectAttr "groupId70.id" "initialShadingGroup_pCube_1Shape.iog.og[0].gid";
connectAttr "initialShadingGroup_pCube13MatSG.mwc" "initialShadingGroup_pCube_1Shape.iog.og[0].gco"
		;
connectAttr "groupId71.id" "initialShadingGroup_pCube_1Shape.ciog.cog[0].cgid";
connectAttr "groupId45.id" "Box_35Shape.iog.og[0].gid";
connectAttr "Box101MatSG.mwc" "Box_35Shape.iog.og[0].gco";
connectAttr "groupParts22.og" "Box_35Shape.i";
connectAttr "groupId46.id" "Box_35Shape.ciog.cog[0].cgid";
connectAttr "groupId68.id" "Box_37Shape.iog.og[0].gid";
connectAttr "Box063MatSG.mwc" "Box_37Shape.iog.og[0].gco";
connectAttr "groupId69.id" "Box_37Shape.ciog.cog[0].cgid";
connectAttr "groupId43.id" "Box_39Shape.iog.og[0].gid";
connectAttr "Box087MatSG.mwc" "Box_39Shape.iog.og[0].gco";
connectAttr "groupId44.id" "Box_39Shape.ciog.cog[0].cgid";
connectAttr "groupId11.id" "Box_41Shape.iog.og[0].gid";
connectAttr "Box099MatSG.mwc" "Box_41Shape.iog.og[0].gco";
connectAttr "groupParts6.og" "Box_41Shape.i";
connectAttr "groupId12.id" "Box_41Shape.ciog.cog[0].cgid";
connectAttr "groupId39.id" "Box_43Shape.iog.og[0].gid";
connectAttr "Box005MatSG.mwc" "Box_43Shape.iog.og[0].gco";
connectAttr "groupId40.id" "Box_43Shape.ciog.cog[0].cgid";
connectAttr "groupId9.id" "Box_45Shape.iog.og[0].gid";
connectAttr "Box058MatSG.mwc" "Box_45Shape.iog.og[0].gco";
connectAttr "groupParts5.og" "Box_45Shape.i";
connectAttr "groupId10.id" "Box_45Shape.ciog.cog[0].cgid";
connectAttr "groupId41.id" "Box_47Shape.iog.og[0].gid";
connectAttr "Box003MatSG.mwc" "Box_47Shape.iog.og[0].gco";
connectAttr "groupId42.id" "Box_47Shape.ciog.cog[0].cgid";
connectAttr "groupId19.id" "Box_49Shape.iog.og[0].gid";
connectAttr "Box057MatSG.mwc" "Box_49Shape.iog.og[0].gco";
connectAttr "groupParts10.og" "Box_49Shape.i";
connectAttr "groupId20.id" "Box_49Shape.ciog.cog[0].cgid";
connectAttr "groupId13.id" "Box_51Shape.iog.og[0].gid";
connectAttr "Box058MatSG.mwc" "Box_51Shape.iog.og[0].gco";
connectAttr "groupParts7.og" "Box_51Shape.i";
connectAttr "groupId14.id" "Box_51Shape.ciog.cog[0].cgid";
connectAttr "groupParts24.og" "polySurfaceShape13.i";
connectAttr "groupId78.id" "polySurfaceShape13.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape13.iog.og[0].gco";
connectAttr "groupParts25.og" "polySurfaceShape14.i";
connectAttr "groupId79.id" "polySurfaceShape14.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape14.iog.og[0].gco";
connectAttr "groupParts26.og" "polySurfaceShape15.i";
connectAttr "groupId80.id" "polySurfaceShape15.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape15.iog.og[0].gco";
connectAttr "groupParts27.og" "polySurfaceShape16.i";
connectAttr "groupId81.id" "polySurfaceShape16.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape16.iog.og[0].gco";
connectAttr "groupParts28.og" "polySurfaceShape17.i";
connectAttr "groupId82.id" "polySurfaceShape17.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape17.iog.og[0].gco";
connectAttr "groupParts29.og" "polySurfaceShape18.i";
connectAttr "groupId83.id" "polySurfaceShape18.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape18.iog.og[0].gco";
connectAttr "groupParts30.og" "polySurfaceShape19.i";
connectAttr "groupId84.id" "polySurfaceShape19.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape19.iog.og[0].gco";
connectAttr "groupParts31.og" "polySurfaceShape20.i";
connectAttr "groupId85.id" "polySurfaceShape20.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape20.iog.og[0].gco";
connectAttr "groupParts32.og" "polySurfaceShape21.i";
connectAttr "groupId86.id" "polySurfaceShape21.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape21.iog.og[0].gco";
connectAttr "groupParts33.og" "polySurfaceShape22.i";
connectAttr "groupId87.id" "polySurfaceShape22.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape22.iog.og[0].gco";
connectAttr "groupParts34.og" "polySurfaceShape23.i";
connectAttr "groupId88.id" "polySurfaceShape23.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape23.iog.og[0].gco";
connectAttr "groupParts35.og" "polySurfaceShape24.i";
connectAttr "groupId89.id" "polySurfaceShape24.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape24.iog.og[0].gco";
connectAttr "groupParts36.og" "polySurfaceShape25.i";
connectAttr "groupId90.id" "polySurfaceShape25.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape25.iog.og[0].gco";
connectAttr "groupParts37.og" "polySurfaceShape26.i";
connectAttr "groupId91.id" "polySurfaceShape26.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape26.iog.og[0].gco";
connectAttr "groupParts38.og" "polySurfaceShape27.i";
connectAttr "groupId92.id" "polySurfaceShape27.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape27.iog.og[0].gco";
connectAttr "groupParts39.og" "polySurfaceShape28.i";
connectAttr "groupId93.id" "polySurfaceShape28.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape28.iog.og[0].gco";
connectAttr "groupParts40.og" "polySurfaceShape29.i";
connectAttr "groupId94.id" "polySurfaceShape29.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape29.iog.og[0].gco";
connectAttr "groupParts41.og" "polySurfaceShape30.i";
connectAttr "groupId95.id" "polySurfaceShape30.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape30.iog.og[0].gco";
connectAttr "groupParts42.og" "polySurfaceShape31.i";
connectAttr "groupId96.id" "polySurfaceShape31.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape31.iog.og[0].gco";
connectAttr "groupParts43.og" "polySurfaceShape32.i";
connectAttr "groupId97.id" "polySurfaceShape32.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape32.iog.og[0].gco";
connectAttr "groupParts44.og" "polySurfaceShape33.i";
connectAttr "groupId98.id" "polySurfaceShape33.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape33.iog.og[0].gco";
connectAttr "groupParts45.og" "polySurfaceShape34.i";
connectAttr "groupId99.id" "polySurfaceShape34.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape34.iog.og[0].gco";
connectAttr "groupParts46.og" "polySurfaceShape35.i";
connectAttr "groupId100.id" "polySurfaceShape35.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape35.iog.og[0].gco";
connectAttr "groupParts47.og" "polySurfaceShape36.i";
connectAttr "groupId101.id" "polySurfaceShape36.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape36.iog.og[0].gco";
connectAttr "groupParts23.og" "|Box_5|transform29|Box_5Shape.i";
connectAttr "groupId76.id" "|Box_5|transform29|Box_5Shape.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "|Box_5|transform29|Box_5Shape.iog.og[0].gco";
connectAttr "groupId77.id" "|Box_5|transform29|Box_5Shape.ciog.cog[0].cgid";
connectAttr "groupParts79.og" "polySurfaceShape61.i";
connectAttr "groupId134.id" "polySurfaceShape61.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape61.iog.og[0].gco";
connectAttr "groupParts80.og" "polySurfaceShape62.i";
connectAttr "groupId135.id" "polySurfaceShape62.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape62.iog.og[0].gco";
connectAttr "groupParts81.og" "polySurfaceShape63.i";
connectAttr "groupId136.id" "polySurfaceShape63.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape63.iog.og[0].gco";
connectAttr "groupParts82.og" "polySurfaceShape64.i";
connectAttr "groupId137.id" "polySurfaceShape64.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape64.iog.og[0].gco";
connectAttr "groupParts83.og" "polySurfaceShape65.i";
connectAttr "groupId138.id" "polySurfaceShape65.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape65.iog.og[0].gco";
connectAttr "groupParts84.og" "polySurfaceShape66.i";
connectAttr "groupId139.id" "polySurfaceShape66.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape66.iog.og[0].gco";
connectAttr "groupParts85.og" "polySurfaceShape67.i";
connectAttr "groupId140.id" "polySurfaceShape67.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape67.iog.og[0].gco";
connectAttr "groupParts86.og" "polySurfaceShape68.i";
connectAttr "groupId141.id" "polySurfaceShape68.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape68.iog.og[0].gco";
connectAttr "groupParts87.og" "polySurfaceShape69.i";
connectAttr "groupId142.id" "polySurfaceShape69.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape69.iog.og[0].gco";
connectAttr "groupParts88.og" "polySurfaceShape70.i";
connectAttr "groupId143.id" "polySurfaceShape70.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape70.iog.og[0].gco";
connectAttr "groupParts89.og" "polySurfaceShape71.i";
connectAttr "groupId144.id" "polySurfaceShape71.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape71.iog.og[0].gco";
connectAttr "groupParts90.og" "polySurfaceShape72.i";
connectAttr "groupId145.id" "polySurfaceShape72.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape72.iog.og[0].gco";
connectAttr "groupParts91.og" "polySurfaceShape73.i";
connectAttr "groupId146.id" "polySurfaceShape73.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape73.iog.og[0].gco";
connectAttr "groupParts92.og" "polySurfaceShape74.i";
connectAttr "groupId147.id" "polySurfaceShape74.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape74.iog.og[0].gco";
connectAttr "groupParts93.og" "polySurfaceShape75.i";
connectAttr "groupId148.id" "polySurfaceShape75.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape75.iog.og[0].gco";
connectAttr "groupParts94.og" "polySurfaceShape76.i";
connectAttr "groupId149.id" "polySurfaceShape76.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape76.iog.og[0].gco";
connectAttr "groupParts95.og" "polySurfaceShape77.i";
connectAttr "groupId150.id" "polySurfaceShape77.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape77.iog.og[0].gco";
connectAttr "groupParts96.og" "polySurfaceShape78.i";
connectAttr "groupId151.id" "polySurfaceShape78.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape78.iog.og[0].gco";
connectAttr "groupParts97.og" "polySurfaceShape79.i";
connectAttr "groupId152.id" "polySurfaceShape79.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape79.iog.og[0].gco";
connectAttr "groupParts98.og" "polySurfaceShape80.i";
connectAttr "groupId153.id" "polySurfaceShape80.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape80.iog.og[0].gco";
connectAttr "groupParts99.og" "polySurfaceShape81.i";
connectAttr "groupId154.id" "polySurfaceShape81.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape81.iog.og[0].gco";
connectAttr "groupParts100.og" "polySurfaceShape82.i";
connectAttr "groupId155.id" "polySurfaceShape82.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape82.iog.og[0].gco";
connectAttr "groupParts101.og" "polySurfaceShape83.i";
connectAttr "groupId156.id" "polySurfaceShape83.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape83.iog.og[0].gco";
connectAttr "groupParts102.og" "polySurfaceShape84.i";
connectAttr "groupId157.id" "polySurfaceShape84.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape84.iog.og[0].gco";
connectAttr "groupParts103.og" "polySurfaceShape85.i";
connectAttr "groupId158.id" "polySurfaceShape85.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape85.iog.og[0].gco";
connectAttr "groupParts104.og" "polySurfaceShape86.i";
connectAttr "groupId159.id" "polySurfaceShape86.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape86.iog.og[0].gco";
connectAttr "groupParts105.og" "polySurfaceShape87.i";
connectAttr "groupId160.id" "polySurfaceShape87.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape87.iog.og[0].gco";
connectAttr "groupParts106.og" "polySurfaceShape88.i";
connectAttr "groupId161.id" "polySurfaceShape88.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape88.iog.og[0].gco";
connectAttr "groupParts107.og" "polySurfaceShape89.i";
connectAttr "groupId162.id" "polySurfaceShape89.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape89.iog.og[0].gco";
connectAttr "groupParts108.og" "polySurfaceShape90.i";
connectAttr "groupId163.id" "polySurfaceShape90.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurfaceShape90.iog.og[0].gco";
connectAttr "groupParts78.og" "|Box_7|transform72|Box_7Shape.i";
connectAttr "polyTweakUV1.uvtk[0]" "|Box_7|transform72|Box_7Shape.uvst[0].uvtw";
connectAttr "groupId132.id" "|Box_7|transform72|Box_7Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "|Box_7|transform72|Box_7Shape.iog.og[0].gco";
connectAttr "groupId133.id" "|Box_7|transform72|Box_7Shape.ciog.cog[0].cgid";
connectAttr "groupParts118.og" "polySurfaceShape91.i";
connectAttr "groupId174.id" "polySurfaceShape91.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape91.iog.og[0].gco";
connectAttr "groupParts119.og" "polySurfaceShape92.i";
connectAttr "groupId175.id" "polySurfaceShape92.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape92.iog.og[0].gco";
connectAttr "groupParts120.og" "polySurfaceShape93.i";
connectAttr "groupId176.id" "polySurfaceShape93.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape93.iog.og[0].gco";
connectAttr "groupParts121.og" "polySurfaceShape94.i";
connectAttr "groupId177.id" "polySurfaceShape94.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape94.iog.og[0].gco";
connectAttr "groupParts122.og" "polySurfaceShape95.i";
connectAttr "groupId178.id" "polySurfaceShape95.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape95.iog.og[0].gco";
connectAttr "groupParts123.og" "polySurfaceShape96.i";
connectAttr "groupId179.id" "polySurfaceShape96.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape96.iog.og[0].gco";
connectAttr "groupParts124.og" "polySurfaceShape97.i";
connectAttr "groupId180.id" "polySurfaceShape97.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape97.iog.og[0].gco";
connectAttr "groupParts125.og" "polySurfaceShape98.i";
connectAttr "groupId181.id" "polySurfaceShape98.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape98.iog.og[0].gco";
connectAttr "groupParts126.og" "polySurfaceShape99.i";
connectAttr "groupId182.id" "polySurfaceShape99.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape99.iog.og[0].gco";
connectAttr "groupParts127.og" "polySurfaceShape100.i";
connectAttr "groupId183.id" "polySurfaceShape100.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape100.iog.og[0].gco";
connectAttr "groupParts128.og" "polySurfaceShape101.i";
connectAttr "groupId184.id" "polySurfaceShape101.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape101.iog.og[0].gco";
connectAttr "groupParts129.og" "polySurfaceShape102.i";
connectAttr "groupId185.id" "polySurfaceShape102.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape102.iog.og[0].gco";
connectAttr "groupParts130.og" "polySurfaceShape103.i";
connectAttr "groupId186.id" "polySurfaceShape103.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape103.iog.og[0].gco";
connectAttr "groupParts131.og" "polySurfaceShape104.i";
connectAttr "groupId187.id" "polySurfaceShape104.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape104.iog.og[0].gco";
connectAttr "groupParts132.og" "polySurfaceShape105.i";
connectAttr "groupId188.id" "polySurfaceShape105.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape105.iog.og[0].gco";
connectAttr "groupParts133.og" "polySurfaceShape106.i";
connectAttr "groupId189.id" "polySurfaceShape106.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurfaceShape106.iog.og[0].gco";
connectAttr "groupParts117.og" "|Box_1|transform101|Box_1Shape.i";
connectAttr "polyTweakUV2.uvtk[0]" "|Box_1|transform101|Box_1Shape.uvst[0].uvtw"
		;
connectAttr "groupId172.id" "|Box_1|transform101|Box_1Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "|Box_1|transform101|Box_1Shape.iog.og[0].gco";
connectAttr "groupId173.id" "|Box_1|transform101|Box_1Shape.ciog.cog[0].cgid";
connectAttr "groupId102.id" "|polySurface20|transform54|polySurface20Shape.iog.og[0].gid"
		;
connectAttr "blinn1SG.mwc" "|polySurface20|transform54|polySurface20Shape.iog.og[0].gco"
		;
connectAttr "polyTriangulate2.out" "|polySurface20|transform54|polySurface20Shape.i"
		;
connectAttr "groupParts50.og" "polySurfaceShape37.i";
connectAttr "groupId104.id" "polySurfaceShape37.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape37.iog.og[0].gco";
connectAttr "groupParts51.og" "polySurfaceShape38.i";
connectAttr "groupId105.id" "polySurfaceShape38.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape38.iog.og[0].gco";
connectAttr "groupParts52.og" "polySurfaceShape39.i";
connectAttr "groupId106.id" "polySurfaceShape39.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape39.iog.og[0].gco";
connectAttr "groupParts53.og" "polySurfaceShape40.i";
connectAttr "groupId107.id" "polySurfaceShape40.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape40.iog.og[0].gco";
connectAttr "groupParts54.og" "polySurfaceShape41.i";
connectAttr "groupId108.id" "polySurfaceShape41.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape41.iog.og[0].gco";
connectAttr "groupParts55.og" "polySurfaceShape42.i";
connectAttr "groupId109.id" "polySurfaceShape42.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape42.iog.og[0].gco";
connectAttr "groupParts56.og" "polySurfaceShape43.i";
connectAttr "groupId110.id" "polySurfaceShape43.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape43.iog.og[0].gco";
connectAttr "groupParts57.og" "polySurfaceShape44.i";
connectAttr "groupId111.id" "polySurfaceShape44.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape44.iog.og[0].gco";
connectAttr "groupParts58.og" "polySurfaceShape45.i";
connectAttr "groupId112.id" "polySurfaceShape45.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape45.iog.og[0].gco";
connectAttr "groupParts59.og" "polySurfaceShape46.i";
connectAttr "groupId113.id" "polySurfaceShape46.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape46.iog.og[0].gco";
connectAttr "groupParts60.og" "polySurfaceShape47.i";
connectAttr "groupId114.id" "polySurfaceShape47.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape47.iog.og[0].gco";
connectAttr "groupParts61.og" "polySurfaceShape48.i";
connectAttr "groupId115.id" "polySurfaceShape48.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape48.iog.og[0].gco";
connectAttr "groupParts62.og" "polySurfaceShape49.i";
connectAttr "groupId116.id" "polySurfaceShape49.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape49.iog.og[0].gco";
connectAttr "groupParts63.og" "polySurfaceShape50.i";
connectAttr "groupId117.id" "polySurfaceShape50.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape50.iog.og[0].gco";
connectAttr "groupParts64.og" "polySurfaceShape51.i";
connectAttr "groupId118.id" "polySurfaceShape51.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape51.iog.og[0].gco";
connectAttr "groupParts65.og" "polySurfaceShape52.i";
connectAttr "groupId119.id" "polySurfaceShape52.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape52.iog.og[0].gco";
connectAttr "groupParts66.og" "polySurfaceShape53.i";
connectAttr "groupId120.id" "polySurfaceShape53.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape53.iog.og[0].gco";
connectAttr "groupParts67.og" "polySurfaceShape54.i";
connectAttr "groupId121.id" "polySurfaceShape54.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape54.iog.og[0].gco";
connectAttr "groupParts68.og" "polySurfaceShape55.i";
connectAttr "groupId122.id" "polySurfaceShape55.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape55.iog.og[0].gco";
connectAttr "groupParts69.og" "polySurfaceShape56.i";
connectAttr "groupId123.id" "polySurfaceShape56.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape56.iog.og[0].gco";
connectAttr "groupParts70.og" "polySurfaceShape57.i";
connectAttr "groupId124.id" "polySurfaceShape57.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape57.iog.og[0].gco";
connectAttr "groupParts71.og" "polySurfaceShape58.i";
connectAttr "groupId125.id" "polySurfaceShape58.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape58.iog.og[0].gco";
connectAttr "groupParts72.og" "polySurfaceShape59.i";
connectAttr "groupId126.id" "polySurfaceShape59.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape59.iog.og[0].gco";
connectAttr "groupParts73.og" "polySurfaceShape60.i";
connectAttr "groupId127.id" "polySurfaceShape60.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurfaceShape60.iog.og[0].gco";
connectAttr "polySoftEdge4.out" "|polySurface25|transform55|polySurface20Shape.i"
		;
connectAttr "groupId103.id" "|polySurface25|transform55|polySurface20Shape.iog.og[0].gid"
		;
connectAttr "blinn1SG.mwc" "|polySurface25|transform55|polySurface20Shape.iog.og[0].gco"
		;
connectAttr "groupParts74.og" "polySurface40Shape.i";
connectAttr "groupId128.id" "polySurface40Shape.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurface40Shape.iog.og[0].gco";
connectAttr "groupParts75.og" "polySurface35Shape.i";
connectAttr "groupId129.id" "polySurface35Shape.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurface35Shape.iog.og[0].gco";
connectAttr "groupParts76.og" "polySurface39Shape.i";
connectAttr "groupId130.id" "polySurface39Shape.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurface39Shape.iog.og[0].gco";
connectAttr "groupParts77.og" "polySurface32Shape.i";
connectAttr "groupId131.id" "polySurface32Shape.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurface32Shape.iog.og[0].gco";
connectAttr "groupParts109.og" "polySurface49Shape.i";
connectAttr "groupId164.id" "polySurface49Shape.iog.og[0].gid";
connectAttr "blinn1SG.mwc" "polySurface49Shape.iog.og[0].gco";
connectAttr "groupParts110.og" "polySurface56Shape.i";
connectAttr "groupId165.id" "polySurface56Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface56Shape.iog.og[0].gco";
connectAttr "groupParts111.og" "polySurface51Shape.i";
connectAttr "groupId166.id" "polySurface51Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface51Shape.iog.og[0].gco";
connectAttr "groupParts112.og" "polySurface62Shape.i";
connectAttr "groupId167.id" "polySurface62Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface62Shape.iog.og[0].gco";
connectAttr "groupParts113.og" "polySurface69Shape.i";
connectAttr "groupId168.id" "polySurface69Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface69Shape.iog.og[0].gco";
connectAttr "groupParts114.og" "polySurface70Shape.i";
connectAttr "groupId169.id" "polySurface70Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface70Shape.iog.og[0].gco";
connectAttr "groupParts115.og" "polySurface72Shape.i";
connectAttr "groupId170.id" "polySurface72Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface72Shape.iog.og[0].gco";
connectAttr "groupParts116.og" "polySurface78Shape.i";
connectAttr "groupId171.id" "polySurface78Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface78Shape.iog.og[0].gco";
connectAttr "groupParts134.og" "polySurface84Shape.i";
connectAttr "groupId190.id" "polySurface84Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurface84Shape.iog.og[0].gco";
connectAttr "groupParts135.og" "polySurface89Shape.i";
connectAttr "groupId191.id" "polySurface89Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurface89Shape.iog.og[0].gco";
connectAttr "groupParts136.og" "polySurface88Shape.i";
connectAttr "groupId192.id" "polySurface88Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurface88Shape.iog.og[0].gco";
connectAttr "groupParts137.og" "polySurface81Shape.i";
connectAttr "groupId193.id" "polySurface81Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurface81Shape.iog.og[0].gco";
connectAttr "groupParts138.og" "polySurface92Shape.i";
connectAttr "groupId194.id" "polySurface92Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurface92Shape.iog.og[0].gco";
connectAttr "groupParts139.og" "polySurface95Shape.i";
connectAttr "groupId195.id" "polySurface95Shape.iog.og[0].gid";
connectAttr "blinn3SG.mwc" "polySurface95Shape.iog.og[0].gco";
connectAttr "groupParts140.og" "polySurface64Shape.i";
connectAttr "groupId196.id" "polySurface64Shape.iog.og[0].gid";
connectAttr "blinn2SG.mwc" "polySurface64Shape.iog.og[0].gco";
relationship "link" ":lightLinker1" "Box063MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box004MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box085MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box061MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box054MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box007MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "initialShadingGroup_pCube13MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box006MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box100MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box086MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box055MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box062MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box002MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box053MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box001MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box101MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box087MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box099MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box005MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box058MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box003MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "Box057MatSG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "blinn1SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "blinn2SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "blinn3SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box063MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box004MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box085MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box061MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box054MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box007MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "initialShadingGroup_pCube13MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box006MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box100MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box086MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box055MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box062MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box002MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box053MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box001MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box101MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box087MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box099MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box005MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box058MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box003MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "Box057MatSG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "blinn1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "blinn2SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "blinn3SG.message" ":defaultLightSet.message";
connectAttr "Box063Mat.oc" "Box063MatSG.ss";
connectAttr "|Script|Box|Box_1|transform28|Box_1Shape.iog.og[0]" "Box063MatSG.dsm"
		 -na;
connectAttr "|Script|Box|Box_1|transform28|Box_1Shape.ciog.cog[0]" "Box063MatSG.dsm"
		 -na;
connectAttr "Box_37Shape.iog.og[0]" "Box063MatSG.dsm" -na;
connectAttr "Box_37Shape.ciog.cog[0]" "Box063MatSG.dsm" -na;
connectAttr "Box_33Shape.iog.og[0]" "Box063MatSG.dsm" -na;
connectAttr "Box_33Shape.ciog.cog[0]" "Box063MatSG.dsm" -na;
connectAttr "Box_17Shape.iog.og[0]" "Box063MatSG.dsm" -na;
connectAttr "Box_17Shape.ciog.cog[0]" "Box063MatSG.dsm" -na;
connectAttr "groupId60.msg" "Box063MatSG.gn" -na;
connectAttr "groupId61.msg" "Box063MatSG.gn" -na;
connectAttr "groupId68.msg" "Box063MatSG.gn" -na;
connectAttr "groupId69.msg" "Box063MatSG.gn" -na;
connectAttr "groupId72.msg" "Box063MatSG.gn" -na;
connectAttr "groupId73.msg" "Box063MatSG.gn" -na;
connectAttr "groupId74.msg" "Box063MatSG.gn" -na;
connectAttr "groupId75.msg" "Box063MatSG.gn" -na;
connectAttr "Box063MatSG.msg" "materialInfo0.sg";
connectAttr "Box063Mat.msg" "materialInfo0.m";
connectAttr "Box004Mat.oc" "Box004MatSG.ss";
connectAttr "Box_3Shape.iog.og[0]" "Box004MatSG.dsm" -na;
connectAttr "Box_3Shape.ciog.cog[0]" "Box004MatSG.dsm" -na;
connectAttr "groupId35.msg" "Box004MatSG.gn" -na;
connectAttr "groupId36.msg" "Box004MatSG.gn" -na;
connectAttr "Box004MatSG.msg" "materialInfo1.sg";
connectAttr "Box004Mat.msg" "materialInfo1.m";
connectAttr "Box085Mat.oc" "Box085MatSG.ss";
connectAttr "|Script|Box_4|Box_5|transform11|Box_5Shape.iog.og[0]" "Box085MatSG.dsm"
		 -na;
connectAttr "|Script|Box_4|Box_5|transform11|Box_5Shape.ciog.cog[0]" "Box085MatSG.dsm"
		 -na;
connectAttr "groupId1.msg" "Box085MatSG.gn" -na;
connectAttr "groupId2.msg" "Box085MatSG.gn" -na;
connectAttr "Box085MatSG.msg" "materialInfo2.sg";
connectAttr "Box085Mat.msg" "materialInfo2.m";
connectAttr "Box061Mat.oc" "Box061MatSG.ss";
connectAttr "|Script|Box_6|Box_7|transform20|Box_7Shape.iog.og[0]" "Box061MatSG.dsm"
		 -na;
connectAttr "|Script|Box_6|Box_7|transform20|Box_7Shape.ciog.cog[0]" "Box061MatSG.dsm"
		 -na;
connectAttr "groupId33.msg" "Box061MatSG.gn" -na;
connectAttr "groupId34.msg" "Box061MatSG.gn" -na;
connectAttr "Box061MatSG.msg" "materialInfo3.sg";
connectAttr "Box061Mat.msg" "materialInfo3.m";
connectAttr "Box054Mat.oc" "Box054MatSG.ss";
connectAttr "Box_9Shape.iog.og[0]" "Box054MatSG.dsm" -na;
connectAttr "Box_9Shape.ciog.cog[0]" "Box054MatSG.dsm" -na;
connectAttr "groupId3.msg" "Box054MatSG.gn" -na;
connectAttr "groupId4.msg" "Box054MatSG.gn" -na;
connectAttr "Box054MatSG.msg" "materialInfo4.sg";
connectAttr "Box054Mat.msg" "materialInfo4.m";
connectAttr "Box007Mat.oc" "Box007MatSG.ss";
connectAttr "Box_11Shape.iog.og[0]" "Box007MatSG.dsm" -na;
connectAttr "Box_11Shape.ciog.cog[0]" "Box007MatSG.dsm" -na;
connectAttr "groupId17.msg" "Box007MatSG.gn" -na;
connectAttr "groupId18.msg" "Box007MatSG.gn" -na;
connectAttr "Box007MatSG.msg" "materialInfo5.sg";
connectAttr "Box007Mat.msg" "materialInfo5.m";
connectAttr "initialShadingGroup_pCube13Mat.oc" "initialShadingGroup_pCube13MatSG.ss"
		;
connectAttr "initialShadingGroup_pCubeShape.iog.og[0]" "initialShadingGroup_pCube13MatSG.dsm"
		 -na;
connectAttr "initialShadingGroup_pCubeShape.ciog.cog[0]" "initialShadingGroup_pCube13MatSG.dsm"
		 -na;
connectAttr "initialShadingGroup_pCube_1Shape.iog.og[0]" "initialShadingGroup_pCube13MatSG.dsm"
		 -na;
connectAttr "initialShadingGroup_pCube_1Shape.ciog.cog[0]" "initialShadingGroup_pCube13MatSG.dsm"
		 -na;
connectAttr "groupId66.msg" "initialShadingGroup_pCube13MatSG.gn" -na;
connectAttr "groupId67.msg" "initialShadingGroup_pCube13MatSG.gn" -na;
connectAttr "groupId70.msg" "initialShadingGroup_pCube13MatSG.gn" -na;
connectAttr "groupId71.msg" "initialShadingGroup_pCube13MatSG.gn" -na;
connectAttr "initialShadingGroup_pCube13MatSG.msg" "materialInfo6.sg";
connectAttr "initialShadingGroup_pCube13Mat.msg" "materialInfo6.m";
connectAttr "Box006Mat.oc" "Box006MatSG.ss";
connectAttr "Box_13Shape.iog.og[0]" "Box006MatSG.dsm" -na;
connectAttr "Box_13Shape.ciog.cog[0]" "Box006MatSG.dsm" -na;
connectAttr "groupId15.msg" "Box006MatSG.gn" -na;
connectAttr "groupId16.msg" "Box006MatSG.gn" -na;
connectAttr "Box006MatSG.msg" "materialInfo7.sg";
connectAttr "Box006Mat.msg" "materialInfo7.m";
connectAttr "Box100Mat.oc" "Box100MatSG.ss";
connectAttr "Box_15Shape.iog.og[0]" "Box100MatSG.dsm" -na;
connectAttr "Box_15Shape.ciog.cog[0]" "Box100MatSG.dsm" -na;
connectAttr "groupId49.msg" "Box100MatSG.gn" -na;
connectAttr "groupId50.msg" "Box100MatSG.gn" -na;
connectAttr "Box100MatSG.msg" "materialInfo8.sg";
connectAttr "Box100Mat.msg" "materialInfo8.m";
connectAttr "Box086Mat.oc" "Box086MatSG.ss";
connectAttr "Box_19Shape.iog.og[0]" "Box086MatSG.dsm" -na;
connectAttr "Box_19Shape.ciog.cog[0]" "Box086MatSG.dsm" -na;
connectAttr "Box_31Shape.iog.og[0]" "Box086MatSG.dsm" -na;
connectAttr "Box_31Shape.ciog.cog[0]" "Box086MatSG.dsm" -na;
connectAttr "groupId21.msg" "Box086MatSG.gn" -na;
connectAttr "groupId22.msg" "Box086MatSG.gn" -na;
connectAttr "groupId47.msg" "Box086MatSG.gn" -na;
connectAttr "groupId48.msg" "Box086MatSG.gn" -na;
connectAttr "Box086MatSG.msg" "materialInfo9.sg";
connectAttr "Box086Mat.msg" "materialInfo9.m";
connectAttr "Box055Mat.oc" "Box055MatSG.ss";
connectAttr "Box_21Shape.iog.og[0]" "Box055MatSG.dsm" -na;
connectAttr "Box_21Shape.ciog.cog[0]" "Box055MatSG.dsm" -na;
connectAttr "groupId7.msg" "Box055MatSG.gn" -na;
connectAttr "groupId8.msg" "Box055MatSG.gn" -na;
connectAttr "Box055MatSG.msg" "materialInfo10.sg";
connectAttr "Box055Mat.msg" "materialInfo10.m";
connectAttr "Box062Mat.oc" "Box062MatSG.ss";
connectAttr "Box_23Shape.iog.og[0]" "Box062MatSG.dsm" -na;
connectAttr "Box_23Shape.ciog.cog[0]" "Box062MatSG.dsm" -na;
connectAttr "groupId37.msg" "Box062MatSG.gn" -na;
connectAttr "groupId38.msg" "Box062MatSG.gn" -na;
connectAttr "Box062MatSG.msg" "materialInfo11.sg";
connectAttr "Box062Mat.msg" "materialInfo11.m";
connectAttr "Box002Mat.oc" "Box002MatSG.ss";
connectAttr "Box_25Shape.iog.og[0]" "Box002MatSG.dsm" -na;
connectAttr "Box_25Shape.ciog.cog[0]" "Box002MatSG.dsm" -na;
connectAttr "groupId64.msg" "Box002MatSG.gn" -na;
connectAttr "groupId65.msg" "Box002MatSG.gn" -na;
connectAttr "Box002MatSG.msg" "materialInfo12.sg";
connectAttr "Box002Mat.msg" "materialInfo12.m";
connectAttr "Box053Mat.oc" "Box053MatSG.ss";
connectAttr "Box_27Shape.iog.og[0]" "Box053MatSG.dsm" -na;
connectAttr "Box_27Shape.ciog.cog[0]" "Box053MatSG.dsm" -na;
connectAttr "groupId5.msg" "Box053MatSG.gn" -na;
connectAttr "groupId6.msg" "Box053MatSG.gn" -na;
connectAttr "Box053MatSG.msg" "materialInfo13.sg";
connectAttr "Box053Mat.msg" "materialInfo13.m";
connectAttr "Box001Mat.oc" "Box001MatSG.ss";
connectAttr "Box_29Shape.iog.og[0]" "Box001MatSG.dsm" -na;
connectAttr "Box_29Shape.ciog.cog[0]" "Box001MatSG.dsm" -na;
connectAttr "groupId62.msg" "Box001MatSG.gn" -na;
connectAttr "groupId63.msg" "Box001MatSG.gn" -na;
connectAttr "Box001MatSG.msg" "materialInfo14.sg";
connectAttr "Box001Mat.msg" "materialInfo14.m";
connectAttr "Box101Mat.oc" "Box101MatSG.ss";
connectAttr "Box_35Shape.iog.og[0]" "Box101MatSG.dsm" -na;
connectAttr "Box_35Shape.ciog.cog[0]" "Box101MatSG.dsm" -na;
connectAttr "groupId45.msg" "Box101MatSG.gn" -na;
connectAttr "groupId46.msg" "Box101MatSG.gn" -na;
connectAttr "Box101MatSG.msg" "materialInfo15.sg";
connectAttr "Box101Mat.msg" "materialInfo15.m";
connectAttr "Box087Mat.oc" "Box087MatSG.ss";
connectAttr "Box_39Shape.iog.og[0]" "Box087MatSG.dsm" -na;
connectAttr "Box_39Shape.ciog.cog[0]" "Box087MatSG.dsm" -na;
connectAttr "groupId43.msg" "Box087MatSG.gn" -na;
connectAttr "groupId44.msg" "Box087MatSG.gn" -na;
connectAttr "Box087MatSG.msg" "materialInfo16.sg";
connectAttr "Box087Mat.msg" "materialInfo16.m";
connectAttr "Box099Mat.oc" "Box099MatSG.ss";
connectAttr "Box_41Shape.iog.og[0]" "Box099MatSG.dsm" -na;
connectAttr "Box_41Shape.ciog.cog[0]" "Box099MatSG.dsm" -na;
connectAttr "groupId11.msg" "Box099MatSG.gn" -na;
connectAttr "groupId12.msg" "Box099MatSG.gn" -na;
connectAttr "Box099MatSG.msg" "materialInfo17.sg";
connectAttr "Box099Mat.msg" "materialInfo17.m";
connectAttr "Box005Mat.oc" "Box005MatSG.ss";
connectAttr "Box_43Shape.iog.og[0]" "Box005MatSG.dsm" -na;
connectAttr "Box_43Shape.ciog.cog[0]" "Box005MatSG.dsm" -na;
connectAttr "groupId39.msg" "Box005MatSG.gn" -na;
connectAttr "groupId40.msg" "Box005MatSG.gn" -na;
connectAttr "Box005MatSG.msg" "materialInfo18.sg";
connectAttr "Box005Mat.msg" "materialInfo18.m";
connectAttr "Box058Mat.oc" "Box058MatSG.ss";
connectAttr "Box_45Shape.iog.og[0]" "Box058MatSG.dsm" -na;
connectAttr "Box_45Shape.ciog.cog[0]" "Box058MatSG.dsm" -na;
connectAttr "Box_51Shape.iog.og[0]" "Box058MatSG.dsm" -na;
connectAttr "Box_51Shape.ciog.cog[0]" "Box058MatSG.dsm" -na;
connectAttr "groupId9.msg" "Box058MatSG.gn" -na;
connectAttr "groupId10.msg" "Box058MatSG.gn" -na;
connectAttr "groupId13.msg" "Box058MatSG.gn" -na;
connectAttr "groupId14.msg" "Box058MatSG.gn" -na;
connectAttr "Box058MatSG.msg" "materialInfo19.sg";
connectAttr "Box058Mat.msg" "materialInfo19.m";
connectAttr "Box003Mat.oc" "Box003MatSG.ss";
connectAttr "Box_47Shape.iog.og[0]" "Box003MatSG.dsm" -na;
connectAttr "Box_47Shape.ciog.cog[0]" "Box003MatSG.dsm" -na;
connectAttr "groupId41.msg" "Box003MatSG.gn" -na;
connectAttr "groupId42.msg" "Box003MatSG.gn" -na;
connectAttr "Box003MatSG.msg" "materialInfo20.sg";
connectAttr "Box003Mat.msg" "materialInfo20.m";
connectAttr "Box057Mat.oc" "Box057MatSG.ss";
connectAttr "Box_49Shape.iog.og[0]" "Box057MatSG.dsm" -na;
connectAttr "Box_49Shape.ciog.cog[0]" "Box057MatSG.dsm" -na;
connectAttr "groupId19.msg" "Box057MatSG.gn" -na;
connectAttr "groupId20.msg" "Box057MatSG.gn" -na;
connectAttr "Box057MatSG.msg" "materialInfo21.sg";
connectAttr "Box057Mat.msg" "materialInfo21.m";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "polySurfaceShape1.o" "polyConnectComponents1.ip";
connectAttr "polyConnectComponents1.out" "polyBridgeEdge1.ip";
connectAttr "Box_35Shape.wm" "polyBridgeEdge1.mp";
connectAttr "polyBridgeEdge1.out" "polyExtrudeEdge1.ip";
connectAttr "Box_35Shape.wm" "polyExtrudeEdge1.mp";
connectAttr "polyExtrudeEdge1.out" "deleteComponent1.ig";
connectAttr "deleteComponent1.og" "deleteComponent2.ig";
connectAttr "deleteComponent2.og" "polyDelEdge1.ip";
connectAttr "polyDelEdge1.out" "polyDelEdge2.ip";
connectAttr "polyDelEdge2.out" "polyDelEdge3.ip";
connectAttr "polyDelEdge3.out" "polyDelEdge4.ip";
connectAttr "polyDelEdge4.out" "deleteComponent3.ig";
connectAttr "deleteComponent3.og" "deleteComponent4.ig";
connectAttr "deleteComponent4.og" "polyDelEdge5.ip";
connectAttr "polyDelEdge5.out" "deleteComponent5.ig";
connectAttr "polySurfaceShape2.o" "polyAutoProj1.ip";
connectAttr "|Script|Box_4|Box_5|transform11|Box_5Shape.wm" "polyAutoProj1.mp";
connectAttr "polySurfaceShape3.o" "polyAutoProj2.ip";
connectAttr "Box_9Shape.wm" "polyAutoProj2.mp";
connectAttr "polySurfaceShape4.o" "polyAutoProj3.ip";
connectAttr "Box_27Shape.wm" "polyAutoProj3.mp";
connectAttr "polySurfaceShape5.o" "polyAutoProj4.ip";
connectAttr "Box_21Shape.wm" "polyAutoProj4.mp";
connectAttr "polySurfaceShape6.o" "polyAutoProj5.ip";
connectAttr "Box_45Shape.wm" "polyAutoProj5.mp";
connectAttr "polySurfaceShape7.o" "polyAutoProj6.ip";
connectAttr "Box_41Shape.wm" "polyAutoProj6.mp";
connectAttr "polySurfaceShape8.o" "polyAutoProj7.ip";
connectAttr "Box_51Shape.wm" "polyAutoProj7.mp";
connectAttr "polySurfaceShape9.o" "polyAutoProj8.ip";
connectAttr "Box_13Shape.wm" "polyAutoProj8.mp";
connectAttr "polySurfaceShape10.o" "polyAutoProj9.ip";
connectAttr "Box_11Shape.wm" "polyAutoProj9.mp";
connectAttr "polySurfaceShape11.o" "polyAutoProj10.ip";
connectAttr "Box_49Shape.wm" "polyAutoProj10.mp";
connectAttr "polySurfaceShape12.o" "polyAutoProj11.ip";
connectAttr "Box_19Shape.wm" "polyAutoProj11.mp";
connectAttr "|Script|Box_4|Box_5|transform11|Box_5Shape.o" "polyUnite1.ip[0]";
connectAttr "Box_9Shape.o" "polyUnite1.ip[1]";
connectAttr "Box_27Shape.o" "polyUnite1.ip[2]";
connectAttr "Box_21Shape.o" "polyUnite1.ip[3]";
connectAttr "Box_45Shape.o" "polyUnite1.ip[4]";
connectAttr "Box_41Shape.o" "polyUnite1.ip[5]";
connectAttr "Box_51Shape.o" "polyUnite1.ip[6]";
connectAttr "Box_13Shape.o" "polyUnite1.ip[7]";
connectAttr "Box_11Shape.o" "polyUnite1.ip[8]";
connectAttr "Box_49Shape.o" "polyUnite1.ip[9]";
connectAttr "Box_19Shape.o" "polyUnite1.ip[10]";
connectAttr "|Script|Box_4|Box_5|transform11|Box_5Shape.wm" "polyUnite1.im[0]";
connectAttr "Box_9Shape.wm" "polyUnite1.im[1]";
connectAttr "Box_27Shape.wm" "polyUnite1.im[2]";
connectAttr "Box_21Shape.wm" "polyUnite1.im[3]";
connectAttr "Box_45Shape.wm" "polyUnite1.im[4]";
connectAttr "Box_41Shape.wm" "polyUnite1.im[5]";
connectAttr "Box_51Shape.wm" "polyUnite1.im[6]";
connectAttr "Box_13Shape.wm" "polyUnite1.im[7]";
connectAttr "Box_11Shape.wm" "polyUnite1.im[8]";
connectAttr "Box_49Shape.wm" "polyUnite1.im[9]";
connectAttr "Box_19Shape.wm" "polyUnite1.im[10]";
connectAttr "polyAutoProj1.out" "groupParts1.ig";
connectAttr "groupId1.id" "groupParts1.gi";
connectAttr "polyAutoProj2.out" "groupParts2.ig";
connectAttr "groupId3.id" "groupParts2.gi";
connectAttr "polyAutoProj3.out" "groupParts3.ig";
connectAttr "groupId5.id" "groupParts3.gi";
connectAttr "polyAutoProj4.out" "groupParts4.ig";
connectAttr "groupId7.id" "groupParts4.gi";
connectAttr "polyAutoProj5.out" "groupParts5.ig";
connectAttr "groupId9.id" "groupParts5.gi";
connectAttr "polyAutoProj6.out" "groupParts6.ig";
connectAttr "groupId11.id" "groupParts6.gi";
connectAttr "polyAutoProj7.out" "groupParts7.ig";
connectAttr "groupId13.id" "groupParts7.gi";
connectAttr "polyAutoProj8.out" "groupParts8.ig";
connectAttr "groupId15.id" "groupParts8.gi";
connectAttr "polyAutoProj9.out" "groupParts9.ig";
connectAttr "groupId17.id" "groupParts9.gi";
connectAttr "polyAutoProj10.out" "groupParts10.ig";
connectAttr "groupId19.id" "groupParts10.gi";
connectAttr "polyAutoProj11.out" "groupParts11.ig";
connectAttr "groupId21.id" "groupParts11.gi";
connectAttr "polyUnite1.out" "polyAutoProj12.ip";
connectAttr "|Box_5|transform29|Box_5Shape.wm" "polyAutoProj12.mp";
connectAttr "|Script|Box_6|Box_7|transform20|Box_7Shape.o" "polyUnite2.ip[0]";
connectAttr "Box_3Shape.o" "polyUnite2.ip[1]";
connectAttr "Box_23Shape.o" "polyUnite2.ip[2]";
connectAttr "Box_43Shape.o" "polyUnite2.ip[3]";
connectAttr "Box_47Shape.o" "polyUnite2.ip[4]";
connectAttr "Box_39Shape.o" "polyUnite2.ip[5]";
connectAttr "Box_35Shape.o" "polyUnite2.ip[6]";
connectAttr "Box_31Shape.o" "polyUnite2.ip[7]";
connectAttr "Box_15Shape.o" "polyUnite2.ip[8]";
connectAttr "|Script|Box_6|Box_7|transform20|Box_7Shape.wm" "polyUnite2.im[0]";
connectAttr "Box_3Shape.wm" "polyUnite2.im[1]";
connectAttr "Box_23Shape.wm" "polyUnite2.im[2]";
connectAttr "Box_43Shape.wm" "polyUnite2.im[3]";
connectAttr "Box_47Shape.wm" "polyUnite2.im[4]";
connectAttr "Box_39Shape.wm" "polyUnite2.im[5]";
connectAttr "Box_35Shape.wm" "polyUnite2.im[6]";
connectAttr "Box_31Shape.wm" "polyUnite2.im[7]";
connectAttr "Box_15Shape.wm" "polyUnite2.im[8]";
connectAttr "deleteComponent5.og" "groupParts22.ig";
connectAttr "groupId45.id" "groupParts22.gi";
connectAttr "polyUnite2.out" "polyAutoProj13.ip";
connectAttr "|Box_7|transform72|Box_7Shape.wm" "polyAutoProj13.mp";
connectAttr "polyAutoProj13.out" "polyTweakUV1.ip";
connectAttr "|Script|Box|Box_1|transform28|Box_1Shape.o" "polyUnite3.ip[0]";
connectAttr "Box_29Shape.o" "polyUnite3.ip[1]";
connectAttr "Box_25Shape.o" "polyUnite3.ip[2]";
connectAttr "initialShadingGroup_pCubeShape.o" "polyUnite3.ip[3]";
connectAttr "Box_37Shape.o" "polyUnite3.ip[4]";
connectAttr "initialShadingGroup_pCube_1Shape.o" "polyUnite3.ip[5]";
connectAttr "Box_33Shape.o" "polyUnite3.ip[6]";
connectAttr "Box_17Shape.o" "polyUnite3.ip[7]";
connectAttr "|Script|Box|Box_1|transform28|Box_1Shape.wm" "polyUnite3.im[0]";
connectAttr "Box_29Shape.wm" "polyUnite3.im[1]";
connectAttr "Box_25Shape.wm" "polyUnite3.im[2]";
connectAttr "initialShadingGroup_pCubeShape.wm" "polyUnite3.im[3]";
connectAttr "Box_37Shape.wm" "polyUnite3.im[4]";
connectAttr "initialShadingGroup_pCube_1Shape.wm" "polyUnite3.im[5]";
connectAttr "Box_33Shape.wm" "polyUnite3.im[6]";
connectAttr "Box_17Shape.wm" "polyUnite3.im[7]";
connectAttr "polyUnite3.out" "polyAutoProj14.ip";
connectAttr "|Box_1|transform101|Box_1Shape.wm" "polyAutoProj14.mp";
connectAttr "polyAutoProj14.out" "polyTweakUV2.ip";
connectAttr "ChannelCT2WindowDiffuse_1.oc" "CT2Window.c";
connectAttr "ChannelCT2WindowSpecular_1.oc" "CT2Window.sc";
connectAttr "CT2Window.oc" "blinn1SG.ss";
connectAttr "|Box_5|transform29|Box_5Shape.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "|Box_5|transform29|Box_5Shape.ciog.cog[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape13.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape14.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape15.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape16.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape17.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape18.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape19.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape20.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape21.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape22.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape23.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape24.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape25.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape26.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape27.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape28.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape29.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape30.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape31.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape32.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape33.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape34.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape35.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape36.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "|polySurface20|transform54|polySurface20Shape.iog.og[0]" "blinn1SG.dsm"
		 -na;
connectAttr "|polySurface25|transform55|polySurface20Shape.iog.og[0]" "blinn1SG.dsm"
		 -na;
connectAttr "polySurfaceShape37.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape38.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape39.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape40.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape41.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape42.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape43.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape44.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape45.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape46.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape47.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape48.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape49.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape50.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape51.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape52.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape53.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape54.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape55.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape56.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape57.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape58.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape59.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurfaceShape60.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurface40Shape.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurface35Shape.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurface39Shape.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurface32Shape.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "polySurface49Shape.iog.og[0]" "blinn1SG.dsm" -na;
connectAttr "groupId76.msg" "blinn1SG.gn" -na;
connectAttr "groupId77.msg" "blinn1SG.gn" -na;
connectAttr "groupId78.msg" "blinn1SG.gn" -na;
connectAttr "groupId79.msg" "blinn1SG.gn" -na;
connectAttr "groupId80.msg" "blinn1SG.gn" -na;
connectAttr "groupId81.msg" "blinn1SG.gn" -na;
connectAttr "groupId82.msg" "blinn1SG.gn" -na;
connectAttr "groupId83.msg" "blinn1SG.gn" -na;
connectAttr "groupId84.msg" "blinn1SG.gn" -na;
connectAttr "groupId85.msg" "blinn1SG.gn" -na;
connectAttr "groupId86.msg" "blinn1SG.gn" -na;
connectAttr "groupId87.msg" "blinn1SG.gn" -na;
connectAttr "groupId88.msg" "blinn1SG.gn" -na;
connectAttr "groupId89.msg" "blinn1SG.gn" -na;
connectAttr "groupId90.msg" "blinn1SG.gn" -na;
connectAttr "groupId91.msg" "blinn1SG.gn" -na;
connectAttr "groupId92.msg" "blinn1SG.gn" -na;
connectAttr "groupId93.msg" "blinn1SG.gn" -na;
connectAttr "groupId94.msg" "blinn1SG.gn" -na;
connectAttr "groupId95.msg" "blinn1SG.gn" -na;
connectAttr "groupId96.msg" "blinn1SG.gn" -na;
connectAttr "groupId97.msg" "blinn1SG.gn" -na;
connectAttr "groupId98.msg" "blinn1SG.gn" -na;
connectAttr "groupId99.msg" "blinn1SG.gn" -na;
connectAttr "groupId100.msg" "blinn1SG.gn" -na;
connectAttr "groupId101.msg" "blinn1SG.gn" -na;
connectAttr "groupId102.msg" "blinn1SG.gn" -na;
connectAttr "groupId103.msg" "blinn1SG.gn" -na;
connectAttr "groupId104.msg" "blinn1SG.gn" -na;
connectAttr "groupId105.msg" "blinn1SG.gn" -na;
connectAttr "groupId106.msg" "blinn1SG.gn" -na;
connectAttr "groupId107.msg" "blinn1SG.gn" -na;
connectAttr "groupId108.msg" "blinn1SG.gn" -na;
connectAttr "groupId109.msg" "blinn1SG.gn" -na;
connectAttr "groupId110.msg" "blinn1SG.gn" -na;
connectAttr "groupId111.msg" "blinn1SG.gn" -na;
connectAttr "groupId112.msg" "blinn1SG.gn" -na;
connectAttr "groupId113.msg" "blinn1SG.gn" -na;
connectAttr "groupId114.msg" "blinn1SG.gn" -na;
connectAttr "groupId115.msg" "blinn1SG.gn" -na;
connectAttr "groupId116.msg" "blinn1SG.gn" -na;
connectAttr "groupId117.msg" "blinn1SG.gn" -na;
connectAttr "groupId118.msg" "blinn1SG.gn" -na;
connectAttr "groupId119.msg" "blinn1SG.gn" -na;
connectAttr "groupId120.msg" "blinn1SG.gn" -na;
connectAttr "groupId121.msg" "blinn1SG.gn" -na;
connectAttr "groupId122.msg" "blinn1SG.gn" -na;
connectAttr "groupId123.msg" "blinn1SG.gn" -na;
connectAttr "groupId124.msg" "blinn1SG.gn" -na;
connectAttr "groupId125.msg" "blinn1SG.gn" -na;
connectAttr "groupId126.msg" "blinn1SG.gn" -na;
connectAttr "groupId127.msg" "blinn1SG.gn" -na;
connectAttr "groupId128.msg" "blinn1SG.gn" -na;
connectAttr "groupId129.msg" "blinn1SG.gn" -na;
connectAttr "groupId130.msg" "blinn1SG.gn" -na;
connectAttr "groupId131.msg" "blinn1SG.gn" -na;
connectAttr "groupId164.msg" "blinn1SG.gn" -na;
connectAttr "blinn1SG.msg" "materialInfo22.sg";
connectAttr "CT2Window.msg" "materialInfo22.m";
connectAttr "ChannelCT2WindowDiffuse_1.msg" "materialInfo22.t" -na;
connectAttr "ChannelCTMidDiffuse_1.oc" "CTMid.c";
connectAttr "ChannelCTMidSpecular_1.oc" "CTMid.sc";
connectAttr "CTMid.oc" "blinn2SG.ss";
connectAttr "|Box_7|transform72|Box_7Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "|Box_7|transform72|Box_7Shape.ciog.cog[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape61.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape62.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape63.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape64.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape65.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape66.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape67.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape68.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape69.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape70.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape71.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape72.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape73.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape74.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape75.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape76.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape77.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape78.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape79.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape80.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape81.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape82.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape83.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape84.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape85.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape86.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape87.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape88.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape89.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurfaceShape90.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface56Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface51Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface62Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface69Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface70Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface72Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface78Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "polySurface64Shape.iog.og[0]" "blinn2SG.dsm" -na;
connectAttr "groupId132.msg" "blinn2SG.gn" -na;
connectAttr "groupId133.msg" "blinn2SG.gn" -na;
connectAttr "groupId134.msg" "blinn2SG.gn" -na;
connectAttr "groupId135.msg" "blinn2SG.gn" -na;
connectAttr "groupId136.msg" "blinn2SG.gn" -na;
connectAttr "groupId137.msg" "blinn2SG.gn" -na;
connectAttr "groupId138.msg" "blinn2SG.gn" -na;
connectAttr "groupId139.msg" "blinn2SG.gn" -na;
connectAttr "groupId140.msg" "blinn2SG.gn" -na;
connectAttr "groupId141.msg" "blinn2SG.gn" -na;
connectAttr "groupId142.msg" "blinn2SG.gn" -na;
connectAttr "groupId143.msg" "blinn2SG.gn" -na;
connectAttr "groupId144.msg" "blinn2SG.gn" -na;
connectAttr "groupId145.msg" "blinn2SG.gn" -na;
connectAttr "groupId146.msg" "blinn2SG.gn" -na;
connectAttr "groupId147.msg" "blinn2SG.gn" -na;
connectAttr "groupId148.msg" "blinn2SG.gn" -na;
connectAttr "groupId149.msg" "blinn2SG.gn" -na;
connectAttr "groupId150.msg" "blinn2SG.gn" -na;
connectAttr "groupId151.msg" "blinn2SG.gn" -na;
connectAttr "groupId152.msg" "blinn2SG.gn" -na;
connectAttr "groupId153.msg" "blinn2SG.gn" -na;
connectAttr "groupId154.msg" "blinn2SG.gn" -na;
connectAttr "groupId155.msg" "blinn2SG.gn" -na;
connectAttr "groupId156.msg" "blinn2SG.gn" -na;
connectAttr "groupId157.msg" "blinn2SG.gn" -na;
connectAttr "groupId158.msg" "blinn2SG.gn" -na;
connectAttr "groupId159.msg" "blinn2SG.gn" -na;
connectAttr "groupId160.msg" "blinn2SG.gn" -na;
connectAttr "groupId161.msg" "blinn2SG.gn" -na;
connectAttr "groupId162.msg" "blinn2SG.gn" -na;
connectAttr "groupId163.msg" "blinn2SG.gn" -na;
connectAttr "groupId165.msg" "blinn2SG.gn" -na;
connectAttr "groupId166.msg" "blinn2SG.gn" -na;
connectAttr "groupId167.msg" "blinn2SG.gn" -na;
connectAttr "groupId168.msg" "blinn2SG.gn" -na;
connectAttr "groupId169.msg" "blinn2SG.gn" -na;
connectAttr "groupId170.msg" "blinn2SG.gn" -na;
connectAttr "groupId171.msg" "blinn2SG.gn" -na;
connectAttr "groupId196.msg" "blinn2SG.gn" -na;
connectAttr "blinn2SG.msg" "materialInfo23.sg";
connectAttr "CTMid.msg" "materialInfo23.m";
connectAttr "ChannelCTMidDiffuse_1.msg" "materialInfo23.t" -na;
connectAttr "ChannelCT2ADiffuse_1.oc" "CT2A.c";
connectAttr "ChannelCT2ASpecular_1.oc" "CT2A.sc";
connectAttr "CT2A.oc" "blinn3SG.ss";
connectAttr "|Box_1|transform101|Box_1Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "|Box_1|transform101|Box_1Shape.ciog.cog[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape91.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape92.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape93.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape94.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape95.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape96.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape97.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape98.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape99.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape100.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape101.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape102.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape103.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape104.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape105.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurfaceShape106.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurface84Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurface89Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurface88Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurface81Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurface92Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "polySurface95Shape.iog.og[0]" "blinn3SG.dsm" -na;
connectAttr "groupId172.msg" "blinn3SG.gn" -na;
connectAttr "groupId173.msg" "blinn3SG.gn" -na;
connectAttr "groupId174.msg" "blinn3SG.gn" -na;
connectAttr "groupId175.msg" "blinn3SG.gn" -na;
connectAttr "groupId176.msg" "blinn3SG.gn" -na;
connectAttr "groupId177.msg" "blinn3SG.gn" -na;
connectAttr "groupId178.msg" "blinn3SG.gn" -na;
connectAttr "groupId179.msg" "blinn3SG.gn" -na;
connectAttr "groupId180.msg" "blinn3SG.gn" -na;
connectAttr "groupId181.msg" "blinn3SG.gn" -na;
connectAttr "groupId182.msg" "blinn3SG.gn" -na;
connectAttr "groupId183.msg" "blinn3SG.gn" -na;
connectAttr "groupId184.msg" "blinn3SG.gn" -na;
connectAttr "groupId185.msg" "blinn3SG.gn" -na;
connectAttr "groupId186.msg" "blinn3SG.gn" -na;
connectAttr "groupId187.msg" "blinn3SG.gn" -na;
connectAttr "groupId188.msg" "blinn3SG.gn" -na;
connectAttr "groupId189.msg" "blinn3SG.gn" -na;
connectAttr "groupId190.msg" "blinn3SG.gn" -na;
connectAttr "groupId191.msg" "blinn3SG.gn" -na;
connectAttr "groupId192.msg" "blinn3SG.gn" -na;
connectAttr "groupId193.msg" "blinn3SG.gn" -na;
connectAttr "groupId194.msg" "blinn3SG.gn" -na;
connectAttr "groupId195.msg" "blinn3SG.gn" -na;
connectAttr "blinn3SG.msg" "materialInfo24.sg";
connectAttr "CT2A.msg" "materialInfo24.m";
connectAttr "ChannelCT2ADiffuse_1.msg" "materialInfo24.t" -na;
connectAttr "polyTweakUV1.out" "polyAutoProj15.ip";
connectAttr "|Box_7|transform72|Box_7Shape.wm" "polyAutoProj15.mp";
connectAttr "polyAutoProj15.out" "deleteComponent6.ig";
connectAttr "deleteComponent6.og" "deleteComponent7.ig";
connectAttr "deleteComponent7.og" "polyMergeVert1.ip";
connectAttr "|Box_7|transform72|Box_7Shape.wm" "polyMergeVert1.mp";
connectAttr "polyMergeVert1.out" "polyAutoProj16.ip";
connectAttr "|Box_7|transform72|Box_7Shape.wm" "polyAutoProj16.mp";
connectAttr "|Box_5|transform29|Box_5Shape.o" "polySeparate1.ip";
connectAttr "polyAutoProj12.out" "groupParts23.ig";
connectAttr "groupId76.id" "groupParts23.gi";
connectAttr "polySeparate1.out[0]" "groupParts24.ig";
connectAttr "groupId78.id" "groupParts24.gi";
connectAttr "polySeparate1.out[1]" "groupParts25.ig";
connectAttr "groupId79.id" "groupParts25.gi";
connectAttr "polySeparate1.out[2]" "groupParts26.ig";
connectAttr "groupId80.id" "groupParts26.gi";
connectAttr "polySeparate1.out[3]" "groupParts27.ig";
connectAttr "groupId81.id" "groupParts27.gi";
connectAttr "polySeparate1.out[4]" "groupParts28.ig";
connectAttr "groupId82.id" "groupParts28.gi";
connectAttr "polySeparate1.out[5]" "groupParts29.ig";
connectAttr "groupId83.id" "groupParts29.gi";
connectAttr "polySeparate1.out[6]" "groupParts30.ig";
connectAttr "groupId84.id" "groupParts30.gi";
connectAttr "polySeparate1.out[7]" "groupParts31.ig";
connectAttr "groupId85.id" "groupParts31.gi";
connectAttr "polySeparate1.out[8]" "groupParts32.ig";
connectAttr "groupId86.id" "groupParts32.gi";
connectAttr "polySeparate1.out[9]" "groupParts33.ig";
connectAttr "groupId87.id" "groupParts33.gi";
connectAttr "polySeparate1.out[10]" "groupParts34.ig";
connectAttr "groupId88.id" "groupParts34.gi";
connectAttr "polySeparate1.out[11]" "groupParts35.ig";
connectAttr "groupId89.id" "groupParts35.gi";
connectAttr "polySeparate1.out[12]" "groupParts36.ig";
connectAttr "groupId90.id" "groupParts36.gi";
connectAttr "polySeparate1.out[13]" "groupParts37.ig";
connectAttr "groupId91.id" "groupParts37.gi";
connectAttr "polySeparate1.out[14]" "groupParts38.ig";
connectAttr "groupId92.id" "groupParts38.gi";
connectAttr "polySeparate1.out[15]" "groupParts39.ig";
connectAttr "groupId93.id" "groupParts39.gi";
connectAttr "polySeparate1.out[16]" "groupParts40.ig";
connectAttr "groupId94.id" "groupParts40.gi";
connectAttr "polySeparate1.out[17]" "groupParts41.ig";
connectAttr "groupId95.id" "groupParts41.gi";
connectAttr "polySeparate1.out[18]" "groupParts42.ig";
connectAttr "groupId96.id" "groupParts42.gi";
connectAttr "polySeparate1.out[19]" "groupParts43.ig";
connectAttr "groupId97.id" "groupParts43.gi";
connectAttr "polySeparate1.out[20]" "groupParts44.ig";
connectAttr "groupId98.id" "groupParts44.gi";
connectAttr "polySeparate1.out[21]" "groupParts45.ig";
connectAttr "groupId99.id" "groupParts45.gi";
connectAttr "polySeparate1.out[22]" "groupParts46.ig";
connectAttr "groupId100.id" "groupParts46.gi";
connectAttr "polySeparate1.out[23]" "groupParts47.ig";
connectAttr "groupId101.id" "groupParts47.gi";
connectAttr "polySurfaceShape32.o" "polyUnite4.ip[0]";
connectAttr "polySurfaceShape19.o" "polyUnite4.ip[1]";
connectAttr "polySurfaceShape31.o" "polyUnite4.ip[2]";
connectAttr "polySurfaceShape32.wm" "polyUnite4.im[0]";
connectAttr "polySurfaceShape19.wm" "polyUnite4.im[1]";
connectAttr "polySurfaceShape31.wm" "polyUnite4.im[2]";
connectAttr "polyUnite4.out" "groupParts48.ig";
connectAttr "groupId102.id" "groupParts48.gi";
connectAttr "groupParts48.og" "deleteComponent8.ig";
connectAttr "deleteComponent8.og" "deleteComponent9.ig";
connectAttr "deleteComponent9.og" "deleteComponent10.ig";
connectAttr "deleteComponent10.og" "polySplitRing1.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polySplitRing1.mp"
		;
connectAttr "polySplitRing1.out" "polySplitRing2.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polySplitRing2.mp"
		;
connectAttr "polySplitRing2.out" "polySplitRing3.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polySplitRing3.mp"
		;
connectAttr "polyTweak1.out" "polyExtrudeFace1.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polyExtrudeFace1.mp"
		;
connectAttr "polySplitRing3.out" "polyTweak1.ip";
connectAttr "polyExtrudeFace1.out" "polyBevel1.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polyBevel1.mp";
connectAttr "polyTweak2.out" "polyBevel2.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polyBevel2.mp";
connectAttr "polyBevel1.out" "polyTweak2.ip";
connectAttr "polyTweak3.out" "polyBevel3.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polyBevel3.mp";
connectAttr "polyBevel2.out" "polyTweak3.ip";
connectAttr "polyBevel3.out" "polyTweak4.ip";
connectAttr "polyTweak4.out" "deleteComponent11.ig";
connectAttr "deleteComponent11.og" "deleteComponent12.ig";
connectAttr "deleteComponent12.og" "deleteComponent13.ig";
connectAttr "deleteComponent13.og" "deleteComponent14.ig";
connectAttr "deleteComponent14.og" "deleteComponent15.ig";
connectAttr "deleteComponent15.og" "polyTriangulate1.ip";
connectAttr "polyTriangulate1.out" "polyQuad1.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polyQuad1.mp";
connectAttr "polyQuad1.out" "polyTriangulate2.ip";
connectAttr "|polySurface20|transform54|polySurface20Shape.o" "polyUnite5.ip[0]"
		;
connectAttr "polySurfaceShape28.o" "polyUnite5.ip[1]";
connectAttr "polySurfaceShape27.o" "polyUnite5.ip[2]";
connectAttr "polySurfaceShape26.o" "polyUnite5.ip[3]";
connectAttr "polySurfaceShape30.o" "polyUnite5.ip[4]";
connectAttr "polySurfaceShape29.o" "polyUnite5.ip[5]";
connectAttr "polySurfaceShape22.o" "polyUnite5.ip[6]";
connectAttr "polySurfaceShape21.o" "polyUnite5.ip[7]";
connectAttr "polySurfaceShape20.o" "polyUnite5.ip[8]";
connectAttr "polySurfaceShape25.o" "polyUnite5.ip[9]";
connectAttr "polySurfaceShape24.o" "polyUnite5.ip[10]";
connectAttr "polySurfaceShape23.o" "polyUnite5.ip[11]";
connectAttr "polySurfaceShape18.o" "polyUnite5.ip[12]";
connectAttr "polySurfaceShape17.o" "polyUnite5.ip[13]";
connectAttr "polySurfaceShape16.o" "polyUnite5.ip[14]";
connectAttr "polySurfaceShape15.o" "polyUnite5.ip[15]";
connectAttr "polySurfaceShape14.o" "polyUnite5.ip[16]";
connectAttr "polySurfaceShape13.o" "polyUnite5.ip[17]";
connectAttr "polySurfaceShape34.o" "polyUnite5.ip[18]";
connectAttr "polySurfaceShape33.o" "polyUnite5.ip[19]";
connectAttr "polySurfaceShape36.o" "polyUnite5.ip[20]";
connectAttr "polySurfaceShape35.o" "polyUnite5.ip[21]";
connectAttr "|polySurface20|transform54|polySurface20Shape.wm" "polyUnite5.im[0]"
		;
connectAttr "polySurfaceShape28.wm" "polyUnite5.im[1]";
connectAttr "polySurfaceShape27.wm" "polyUnite5.im[2]";
connectAttr "polySurfaceShape26.wm" "polyUnite5.im[3]";
connectAttr "polySurfaceShape30.wm" "polyUnite5.im[4]";
connectAttr "polySurfaceShape29.wm" "polyUnite5.im[5]";
connectAttr "polySurfaceShape22.wm" "polyUnite5.im[6]";
connectAttr "polySurfaceShape21.wm" "polyUnite5.im[7]";
connectAttr "polySurfaceShape20.wm" "polyUnite5.im[8]";
connectAttr "polySurfaceShape25.wm" "polyUnite5.im[9]";
connectAttr "polySurfaceShape24.wm" "polyUnite5.im[10]";
connectAttr "polySurfaceShape23.wm" "polyUnite5.im[11]";
connectAttr "polySurfaceShape18.wm" "polyUnite5.im[12]";
connectAttr "polySurfaceShape17.wm" "polyUnite5.im[13]";
connectAttr "polySurfaceShape16.wm" "polyUnite5.im[14]";
connectAttr "polySurfaceShape15.wm" "polyUnite5.im[15]";
connectAttr "polySurfaceShape14.wm" "polyUnite5.im[16]";
connectAttr "polySurfaceShape13.wm" "polyUnite5.im[17]";
connectAttr "polySurfaceShape34.wm" "polyUnite5.im[18]";
connectAttr "polySurfaceShape33.wm" "polyUnite5.im[19]";
connectAttr "polySurfaceShape36.wm" "polyUnite5.im[20]";
connectAttr "polySurfaceShape35.wm" "polyUnite5.im[21]";
connectAttr "polyUnite5.out" "groupParts49.ig";
connectAttr "groupId103.id" "groupParts49.gi";
connectAttr "groupParts49.og" "polyAutoProj17.ip";
connectAttr "|polySurface25|transform55|polySurface20Shape.wm" "polyAutoProj17.mp"
		;
connectAttr "polyTweakUV2.out" "polyAutoProj18.ip";
connectAttr "|Box_1|transform101|Box_1Shape.wm" "polyAutoProj18.mp";
connectAttr "polyAutoProj17.out" "polySoftEdge1.ip";
connectAttr "|polySurface25|transform55|polySurface20Shape.wm" "polySoftEdge1.mp"
		;
connectAttr "polySoftEdge1.out" "polySoftEdge2.ip";
connectAttr "|polySurface25|transform55|polySurface20Shape.wm" "polySoftEdge2.mp"
		;
connectAttr "polySoftEdge2.out" "polySoftEdge3.ip";
connectAttr "|polySurface25|transform55|polySurface20Shape.wm" "polySoftEdge3.mp"
		;
connectAttr "polySoftEdge3.out" "polySoftEdge4.ip";
connectAttr "|polySurface25|transform55|polySurface20Shape.wm" "polySoftEdge4.mp"
		;
connectAttr "|polySurface25|transform55|polySurface20Shape.o" "polySeparate2.ip"
		;
connectAttr "polySeparate2.out[0]" "groupParts50.ig";
connectAttr "groupId104.id" "groupParts50.gi";
connectAttr "polySeparate2.out[1]" "groupParts51.ig";
connectAttr "groupId105.id" "groupParts51.gi";
connectAttr "polySeparate2.out[2]" "groupParts52.ig";
connectAttr "groupId106.id" "groupParts52.gi";
connectAttr "polySeparate2.out[3]" "groupParts53.ig";
connectAttr "groupId107.id" "groupParts53.gi";
connectAttr "polySeparate2.out[4]" "groupParts54.ig";
connectAttr "groupId108.id" "groupParts54.gi";
connectAttr "polySeparate2.out[5]" "groupParts55.ig";
connectAttr "groupId109.id" "groupParts55.gi";
connectAttr "polySeparate2.out[6]" "groupParts56.ig";
connectAttr "groupId110.id" "groupParts56.gi";
connectAttr "polySeparate2.out[7]" "groupParts57.ig";
connectAttr "groupId111.id" "groupParts57.gi";
connectAttr "polySeparate2.out[8]" "groupParts58.ig";
connectAttr "groupId112.id" "groupParts58.gi";
connectAttr "polySeparate2.out[9]" "groupParts59.ig";
connectAttr "groupId113.id" "groupParts59.gi";
connectAttr "polySeparate2.out[10]" "groupParts60.ig";
connectAttr "groupId114.id" "groupParts60.gi";
connectAttr "polySeparate2.out[11]" "groupParts61.ig";
connectAttr "groupId115.id" "groupParts61.gi";
connectAttr "polySeparate2.out[12]" "groupParts62.ig";
connectAttr "groupId116.id" "groupParts62.gi";
connectAttr "polySeparate2.out[13]" "groupParts63.ig";
connectAttr "groupId117.id" "groupParts63.gi";
connectAttr "polySeparate2.out[14]" "groupParts64.ig";
connectAttr "groupId118.id" "groupParts64.gi";
connectAttr "polySeparate2.out[15]" "groupParts65.ig";
connectAttr "groupId119.id" "groupParts65.gi";
connectAttr "polySeparate2.out[16]" "groupParts66.ig";
connectAttr "groupId120.id" "groupParts66.gi";
connectAttr "polySeparate2.out[17]" "groupParts67.ig";
connectAttr "groupId121.id" "groupParts67.gi";
connectAttr "polySeparate2.out[18]" "groupParts68.ig";
connectAttr "groupId122.id" "groupParts68.gi";
connectAttr "polySeparate2.out[19]" "groupParts69.ig";
connectAttr "groupId123.id" "groupParts69.gi";
connectAttr "polySeparate2.out[20]" "groupParts70.ig";
connectAttr "groupId124.id" "groupParts70.gi";
connectAttr "polySeparate2.out[21]" "groupParts71.ig";
connectAttr "groupId125.id" "groupParts71.gi";
connectAttr "polySeparate2.out[22]" "groupParts72.ig";
connectAttr "groupId126.id" "groupParts72.gi";
connectAttr "polySeparate2.out[23]" "groupParts73.ig";
connectAttr "groupId127.id" "groupParts73.gi";
connectAttr "polySurfaceShape51.o" "polyUnite6.ip[0]";
connectAttr "polySurfaceShape53.o" "polyUnite6.ip[1]";
connectAttr "polySurfaceShape52.o" "polyUnite6.ip[2]";
connectAttr "polySurfaceShape51.wm" "polyUnite6.im[0]";
connectAttr "polySurfaceShape53.wm" "polyUnite6.im[1]";
connectAttr "polySurfaceShape52.wm" "polyUnite6.im[2]";
connectAttr "polyUnite6.out" "groupParts74.ig";
connectAttr "groupId128.id" "groupParts74.gi";
connectAttr "polySurfaceShape46.o" "polyUnite7.ip[0]";
connectAttr "polySurfaceShape57.o" "polyUnite7.ip[1]";
connectAttr "polySurfaceShape58.o" "polyUnite7.ip[2]";
connectAttr "polySurfaceShape47.o" "polyUnite7.ip[3]";
connectAttr "polySurfaceShape40.o" "polyUnite7.ip[4]";
connectAttr "polySurfaceShape41.o" "polyUnite7.ip[5]";
connectAttr "polySurfaceShape48.o" "polyUnite7.ip[6]";
connectAttr "polySurfaceShape46.wm" "polyUnite7.im[0]";
connectAttr "polySurfaceShape57.wm" "polyUnite7.im[1]";
connectAttr "polySurfaceShape58.wm" "polyUnite7.im[2]";
connectAttr "polySurfaceShape47.wm" "polyUnite7.im[3]";
connectAttr "polySurfaceShape40.wm" "polyUnite7.im[4]";
connectAttr "polySurfaceShape41.wm" "polyUnite7.im[5]";
connectAttr "polySurfaceShape48.wm" "polyUnite7.im[6]";
connectAttr "polyUnite7.out" "groupParts75.ig";
connectAttr "groupId129.id" "groupParts75.gi";
connectAttr "polySurfaceShape50.o" "polyUnite8.ip[0]";
connectAttr "polySurfaceShape42.o" "polyUnite8.ip[1]";
connectAttr "polySurfaceShape45.o" "polyUnite8.ip[2]";
connectAttr "polySurfaceShape49.o" "polyUnite8.ip[3]";
connectAttr "polySurfaceShape50.wm" "polyUnite8.im[0]";
connectAttr "polySurfaceShape42.wm" "polyUnite8.im[1]";
connectAttr "polySurfaceShape45.wm" "polyUnite8.im[2]";
connectAttr "polySurfaceShape49.wm" "polyUnite8.im[3]";
connectAttr "polyUnite8.out" "groupParts76.ig";
connectAttr "groupId130.id" "groupParts76.gi";
connectAttr "polySurfaceShape43.o" "polyUnite9.ip[0]";
connectAttr "polySurfaceShape44.o" "polyUnite9.ip[1]";
connectAttr "polySurfaceShape43.wm" "polyUnite9.im[0]";
connectAttr "polySurfaceShape44.wm" "polyUnite9.im[1]";
connectAttr "polyUnite9.out" "groupParts77.ig";
connectAttr "groupId131.id" "groupParts77.gi";
connectAttr "|Box_7|transform72|Box_7Shape.o" "polySeparate3.ip";
connectAttr "polyAutoProj16.out" "groupParts78.ig";
connectAttr "groupId132.id" "groupParts78.gi";
connectAttr "polySeparate3.out[0]" "groupParts79.ig";
connectAttr "groupId134.id" "groupParts79.gi";
connectAttr "polySeparate3.out[1]" "groupParts80.ig";
connectAttr "groupId135.id" "groupParts80.gi";
connectAttr "polySeparate3.out[2]" "groupParts81.ig";
connectAttr "groupId136.id" "groupParts81.gi";
connectAttr "polySeparate3.out[3]" "groupParts82.ig";
connectAttr "groupId137.id" "groupParts82.gi";
connectAttr "polySeparate3.out[4]" "groupParts83.ig";
connectAttr "groupId138.id" "groupParts83.gi";
connectAttr "polySeparate3.out[5]" "groupParts84.ig";
connectAttr "groupId139.id" "groupParts84.gi";
connectAttr "polySeparate3.out[6]" "groupParts85.ig";
connectAttr "groupId140.id" "groupParts85.gi";
connectAttr "polySeparate3.out[7]" "groupParts86.ig";
connectAttr "groupId141.id" "groupParts86.gi";
connectAttr "polySeparate3.out[8]" "groupParts87.ig";
connectAttr "groupId142.id" "groupParts87.gi";
connectAttr "polySeparate3.out[9]" "groupParts88.ig";
connectAttr "groupId143.id" "groupParts88.gi";
connectAttr "polySeparate3.out[10]" "groupParts89.ig";
connectAttr "groupId144.id" "groupParts89.gi";
connectAttr "polySeparate3.out[11]" "groupParts90.ig";
connectAttr "groupId145.id" "groupParts90.gi";
connectAttr "polySeparate3.out[12]" "groupParts91.ig";
connectAttr "groupId146.id" "groupParts91.gi";
connectAttr "polySeparate3.out[13]" "groupParts92.ig";
connectAttr "groupId147.id" "groupParts92.gi";
connectAttr "polySeparate3.out[14]" "groupParts93.ig";
connectAttr "groupId148.id" "groupParts93.gi";
connectAttr "polySeparate3.out[15]" "groupParts94.ig";
connectAttr "groupId149.id" "groupParts94.gi";
connectAttr "polySeparate3.out[16]" "groupParts95.ig";
connectAttr "groupId150.id" "groupParts95.gi";
connectAttr "polySeparate3.out[17]" "groupParts96.ig";
connectAttr "groupId151.id" "groupParts96.gi";
connectAttr "polySeparate3.out[18]" "groupParts97.ig";
connectAttr "groupId152.id" "groupParts97.gi";
connectAttr "polySeparate3.out[19]" "groupParts98.ig";
connectAttr "groupId153.id" "groupParts98.gi";
connectAttr "polySeparate3.out[20]" "groupParts99.ig";
connectAttr "groupId154.id" "groupParts99.gi";
connectAttr "polySeparate3.out[21]" "groupParts100.ig";
connectAttr "groupId155.id" "groupParts100.gi";
connectAttr "polySeparate3.out[22]" "groupParts101.ig";
connectAttr "groupId156.id" "groupParts101.gi";
connectAttr "polySeparate3.out[23]" "groupParts102.ig";
connectAttr "groupId157.id" "groupParts102.gi";
connectAttr "polySeparate3.out[24]" "groupParts103.ig";
connectAttr "groupId158.id" "groupParts103.gi";
connectAttr "polySeparate3.out[25]" "groupParts104.ig";
connectAttr "groupId159.id" "groupParts104.gi";
connectAttr "polySeparate3.out[26]" "groupParts105.ig";
connectAttr "groupId160.id" "groupParts105.gi";
connectAttr "polySeparate3.out[27]" "groupParts106.ig";
connectAttr "groupId161.id" "groupParts106.gi";
connectAttr "polySeparate3.out[28]" "groupParts107.ig";
connectAttr "groupId162.id" "groupParts107.gi";
connectAttr "polySeparate3.out[29]" "groupParts108.ig";
connectAttr "groupId163.id" "groupParts108.gi";
connectAttr "polySurfaceShape60.o" "polyUnite10.ip[0]";
connectAttr "polySurfaceShape55.o" "polyUnite10.ip[1]";
connectAttr "polySurfaceShape56.o" "polyUnite10.ip[2]";
connectAttr "polySurfaceShape59.o" "polyUnite10.ip[3]";
connectAttr "polySurfaceShape60.wm" "polyUnite10.im[0]";
connectAttr "polySurfaceShape55.wm" "polyUnite10.im[1]";
connectAttr "polySurfaceShape56.wm" "polyUnite10.im[2]";
connectAttr "polySurfaceShape59.wm" "polyUnite10.im[3]";
connectAttr "polyUnite10.out" "groupParts109.ig";
connectAttr "groupId164.id" "groupParts109.gi";
connectAttr "polySurfaceShape67.o" "polyUnite11.ip[0]";
connectAttr "polySurfaceShape64.o" "polyUnite11.ip[1]";
connectAttr "polySurfaceShape65.o" "polyUnite11.ip[2]";
connectAttr "polySurfaceShape66.o" "polyUnite11.ip[3]";
connectAttr "polySurfaceShape67.wm" "polyUnite11.im[0]";
connectAttr "polySurfaceShape64.wm" "polyUnite11.im[1]";
connectAttr "polySurfaceShape65.wm" "polyUnite11.im[2]";
connectAttr "polySurfaceShape66.wm" "polyUnite11.im[3]";
connectAttr "polyUnite11.out" "groupParts110.ig";
connectAttr "groupId165.id" "groupParts110.gi";
connectAttr "polySurfaceShape62.o" "polyUnite12.ip[0]";
connectAttr "polySurfaceShape61.o" "polyUnite12.ip[1]";
connectAttr "polySurfaceShape68.o" "polyUnite12.ip[2]";
connectAttr "polySurfaceShape70.o" "polyUnite12.ip[3]";
connectAttr "polySurfaceShape71.o" "polyUnite12.ip[4]";
connectAttr "polySurfaceShape69.o" "polyUnite12.ip[5]";
connectAttr "polySurfaceShape62.wm" "polyUnite12.im[0]";
connectAttr "polySurfaceShape61.wm" "polyUnite12.im[1]";
connectAttr "polySurfaceShape68.wm" "polyUnite12.im[2]";
connectAttr "polySurfaceShape70.wm" "polyUnite12.im[3]";
connectAttr "polySurfaceShape71.wm" "polyUnite12.im[4]";
connectAttr "polySurfaceShape69.wm" "polyUnite12.im[5]";
connectAttr "polyUnite12.out" "groupParts111.ig";
connectAttr "groupId166.id" "groupParts111.gi";
connectAttr "polySurfaceShape73.o" "polyUnite13.ip[0]";
connectAttr "polySurfaceShape72.o" "polyUnite13.ip[1]";
connectAttr "polySurfaceShape73.wm" "polyUnite13.im[0]";
connectAttr "polySurfaceShape72.wm" "polyUnite13.im[1]";
connectAttr "polyUnite13.out" "groupParts112.ig";
connectAttr "groupId167.id" "groupParts112.gi";
connectAttr "polySurfaceShape80.o" "polyUnite14.ip[0]";
connectAttr "polySurfaceShape77.o" "polyUnite14.ip[1]";
connectAttr "polySurfaceShape76.o" "polyUnite14.ip[2]";
connectAttr "polySurfaceShape80.wm" "polyUnite14.im[0]";
connectAttr "polySurfaceShape77.wm" "polyUnite14.im[1]";
connectAttr "polySurfaceShape76.wm" "polyUnite14.im[2]";
connectAttr "polyUnite14.out" "groupParts113.ig";
connectAttr "groupId168.id" "groupParts113.gi";
connectAttr "polySurfaceShape81.o" "polyUnite15.ip[0]";
connectAttr "polySurfaceShape84.o" "polyUnite15.ip[1]";
connectAttr "polySurfaceShape90.o" "polyUnite15.ip[2]";
connectAttr "polySurfaceShape85.o" "polyUnite15.ip[3]";
connectAttr "polySurfaceShape88.o" "polyUnite15.ip[4]";
connectAttr "polySurfaceShape81.wm" "polyUnite15.im[0]";
connectAttr "polySurfaceShape84.wm" "polyUnite15.im[1]";
connectAttr "polySurfaceShape90.wm" "polyUnite15.im[2]";
connectAttr "polySurfaceShape85.wm" "polyUnite15.im[3]";
connectAttr "polySurfaceShape88.wm" "polyUnite15.im[4]";
connectAttr "polyUnite15.out" "groupParts114.ig";
connectAttr "groupId169.id" "groupParts114.gi";
connectAttr "polySurfaceShape83.o" "polyUnite16.ip[0]";
connectAttr "polySurfaceShape82.o" "polyUnite16.ip[1]";
connectAttr "polySurfaceShape83.wm" "polyUnite16.im[0]";
connectAttr "polySurfaceShape82.wm" "polyUnite16.im[1]";
connectAttr "polyUnite16.out" "groupParts115.ig";
connectAttr "groupId170.id" "groupParts115.gi";
connectAttr "polySurfaceShape89.o" "polyUnite17.ip[0]";
connectAttr "polySurfaceShape86.o" "polyUnite17.ip[1]";
connectAttr "polySurfaceShape89.wm" "polyUnite17.im[0]";
connectAttr "polySurfaceShape86.wm" "polyUnite17.im[1]";
connectAttr "polyUnite17.out" "groupParts116.ig";
connectAttr "groupId171.id" "groupParts116.gi";
connectAttr "|Box_1|transform101|Box_1Shape.o" "polySeparate4.ip";
connectAttr "polyAutoProj18.out" "groupParts117.ig";
connectAttr "groupId172.id" "groupParts117.gi";
connectAttr "polySeparate4.out[0]" "groupParts118.ig";
connectAttr "groupId174.id" "groupParts118.gi";
connectAttr "polySeparate4.out[1]" "groupParts119.ig";
connectAttr "groupId175.id" "groupParts119.gi";
connectAttr "polySeparate4.out[2]" "groupParts120.ig";
connectAttr "groupId176.id" "groupParts120.gi";
connectAttr "polySeparate4.out[3]" "groupParts121.ig";
connectAttr "groupId177.id" "groupParts121.gi";
connectAttr "polySeparate4.out[4]" "groupParts122.ig";
connectAttr "groupId178.id" "groupParts122.gi";
connectAttr "polySeparate4.out[5]" "groupParts123.ig";
connectAttr "groupId179.id" "groupParts123.gi";
connectAttr "polySeparate4.out[6]" "groupParts124.ig";
connectAttr "groupId180.id" "groupParts124.gi";
connectAttr "polySeparate4.out[7]" "groupParts125.ig";
connectAttr "groupId181.id" "groupParts125.gi";
connectAttr "polySeparate4.out[8]" "groupParts126.ig";
connectAttr "groupId182.id" "groupParts126.gi";
connectAttr "polySeparate4.out[9]" "groupParts127.ig";
connectAttr "groupId183.id" "groupParts127.gi";
connectAttr "polySeparate4.out[10]" "groupParts128.ig";
connectAttr "groupId184.id" "groupParts128.gi";
connectAttr "polySeparate4.out[11]" "groupParts129.ig";
connectAttr "groupId185.id" "groupParts129.gi";
connectAttr "polySeparate4.out[12]" "groupParts130.ig";
connectAttr "groupId186.id" "groupParts130.gi";
connectAttr "polySeparate4.out[13]" "groupParts131.ig";
connectAttr "groupId187.id" "groupParts131.gi";
connectAttr "polySeparate4.out[14]" "groupParts132.ig";
connectAttr "groupId188.id" "groupParts132.gi";
connectAttr "polySeparate4.out[15]" "groupParts133.ig";
connectAttr "groupId189.id" "groupParts133.gi";
connectAttr "polySurfaceShape95.o" "polyUnite18.ip[0]";
connectAttr "polySurfaceShape97.o" "polyUnite18.ip[1]";
connectAttr "polySurfaceShape96.o" "polyUnite18.ip[2]";
connectAttr "polySurfaceShape95.wm" "polyUnite18.im[0]";
connectAttr "polySurfaceShape97.wm" "polyUnite18.im[1]";
connectAttr "polySurfaceShape96.wm" "polyUnite18.im[2]";
connectAttr "polyUnite18.out" "groupParts134.ig";
connectAttr "groupId190.id" "groupParts134.gi";
connectAttr "polySurfaceShape100.o" "polyUnite19.ip[0]";
connectAttr "polySurfaceShape101.o" "polyUnite19.ip[1]";
connectAttr "polySurfaceShape102.o" "polyUnite19.ip[2]";
connectAttr "polySurfaceShape100.wm" "polyUnite19.im[0]";
connectAttr "polySurfaceShape101.wm" "polyUnite19.im[1]";
connectAttr "polySurfaceShape102.wm" "polyUnite19.im[2]";
connectAttr "polyUnite19.out" "groupParts135.ig";
connectAttr "groupId191.id" "groupParts135.gi";
connectAttr "polySurfaceShape99.o" "polyUnite20.ip[0]";
connectAttr "polySurfaceShape98.o" "polyUnite20.ip[1]";
connectAttr "polySurfaceShape99.wm" "polyUnite20.im[0]";
connectAttr "polySurfaceShape98.wm" "polyUnite20.im[1]";
connectAttr "polyUnite20.out" "groupParts136.ig";
connectAttr "groupId192.id" "groupParts136.gi";
connectAttr "polySurfaceShape92.o" "polyUnite21.ip[0]";
connectAttr "polySurfaceShape91.o" "polyUnite21.ip[1]";
connectAttr "polySurfaceShape92.wm" "polyUnite21.im[0]";
connectAttr "polySurfaceShape91.wm" "polyUnite21.im[1]";
connectAttr "polyUnite21.out" "groupParts137.ig";
connectAttr "groupId193.id" "groupParts137.gi";
connectAttr "polySurfaceShape103.o" "polyUnite22.ip[0]";
connectAttr "polySurfaceShape104.o" "polyUnite22.ip[1]";
connectAttr "polySurfaceShape103.wm" "polyUnite22.im[0]";
connectAttr "polySurfaceShape104.wm" "polyUnite22.im[1]";
connectAttr "polyUnite22.out" "groupParts138.ig";
connectAttr "groupId194.id" "groupParts138.gi";
connectAttr "polySurfaceShape106.o" "polyUnite23.ip[0]";
connectAttr "polySurfaceShape105.o" "polyUnite23.ip[1]";
connectAttr "polySurfaceShape106.wm" "polyUnite23.im[0]";
connectAttr "polySurfaceShape105.wm" "polyUnite23.im[1]";
connectAttr "polyUnite23.out" "groupParts139.ig";
connectAttr "groupId195.id" "groupParts139.gi";
connectAttr "polySurfaceShape75.o" "polyUnite24.ip[0]";
connectAttr "polySurfaceShape74.o" "polyUnite24.ip[1]";
connectAttr "polySurfaceShape75.wm" "polyUnite24.im[0]";
connectAttr "polySurfaceShape74.wm" "polyUnite24.im[1]";
connectAttr "polyUnite24.out" "groupParts140.ig";
connectAttr "groupId196.id" "groupParts140.gi";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCT2ADiffuse_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCT2ADiffuse_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCT2ADiffuse_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCT2ADiffuse_1.ws";
connectAttr "place2dTexture1.c" "ChannelCT2ADiffuse_1.c";
connectAttr "place2dTexture1.tf" "ChannelCT2ADiffuse_1.tf";
connectAttr "place2dTexture1.rf" "ChannelCT2ADiffuse_1.rf";
connectAttr "place2dTexture1.mu" "ChannelCT2ADiffuse_1.mu";
connectAttr "place2dTexture1.mv" "ChannelCT2ADiffuse_1.mv";
connectAttr "place2dTexture1.s" "ChannelCT2ADiffuse_1.s";
connectAttr "place2dTexture1.wu" "ChannelCT2ADiffuse_1.wu";
connectAttr "place2dTexture1.wv" "ChannelCT2ADiffuse_1.wv";
connectAttr "place2dTexture1.re" "ChannelCT2ADiffuse_1.re";
connectAttr "place2dTexture1.of" "ChannelCT2ADiffuse_1.of";
connectAttr "place2dTexture1.r" "ChannelCT2ADiffuse_1.ro";
connectAttr "place2dTexture1.n" "ChannelCT2ADiffuse_1.n";
connectAttr "place2dTexture1.vt1" "ChannelCT2ADiffuse_1.vt1";
connectAttr "place2dTexture1.vt2" "ChannelCT2ADiffuse_1.vt2";
connectAttr "place2dTexture1.vt3" "ChannelCT2ADiffuse_1.vt3";
connectAttr "place2dTexture1.vc1" "ChannelCT2ADiffuse_1.vc1";
connectAttr "place2dTexture1.o" "ChannelCT2ADiffuse_1.uv";
connectAttr "place2dTexture1.ofs" "ChannelCT2ADiffuse_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCT2ASpecular_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCT2ASpecular_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCT2ASpecular_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCT2ASpecular_1.ws";
connectAttr "place2dTexture2.c" "ChannelCT2ASpecular_1.c";
connectAttr "place2dTexture2.tf" "ChannelCT2ASpecular_1.tf";
connectAttr "place2dTexture2.rf" "ChannelCT2ASpecular_1.rf";
connectAttr "place2dTexture2.mu" "ChannelCT2ASpecular_1.mu";
connectAttr "place2dTexture2.mv" "ChannelCT2ASpecular_1.mv";
connectAttr "place2dTexture2.s" "ChannelCT2ASpecular_1.s";
connectAttr "place2dTexture2.wu" "ChannelCT2ASpecular_1.wu";
connectAttr "place2dTexture2.wv" "ChannelCT2ASpecular_1.wv";
connectAttr "place2dTexture2.re" "ChannelCT2ASpecular_1.re";
connectAttr "place2dTexture2.of" "ChannelCT2ASpecular_1.of";
connectAttr "place2dTexture2.r" "ChannelCT2ASpecular_1.ro";
connectAttr "place2dTexture2.n" "ChannelCT2ASpecular_1.n";
connectAttr "place2dTexture2.vt1" "ChannelCT2ASpecular_1.vt1";
connectAttr "place2dTexture2.vt2" "ChannelCT2ASpecular_1.vt2";
connectAttr "place2dTexture2.vt3" "ChannelCT2ASpecular_1.vt3";
connectAttr "place2dTexture2.vc1" "ChannelCT2ASpecular_1.vc1";
connectAttr "place2dTexture2.o" "ChannelCT2ASpecular_1.uv";
connectAttr "place2dTexture2.ofs" "ChannelCT2ASpecular_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCT2WindowDiffuse_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCT2WindowDiffuse_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCT2WindowDiffuse_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCT2WindowDiffuse_1.ws";
connectAttr "place2dTexture3.c" "ChannelCT2WindowDiffuse_1.c";
connectAttr "place2dTexture3.tf" "ChannelCT2WindowDiffuse_1.tf";
connectAttr "place2dTexture3.rf" "ChannelCT2WindowDiffuse_1.rf";
connectAttr "place2dTexture3.mu" "ChannelCT2WindowDiffuse_1.mu";
connectAttr "place2dTexture3.mv" "ChannelCT2WindowDiffuse_1.mv";
connectAttr "place2dTexture3.s" "ChannelCT2WindowDiffuse_1.s";
connectAttr "place2dTexture3.wu" "ChannelCT2WindowDiffuse_1.wu";
connectAttr "place2dTexture3.wv" "ChannelCT2WindowDiffuse_1.wv";
connectAttr "place2dTexture3.re" "ChannelCT2WindowDiffuse_1.re";
connectAttr "place2dTexture3.of" "ChannelCT2WindowDiffuse_1.of";
connectAttr "place2dTexture3.r" "ChannelCT2WindowDiffuse_1.ro";
connectAttr "place2dTexture3.n" "ChannelCT2WindowDiffuse_1.n";
connectAttr "place2dTexture3.vt1" "ChannelCT2WindowDiffuse_1.vt1";
connectAttr "place2dTexture3.vt2" "ChannelCT2WindowDiffuse_1.vt2";
connectAttr "place2dTexture3.vt3" "ChannelCT2WindowDiffuse_1.vt3";
connectAttr "place2dTexture3.vc1" "ChannelCT2WindowDiffuse_1.vc1";
connectAttr "place2dTexture3.o" "ChannelCT2WindowDiffuse_1.uv";
connectAttr "place2dTexture3.ofs" "ChannelCT2WindowDiffuse_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCT2WindowNormalMap_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCT2WindowNormalMap_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCT2WindowNormalMap_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCT2WindowNormalMap_1.ws";
connectAttr "place2dTexture4.c" "ChannelCT2WindowNormalMap_1.c";
connectAttr "place2dTexture4.tf" "ChannelCT2WindowNormalMap_1.tf";
connectAttr "place2dTexture4.rf" "ChannelCT2WindowNormalMap_1.rf";
connectAttr "place2dTexture4.mu" "ChannelCT2WindowNormalMap_1.mu";
connectAttr "place2dTexture4.mv" "ChannelCT2WindowNormalMap_1.mv";
connectAttr "place2dTexture4.s" "ChannelCT2WindowNormalMap_1.s";
connectAttr "place2dTexture4.wu" "ChannelCT2WindowNormalMap_1.wu";
connectAttr "place2dTexture4.wv" "ChannelCT2WindowNormalMap_1.wv";
connectAttr "place2dTexture4.re" "ChannelCT2WindowNormalMap_1.re";
connectAttr "place2dTexture4.of" "ChannelCT2WindowNormalMap_1.of";
connectAttr "place2dTexture4.r" "ChannelCT2WindowNormalMap_1.ro";
connectAttr "place2dTexture4.n" "ChannelCT2WindowNormalMap_1.n";
connectAttr "place2dTexture4.vt1" "ChannelCT2WindowNormalMap_1.vt1";
connectAttr "place2dTexture4.vt2" "ChannelCT2WindowNormalMap_1.vt2";
connectAttr "place2dTexture4.vt3" "ChannelCT2WindowNormalMap_1.vt3";
connectAttr "place2dTexture4.vc1" "ChannelCT2WindowNormalMap_1.vc1";
connectAttr "place2dTexture4.o" "ChannelCT2WindowNormalMap_1.uv";
connectAttr "place2dTexture4.ofs" "ChannelCT2WindowNormalMap_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCT2WindowSpecular_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCT2WindowSpecular_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCT2WindowSpecular_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCT2WindowSpecular_1.ws";
connectAttr "place2dTexture5.c" "ChannelCT2WindowSpecular_1.c";
connectAttr "place2dTexture5.tf" "ChannelCT2WindowSpecular_1.tf";
connectAttr "place2dTexture5.rf" "ChannelCT2WindowSpecular_1.rf";
connectAttr "place2dTexture5.mu" "ChannelCT2WindowSpecular_1.mu";
connectAttr "place2dTexture5.mv" "ChannelCT2WindowSpecular_1.mv";
connectAttr "place2dTexture5.s" "ChannelCT2WindowSpecular_1.s";
connectAttr "place2dTexture5.wu" "ChannelCT2WindowSpecular_1.wu";
connectAttr "place2dTexture5.wv" "ChannelCT2WindowSpecular_1.wv";
connectAttr "place2dTexture5.re" "ChannelCT2WindowSpecular_1.re";
connectAttr "place2dTexture5.of" "ChannelCT2WindowSpecular_1.of";
connectAttr "place2dTexture5.r" "ChannelCT2WindowSpecular_1.ro";
connectAttr "place2dTexture5.n" "ChannelCT2WindowSpecular_1.n";
connectAttr "place2dTexture5.vt1" "ChannelCT2WindowSpecular_1.vt1";
connectAttr "place2dTexture5.vt2" "ChannelCT2WindowSpecular_1.vt2";
connectAttr "place2dTexture5.vt3" "ChannelCT2WindowSpecular_1.vt3";
connectAttr "place2dTexture5.vc1" "ChannelCT2WindowSpecular_1.vc1";
connectAttr "place2dTexture5.o" "ChannelCT2WindowSpecular_1.uv";
connectAttr "place2dTexture5.ofs" "ChannelCT2WindowSpecular_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCTMidDiffuse_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCTMidDiffuse_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCTMidDiffuse_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCTMidDiffuse_1.ws";
connectAttr "place2dTexture6.c" "ChannelCTMidDiffuse_1.c";
connectAttr "place2dTexture6.tf" "ChannelCTMidDiffuse_1.tf";
connectAttr "place2dTexture6.rf" "ChannelCTMidDiffuse_1.rf";
connectAttr "place2dTexture6.mu" "ChannelCTMidDiffuse_1.mu";
connectAttr "place2dTexture6.mv" "ChannelCTMidDiffuse_1.mv";
connectAttr "place2dTexture6.s" "ChannelCTMidDiffuse_1.s";
connectAttr "place2dTexture6.wu" "ChannelCTMidDiffuse_1.wu";
connectAttr "place2dTexture6.wv" "ChannelCTMidDiffuse_1.wv";
connectAttr "place2dTexture6.re" "ChannelCTMidDiffuse_1.re";
connectAttr "place2dTexture6.of" "ChannelCTMidDiffuse_1.of";
connectAttr "place2dTexture6.r" "ChannelCTMidDiffuse_1.ro";
connectAttr "place2dTexture6.n" "ChannelCTMidDiffuse_1.n";
connectAttr "place2dTexture6.vt1" "ChannelCTMidDiffuse_1.vt1";
connectAttr "place2dTexture6.vt2" "ChannelCTMidDiffuse_1.vt2";
connectAttr "place2dTexture6.vt3" "ChannelCTMidDiffuse_1.vt3";
connectAttr "place2dTexture6.vc1" "ChannelCTMidDiffuse_1.vc1";
connectAttr "place2dTexture6.o" "ChannelCTMidDiffuse_1.uv";
connectAttr "place2dTexture6.ofs" "ChannelCTMidDiffuse_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCTMidNormalMap_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCTMidNormalMap_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCTMidNormalMap_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCTMidNormalMap_1.ws";
connectAttr "place2dTexture7.c" "ChannelCTMidNormalMap_1.c";
connectAttr "place2dTexture7.tf" "ChannelCTMidNormalMap_1.tf";
connectAttr "place2dTexture7.rf" "ChannelCTMidNormalMap_1.rf";
connectAttr "place2dTexture7.mu" "ChannelCTMidNormalMap_1.mu";
connectAttr "place2dTexture7.mv" "ChannelCTMidNormalMap_1.mv";
connectAttr "place2dTexture7.s" "ChannelCTMidNormalMap_1.s";
connectAttr "place2dTexture7.wu" "ChannelCTMidNormalMap_1.wu";
connectAttr "place2dTexture7.wv" "ChannelCTMidNormalMap_1.wv";
connectAttr "place2dTexture7.re" "ChannelCTMidNormalMap_1.re";
connectAttr "place2dTexture7.of" "ChannelCTMidNormalMap_1.of";
connectAttr "place2dTexture7.r" "ChannelCTMidNormalMap_1.ro";
connectAttr "place2dTexture7.n" "ChannelCTMidNormalMap_1.n";
connectAttr "place2dTexture7.vt1" "ChannelCTMidNormalMap_1.vt1";
connectAttr "place2dTexture7.vt2" "ChannelCTMidNormalMap_1.vt2";
connectAttr "place2dTexture7.vt3" "ChannelCTMidNormalMap_1.vt3";
connectAttr "place2dTexture7.vc1" "ChannelCTMidNormalMap_1.vc1";
connectAttr "place2dTexture7.o" "ChannelCTMidNormalMap_1.uv";
connectAttr "place2dTexture7.ofs" "ChannelCTMidNormalMap_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "ChannelCTMidSpecular_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "ChannelCTMidSpecular_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "ChannelCTMidSpecular_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "ChannelCTMidSpecular_1.ws";
connectAttr "place2dTexture8.c" "ChannelCTMidSpecular_1.c";
connectAttr "place2dTexture8.tf" "ChannelCTMidSpecular_1.tf";
connectAttr "place2dTexture8.rf" "ChannelCTMidSpecular_1.rf";
connectAttr "place2dTexture8.mu" "ChannelCTMidSpecular_1.mu";
connectAttr "place2dTexture8.mv" "ChannelCTMidSpecular_1.mv";
connectAttr "place2dTexture8.s" "ChannelCTMidSpecular_1.s";
connectAttr "place2dTexture8.wu" "ChannelCTMidSpecular_1.wu";
connectAttr "place2dTexture8.wv" "ChannelCTMidSpecular_1.wv";
connectAttr "place2dTexture8.re" "ChannelCTMidSpecular_1.re";
connectAttr "place2dTexture8.of" "ChannelCTMidSpecular_1.of";
connectAttr "place2dTexture8.r" "ChannelCTMidSpecular_1.ro";
connectAttr "place2dTexture8.n" "ChannelCTMidSpecular_1.n";
connectAttr "place2dTexture8.vt1" "ChannelCTMidSpecular_1.vt1";
connectAttr "place2dTexture8.vt2" "ChannelCTMidSpecular_1.vt2";
connectAttr "place2dTexture8.vt3" "ChannelCTMidSpecular_1.vt3";
connectAttr "place2dTexture8.vc1" "ChannelCTMidSpecular_1.vc1";
connectAttr "place2dTexture8.o" "ChannelCTMidSpecular_1.uv";
connectAttr "place2dTexture8.ofs" "ChannelCTMidSpecular_1.fs";
connectAttr ":defaultArnoldDisplayDriver.msg" ":defaultArnoldRenderOptions.drivers"
		 -na;
connectAttr ":defaultArnoldFilter.msg" ":defaultArnoldRenderOptions.filt";
connectAttr ":defaultArnoldDriver.msg" ":defaultArnoldRenderOptions.drvr";
connectAttr "ChannelCTMidNormalMap_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[0].dn"
		;
connectAttr "blinn1SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[1].dn"
		;
connectAttr "place2dTexture4.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[2].dn"
		;
connectAttr "place2dTexture5.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[3].dn"
		;
connectAttr "place2dTexture6.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[4].dn"
		;
connectAttr "ChannelCT2ADiffuse_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[5].dn"
		;
connectAttr "CTMid.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[6].dn"
		;
connectAttr "ChannelCT2WindowSpecular_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[7].dn"
		;
connectAttr "ChannelCT2WindowNormalMap_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[8].dn"
		;
connectAttr "place2dTexture8.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[9].dn"
		;
connectAttr "place2dTexture1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[10].dn"
		;
connectAttr "blinn3SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[11].dn"
		;
connectAttr "place2dTexture3.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[12].dn"
		;
connectAttr "place2dTexture2.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[13].dn"
		;
connectAttr "CT2A.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[14].dn"
		;
connectAttr "CT2Window.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[15].dn"
		;
connectAttr "ChannelCT2ASpecular_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[16].dn"
		;
connectAttr "place2dTexture7.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[17].dn"
		;
connectAttr "ChannelCTMidDiffuse_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[18].dn"
		;
connectAttr "blinn2SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[19].dn"
		;
connectAttr "ChannelCTMidSpecular_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[20].dn"
		;
connectAttr "ChannelCT2WindowDiffuse_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[21].dn"
		;
connectAttr "Box063MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box004MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box085MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box061MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box054MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box007MatSG.pa" ":renderPartition.st" -na;
connectAttr "initialShadingGroup_pCube13MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box006MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box100MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box086MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box055MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box062MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box002MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box053MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box001MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box101MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box087MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box099MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box005MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box058MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box003MatSG.pa" ":renderPartition.st" -na;
connectAttr "Box057MatSG.pa" ":renderPartition.st" -na;
connectAttr "blinn1SG.pa" ":renderPartition.st" -na;
connectAttr "blinn2SG.pa" ":renderPartition.st" -na;
connectAttr "blinn3SG.pa" ":renderPartition.st" -na;
connectAttr "Box063Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box004Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box085Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box061Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box054Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box007Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "initialShadingGroup_pCube13Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box006Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box100Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box086Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box055Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box062Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box002Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box053Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box001Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box101Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box087Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box099Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box005Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box058Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box003Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "Box057Mat.msg" ":defaultShaderList1.s" -na;
connectAttr "CT2Window.msg" ":defaultShaderList1.s" -na;
connectAttr "CTMid.msg" ":defaultShaderList1.s" -na;
connectAttr "CT2A.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture4.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture5.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture6.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture7.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture8.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "ChannelCT2ADiffuse_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCT2ASpecular_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCT2WindowDiffuse_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCT2WindowNormalMap_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCT2WindowSpecular_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCTMidDiffuse_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCTMidNormalMap_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "ChannelCTMidSpecular_1.msg" ":defaultTextureList1.tx" -na;
// End of ct - copia.ma
