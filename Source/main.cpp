#include "UltraEngine.h"

using namespace UltraEngine;

int main(int argc, const char* argv[])
{
    //Get the displays
    auto displays = GetDisplays();

    //Create a window
    auto window = CreateWindow("Ultra Engine", 0, 0, 800, 600, displays[0], WINDOW_TITLEBAR | WINDOW_RESIZABLE | WINDOW_CENTER);

    //Create User Interface
    auto ui = CreateInterface(window);

    //Create widget
    auto sz = ui->root->GetSize();
    auto listbox = CreateListBox(20, 20, sz.x - 40, sz.y - 40, ui->root);
    listbox->AddItem("Item 1", true);
    listbox->AddItem("Item 2");
    listbox->AddItem("Item 3");
    listbox->AddItem("Item 4");
    listbox->AddItem("Item 5");
    listbox->AddItem("Item 6");
    
    listbox->SetLayout(1,1,1,1);

    while (true)
    {
        const Event ev = WaitEvent();
        switch (ev.id)
        {
            case EVENT_WIDGETACTION:
                Print("Item " + String(ev.data) + " action");
                break;
            case EVENT_WIDGETSELECT:
                Print("Item " + String(ev.data) +" selected");
                break;
            case EVENT_QUIT:
            case EVENT_WINDOWCLOSE:
                return 0;
                break;
            default: break;
        }
    }
    return 0;
}
