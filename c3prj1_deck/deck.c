#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
   for(size_t i =0; i < hand->n_cards;i++) {
     print_card(*hand->cards[i]);
     printf(" ");
   }
 }

int deck_contains(deck_t * d, card_t c) {
  for(size_t i = 0; i < d->n_cards; i++) {
    if (d->cards[i]->value == c.value &&
	d->cards[i]->suit == c.suit) {
      return 1;
    }
  }
  return 0;
}
//you can do this without mallocing temp space.
//e.g.m you can randomly swap positions
void shuffle(deck_t * d){
  card_t ** temp = calloc(d->n_cards, sizeof(*temp));
  size_t n = d->n_cards;
  for(size_t i = 0; i < d->n_cards; i++) {
    size_t ind = random();
    ind = ind % n;
    size_t j = 0;
    while(ind > 0 || temp[j] != NULL) {
      if (temp[j] == NULL){
	ind--;
      }
      j++;
      assert(j < d->n_cards);
    }
    temp[j] = d->cards[i];
    n--;
  }
  free(d->cards);
  d->cards = temp;
}

void assert_full_deck(deck_t * d) {
  assert(d->n_cards == 52);
  for(unsigned i = 0; i < 52; i++) {
    assert(deck_contains(d, card_from_num(i)));
  }
}

