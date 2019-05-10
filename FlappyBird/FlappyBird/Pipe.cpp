#include "pch.h"
#include "Pipe.h"

Pipe::Pipe(GameDataRef data) :_data(data) {}

Pipe::~Pipe() {}

void Pipe::DrawPipes() { for (unsigned short int i = 0; i < pipeSprites.size(); i++) _data->window.draw(pipeSprites.at(i)); }