using UnityEngine;

public class PanelController : MonoBehaviour
{
    public GameObject panel; // PanelをInspectorからアサイン
    
    // Panelを表示する
    public void ShowPanel()
    {
        panel.SetActive(true);
    }

    // Panelを非表示にする
    public void HidePanel()
    {
        panel.SetActive(false);
    }
}