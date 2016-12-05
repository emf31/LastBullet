using UnityEngine;
using System.Collections.Generic;
using System.IO;
using UnityEditor;

public class Exporter : MonoBehaviour {


	public string fileName="";

	// Use this for initialization
	void Start () {
		object[] obj = FindSceneObjectsOfType(typeof(GameObject));

		Raiz raiz = new Raiz();

		foreach (object o in obj) {
			GameObject g = (GameObject)o;
            if (!g.name.Equals("Script")) {
            GameObject parent=g.transform.parent.gameObject;
            if (parent!=null)
            {
                if (parent.name.Equals("Script"))
                {
                    Objeto objeto = new Objeto();

                    objeto.nombre = g.name;
                    objeto.posX = g.transform.position.x;
                    objeto.posY = g.transform.position.y;
                    objeto.posZ = g.transform.position.z;

                        //g.transform.sca
                    objeto.sizeX = g.transform.lossyScale.x;
                    objeto.sizeY = g.transform.lossyScale.y;
                    objeto.sizeZ = g.transform.lossyScale.z;

                    //var a = ;
                    objeto.rotX = g.transform.rotation.eulerAngles.x;
                    objeto.rotY = g.transform.rotation.eulerAngles.y;
                    objeto.rotZ = g.transform.rotation.eulerAngles.z;

                    Rigidbody rb;
                    if (rb = g.GetComponent<Rigidbody>())
                        objeto.masa = rb.mass;
                    else
                        objeto.masa = 0;
                    g.scene.path.ToString();

                    if (g.name.Equals("terminal"))
                        Debug.Log(AssetDatabase.GetAssetPath(g.gameObject));

                    raiz.addChild(objeto);
                }
            }
		}
        }

        if (fileName == "") {
			fileName = "C:\\defaultMapName.lbmap";
		}
		var sr = File.CreateText(fileName);
		sr.WriteLine(raiz.toJson());
		sr.Close();

	}
	
	// Update is called once per frame
	void Update () {
	
	}
}


public class Objeto {
	public string nombre;
	public float posX, posY, posZ;
	public float sizeX, sizeY, sizeZ;
	public float rotX, rotY, rotZ;
    public float masa;

	public bool hasChild;

	public Objeto() {

	}
}

public class Raiz {

	public List<Objeto> children;

	public Raiz() {
		children = new List<Objeto>();
	}

	public void addChild(Objeto obj) {
		children.Add(obj);
	}

	public string toJson() {
		string json="[";
        for (int i = 0; i < children.Count; i++) {
			string objeto = JsonUtility.ToJson(children[i]);
			if(i < children.Count-1) {
                json += objeto + ",";
            }else
            {
                json += objeto;
            }
		}
		json = json + "]";
		return json;
	}
}