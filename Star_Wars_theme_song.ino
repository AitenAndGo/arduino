void play(String music);

float notes[7][7] = {{0},{0}};

void setup()
{
  pinMode(8, OUTPUT);
  // only notes i use
  notes[2][3] = 130.81;
  notes[2][4] = 261.63;
  notes[2][5] = 523.25;
  notes[0][4] = 440.00;
  notes[1][4] = 493.88;
  notes[3][4] = 293.67;
  notes[4][4] = 329.63;
  notes[5][4] = 349.23;
  notes[6][4] = 392.00;
}

void loop()
{
  //piano leter notes
  play("C4-G4-F4.E4.D4.C5-G4-F4.E4.D4.C5-G4-F4.E4.F4.D4/C4-G4-F4.E4.D4.C5-G4-F4.E4.D4.C4-G4-F4.E4.F4.D4");
  delay(20);
}

void play(String music)
{
  int i = 0;
  float note = 0;
  int del = 0;
  while (music[i] != '\0')
  {
    if (music[i] == '/')
    {
      delay(500);
      i++;
    }
    else
    {
      note = notes[(music[i] - 'A')][(music[i + 1] - '0')];
      switch (music[i+2])
      {
        case '.':
        del = 250;
        break;

        case '-':
        del = 800;
        break;
        
        case '/':
        del = 1000;
        break;
      }
      tone(8, note, (del));
      delay(del);
      noTone(8);
      i += 3;
    }
  }
}
