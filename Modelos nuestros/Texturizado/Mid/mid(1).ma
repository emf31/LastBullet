//Maya ASCII 2017 scene
//Name: mid(1).ma
//Last modified: Thu, Mar 09, 2017 01:06:51 PM
//Codeset: 1252
requires maya "2017";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2017";
fileInfo "version" "2017";
fileInfo "cutIdentifier" "201606150345-997974";
fileInfo "osv" "Microsoft Windows 8 , 64-bit  (Build 9200)\n";
fileInfo "license" "student";
createNode transform -s -n "persp";
	rename -uid "1C16E372-4031-BE29-F233-1DB5A827DEB8";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -204.94209203831065 177.48608648595982 -54.192526349715493 ;
	setAttr ".r" -type "double3" -41.276862662371158 596.99999999997181 0 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "E16D5823-4FA7-F6B3-6D53-839D5D8504F9";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".fcp" 1000;
	setAttr ".coi" 262.94405984448343;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
createNode transform -s -n "top";
	rename -uid "C300D7D8-4AC5-0FDB-ACCC-268E3BC4A9C2";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 100.1 0 ;
	setAttr ".r" -type "double3" -89.999999999999986 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "25888930-4762-C1C9-C405-4083FE706F12";
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
	rename -uid "CFD94A35-49FF-AC37-B9C1-ABA02D4218CA";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 100.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "9FF7E7B9-458C-DFB3-22DF-D388358E8073";
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
	rename -uid "92ABE2C4-45A7-7B48-DC5A-2E8A9E823C6A";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 100.1 0 0 ;
	setAttr ".r" -type "double3" 0 89.999999999999986 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "CA2A23C7-4F63-D2F6-A9BD-E8A906C22115";
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
	rename -uid "685D09CB-42B7-FE09-A9CE-88B1B5D54FC6";
	setAttr ".ro" 2;
createNode transform -n "mid" -p "Script";
	rename -uid "9E555EA2-45E3-24B3-EF8C-AAB1E952C3F0";
	setAttr ".t" -type "double3" -24.03 4.08 75.17 ;
	setAttr ".ro" 2;
createNode transform -n "mid_1" -p "mid";
	rename -uid "9FE2E175-4B5A-4641-5F4C-9E86A0BB6E1A";
	setAttr ".ro" 2;
createNode transform -n "transform17" -p "mid_1";
	rename -uid "0D6C7453-492B-4B7F-3268-EA92CA381C75";
	setAttr ".v" no;
createNode mesh -n "mid_1Shape" -p "transform17";
	rename -uid "376AD0D8-4597-874B-277E-6D904EC05C1B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -1 16.75589943 2.88450003 -1 16.75589943 -2.88450003
		 1 16.75589943 -2.88450003 1 16.75589943 2.88450003 -1 0 -2.88450003 -1 16.75589943 -2.88450003
		 -1 16.75589943 2.88450003 -1 0 2.88450003;
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
createNode transform -n "mid_2" -p "Script";
	rename -uid "E2535A2D-46A2-6C21-A634-AA9FA3C469F2";
	setAttr ".t" -type "double3" -84.57 4.72 57 ;
	setAttr ".ro" 2;
createNode transform -n "mid_3" -p "mid_2";
	rename -uid "1E61C777-48CA-1B84-70FA-51B0C584FDDE";
	setAttr ".ro" 2;
createNode transform -n "transform20" -p "|Script|mid_2|mid_3";
	rename -uid "616EC031-4BA8-52C1-C9B0-BFA778B1B3F1";
	setAttr ".v" no;
createNode mesh -n "mid_3Shape" -p "transform20";
	rename -uid "5977A856-4804-D8CF-9E41-69AA8D7521D2";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:7]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 16 ".uvst[0].uvsp[0:15]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 16 ".vt[0:15]"  -1 16.67230034 6 -1 16.67230034 -6 1 16.67230034 -6
		 1 16.67230034 6 -1 0 6 -1 16.67230034 6 1 16.67230034 6 1 0 6 1 0 6 1 16.67230034 6
		 1 16.67230034 -6 1 0 -6 -1 0 -6 -1 16.67230034 -6 -1 16.67230034 6 -1 0 6;
	setAttr -s 20 ".ed[0:19]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0 12 13 0 13 14 0 14 12 0 14 15 0
		 15 12 0;
	setAttr -s 24 ".n[0:23]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
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
createNode transform -n "conector" -p "Script";
	rename -uid "206B98F8-4314-BE00-28D5-ADA3B32FE14E";
	setAttr ".t" -type "double3" -33.49 1.32 50.06 ;
	setAttr ".r" -type "double3" 19.71755 0 0 ;
	setAttr ".ro" 2;
createNode transform -n "conector_1" -p "conector";
	rename -uid "E162E70A-4B48-256B-83CA-9C85E2D90008";
	setAttr ".ro" 2;
createNode mesh -n "polySurfaceShape1" -p "conector_1";
	rename -uid "66E197A5-432B-8E28-1502-59A80A5C910B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".pt[9]" -type "float3"  0 8.9406967e-008 -1.1920929e-007;
	setAttr -s 110 ".vt[0:109]"  -3.71479988 -0.1005 7.66830015 -3.71479988 -0.082199998 6.27409983
		 -3.71479988 -0.064000003 4.87979984 -3.71479988 0.082199998 -6.27409983 -3.71479988 0.0091000004 -0.69709998
		 -3.71479988 -0.045699999 3.48559999 -3.71479988 -0.0274 2.091399908 -3.71479988 -0.0091000004 0.69709998
		 -3.71479988 0.0274 -2.091399908 -3.71479988 0.045699999 -3.48559999 -3.71479988 0.064000003 -4.87979984
		 3.71479988 -0.1005 7.66830015 3.71479988 -0.064000003 4.87979984 3.71479988 0.082199998 -6.27409983
		 3.71479988 -0.082199998 6.27409983 3.71479988 0.0091000004 -0.69709998 3.71479988 -0.045699999 3.48559999
		 3.71479988 -0.0274 2.091399908 3.71479988 -0.0091000004 0.69709998 3.71479988 0.0274 -2.091399908
		 3.71479988 0.045699999 -3.48559999 3.71479988 0.064000003 -4.87979984 -3.71479988 0.1005 -7.66830015
		 3.71479988 0.1005 -7.66830015 3.71479988 0.58380002 -6.4776001 -3.71479988 0.58380002 -6.4776001
		 -3.71479988 0.082199998 -6.27409983 3.71479988 0.082199998 -6.27409983 3.71479988 0.56550002 -5.083399773
		 -3.71479988 0.56550002 -5.083399773 -3.71479988 0.064000003 -4.87979984 3.71479988 0.064000003 -4.87979984
		 3.71479988 0.54720002 -3.68919992 -3.71479988 0.54720002 -3.68919992 -3.71479988 0.045699999 -3.48559999
		 3.71479988 0.045699999 -3.48559999 3.71479988 0.52899998 -2.29489994 -3.71479988 0.52899998 -2.29489994
		 -3.71479988 0.0274 -2.091399908 3.71479988 0.0274 -2.091399908 3.71479988 0.51069999 -0.90069997
		 -3.71479988 0.51069999 -0.90069997 -3.71479988 0.0091000004 -0.69709998 3.71479988 0.0091000004 -0.69709998
		 3.71479988 0.49239999 0.49349999 -3.71479988 0.49239999 0.49349999 -3.71479988 -0.0091000004 0.69709998
		 3.71479988 -0.0091000004 0.69709998 3.71479988 0.47409999 1.88779998 -3.71479988 0.47409999 1.88779998
		 -3.71479988 -0.0274 2.091399908 3.71479988 -0.0274 2.091399908 3.71479988 0.45590001 3.28200006
		 -3.71479988 0.45590001 3.28200006 -3.71479988 -0.045699999 3.48559999 3.71479988 -0.045699999 3.48559999
		 3.71479988 0.43759999 4.67619991 -3.71479988 0.43759999 4.67619991 -3.71479988 -0.064000003 4.87979984
		 3.71479988 -0.064000003 4.87979984 3.71479988 0.41929999 6.070499897 -3.71479988 0.41929999 6.070499897
		 -3.71479988 -0.082199998 6.27409983 3.71479988 -0.082199998 6.27409983 3.71479988 0.40099999 7.46470022
		 -3.71479988 0.40099999 7.46470022 -3.71479988 0.58380002 -6.4776001 3.71479988 0.58380002 -6.4776001
		 3.71479988 0.082199998 -6.27409983 -3.71479988 0.082199998 -6.27409983 -3.71479988 0.56550002 -5.083399773
		 3.71479988 0.56550002 -5.083399773 3.71479988 0.064000003 -4.87979984 -3.71479988 0.064000003 -4.87979984
		 -3.71479988 0.54720002 -3.68919992 3.71479988 0.54720002 -3.68919992 3.71479988 0.045699999 -3.48559999
		 -3.71479988 0.045699999 -3.48559999 -3.71479988 0.52899998 -2.29489994 3.71479988 0.52899998 -2.29489994
		 3.71479988 0.0274 -2.091399908 -3.71479988 0.0274 -2.091399908 -3.71479988 0.51069999 -0.90069997
		 3.71479988 0.51069999 -0.90069997 3.71479988 0.0091000004 -0.69709998 -3.71479988 0.0091000004 -0.69709998
		 -3.71479988 0.49239999 0.49349999 3.71479988 0.49239999 0.49349999 3.71479988 -0.0091000004 0.69709998
		 -3.71479988 -0.0091000004 0.69709998 -3.71479988 0.47409999 1.88779998 3.71479988 0.47409999 1.88779998
		 3.71479988 -0.0274 2.091399908 -3.71479988 -0.0274 2.091399908 -3.71479988 0.45590001 3.28200006
		 3.71479988 0.45590001 3.28200006 3.71479988 -0.045699999 3.48559999 -3.71479988 -0.045699999 3.48559999
		 -3.71479988 0.43759999 4.67619991 3.71479988 0.43759999 4.67619991 3.71479988 -0.064000003 4.87979984
		 -3.71479988 -0.064000003 4.87979984 -3.71479988 0.41929999 6.070499897 3.71479988 0.41929999 6.070499897
		 3.71479988 -0.082199998 6.27409983 -3.71479988 -0.082199998 6.27409983 -3.71479988 0.40099999 7.46470022
		 3.71479988 0.40099999 7.46470022 3.71479988 -0.1005 7.66830015 -3.71479988 -0.1005 7.66830015;
	setAttr -s 144 ".ed[0:143]"  0 1 0 2 1 0 0 2 0 3 2 0 3 4 0 4 2 0 4 5 0
		 5 2 0 4 6 0 6 5 0 4 7 0 7 6 0 8 4 0 3 9 0 9 8 0 3 10 0 10 9 0 11 12 0 12 13 0 11 14 0
		 14 12 0 12 15 0 12 16 0 16 15 0 16 17 0 17 15 0 17 18 0 18 15 0 15 19 0 19 13 0 19 20 0
		 20 13 0 20 21 0 21 13 0 22 23 0 23 24 0 24 22 0 24 25 0 25 22 0 26 27 0 27 28 0 28 26 0
		 28 29 0 29 26 0 30 31 0 31 32 0 32 30 0 32 33 0 33 30 0 34 35 0 35 36 0 36 34 0 36 37 0
		 37 34 0 38 39 0 39 40 0 40 38 0 40 41 0 41 38 0 42 43 0 43 44 0 44 42 0 44 45 0 45 42 0
		 46 47 0 47 48 0 48 46 0 48 49 0 49 46 0 50 51 0 51 52 0 52 50 0 52 53 0 53 50 0 54 55 0
		 55 56 0 56 54 0 56 57 0 57 54 0 58 59 0 59 60 0 60 58 0 60 61 0 61 58 0 62 63 0 63 64 0
		 64 62 0 64 65 0 65 62 0 66 67 0 67 68 0 68 66 0 68 69 0 69 66 0 70 71 0 71 72 0 72 70 0
		 72 73 0 73 70 0 74 75 0 75 76 0 76 74 0 76 77 0 77 74 0 78 79 0 79 80 0 80 78 0 80 81 0
		 81 78 0 82 83 0 83 84 0 84 82 0 84 85 0 85 82 0 86 87 0 87 88 0 88 86 0 88 89 0 89 86 0
		 90 91 0 91 92 0 92 90 0 92 93 0 93 90 0 94 95 0 95 96 0 96 94 0 96 97 0 97 94 0 98 99 0
		 99 100 0 100 98 0 100 101 0 101 98 0 102 103 0 103 104 0 104 102 0 104 105 0 105 102 0
		 106 107 0 107 108 0 108 106 0 108 109 0 109 106 0;
	setAttr -s 176 ".n";
	setAttr ".n[0:165]" -type "float3"  -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0
		 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198
		 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927
		 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.92658198 -0.3760927 0 0.3760927
		 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0
		 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198
		 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927
		 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0
		 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198
		 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927
		 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0
		 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198
		 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927
		 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0
		 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198
		 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927
		 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0
		 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198
		 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927
		 0.92658198;
	setAttr ".n[166:175]" -type "float3"  0 0.3760927 0.92658198 0 0.3760927 0.92658198
		 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927
		 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0 0.3760927 0.92658198 0
		 0.3760927 0.92658198;
	setAttr -s 58 -ch 176 ".fc[0:57]" -type "polyFaces" 
		f 3 -3 0 -2
		f 3 3 -6 -5
		f 3 5 -8 -7
		f 3 6 -10 -9
		f 3 8 -12 -11
		f 4 -15 -14 4 -13
		f 3 13 -17 -16
		f 3 17 -21 -20
		f 3 21 -24 -23
		f 3 23 -26 -25
		f 3 25 -28 -27
		f 4 -30 -29 -22 18
		f 3 29 -32 -31
		f 3 31 -34 -33
		f 3 -37 -36 -35
		f 3 -39 -38 36
		f 3 -42 -41 -40
		f 3 -44 -43 41
		f 3 -47 -46 -45
		f 3 -49 -48 46
		f 3 -52 -51 -50
		f 3 -54 -53 51
		f 3 -57 -56 -55
		f 3 -59 -58 56
		f 3 -62 -61 -60
		f 3 -64 -63 61
		f 3 -67 -66 -65
		f 3 -69 -68 66
		f 3 -72 -71 -70
		f 3 -74 -73 71
		f 3 -77 -76 -75
		f 3 -79 -78 76
		f 3 -82 -81 -80
		f 3 -84 -83 81
		f 3 -87 -86 -85
		f 3 -89 -88 86
		f 3 -92 -91 -90
		f 3 -94 -93 91
		f 3 -97 -96 -95
		f 3 -99 -98 96
		f 3 -102 -101 -100
		f 3 -104 -103 101
		f 3 -107 -106 -105
		f 3 -109 -108 106
		f 3 -112 -111 -110
		f 3 -114 -113 111
		f 3 -117 -116 -115
		f 3 -119 -118 116
		f 3 -122 -121 -120
		f 3 -124 -123 121
		f 3 -127 -126 -125
		f 3 -129 -128 126
		f 3 -132 -131 -130
		f 3 -134 -133 131
		f 3 -137 -136 -135
		f 3 -139 -138 136
		f 3 -142 -141 -140
		f 3 -144 -143 141;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "transform1" -p "conector_1";
	rename -uid "4A30E421-4DD0-9BBB-C8BD-CAAF8BF3F79B";
	setAttr ".v" no;
createNode mesh -n "conector_1Shape" -p "transform1";
	rename -uid "EBE1EF37-4AB6-DF5C-216E-259DCA4608E9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".pt";
	setAttr ".pt[6]" -type "float3" 0 2.9802322e-008 5.9604645e-008 ;
	setAttr ".pt[8]" -type "float3" 0 -1.0430813e-007 -6.3329935e-008 ;
	setAttr ".pt[9]" -type "float3" 0 -1.6391277e-007 -1.527369e-007 ;
	setAttr ".pt[10]" -type "float3" 0 0 -5.9604645e-008 ;
	setAttr ".pt[13]" -type "float3" 0 0 -2.9802322e-008 ;
	setAttr ".pt[16]" -type "float3" 0 5.9604645e-008 1.1920929e-007 ;
createNode transform -n "mid_4" -p "Script";
	rename -uid "C7D0AEF0-4FBF-8F7A-23C5-D58157FAA6B6";
	setAttr ".t" -type "double3" -74.65 4.88 85.87 ;
	setAttr ".ro" 2;
createNode transform -n "mid_5" -p "mid_4";
	rename -uid "F78244B7-4A37-B9B9-9553-73A010BD4951";
	setAttr ".t" -type "double3" 0.62 0 -0.07 ;
	setAttr ".ro" 2;
createNode transform -n "transform2" -p "mid_5";
	rename -uid "78358B22-4573-ACDF-D456-58A3BC95406D";
	setAttr ".v" no;
createNode mesh -n "mid_5Shape" -p "transform2";
	rename -uid "F3F80705-4B7A-60AF-1431-E6BDEBB8F2C3";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -9.60680008 16.75589943 1 -9.60680008 16.75589943 -1
		 9.60680008 16.75589943 -1 9.60680008 16.75589943 1 9.60680008 0 -1 9.60680008 16.75589943 -1
		 -9.60680008 16.75589943 -1 -9.60680008 0 -1;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1;
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
createNode transform -n "conector_2" -p "Script";
	rename -uid "C5DA0E28-4FBF-FA45-E72A-E5959E9DC261";
	setAttr ".t" -type "double3" -38.78 3.67 49.38 ;
	setAttr ".ro" 2;
createNode transform -n "conector_3" -p "conector_2";
	rename -uid "80032A38-47E9-B435-28F7-DBBF9399A1C5";
	setAttr ".ro" 2;
createNode transform -n "transform4" -p "conector_3";
	rename -uid "C89F4C85-4762-C1DF-5B6B-0F928ACFC9C6";
	setAttr ".v" no;
createNode mesh -n "conector_3Shape" -p "transform4";
	rename -uid "0CADD694-449E-5D85-A9D3-1A9C5D7C0EA7";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 1 0 1 1 0 1 0 0 0
		 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -1.60020006 0 7.3119998 -1.60020006 0 -7.3119998
		 1.60020006 0 -7.3119998 1.60020006 0 7.3119998 -1.60020006 0 7.3119998 1.60020006 0 7.3119998
		 1.60020006 -5.95419979 7.3119998 -1.60020006 -5.95419979 7.3119998 1.60020006 0 7.3119998
		 1.60020006 0 -7.3119998 1.60020006 -5.95419979 -7.3119998 1.60020006 -5.95419979 7.3119998;
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
createNode transform -n "Box" -p "Script";
	rename -uid "98E491A7-4EF5-A27A-1884-118B4FFBC84B";
	setAttr ".t" -type "double3" -32.8 -1.59 63.76 ;
	setAttr ".ro" 2;
createNode transform -n "Box_1" -p "Box";
	rename -uid "11979B96-468D-9D16-3D27-51953F591F45";
	setAttr ".ro" 2;
createNode transform -n "transform19" -p "Box_1";
	rename -uid "C3F386F2-417D-9258-C30F-BD8299130583";
	setAttr ".v" no;
createNode mesh -n "Box_1Shape" -p "transform19";
	rename -uid "46F5D279-45F6-BDA0-2024-9AB809D5EBF4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  13.52320004 0.76840001 -7.068999767 13.52320004 0.76840001 7.068999767
		 -13.52320004 0.76840001 7.068999767 -13.52320004 0.76840001 -7.068999767;
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
createNode transform -n "conector_4" -p "Script";
	rename -uid "10F896C3-45A4-8511-B61D-7B84D79EF058";
	setAttr ".t" -type "double3" -26.16 3.44 50 ;
	setAttr ".ro" 2;
createNode transform -n "conector_5" -p "conector_4";
	rename -uid "C8B0C2F0-46C7-5A07-AF61-B888EBAC6FD0";
	setAttr ".t" -type "double3" 0 0 -0.72 ;
	setAttr ".ro" 2;
createNode transform -n "transform18" -p "conector_5";
	rename -uid "296847C5-45AC-5848-6538-7387723361ED";
	setAttr ".v" no;
createNode mesh -n "conector_5Shape" -p "transform18";
	rename -uid "B95833B9-4A68-7286-5E98-FE918E34BE3B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -0.50370002 18.23500061 5.8993001 -0.50370002 18.23500061 -5.87220001
		 0.50370002 18.23500061 -5.87220001 0.50370002 18.23500061 5.8993001 -0.50370002 0 -5.88570023
		 -0.50370002 18.23500061 -5.87220001 -0.50370002 18.23500061 5.8993001 -0.50370002 0 5.88570023;
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
createNode transform -n "Box_2" -p "Script";
	rename -uid "67FC28BB-4755-0D5C-BE57-0FAFF97A31B7";
	setAttr ".t" -type "double3" -55.9 1.59 53.94 ;
	setAttr ".ro" 2;
createNode transform -n "Box_3" -p "Box_2";
	rename -uid "9962E997-450C-AE81-B3CB-2A8BB2DB07BE";
	setAttr ".ro" 2;
createNode transform -n "transform13" -p "Box_3";
	rename -uid "620F13B7-4EBC-50A1-B470-8FA7A9B42790";
	setAttr ".v" no;
createNode mesh -n "Box_3Shape" -p "transform13";
	rename -uid "D525942A-4A71-330B-DF3F-739B71537C1A";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -10.43939972 3.29159999 2.76609993 -10.43939972 3.29159999 -2.76609993
		 10.43939972 3.29159999 -2.76609993 10.43939972 3.29159999 2.76609993 -10.43939972 -3.29159999 2.76609993
		 -10.43939972 3.29159999 2.76609993 10.43939972 3.29159999 2.76609993 10.43939972 -3.29159999 2.76609993;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1;
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
createNode transform -n "mid_6" -p "Script";
	rename -uid "266C3BDE-4EB1-AACC-0D2F-478C52B06A37";
	setAttr ".t" -type "double3" -22.05 -1.13 71.5 ;
	setAttr ".ro" 2;
createNode transform -n "mid_7" -p "mid_6";
	rename -uid "9C5FBEA2-40CC-C76D-A335-DC9794EC190E";
	setAttr ".ro" 2;
createNode transform -n "transform16" -p "mid_7";
	rename -uid "4DA62EA3-4DFD-420E-F5D8-049076B0A3AF";
	setAttr ".v" no;
createNode mesh -n "mid_7Shape" -p "transform16";
	rename -uid "75810AA1-4E3D-1FF0-7C3A-7FA07AC25CA9";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -2.8908 21.94179916 0.72680002 -2.8908 21.94179916 -0.72680002
		 2.8908 21.94179916 -0.72680002 2.8908 21.94179916 0.72680002 2.8908 0 -0.72680002
		 2.8908 21.94179916 -0.72680002 -2.8908 21.94179916 -0.72680002 -2.8908 0 -0.72680002
		 -2.8908 0 -0.72680002 -2.8908 21.94179916 -0.72680002 -2.8908 21.94179916 0.72680002
		 -2.8908 0 0.72680002;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0;
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
createNode transform -n "conector_6" -p "Script";
	rename -uid "70D52218-4729-51B9-A107-17BB8850CC41";
	setAttr ".t" -type "double3" -28.24 3.67 49.38 ;
	setAttr ".ro" 2;
createNode transform -n "conector_7" -p "conector_6";
	rename -uid "C86A9FE7-40B2-8469-8F45-E5B306254DAE";
	setAttr ".ro" 2;
createNode transform -n "transform15" -p "conector_7";
	rename -uid "24920582-4C9C-A87D-3243-D9A9B0E06070";
	setAttr ".v" no;
createNode mesh -n "conector_7Shape" -p "transform15";
	rename -uid "7D30C408-40A7-3E31-8385-DDB694AE4C36";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 1 0 1 1 0 1 0 0 0
		 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -1.60020006 0 7.3119998 -1.60020006 0 -7.3119998
		 1.60020006 0 -7.3119998 1.60020006 0 7.3119998 -1.60020006 0 7.3119998 1.60020006 0 7.3119998
		 1.60020006 -5.95419979 7.3119998 -1.60020006 -5.95419979 7.3119998 -1.60020006 0 -7.3119998
		 -1.60020006 0 7.3119998 -1.60020006 -5.95419979 7.3119998 -1.60020006 -5.95419979 -7.3119998;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0;
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
createNode transform -n "Box_4" -p "Script";
	rename -uid "04912653-48DC-EF98-DE83-F58F4117DB8F";
	setAttr ".t" -type "double3" -35.36 1.59 74.41 ;
	setAttr ".ro" 2;
createNode transform -n "Box_5" -p "Box_4";
	rename -uid "059C04C1-4BC7-3EB0-D5F9-D1900300250D";
	setAttr ".ro" 2;
createNode transform -n "transform14" -p "Box_5";
	rename -uid "CB20B4DD-4B1C-A33A-A6B9-36851A270B8D";
	setAttr ".v" no;
createNode mesh -n "Box_5Shape" -p "transform14";
	rename -uid "36E9101E-4805-A222-E6A7-B4AD124F8AFE";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -10.37290001 3.29159999 3.61129999 -10.37290001 3.29159999 -3.61129999
		 10.37290001 3.29159999 -3.61129999 10.37290001 3.29159999 3.61129999 10.37290001 -3.29159999 -3.61129999
		 10.37290001 3.29159999 -3.61129999 -10.37290001 3.29159999 -3.61129999 -10.37290001 -3.29159999 -3.61129999;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1;
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
createNode transform -n "mid_8" -p "Script";
	rename -uid "62999AF8-4731-B433-FA2C-649C3596C1D2";
	setAttr ".t" -type "double3" -84.78 4.8 78.74 ;
	setAttr ".ro" 2;
createNode transform -n "mid_9" -p "mid_8";
	rename -uid "C5D55CC9-4AB2-E494-5E36-15A688984975";
	setAttr ".t" -type "double3" 0.18 0 0.11 ;
	setAttr ".ro" 2;
createNode transform -n "transform12" -p "mid_9";
	rename -uid "95FE33D4-4577-252D-4E1A-5AB6054F1363";
	setAttr ".v" no;
createNode mesh -n "mid_9Shape" -p "transform12";
	rename -uid "E5DAE7FD-4AB4-EA3A-C7ED-EB9934450905";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:7]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 16 ".uvst[0].uvsp[0:15]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 16 ".vt[0:15]"  -1 16.67230034 6 -1 16.67230034 -6 1 16.67230034 -6
		 1 16.67230034 6 1 0 6 1 16.67230034 6 1 16.67230034 -6 1 0 -6 1 0 -6 1 16.67230034 -6
		 -1 16.67230034 -6 -1 0 -6 -1 0 -6 -1 16.67230034 -6 -1 16.67230034 6 -1 0 6;
	setAttr -s 20 ".ed[0:19]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0 12 13 0 13 14 0 14 12 0 14 15 0
		 15 12 0;
	setAttr -s 24 ".n[0:23]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
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
createNode transform -n "mid_10" -p "Script";
	rename -uid "28FBF26A-4D21-AD85-888B-A3B642F7C64F";
	setAttr ".t" -type "double3" -23.01 -0.84 53.87 ;
	setAttr ".ro" 2;
createNode transform -n "mid_11" -p "mid_10";
	rename -uid "7D58E4DC-4177-9500-10CE-E59659AF16F7";
	setAttr ".t" -type "double3" 0 0 0.1 ;
	setAttr ".ro" 2;
createNode transform -n "transform11" -p "mid_11";
	rename -uid "375D2E38-407E-9BCE-F1DD-46A48F55CB46";
	setAttr ".v" no;
createNode mesh -n "mid_11Shape" -p "transform11";
	rename -uid "25C35ABD-4053-80C3-7628-F18F3A814294";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 12 ".vt[0:11]"  -3.64779997 22.3871994 2.79110003 -3.64779997 22.3871994 1.18359995
		 3.64779997 22.3871994 1.18359995 3.64779997 22.3871994 2.79110003 -3.64779997 0 2.77760005
		 -3.64779997 22.3871994 2.79110003 3.64779997 22.3871994 2.79110003 3.64779997 0 2.77760005
		 -3.64779997 0 1.17009997 -3.64779997 22.3871994 1.18359995 -3.64779997 22.3871994 2.79110003
		 -3.64779997 0 2.77760005;
	setAttr -s 15 ".ed[0:14]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0;
	setAttr -s 18 ".n[0:17]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 -0.00060000003 0.99999988 0 -0.00060000003 0.99999988 0 -0.00060000003
		 0.99999988 0 -0.00060000003 0.99999988 0 -0.00060000003 0.99999988 0 -0.00060000003
		 0.99999988 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
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
createNode transform -n "Box_6" -p "Script";
	rename -uid "6852AE24-4CFE-A752-9D14-AAAB48673681";
	setAttr ".t" -type "double3" -56.45 1.21 63.71 ;
	setAttr ".r" -type "double3" 0 0 -15.913219999999999 ;
	setAttr ".ro" 2;
createNode transform -n "Box_7" -p "Box_6";
	rename -uid "BCB978BD-4B0C-DB7C-A455-80BB01A52497";
	setAttr ".t" -type "double3" -0.07 0.06 0.06 ;
	setAttr ".ro" 2;
createNode transform -n "transform7" -p "Box_7";
	rename -uid "055243B9-4B9B-69E8-CFDC-03A439EA9B9A";
	setAttr ".v" no;
createNode mesh -n "Box_7Shape" -p "transform7";
	rename -uid "0A18DF27-4BB0-CAA1-3B30-378595854045";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:11]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 24 ".uvst[0].uvsp[0:23]" -type "float2" 1 0 0 0 0 1 1 1 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 24 ".vt[0:23]"  -10.43939972 -0.76499999 7.068999767 10.43939972 -0.76499999 7.068999767
		 10.43939972 -0.76499999 -7.068999767 -10.43939972 -0.76499999 -7.068999767 -10.43939972 0.76499999 7.068999767
		 -10.43939972 0.76499999 -7.068999767 10.43939972 0.76499999 -7.068999767 10.43939972 0.76499999 7.068999767
		 -10.43939972 -0.76499999 7.068999767 -10.43939972 0.76499999 7.068999767 10.43939972 0.76499999 7.068999767
		 10.43939972 -0.76499999 7.068999767 10.43939972 -0.76499999 7.068999767 10.43939972 0.76499999 7.068999767
		 10.43939972 0.76499999 -7.068999767 10.43939972 -0.76499999 -7.068999767 10.43939972 -0.76499999 -7.068999767
		 10.43939972 0.76499999 -7.068999767 -10.43939972 0.76499999 -7.068999767 -10.43939972 -0.76499999 -7.068999767
		 -10.43939972 -0.76499999 -7.068999767 -10.43939972 0.76499999 -7.068999767 -10.43939972 0.76499999 7.068999767
		 -10.43939972 -0.76499999 7.068999767;
	setAttr -s 30 ".ed[0:29]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0 12 13 0 13 14 0 14 12 0 14 15 0
		 15 12 0 16 17 0 17 18 0 18 16 0 18 19 0 19 16 0 20 21 0 21 22 0 22 20 0 22 23 0 23 20 0;
	setAttr -s 36 ".n[0:35]" -type "float3"  0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0
		 0 1 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 12 -ch 36 ".fc[0:11]" -type "polyFaces" 
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
		f 3 -23 -22 -21
		mu 0 3 16 18 17
		f 3 -25 -24 22
		mu 0 3 16 19 18
		f 3 -28 -27 -26
		mu 0 3 20 22 21
		f 3 -30 -29 27
		mu 0 3 20 23 22;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "Box_8" -p "Script";
	rename -uid "FE715890-4A4A-C18A-5AC5-FE98EF3E6878";
	setAttr ".t" -type "double3" -74.95 4.115 68.08 ;
	setAttr ".ro" 2;
createNode transform -n "Box_9" -p "Box_8";
	rename -uid "867AB0F6-422E-4B7B-6794-D0B9CABAF307";
	setAttr ".ro" 2;
createNode transform -n "transform6" -p "Box_9";
	rename -uid "238D2AC3-484D-B14D-2F39-F88F9544204C";
	setAttr ".v" no;
createNode mesh -n "Box_9Shape" -p "transform6";
	rename -uid "D0B6AF3C-4796-6CEC-5BC1-47B525118567";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:1]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 1 1 1 0 0 0 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 4 ".vt[0:3]"  8.61310005 0.76840001 -16.90369987 8.61310005 0.76840001 16.90369987
		 -8.61310005 0.76840001 16.90369987 -8.61310005 0.76840001 -16.90369987;
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
createNode transform -n "conector_8" -p "Script";
	rename -uid "FFB0B998-4BCB-0B09-AC7B-41A9AAC9C06A";
	setAttr ".t" -type "double3" -42.94 -1.32 49.46 ;
	setAttr ".ro" 2;
createNode transform -n "conector_9" -p "conector_8";
	rename -uid "3AC7ECC8-4E32-9263-C4D3-97A62412A594";
	setAttr ".ro" 2;
createNode transform -n "transform5" -p "conector_9";
	rename -uid "270DD50F-43AC-E188-8BD2-FF92BC8527B3";
	setAttr ".v" no;
createNode mesh -n "conector_9Shape" -p "transform5";
	rename -uid "8034FBFD-416A-7797-97ED-70995B2CE44C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:7]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 16 ".uvst[0].uvsp[0:15]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 16 ".vt[0:15]"  -2.5402 22.3871994 7.25589991 -2.5402 22.3871994 -6.058700085
		 2.5402 22.3871994 -6.058700085 2.5402 22.3871994 7.25589991 -2.5402 0 7.31899977
		 -2.5402 22.3871994 7.25589991 2.5402 22.3871994 7.25589991 2.5402 0 7.31899977 2.5402 0 7.31899977
		 2.5402 22.3871994 7.25589991 2.5402 22.3871994 -6.058700085 2.5402 0 -5.99560022
		 -2.5402 0 -5.99560022 -2.5402 22.3871994 -6.058700085 -2.5402 22.3871994 7.25589991
		 -2.5402 0 7.31899977;
	setAttr -s 20 ".ed[0:19]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 8 9 0 9 10 0 10 8 0 10 11 0 11 8 0 12 13 0 13 14 0 14 12 0 14 15 0
		 15 12 0;
	setAttr -s 24 ".n[0:23]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0.002799989 0.99999613 0 0.002799989 0.99999613 0 0.002799989 0.99999613
		 0 0.002799989 0.99999613 0 0.002799989 0.99999613 0 0.002799989 0.99999613 1 0 0
		 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
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
createNode transform -n "mid_12" -p "Script";
	rename -uid "E7EE8552-4415-6851-6AA2-B0A57C361CD7";
	setAttr ".t" -type "double3" -44.7 4.84 78.84 ;
	setAttr ".ro" 2;
createNode transform -n "mid_13" -p "mid_12";
	rename -uid "3C93F2B0-472D-5D74-FCB3-70BDDE30E07D";
	setAttr ".ro" 2;
createNode transform -n "transform10" -p "mid_13";
	rename -uid "2A7D28E3-48C2-E7A3-A1F4-8F85BA4A611E";
	setAttr ".v" no;
createNode mesh -n "mid_13Shape" -p "transform10";
	rename -uid "5F6D3CCB-46AE-E4F1-C6C4-D7A0AA09EF9E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:59]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 102 ".uvst[0].uvsp[0:101]" -type "float2" 0.42860001 0 0.42860001
		 0 0.57139999 0 0.57139999 0 0.57139999 1 0.57139999 0 0.57139999 0 0.57139999 0.5
		 0.57139999 1 0.57139999 1 0.57139999 1 0.42860001 1 0.42860001 1 0.42860001 0.5 0.42860001
		 0 0.42860001 0 0.42860001 1 0.42860001 1 0.71429998 0 0.71429998 0 0.85710001 0 0.85710001
		 0 0.85710001 1 0.85710001 0 0.85710001 0 0.85710001 0.5 0.85710001 1 0.85710001 1
		 0.85710001 1 0.71429998 1 0.71429998 1 0.71429998 0.5 0.71429998 0 0.71429998 0 0.71429998
		 1 0.71429998 1 0.1429 0 0.1429 0 0.28569999 0 0.28569999 0 0.28569999 1 0.28569999
		 0 0.28569999 0 0.28569999 0.5 0.28569999 1 0.28569999 1 0.28569999 1 0.1429 1 0.1429
		 1 0.1429 0.5 0.1429 0 0.1429 0 0.1429 1 0.1429 1 0 0 0 1 0.1429 1 0.28569999 1 0.42860001
		 1 0.57139999 1 0.71429998 1 0.85710001 1 1 1 1 0 0.42860001 0 0.42860001 0.5 0.57139999
		 0.5 0.57139999 0 0.42860001 1 0.57139999 1 0.85710001 0 0.85710001 1 1 1 1 0 0.71429998
		 0 0.71429998 0.5 0.85710001 0.5 0.85710001 0 0.71429998 1 0.85710001 1 0.57139999
		 0 0.57139999 1 0.71429998 1 0.71429998 0 0.1429 1 0.1429 0 0 0 0 1 0.28569999 1 0.28569999
		 0.5 0.1429 0.5 0.1429 1 0.28569999 0 0.1429 0 0.42860001 1 0.42860001 0 0.28569999
		 0 0.28569999 1 0 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 102 ".vt[0:101]"  -1.73290002 0 -1 -1.73290002 0 -1.77499998
		 -3.097300053 0 -1.77499998 -3.097300053 0 -1 -3.097300053 16.75589943 -1 -3.097300053 0 -1
		 -3.097300053 0 -1.77499998 -3.097300053 12.34259987 -1.77499998 -3.097300053 16.75589943 -1.22379994
		 -3.097300053 16.75589943 -1 -3.097300053 16.75589943 -1.22379994 -1.73290002 16.75589943 -1.22379994
		 -1.73290002 16.75589943 -1 -1.73290002 12.34259987 -1.77499998 -1.73290002 0 -1.77499998
		 -1.73290002 0 -1 -1.73290002 16.75589943 -1 -1.73290002 16.75589943 -1.22379994 -14.12409973 0 -1
		 -14.12409973 0 -1.77499998 -15.48649979 0 -1.77499998 -15.48649979 0 -1 -15.48649979 16.75589943 -1
		 -15.48649979 0 -1 -15.48649979 0 -1.77499998 -15.48649979 12.34259987 -1.77499998
		 -15.48649979 16.75589943 -1.22379994 -15.48649979 16.75589943 -1 -15.48649979 16.75589943 -1.22379994
		 -14.12409973 16.75589943 -1.22379994 -14.12409973 16.75589943 -1 -14.12409973 12.34259987 -1.77499998
		 -14.12409973 0 -1.77499998 -14.12409973 0 -1 -14.12409973 16.75589943 -1 -14.12409973 16.75589943 -1.22379994
		 10.76369953 0 -1 10.76369953 0 -1.77499998 9.29189968 0 -1.77499998 9.29189968 0 -1
		 9.29189968 16.75589943 -1 9.29189968 0 -1 9.29189968 0 -1.77499998 9.29189968 12.34259987 -1.77499998
		 9.29189968 16.75589943 -1.22379994 9.29189968 16.75589943 -1 9.29189968 16.75589943 -1.22379994
		 10.76369953 16.75589943 -1.22379994 10.76369953 16.75589943 -1 10.76369953 12.34259987 -1.77499998
		 10.76369953 0 -1.77499998 10.76369953 0 -1 10.76369953 16.75589943 -1 10.76369953 16.75589943 -1.22379994
		 -21.68120003 16.75589943 1 -21.68120003 16.75589943 -1 -15.48649979 16.75589943 -1
		 -14.12409973 16.75589943 -1 -3.097300053 16.75589943 -1 -1.73290002 16.75589943 -1
		 9.29189968 16.75589943 -1 10.76369953 16.75589943 -1 21.68120003 16.75589943 -1 21.68120003 16.75589943 1
		 -1.73290002 0 -1.77499998 -1.73290002 12.34259987 -1.77499998 -3.097300053 12.34259987 -1.77499998
		 -3.097300053 0 -1.77499998 -1.73290002 16.75589943 -1.22379994 -3.097300053 16.75589943 -1.22379994
		 -15.48649979 0 -1 -15.48649979 16.75589943 -1 -21.68120003 16.75589943 -1 -21.68120003 0 -1
		 -14.12409973 0 -1.77499998 -14.12409973 12.34259987 -1.77499998 -15.48649979 12.34259987 -1.77499998
		 -15.48649979 0 -1.77499998 -14.12409973 16.75589943 -1.22379994 -15.48649979 16.75589943 -1.22379994
		 -3.097300053 0 -1 -3.097300053 16.75589943 -1 -14.12409973 16.75589943 -1 -14.12409973 0 -1
		 10.76369953 16.75589943 -1 10.76369953 0 -1 21.68120003 0 -1 21.68120003 16.75589943 -1
		 9.29189968 16.75589943 -1.22379994 9.29189968 12.34259987 -1.77499998 10.76369953 12.34259987 -1.77499998
		 10.76369953 16.75589943 -1.22379994 9.29189968 0 -1.77499998 10.76369953 0 -1.77499998
		 -1.73290002 16.75589943 -1 -1.73290002 0 -1 9.29189968 0 -1 9.29189968 16.75589943 -1
		 -21.68120003 0 -1 -21.68120003 16.75589943 -1 -21.68120003 16.75589943 1 -21.68120003 0 1;
	setAttr -s 141 ".ed[0:140]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0 7 8 0 8 4 0 9 10 0 10 11 0 11 9 0 11 12 0 12 9 0 13 14 0 14 15 0
		 15 13 0 15 16 0 16 13 0 16 17 0 17 13 0 18 19 0 19 20 0 20 18 0 20 21 0 21 18 0 22 23 0
		 23 24 0 24 22 0 24 25 0 25 22 0 25 26 0 26 22 0 27 28 0 28 29 0 29 27 0 29 30 0 30 27 0
		 31 32 0 32 33 0 33 31 0 33 34 0 34 31 0 34 35 0 35 31 0 36 37 0 37 38 0 38 36 0 38 39 0
		 39 36 0 40 41 0 41 42 0 42 40 0 42 43 0 43 40 0 43 44 0 44 40 0 45 46 0 46 47 0 47 45 0
		 47 48 0 48 45 0 49 50 0 50 51 0 51 49 0 51 52 0 52 49 0 52 53 0 53 49 0 54 55 0 55 56 0
		 56 54 0 56 57 0 57 54 0 57 58 0 58 54 0 58 59 0 59 54 0 59 60 0 60 54 0 60 61 0 61 54 0
		 61 62 0 62 54 0 62 63 0 63 54 0 64 65 0 65 66 0 66 64 0 66 67 0 67 64 0 65 68 0 68 66 0
		 68 69 0 69 66 0 70 71 0 71 72 0 72 70 0 72 73 0 73 70 0 74 75 0 75 76 0 76 74 0 76 77 0
		 77 74 0 75 78 0 78 76 0 78 79 0 79 76 0 80 81 0 81 82 0 82 80 0 82 83 0 83 80 0 84 85 0
		 85 86 0 86 84 0 86 87 0 87 84 0 88 89 0 89 90 0 90 88 0 90 91 0 91 88 0 89 92 0 92 90 0
		 92 93 0 93 90 0 94 95 0 95 96 0 96 94 0 96 97 0 97 94 0 98 99 0 99 100 0 100 98 0
		 100 101 0 101 98 0;
	setAttr -s 180 ".n";
	setAttr ".n[0:165]" -type "float3"  0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0
		 -1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 0 1 0 0 1 0 0
		 1 0 0 1 0 0 1 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0
		 0 1 0 0 1 0 0 1 0 0 1 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 -1 0 0 -1 0 0
		 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0
		 1 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0
		 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 0 -1 0 0.062098142 -0.99807012 0 0.062098142
		 -0.99807012 0 0 -1 0 0 -1 0 0.062098142 -0.99807012 0 0.062098142 -0.99807012 0 0.1238993
		 -0.99229479 0 0.062098142 -0.99807012 0 0.062098142 -0.99807012 0 0.1238993 -0.99229479
		 0 0.1238993 -0.99229479 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0.062098142
		 -0.99807012 0 0.062098142 -0.99807012 0 0 -1 0 0 -1 0 0.062098142 -0.99807012 0 0.062098142
		 -0.99807012 0 0.1238993 -0.99229479 0 0.062098142 -0.99807012 0 0.062098142 -0.99807012
		 0 0.1238993 -0.99229479 0 0.1238993 -0.99229479 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1
		 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0.1238993 -0.99229479 0 0.062098142
		 -0.99807012 0 0.062098142 -0.99807012 0 0.1238993 -0.99229479 0 0.1238993 -0.99229479
		 0 0.062098142 -0.99807012 0 0.062098142 -0.99807012 0 0 -1 0 0.062098142 -0.99807012
		 0 0.062098142 -0.99807012;
	setAttr ".n[166:179]" -type "float3"  0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0
		 0 -1 0 0 -1 0 0 -1 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0;
	setAttr -s 60 -ch 180 ".fc[0:59]" -type "polyFaces" 
		f 3 -3 -2 -1
		mu 0 3 0 2 1
		f 3 -5 -4 2
		mu 0 3 0 3 2
		f 3 -8 -7 -6
		mu 0 3 4 6 5
		f 3 7 -10 -9
		mu 0 3 6 4 7
		f 3 9 -12 -11
		mu 0 3 7 4 8
		f 3 -15 -14 -13
		mu 0 3 9 11 10
		f 3 -17 -16 14
		mu 0 3 9 12 11
		f 3 -20 -19 -18
		mu 0 3 13 15 14
		f 3 19 -22 -21
		mu 0 3 15 13 16
		f 3 21 -24 -23
		mu 0 3 16 13 17
		f 3 -27 -26 -25
		mu 0 3 18 20 19
		f 3 -29 -28 26
		mu 0 3 18 21 20
		f 3 -32 -31 -30
		mu 0 3 22 24 23
		f 3 31 -34 -33
		mu 0 3 24 22 25
		f 3 33 -36 -35
		mu 0 3 25 22 26
		f 3 -39 -38 -37
		mu 0 3 27 29 28
		f 3 -41 -40 38
		mu 0 3 27 30 29
		f 3 -44 -43 -42
		mu 0 3 31 33 32
		f 3 43 -46 -45
		mu 0 3 33 31 34
		f 3 45 -48 -47
		mu 0 3 34 31 35
		f 3 -51 -50 -49
		mu 0 3 36 38 37
		f 3 -53 -52 50
		mu 0 3 36 39 38
		f 3 -56 -55 -54
		mu 0 3 40 42 41
		f 3 55 -58 -57
		mu 0 3 42 40 43
		f 3 57 -60 -59
		mu 0 3 43 40 44
		f 3 -63 -62 -61
		mu 0 3 45 47 46
		f 3 -65 -64 62
		mu 0 3 45 48 47
		f 3 -68 -67 -66
		mu 0 3 49 51 50
		f 3 67 -70 -69
		mu 0 3 51 49 52
		f 3 69 -72 -71
		mu 0 3 52 49 53
		f 3 -75 -74 -73
		mu 0 3 54 56 55
		f 3 74 -77 -76
		mu 0 3 56 54 57
		f 3 76 -79 -78
		mu 0 3 57 54 58
		f 3 78 -81 -80
		mu 0 3 58 54 59
		f 3 80 -83 -82
		mu 0 3 59 54 60
		f 3 82 -85 -84
		mu 0 3 60 54 61
		f 3 84 -87 -86
		mu 0 3 61 54 62
		f 3 86 -89 -88
		mu 0 3 62 54 63
		f 3 -92 -91 -90
		mu 0 3 64 66 65
		f 3 -94 -93 91
		mu 0 3 64 67 66
		f 3 -96 -95 90
		mu 0 3 66 68 65
		f 3 -98 -97 95
		mu 0 3 66 69 68
		f 3 -101 -100 -99
		mu 0 3 70 72 71
		f 3 -103 -102 100
		mu 0 3 70 73 72
		f 3 -106 -105 -104
		mu 0 3 74 76 75
		f 3 -108 -107 105
		mu 0 3 74 77 76
		f 3 -110 -109 104
		mu 0 3 76 78 75
		f 3 -112 -111 109
		mu 0 3 76 79 78
		f 3 -115 -114 -113
		mu 0 3 80 82 81
		f 3 -117 -116 114
		mu 0 3 80 83 82
		f 3 -120 -119 -118
		mu 0 3 84 86 85
		f 3 -122 -121 119
		mu 0 3 84 87 86
		f 3 -125 -124 -123
		mu 0 3 88 90 89
		f 3 -127 -126 124
		mu 0 3 88 91 90
		f 3 -129 -128 123
		mu 0 3 90 92 89
		f 3 -131 -130 128
		mu 0 3 90 93 92
		f 3 -134 -133 -132
		mu 0 3 94 96 95
		f 3 -136 -135 133
		mu 0 3 94 97 96
		f 3 -139 -138 -137
		mu 0 3 98 100 99
		f 3 -141 -140 138
		mu 0 3 98 101 100;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "mid_14" -p "Script";
	rename -uid "B9F3A5AC-47C3-6416-1EF1-6895BDF96DC8";
	setAttr ".t" -type "double3" -65.4 4.92 82.28 ;
	setAttr ".ro" 2;
createNode transform -n "mid_15" -p "mid_14";
	rename -uid "016D4E23-4242-ECE8-0349-F7918331C2FB";
	setAttr ".ro" 2;
createNode transform -n "transform9" -p "mid_15";
	rename -uid "515D534E-4344-7ACE-31B4-1FA2C7D1AC0C";
	setAttr ".v" no;
createNode mesh -n "mid_15Shape" -p "transform9";
	rename -uid "F371C849-4DF1-955D-C878-AC96A89DAA40";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -1 16.75589943 2.48119998 -1 16.75589943 -2.48119998
		 1 16.75589943 -2.48119998 1 16.75589943 2.48119998 -1 0 -2.48119998 -1 16.75589943 -2.48119998
		 -1 16.75589943 2.48119998 -1 0 2.48119998;
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
createNode transform -n "Box_10" -p "Script";
	rename -uid "163270BE-4FA2-B501-D93C-C9AB071CF70A";
	setAttr ".t" -type "double3" -55.94 1.59 74.41 ;
	setAttr ".ro" 2;
createNode transform -n "Box_11" -p "Box_10";
	rename -uid "818EDE99-4F11-34B4-0BB2-3BA2F29A2837";
	setAttr ".t" -type "double3" 0.03 0 0 ;
	setAttr ".ro" 2;
createNode transform -n "transform8" -p "Box_11";
	rename -uid "10A5EBE5-4F40-0FF4-32E9-85A549D9159C";
	setAttr ".v" no;
createNode mesh -n "Box_11Shape" -p "transform8";
	rename -uid "C9DEB3BF-46C3-BD96-4E25-01BD20A93395";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -10.43939972 3.29159999 3.61129999 -10.43939972 3.29159999 -3.61129999
		 10.43939972 3.29159999 -3.61129999 10.43939972 3.29159999 3.61129999 10.43939972 -3.29159999 -3.61129999
		 10.43939972 3.29159999 -3.61129999 -10.43939972 3.29159999 -3.61129999 -10.43939972 -3.29159999 -3.61129999;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1 0 0 -1;
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
createNode transform -n "mid_16" -p "Script";
	rename -uid "7470F4E5-48CB-3FDA-9BBB-17AFC2DA6065";
	setAttr ".t" -type "double3" -64.51 4.72 50.1 ;
	setAttr ".ro" 2;
createNode transform -n "mid_17" -p "mid_16";
	rename -uid "BE0EC30E-4397-DEDF-96A3-77B09350F60D";
	setAttr ".ro" 2;
createNode transform -n "transform3" -p "mid_17";
	rename -uid "A85BB874-4A7F-D913-5C3E-E6BE833BA2F2";
	setAttr ".v" no;
createNode mesh -n "mid_17Shape" -p "transform3";
	rename -uid "BC77A461-4AE6-14B2-B96E-10949A07BD5F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[0:3]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 2 ".ciog[0].cog";
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 8 ".uvst[0].uvsp[0:7]" -type "float2" 0 0 0 1 1 1 1 0 0
		 0 0 1 1 1 1 0;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 8 ".vt[0:7]"  -19.051300049 16.5904007 1 -19.051300049 16.5904007 -1
		 19.051300049 16.5904007 -1 19.051300049 16.5904007 1 -19.051300049 0 1 -19.051300049 16.5904007 1
		 19.051300049 16.5904007 1 19.051300049 0 1;
	setAttr -s 10 ".ed[0:9]"  0 1 0 1 2 0 2 0 0 2 3 0 3 0 0 4 5 0 5 6 0
		 6 4 0 6 7 0 7 4 0;
	setAttr -s 12 ".n[0:11]" -type "float3"  0 1 0 0 1 0 0 1 0 0 1 0 0 1
		 0 0 1 0 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1 0 0 1;
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
createNode transform -n "mid_3";
	rename -uid "8659CC6B-4FC7-C3D1-AB77-6B8A087CAF0E";
	setAttr ".rp" -type "double3" -52.379600000381465 9.6824114052177741 64.434000101089481 ;
	setAttr ".sp" -type "double3" -52.379600000381465 9.6824114052177741 64.434000101089481 ;
createNode mesh -n "mid_3Shape" -p "|mid_3";
	rename -uid "E36234AC-494B-5B2B-79C7-70980846994B";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
createNode displayLayerManager -n "layerManager";
	rename -uid "D3D5C43E-47AF-D93F-2460-9BAE1B6E1577";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "4BE96775-4DA5-E90F-80C7-9C804F3DA71A";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "48A20C41-4D6D-5E80-431D-4FBDD3E6DC33";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "A054E572-417E-D1A7-3E58-F79A3DADC880";
createNode displayLayer -n "defaultLayer";
	rename -uid "AAF48858-48AA-9A5E-CB83-2993588FB92B";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "B8699E42-4995-3F22-BA91-23BF45E3FF2E";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "C3E1C363-4277-B497-356C-CAAC56CA0CB3";
	setAttr ".g" yes;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "A3945FC0-4420-3BD8-CCF3-5382B1BE95D3";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"top\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n"
		+ "                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n"
		+ "                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n"
		+ "                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 558\n                -height 336\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n"
		+ "                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n"
		+ "            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n"
		+ "            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 558\n            -height 336\n            -sceneRenderFilter 0\n            $editorName;\n"
		+ "        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"side\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n"
		+ "                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n"
		+ "                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n"
		+ "                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 558\n                -height 335\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n"
		+ "            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n"
		+ "            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n"
		+ "            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 558\n            -height 335\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels `;\n"
		+ "\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"front\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n"
		+ "                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n"
		+ "                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n"
		+ "                -width 558\n                -height 335\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n"
		+ "            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n"
		+ "            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n"
		+ "            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 558\n            -height 335\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" == $panelName) {\n\t\tif ($useSceneConfig) {\n\t\t\t$panelName = `modelPanel -unParent -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels `;\n\t\t\t$editorName = $panelName;\n            modelEditor -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n"
		+ "                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -rendererName \"vp2Renderer\" \n                -objectFilterShowInHUD 1\n                -isFiltered 0\n"
		+ "                -colorResolution 256 256 \n                -bumpResolution 512 512 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 1\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n"
		+ "                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 1123\n                -height 716\n                -sceneRenderFilter 0\n                $editorName;\n            modelEditor -e -viewSelected 0 $editorName;\n            modelEditor -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName;\n\t\t}\n\t} else {\n"
		+ "\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n"
		+ "            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n"
		+ "            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1123\n            -height 716\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n"
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
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1123\\n    -height 716\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1123\\n    -height 716\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        setFocus `paneLayout -q -p1 $gMainPane`;\n        sceneUIReplacement -deleteRemaining;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "E475B8E9-460E-37C1-3036-509E32EB9E3A";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode polyMergeVert -n "polyMergeVert1";
	rename -uid "A3BAF551-418F-0F71-6769-79AEFA481DB1";
	setAttr ".ics" -type "componentList" 3 "vtx[9]" "vtx[34]" "vtx[77]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode deleteComponent -n "deleteComponent1";
	rename -uid "B8880D98-4B55-2C24-38F4-A0AC4F73184B";
	setAttr ".dc" -type "componentList" 1 "e[14]";
createNode deleteComponent -n "deleteComponent2";
	rename -uid "69D5EDD9-4772-B8D8-AC26-9F977B7E35EE";
	setAttr ".dc" -type "componentList" 2 "f[1]" "f[5]";
createNode deleteComponent -n "deleteComponent3";
	rename -uid "239E8FAA-4D5E-7889-051B-7590062E70CA";
	setAttr ".dc" -type "componentList" 1 "f[4]";
createNode deleteComponent -n "deleteComponent4";
	rename -uid "E40C7E8F-4556-03F5-DBDE-4EB45C6A974C";
	setAttr ".dc" -type "componentList" 1 "f[1:3]";
createNode deleteComponent -n "deleteComponent5";
	rename -uid "8444FEDD-410C-9AB8-A816-25B0CCA768B9";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "deleteComponent6";
	rename -uid "0A4C222F-43C8-A71F-86BD-3F945DEC123B";
	setAttr ".dc" -type "componentList" 1 "f[0]";
createNode deleteComponent -n "deleteComponent7";
	rename -uid "B7EAF604-4C42-16FC-57E3-9A9837A21D03";
	setAttr ".dc" -type "componentList" 2 "f[0]" "f[3]";
createNode deleteComponent -n "deleteComponent8";
	rename -uid "41674763-43F4-F824-A149-A2A9B8DDCAD6";
	setAttr ".dc" -type "componentList" 1 "f[0:1]";
createNode deleteComponent -n "deleteComponent9";
	rename -uid "7149C5E4-4299-E846-6EF9-ADB4F04F8BC0";
	setAttr ".dc" -type "componentList" 1 "f[0:1]";
createNode polyMergeVert -n "polyMergeVert2";
	rename -uid "AC0C4D77-42D2-1351-BFAF-339C4301827C";
	setAttr ".ics" -type "componentList" 2 "vtx[6]" "vtx[46]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyMergeVert -n "polyMergeVert3";
	rename -uid "53116D1D-431E-9044-13EB-2BA8EE4A5C24";
	setAttr ".ics" -type "componentList" 2 "vtx[10]" "vtx[49]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyMergeVert -n "polyMergeVert4";
	rename -uid "07EDBB8A-4DB9-EC80-6BDD-C09460B2427F";
	setAttr ".ics" -type "componentList" 1 "vtx[10]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyMergeVert -n "polyMergeVert5";
	rename -uid "D00A1826-4D79-6D80-7AAA-FCB989E628E1";
	setAttr ".ics" -type "componentList" 2 "vtx[13]" "vtx[52]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyMergeVert -n "polyMergeVert6";
	rename -uid "22B69B72-45B7-57EB-E680-4B85684C2B89";
	setAttr ".ics" -type "componentList" 2 "vtx[17]" "vtx[54]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyMergeVert -n "polyMergeVert7";
	rename -uid "17378892-42C4-1C42-E5F8-7AB8048E8721";
	setAttr ".ics" -type "componentList" 2 "vtx[21]" "vtx[57]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyMergeVert -n "polyMergeVert8";
	rename -uid "B9FA0C71-4700-9F73-1D75-84BC645037BF";
	setAttr ".ics" -type "componentList" 1 "vtx[0:81]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 0.94136724658911819 0.33738362000728833 0
		 0 -0.33738362000728833 0.94136724658911819 0 -33.490000000000002 1.3200000000000001 50.060000000000002 1;
	setAttr ".am" yes;
createNode polyUnite -n "polyUnite1";
	rename -uid "28BA3806-4A09-C24E-C227-CBB1BB5C55DF";
	setAttr -s 20 ".ip";
	setAttr -s 20 ".im";
createNode groupId -n "groupId1";
	rename -uid "12AAFE5F-445D-43B2-A81B-B0871868A41C";
	setAttr ".ihi" 0;
createNode groupId -n "groupId2";
	rename -uid "5D887447-466D-C5B1-733A-3ABEAE4CB2B4";
	setAttr ".ihi" 0;
createNode groupId -n "groupId3";
	rename -uid "EE972774-4ED4-9F9C-59CD-58B7F00AF95E";
	setAttr ".ihi" 0;
createNode groupId -n "groupId4";
	rename -uid "65C92172-4093-FC4E-C9EE-9795FD388049";
	setAttr ".ihi" 0;
createNode groupId -n "groupId5";
	rename -uid "91285301-40B1-BEBA-F9D4-2C948438361E";
	setAttr ".ihi" 0;
createNode groupId -n "groupId6";
	rename -uid "99F39ACF-4744-E3A4-B7FB-29B6C3DCD166";
	setAttr ".ihi" 0;
createNode groupId -n "groupId7";
	rename -uid "45680CFE-4F13-C2DC-43B7-608094D55598";
	setAttr ".ihi" 0;
createNode groupId -n "groupId8";
	rename -uid "E58C5D7B-42EF-74E4-8523-5AA516C35D4E";
	setAttr ".ihi" 0;
createNode groupId -n "groupId9";
	rename -uid "91E612C1-4283-2B89-DCF3-E9B0A22C98B3";
	setAttr ".ihi" 0;
createNode groupId -n "groupId10";
	rename -uid "A450C3AE-4989-AE69-DFAA-468A2E6A2FB8";
	setAttr ".ihi" 0;
createNode groupId -n "groupId11";
	rename -uid "39AB028A-4DE1-9B3B-3BD3-FF9FDF2F5F61";
	setAttr ".ihi" 0;
createNode groupId -n "groupId12";
	rename -uid "66D4A265-4C94-09CD-6811-0D9FC37D737A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId13";
	rename -uid "A0159199-4B57-28F5-BC57-A3A728B99ECF";
	setAttr ".ihi" 0;
createNode groupId -n "groupId14";
	rename -uid "18648DD2-40EE-FDA4-0C0D-3987B4B0F359";
	setAttr ".ihi" 0;
createNode groupId -n "groupId15";
	rename -uid "4DD8FE23-48E0-5D3D-4EB2-FD9BD08F468B";
	setAttr ".ihi" 0;
createNode groupId -n "groupId16";
	rename -uid "DDBBB527-40B4-BB5C-45A7-439FFA71D27B";
	setAttr ".ihi" 0;
createNode groupId -n "groupId17";
	rename -uid "8B0A878B-40F7-44FD-F8B1-A7BCB6DBDB8B";
	setAttr ".ihi" 0;
createNode groupId -n "groupId18";
	rename -uid "0F9286DB-4AA2-7114-C583-E9A8BDE0ED1B";
	setAttr ".ihi" 0;
createNode groupId -n "groupId19";
	rename -uid "8FF09563-42E5-B785-48AC-1C94C57DA2EE";
	setAttr ".ihi" 0;
createNode groupId -n "groupId20";
	rename -uid "C726F5D1-4C6A-7B28-554B-82A851357101";
	setAttr ".ihi" 0;
createNode groupId -n "groupId21";
	rename -uid "4C0F6133-4C3F-333A-4E16-65871B246361";
	setAttr ".ihi" 0;
createNode groupId -n "groupId22";
	rename -uid "2D6CF9E5-40D4-A702-0F95-4086986ABB8F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId23";
	rename -uid "2CC676DC-4F1C-DFEE-A87D-4197B6CD17E9";
	setAttr ".ihi" 0;
createNode groupId -n "groupId24";
	rename -uid "810B73E2-489D-81A7-9DD0-F9A7F2A78941";
	setAttr ".ihi" 0;
createNode groupId -n "groupId25";
	rename -uid "91CC1893-40DB-743F-3FA5-2CA1EEA85058";
	setAttr ".ihi" 0;
createNode groupId -n "groupId26";
	rename -uid "BA04DF75-4AC7-EBC8-A90E-8689EA509AB8";
	setAttr ".ihi" 0;
createNode groupId -n "groupId27";
	rename -uid "339809F3-4080-B0EE-DD30-DFA4B5C62CAA";
	setAttr ".ihi" 0;
createNode groupId -n "groupId28";
	rename -uid "3A878080-4ABE-4751-0A81-7EAA5A86B75D";
	setAttr ".ihi" 0;
createNode groupId -n "groupId29";
	rename -uid "3C4FBA99-4031-7616-D756-C19BA6D71E8E";
	setAttr ".ihi" 0;
createNode groupId -n "groupId30";
	rename -uid "7E984CF8-4CC6-7061-1CD2-B4BDEB77D377";
	setAttr ".ihi" 0;
createNode groupId -n "groupId31";
	rename -uid "E8CD0AE4-4B93-3551-0E9F-01A266E335CE";
	setAttr ".ihi" 0;
createNode groupId -n "groupId32";
	rename -uid "5AD33427-4657-41EE-EB1D-4F91DF34C28A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId33";
	rename -uid "B3B37D0B-45A8-6ACF-7783-A587D6E32536";
	setAttr ".ihi" 0;
createNode groupId -n "groupId34";
	rename -uid "939DE06D-4BE3-68D0-70FC-7D9F4A9CAF4E";
	setAttr ".ihi" 0;
createNode groupId -n "groupId35";
	rename -uid "141D8463-40F4-83E3-3412-65A49B4BA15A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId36";
	rename -uid "AE5F6CBD-4FA4-38F4-8E64-649FED6D3A5F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId37";
	rename -uid "969BB69A-4390-2DE1-6E53-BE9AFFECE76A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId38";
	rename -uid "3B6D9DA7-40EA-E341-AF07-02AB2F9EF110";
	setAttr ".ihi" 0;
createNode groupId -n "groupId39";
	rename -uid "6EB8EEB3-4EB2-A3AC-FB4B-52B48748C76E";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts1";
	rename -uid "3661A294-4737-9ABD-ABAD-8DA11D476750";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:43]";
createNode groupId -n "groupId40";
	rename -uid "7A3D5037-4081-D34C-D430-4D8C8E8A7A60";
	setAttr ".ihi" 0;
createNode groupId -n "groupId41";
	rename -uid "9FCA932A-40F3-DB57-1A4C-449D20B53743";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts2";
	rename -uid "81CA6335-407D-7755-451F-BEA37A552A61";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:199]";
createNode polyAutoProj -n "polyAutoProj1";
	rename -uid "48B5699F-499E-9033-5DB4-6F8BAC75C47C";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 1 "f[0:199]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".s" -type "double3" 66.440799713134766 66.440799713134766 66.440799713134766 ;
	setAttr ".ps" 0.20000000298023224;
	setAttr ".dl" yes;
select -ne :time1;
	setAttr ".o" 0;
select -ne :renderPartition;
	setAttr -s 2 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 4 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
select -ne :initialShadingGroup;
	setAttr -s 41 ".dsm";
	setAttr -s 41 ".gn";
select -ne :defaultColorMgtGlobals;
	setAttr ".cme" no;
connectAttr "groupId7.id" "mid_1Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_1Shape.iog.og[1].gco";
connectAttr "groupId8.id" "mid_1Shape.ciog.cog[1].cgid";
connectAttr "groupId1.id" "|Script|mid_2|mid_3|transform20|mid_3Shape.iog.og[1].gid"
		;
connectAttr ":initialShadingGroup.mwc" "|Script|mid_2|mid_3|transform20|mid_3Shape.iog.og[1].gco"
		;
connectAttr "groupId2.id" "|Script|mid_2|mid_3|transform20|mid_3Shape.ciog.cog[1].cgid"
		;
connectAttr "groupId39.id" "conector_1Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "conector_1Shape.iog.og[1].gco";
connectAttr "groupId40.id" "conector_1Shape.ciog.cog[1].cgid";
connectAttr "groupParts1.og" "conector_1Shape.i";
connectAttr "groupId37.id" "mid_5Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_5Shape.iog.og[1].gco";
connectAttr "groupId38.id" "mid_5Shape.ciog.cog[1].cgid";
connectAttr "groupId33.id" "conector_3Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "conector_3Shape.iog.og[1].gco";
connectAttr "groupId34.id" "conector_3Shape.ciog.cog[1].cgid";
connectAttr "groupId3.id" "Box_1Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "Box_1Shape.iog.og[1].gco";
connectAttr "groupId4.id" "Box_1Shape.ciog.cog[1].cgid";
connectAttr "groupId5.id" "conector_5Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "conector_5Shape.iog.og[1].gco";
connectAttr "groupId6.id" "conector_5Shape.ciog.cog[1].cgid";
connectAttr "groupId15.id" "Box_3Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "Box_3Shape.iog.og[1].gco";
connectAttr "groupId16.id" "Box_3Shape.ciog.cog[1].cgid";
connectAttr "groupId9.id" "mid_7Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_7Shape.iog.og[1].gco";
connectAttr "groupId10.id" "mid_7Shape.ciog.cog[1].cgid";
connectAttr "groupId11.id" "conector_7Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "conector_7Shape.iog.og[1].gco";
connectAttr "groupId12.id" "conector_7Shape.ciog.cog[1].cgid";
connectAttr "groupId13.id" "Box_5Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "Box_5Shape.iog.og[1].gco";
connectAttr "groupId14.id" "Box_5Shape.ciog.cog[1].cgid";
connectAttr "groupId17.id" "mid_9Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_9Shape.iog.og[1].gco";
connectAttr "groupId18.id" "mid_9Shape.ciog.cog[1].cgid";
connectAttr "groupId19.id" "mid_11Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_11Shape.iog.og[1].gco";
connectAttr "groupId20.id" "mid_11Shape.ciog.cog[1].cgid";
connectAttr "groupId27.id" "Box_7Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "Box_7Shape.iog.og[1].gco";
connectAttr "groupId28.id" "Box_7Shape.ciog.cog[1].cgid";
connectAttr "groupId29.id" "Box_9Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "Box_9Shape.iog.og[1].gco";
connectAttr "groupId30.id" "Box_9Shape.ciog.cog[1].cgid";
connectAttr "groupId31.id" "conector_9Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "conector_9Shape.iog.og[1].gco";
connectAttr "groupId32.id" "conector_9Shape.ciog.cog[1].cgid";
connectAttr "groupId21.id" "mid_13Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_13Shape.iog.og[1].gco";
connectAttr "groupId22.id" "mid_13Shape.ciog.cog[1].cgid";
connectAttr "groupId23.id" "mid_15Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_15Shape.iog.og[1].gco";
connectAttr "groupId24.id" "mid_15Shape.ciog.cog[1].cgid";
connectAttr "groupId25.id" "Box_11Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "Box_11Shape.iog.og[1].gco";
connectAttr "groupId26.id" "Box_11Shape.ciog.cog[1].cgid";
connectAttr "groupId35.id" "mid_17Shape.iog.og[1].gid";
connectAttr ":initialShadingGroup.mwc" "mid_17Shape.iog.og[1].gco";
connectAttr "groupId36.id" "mid_17Shape.ciog.cog[1].cgid";
connectAttr "polyAutoProj1.out" "|mid_3|mid_3Shape.i";
connectAttr "groupId41.id" "|mid_3|mid_3Shape.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "|mid_3|mid_3Shape.iog.og[0].gco";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "polySurfaceShape1.o" "polyMergeVert1.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert1.mp";
connectAttr "polyMergeVert1.out" "deleteComponent1.ig";
connectAttr "deleteComponent1.og" "deleteComponent2.ig";
connectAttr "deleteComponent2.og" "deleteComponent3.ig";
connectAttr "deleteComponent3.og" "deleteComponent4.ig";
connectAttr "deleteComponent4.og" "deleteComponent5.ig";
connectAttr "deleteComponent5.og" "deleteComponent6.ig";
connectAttr "deleteComponent6.og" "deleteComponent7.ig";
connectAttr "deleteComponent7.og" "deleteComponent8.ig";
connectAttr "deleteComponent8.og" "deleteComponent9.ig";
connectAttr "deleteComponent9.og" "polyMergeVert2.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert2.mp";
connectAttr "polyMergeVert2.out" "polyMergeVert3.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert3.mp";
connectAttr "polyMergeVert3.out" "polyMergeVert4.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert4.mp";
connectAttr "polyMergeVert4.out" "polyMergeVert5.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert5.mp";
connectAttr "polyMergeVert5.out" "polyMergeVert6.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert6.mp";
connectAttr "polyMergeVert6.out" "polyMergeVert7.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert7.mp";
connectAttr "polyMergeVert7.out" "polyMergeVert8.ip";
connectAttr "conector_1Shape.wm" "polyMergeVert8.mp";
connectAttr "|Script|mid_2|mid_3|transform20|mid_3Shape.o" "polyUnite1.ip[0]";
connectAttr "Box_1Shape.o" "polyUnite1.ip[1]";
connectAttr "conector_5Shape.o" "polyUnite1.ip[2]";
connectAttr "mid_1Shape.o" "polyUnite1.ip[3]";
connectAttr "mid_7Shape.o" "polyUnite1.ip[4]";
connectAttr "conector_7Shape.o" "polyUnite1.ip[5]";
connectAttr "Box_5Shape.o" "polyUnite1.ip[6]";
connectAttr "Box_3Shape.o" "polyUnite1.ip[7]";
connectAttr "mid_9Shape.o" "polyUnite1.ip[8]";
connectAttr "mid_11Shape.o" "polyUnite1.ip[9]";
connectAttr "mid_13Shape.o" "polyUnite1.ip[10]";
connectAttr "mid_15Shape.o" "polyUnite1.ip[11]";
connectAttr "Box_11Shape.o" "polyUnite1.ip[12]";
connectAttr "Box_7Shape.o" "polyUnite1.ip[13]";
connectAttr "Box_9Shape.o" "polyUnite1.ip[14]";
connectAttr "conector_9Shape.o" "polyUnite1.ip[15]";
connectAttr "conector_3Shape.o" "polyUnite1.ip[16]";
connectAttr "mid_17Shape.o" "polyUnite1.ip[17]";
connectAttr "mid_5Shape.o" "polyUnite1.ip[18]";
connectAttr "conector_1Shape.o" "polyUnite1.ip[19]";
connectAttr "|Script|mid_2|mid_3|transform20|mid_3Shape.wm" "polyUnite1.im[0]";
connectAttr "Box_1Shape.wm" "polyUnite1.im[1]";
connectAttr "conector_5Shape.wm" "polyUnite1.im[2]";
connectAttr "mid_1Shape.wm" "polyUnite1.im[3]";
connectAttr "mid_7Shape.wm" "polyUnite1.im[4]";
connectAttr "conector_7Shape.wm" "polyUnite1.im[5]";
connectAttr "Box_5Shape.wm" "polyUnite1.im[6]";
connectAttr "Box_3Shape.wm" "polyUnite1.im[7]";
connectAttr "mid_9Shape.wm" "polyUnite1.im[8]";
connectAttr "mid_11Shape.wm" "polyUnite1.im[9]";
connectAttr "mid_13Shape.wm" "polyUnite1.im[10]";
connectAttr "mid_15Shape.wm" "polyUnite1.im[11]";
connectAttr "Box_11Shape.wm" "polyUnite1.im[12]";
connectAttr "Box_7Shape.wm" "polyUnite1.im[13]";
connectAttr "Box_9Shape.wm" "polyUnite1.im[14]";
connectAttr "conector_9Shape.wm" "polyUnite1.im[15]";
connectAttr "conector_3Shape.wm" "polyUnite1.im[16]";
connectAttr "mid_17Shape.wm" "polyUnite1.im[17]";
connectAttr "mid_5Shape.wm" "polyUnite1.im[18]";
connectAttr "conector_1Shape.wm" "polyUnite1.im[19]";
connectAttr "polyMergeVert8.out" "groupParts1.ig";
connectAttr "groupId39.id" "groupParts1.gi";
connectAttr "polyUnite1.out" "groupParts2.ig";
connectAttr "groupId41.id" "groupParts2.gi";
connectAttr "groupParts2.og" "polyAutoProj1.ip";
connectAttr "|mid_3|mid_3Shape.wm" "polyAutoProj1.mp";
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "|Script|mid_2|mid_3|transform20|mid_3Shape.iog.og[1]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "|Script|mid_2|mid_3|transform20|mid_3Shape.ciog.cog[1]" ":initialShadingGroup.dsm"
		 -na;
connectAttr "Box_1Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_1Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_5Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_5Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_1Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_1Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_7Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_7Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_7Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_7Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_5Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_5Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_3Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_3Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_9Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_9Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_11Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_11Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_13Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_13Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_15Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_15Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_11Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_11Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_7Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_7Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_9Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "Box_9Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_9Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_9Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_3Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_3Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_17Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_17Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_5Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "mid_5Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_1Shape.iog.og[1]" ":initialShadingGroup.dsm" -na;
connectAttr "conector_1Shape.ciog.cog[1]" ":initialShadingGroup.dsm" -na;
connectAttr "|mid_3|mid_3Shape.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "groupId1.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId2.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId3.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId4.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId5.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId6.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId7.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId8.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId9.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId10.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId11.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId12.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId13.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId14.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId15.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId16.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId17.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId18.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId19.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId20.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId21.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId22.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId23.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId24.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId25.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId26.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId27.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId28.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId29.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId30.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId31.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId32.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId33.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId34.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId35.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId36.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId37.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId38.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId39.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId40.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId41.msg" ":initialShadingGroup.gn" -na;
// End of mid(1).ma
