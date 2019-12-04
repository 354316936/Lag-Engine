using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IScreenElement {     float VGetZOrder();
    void VSetZOrder(float zOrder);
    bool VIsVisible();
    void VSetVisible(bool visible);      
}
