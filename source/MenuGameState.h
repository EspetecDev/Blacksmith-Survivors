struct MenuGameState;  
MenuGameState* MenuGameState_Init(int x, int y);  // equivalent to "new Point(x, y)"
void MenuGameState__OnEnter();
void MenuGameState__Update();
void MenuGameState__OnExit();
