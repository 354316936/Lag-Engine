using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ButtonUI : BaseUI {
    public Anchor anchor;
    public Rect shape;
    public bool isVisible;
    private Rect oldShape;
    private Anchor oldAnchor;

    // Use this for initialization
    void Start () {
        oldAnchor = anchor;
        oldShape = shape;
        SetPosition(shape.x, shape.y);
    
        SetAnchor(anchor);
	}

    private void OnGUI()
    {
        if (VIsVisible()){
            if (GUI.Button(new Rect(GetPosX(), GetPosY(), GetWidth(), GetHeight()),"")){
                Debug.Log("Button pressed!");
            }
        }
    }

    void ReDraw(){
        oldAnchor = anchor;
        oldShape = shape;
        SetPosition(shape.x, shape.y);
        SetSize(shape.width, shape.height);
        SetAnchor(anchor);
    }

    // Update is called once per frame
    void Update () {
        if (oldAnchor != anchor || oldShape != shape){
            ReDraw();
        }
        else{
            oldAnchor = anchor;
            oldShape = shape;
        }
        SetSize(Screen.width / 16, Screen.height / 10);

        VSetVisible(isVisible);
    }
}
