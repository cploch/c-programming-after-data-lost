#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"
#include <ctype.h>

//c2
void assert_card_valid(card_t c) {
  assert(c.value >= 2);
  assert(c.value <= VALUE_ACE);
  assert(c.suit >= SPADES);
  assert(c.suit <= CLUBS);
}

//c2
const char * ranking_to_string(hand_ranking_t r) {
  switch(r){
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH";
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND";
  case FULL_HOUSE: return "FULL_HOUSE";
  case FLUSH: return "FLUSH";
  case STRAIGHT: return "STRAIGHT";
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND";
  case TWO_PAIR: return "TWO_PAIR";
  case PAIR: return "PAIR";
  case NOTHING: return "NOTHING";
  default : return "???";
  }
}

//c2
char value_letter(card_t c) {
  if (c.value >= 2 && c.value < 10) {
    return '0' + c.value;
  }
  switch(c.value) {
  case 10:          return '0';
  case VALUE_ACE:   return 'A';
  case VALUE_KING:  return 'K';
  case VALUE_QUEEN: return 'Q';
  case VALUE_JACK:  return 'J';
  default: return '?';
  }
}

//c2
char suit_letter(card_t c) {
  switch(c.suit) {
  case SPADES: return 's';
  case HEARTS: return 'h';
  case DIAMONDS: return 'd';
  case CLUBS: return 'c';
  default: return '?';
  }

}
//c2
void print_card(card_t c) {
  assert_card_valid(c);
  printf("%c%c", value_letter(c), suit_letter(c));
}

//c2
card_t card_from_letters(char value_let, char suit_let) {
  card_t ans;
  if (value_let >= '2' && value_let <= '9') {
    ans.value = value_let - '0';
  }
  else {
    switch(value_let) {
    case '0': ans.value = 10; break;
    case 'A': ans.value = VALUE_ACE; break;
    case 'K': ans.value = VALUE_KING; break;
    case 'Q': ans.value = VALUE_QUEEN; break;
    case 'J': ans.value = VALUE_JACK; break;
    default:
      fprintf(stderr, "Invalid card value letter: %c\n", value_let);
      exit(EXIT_FAILURE);
    }
  }
  switch(suit_let) {
  case 's': ans.suit = SPADES; break;
  case 'h': ans.suit = HEARTS; break;
  case 'd': ans.suit = DIAMONDS; break;
  case 'c': ans.suit = CLUBS; break;
  default:
    fprintf(stderr, "Invalid card suit letter: %c\n", suit_let);
    exit(EXIT_FAILURE);
  }
  return ans;
}

card_t card_from_num(unsigned c) {
  assert(c < 52);
  card_t ans;
  ans.value = c % 13 + 2;
  switch (c/13) {
  case 0:
    ans.suit = SPADES;
    break;
  case 1:
    ans.suit = HEARTS;
    break;
  case 2:
    ans.suit = DIAMONDS;
    break;
  case 3:
    ans.suit = CLUBS;
    break;
  default:
    ans.suit = NUM_SUITS;
  }
  assert_card_valid(ans);
  return ans;
}

// Course 4 Prj 1 functions follow below:
void add_card_to(deck_t * deck, card_t c) {
  /*Add the particular card to the given deck (which will
  involve reallocing the array of cards in that deck).
  */
  deck->n_cards++;
  deck->cards = realloc(deck->cards, sizeof(*deck->cards)*(deck->n_cards));
  deck->cards[deck->n_cards - 1] = malloc(sizeof(*(deck->cards[deck->n_cards - 1])));
  deck->cards[deck->n_cards - 1]->value = c.value;
  deck->cards[deck->n_cards - 1]->suit = c.suit;
}

card_t * add_empty_card(deck_t * deck) {
  card_t emptyCard;
  emptyCard.value = 0;
  emptyCard.suit = 0;
  add_card_to(deck, emptyCard);
  return deck->cards[deck->n_cards - 1];
}


unsigned num_from_card(card_t card) {
  assert_card_valid(c);
  unsigned answer = card.suit*13 + card.value - 2;
  return answer;
}
    

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t * answer = malloc(sizeof(deck_t));
  for (int i = 0; i < 52; i++) {
    card_t card = card_from_num(i);
    int card_excluded = deck_contains(excluded_cards, card);
    if (card_excluded == 1) {
      //do nothing
    }
    else {
       add_card_to(answer, card);
    }
  }
  return answer;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  //build deck to exclude
  deck_t * deck_to_exclude;
  deck_t * answer;

  //do make_deck_exclude with that deck

}
