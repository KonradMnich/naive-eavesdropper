#include "naiveEavesdropper.h"

NaiveEavesdropper<700> bug;

void setup() {
  bug.initialize();
}

void loop() {
  bug.eavesdrop();
  bug.print_gossip();
}
