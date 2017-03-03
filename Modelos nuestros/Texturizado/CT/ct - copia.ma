//Maya ASCII 2017 scene
//Name: ct - copia.ma
//Last modified: Fri, Mar 03, 2017 12:13:07 PM
//Codeset: 1252
requires maya "2017";
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
	setAttr ".t" -type "double3" -123.696933319043 117.7165764260069 54.911202308955112 ;
	setAttr ".r" -type "double3" -39.293956322303892 -798.09995136791076 1.542423527809627e-014 ;
	setAttr ".rp" -type "double3" 1.7763568394002505e-015 1.4210854715202004e-014 0 ;
	setAttr ".rpt" -type "double3" -1.8982064174846415e-014 -1.6845054405080024e-014 
		9.5363495939373665e-014 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "322E42B5-478F-7FB6-F2B7-76B6EA9EBE3C";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999979;
	setAttr ".fcp" 1000;
	setAttr ".coi" 171.65282032791015;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" 7.1241159439086914 0.10799980163574219 29.553693771362305 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
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
	setAttr -s 7 ".pt";
	setAttr ".pt[20]" -type "float3" 7.4505806e-009 0 0 ;
	setAttr ".pt[21]" -type "float3" 7.4505806e-009 0 0 ;
	setAttr ".pt[22]" -type "float3" 7.4505806e-009 0 0 ;
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
	setAttr -s 5 ".pt";
	setAttr ".pt[50]" -type "float3" -4.6566129e-010 0 0 ;
	setAttr ".pt[51]" -type "float3" -4.6566129e-010 0 0 ;
	setAttr ".pt[52]" -type "float3" -4.6566129e-010 0 0 ;
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
	setAttr -s 5 ".pt";
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
createNode transform -n "Box_5";
	rename -uid "9F77C864-4704-4736-17E6-39BD82E38FAC";
	setAttr ".rp" -type "double3" -0.1943499622344973 8.8590478460543167 47.07295001387596 ;
	setAttr ".sp" -type "double3" -0.1943499622344973 8.8590478460543167 47.07295001387596 ;
createNode mesh -n "Box_5Shape" -p "|Box_5";
	rename -uid "9FEBFB7E-4449-9BB1-D92B-B8890FC1AB1A";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode transform -n "Box_7";
	rename -uid "42DC7E33-4205-B2E9-2F93-5B89F75CF422";
	setAttr ".rp" -type "double3" -0.70457478225429959 8.8246003150939938 19.577650662946169 ;
	setAttr ".sp" -type "double3" -0.70457478225429959 8.8246003150939938 19.577650662946169 ;
createNode mesh -n "Box_7Shape" -p "|Box_7";
	rename -uid "6FD12D38-4C80-076F-B38D-C58992C97EDA";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.50000001955777407 0.48351326090050861 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 11 ".pt";
	setAttr ".pt[49]" -type "float3" 0 -4.4703484e-008 0 ;
	setAttr ".pt[51]" -type "float3" 0 4.4703484e-008 0 ;
	setAttr ".pt[52]" -type "float3" 0 4.4703484e-008 0 ;
	setAttr ".pt[53]" -type "float3" 0 4.4703484e-008 0 ;
	setAttr ".dr" 1;
createNode transform -n "Box_1";
	rename -uid "5A7F1458-41E5-BF79-36E1-C0B2E5EBB0D8";
	setAttr ".rp" -type "double3" -8.0618009788377876 12.512388592064379 0.17087834358215215 ;
	setAttr ".sp" -type "double3" -8.0618009788377876 12.512388592064379 0.17087834358215215 ;
createNode mesh -n "Box_1Shape" -p "|Box_1";
	rename -uid "14BD54A2-4635-A7CA-E867-35B8FDF25B35";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.49296784587204456 0.4959735949523747 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode displayLayerManager -n "layerManager";
	rename -uid "D1144AAD-4248-C9C5-E1E5-49900B3E5E51";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "CD584E3A-46A0-41FA-B62F-F185ADFC832E";
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
	rename -uid "D8113D58-452D-3564-6660-B5A1B13355A8";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "FA87B511-4520-F9A9-AE3B-D686B9320BFA";
createNode displayLayer -n "defaultLayer";
	rename -uid "0BF82FAD-45DF-3F8C-5ED4-D4BA7AD1C5BA";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "1102E642-45A2-AD52-67ED-6A93B9E0BEF1";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "0BD9F219-452F-CA2A-FB5A-06855038054A";
	setAttr ".g" yes;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "5BA2201A-42F7-8E01-4A0B-8080DFFC900D";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n"
		+ "                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n"
		+ "                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 1\n                -height 1\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n"
		+ "                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n"
		+ "            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n"
		+ "            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n"
		+ "        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n"
		+ "                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n"
		+ "                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n"
		+ "                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 1\n                -height 1\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n"
		+ "            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n"
		+ "            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n"
		+ "            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n"
		+ "                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n"
		+ "                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n"
		+ "                -width 1\n                -height 1\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n"
		+ "            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n"
		+ "            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n"
		+ "            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n"
		+ "                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n"
		+ "                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n"
		+ "                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 1388\n                -height 716\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n"
		+ "\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n"
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
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1388\\n    -height 716\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1388\\n    -height 716\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
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
	setAttr -s 64 ".uvtk[4:63]" -type "float2" 0 2.4912879e-008 0 -2.9802322e-008
		 0 -2.9802322e-008 0 2.4912879e-008 0.00028902292 -0.0013372898 -0.00028902292 0.0013372898
		 0.00028902292 0.0013372898 -0.00028902292 -0.0013372898 -0.021212921 0.019105792
		 0.021212898 -0.019105852 0.028537787 0.0007853508 -0.02853772 -0.0007854104 -0.00076121092
		 -0.0011282861 0.00076121092 0.0011283159 0.00076121092 -0.0011282861 -0.00076121092
		 0.0011283159 -2.9802322e-008 0 1.4901161e-008 0 1.4901161e-008 0 -2.9802322e-008
		 0 0.0005697906 0.0051912069 -0.0005697906 -0.0051912069 -0.0005697906 0.0051912069
		 0.0005697906 -0.0051912069 -0.06823653 0.10720687 -0.048102088 0.095121078 -0.046710953
		 0.10372739 -0.069627665 0.098600619 0.00079768896 0.0072675645 -0.00079768896 -0.0072675436
		 -0.00079768896 0.0072675645 0.00079768896 -0.0072675436 0.0066486467 0.24354798 -0.052172404
		 0.24709743 -0.045289114 0.22633182 -0.0002346423 0.26431358 -0.0093050338 0.22490042
		 -0.026102334 0.23033762 -0.025661606 0.22379798 -0.0097458046 0.23144001 0 -2.8638169e-008
		 0 2.9802322e-008 5.9604645e-008 2.9802322e-008 0 -1.4901161e-008 0.00086331367 -0.0040568709
		 -0.00086331367 0.0040568709 0.00086331367 0.0040568709 -0.00086331367 -0.0040568709
		 -2.0721927e-008 2.2351742e-008 0 2.9802322e-008 2.0721927e-008 -5.9604645e-008 -2.9802322e-008
		 -9.3132257e-009 0.0061122775 -0.034926951 -0.0061122775 0.034926951 0.0061122775
		 0.034926951 -0.0061122775 -0.034926951 0.0040479302 -0.021089196 -0.0040479302 0.021089196
		 0.0040479302 0.021089196 -0.0040479302 -0.021089196;
createNode blinn -n "CT2Window";
	rename -uid "5E5C505B-48B5-CD75-4A7F-A0B6FF045AFB";
createNode shadingEngine -n "blinn1SG";
	rename -uid "02740D9E-40A0-FF0E-90FA-2CBB39EA9F04";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo22";
	rename -uid "DE0EC977-4E80-B6C1-A651-EDBA29C53AE1";
createNode blinn -n "CTMid";
	rename -uid "4270464A-48A9-3FB0-B76F-CEBBB7D1983A";
createNode shadingEngine -n "blinn2SG";
	rename -uid "C1361746-4C11-D6F8-188B-D19F82EC9939";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo23";
	rename -uid "D84155BE-4298-1A6C-03D3-F58C46B0A4A3";
createNode blinn -n "CT2A";
	rename -uid "079EEC87-4F98-534F-9FE2-D19CDD5808C6";
createNode shadingEngine -n "blinn3SG";
	rename -uid "8CC22493-4831-EA4C-1182-549346EAF1CC";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo24";
	rename -uid "FC5FAEEE-45E0-82FB-3A55-0EB726261BBC";
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "7041CF30-4048-AA81-AEA9-A6A89BF65E4D";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -601.02496165675655 -671.77725769182132 ;
	setAttr ".tgi[0].vh" -type "double2" 224.60803924876717 118.75489474636966 ;
	setAttr -s 6 ".tgi[0].ni";
	setAttr ".tgi[0].ni[0].x" 249.04762268066406;
	setAttr ".tgi[0].ni[0].y" -43.333324432373047;
	setAttr ".tgi[0].ni[0].nvs" 1923;
	setAttr ".tgi[0].ni[1].x" -243.33332824707031;
	setAttr ".tgi[0].ni[1].y" 181.66667175292969;
	setAttr ".tgi[0].ni[1].nvs" 1923;
	setAttr ".tgi[0].ni[2].x" -27.142860412597656;
	setAttr ".tgi[0].ni[2].y" -70.714271545410156;
	setAttr ".tgi[0].ni[2].nvs" 1923;
	setAttr ".tgi[0].ni[3].x" -314.95187377929687;
	setAttr ".tgi[0].ni[3].y" -338.03884887695312;
	setAttr ".tgi[0].ni[3].nvs" 1923;
	setAttr ".tgi[0].ni[4].x" -562.06671142578125;
	setAttr ".tgi[0].ni[4].y" -298.26382446289062;
	setAttr ".tgi[0].ni[4].nvs" 1923;
	setAttr ".tgi[0].ni[5].x" 54.285713195800781;
	setAttr ".tgi[0].ni[5].y" 161.42857360839844;
	setAttr ".tgi[0].ni[5].nvs" 1923;
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
select -ne :time1;
	setAttr ".o" 0;
select -ne :renderPartition;
	setAttr -s 27 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 29 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
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
connectAttr "polyAutoProj12.out" "|Box_5|Box_5Shape.i";
connectAttr "polyAutoProj16.out" "|Box_7|Box_7Shape.i";
connectAttr "polyTweakUV1.uvtk[0]" "|Box_7|Box_7Shape.uvst[0].uvtw";
connectAttr "polyTweakUV2.out" "|Box_1|Box_1Shape.i";
connectAttr "polyTweakUV2.uvtk[0]" "|Box_1|Box_1Shape.uvst[0].uvtw";
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
connectAttr "|Box_5|Box_5Shape.wm" "polyAutoProj12.mp";
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
connectAttr "|Box_7|Box_7Shape.wm" "polyAutoProj13.mp";
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
connectAttr "|Box_1|Box_1Shape.wm" "polyAutoProj14.mp";
connectAttr "polyAutoProj14.out" "polyTweakUV2.ip";
connectAttr "CT2Window.oc" "blinn1SG.ss";
connectAttr "|Box_5|Box_5Shape.iog" "blinn1SG.dsm" -na;
connectAttr "blinn1SG.msg" "materialInfo22.sg";
connectAttr "CT2Window.msg" "materialInfo22.m";
connectAttr "CTMid.oc" "blinn2SG.ss";
connectAttr "|Box_7|Box_7Shape.iog" "blinn2SG.dsm" -na;
connectAttr "blinn2SG.msg" "materialInfo23.sg";
connectAttr "CTMid.msg" "materialInfo23.m";
connectAttr "CT2A.oc" "blinn3SG.ss";
connectAttr "|Box_1|Box_1Shape.iog" "blinn3SG.dsm" -na;
connectAttr "blinn3SG.msg" "materialInfo24.sg";
connectAttr "CT2A.msg" "materialInfo24.m";
connectAttr "blinn2SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[0].dn"
		;
connectAttr "CT2Window.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[1].dn"
		;
connectAttr "CTMid.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[2].dn"
		;
connectAttr "blinn3SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[3].dn"
		;
connectAttr "CT2A.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[4].dn"
		;
connectAttr "blinn1SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[5].dn"
		;
connectAttr "polyTweakUV1.out" "polyAutoProj15.ip";
connectAttr "|Box_7|Box_7Shape.wm" "polyAutoProj15.mp";
connectAttr "polyAutoProj15.out" "deleteComponent6.ig";
connectAttr "deleteComponent6.og" "deleteComponent7.ig";
connectAttr "deleteComponent7.og" "polyMergeVert1.ip";
connectAttr "|Box_7|Box_7Shape.wm" "polyMergeVert1.mp";
connectAttr "polyMergeVert1.out" "polyAutoProj16.ip";
connectAttr "|Box_7|Box_7Shape.wm" "polyAutoProj16.mp";
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
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
// End of ct - copia.ma
