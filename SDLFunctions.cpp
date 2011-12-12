
void GameWindow::cleanupSDL()
{
  SDL_FreeSurface(displaySurface);
  SDL_FreeSurface(gameView);
  SDL_Quit();
}

