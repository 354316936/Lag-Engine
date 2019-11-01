using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Dialogue : BaseUI
{
    public Anchor anchor;
    public Rect shape;
    public Texture2D textureToDisplay;
    private Rect oldShape;
    private Anchor oldAnchor;
    private GUIStyle guiStyle = new GUIStyle(); //create a new variable
    // Use this for initialization
    void Start()
    {
        oldAnchor = anchor;
        oldShape = shape;
        SetPosition(shape.x, shape.y);

        SetAnchor(anchor);
    }

    void OnGUI()
    {

        guiStyle.fontSize = 10;
        GUILayout.BeginArea(new Rect(GetPosX(), GetPosY(), (Screen.width - textureToDisplay.width) , (Screen.height - textureToDisplay.height)) , textureToDisplay);
        GUI.contentColor = Color.black;
        GUILayout.Label("Do you like to \n play pokemon?", guiStyle);
        GUILayout.EndArea();

        GUI.Button(new Rect(GetPosX(), GetPosY() * 2, GetWidth() / 2, GetHeight() / 2), "Yes");
        GUI.Button(new Rect(GetPosX() * 1.9f, GetPosY() * 2, GetWidth() / 2, GetHeight() / 2), "No");
    }

    

    void ReDraw()
    {
        oldAnchor = anchor;
        oldShape = shape;
        SetPosition(shape.x, shape.y);
        SetSize(shape.width, shape.height);
        SetAnchor(anchor);
    }

    // Update is called once per frame
    void Update()
    {
        if (oldAnchor != anchor || oldShape != shape)
        {
            ReDraw();
        }
        else
        {
            oldAnchor = anchor;
            oldShape = shape;
        }
        SetSize(Screen.width / 16, Screen.height / 10);


    }
}
