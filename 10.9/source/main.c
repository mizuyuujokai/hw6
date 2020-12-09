#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct card {
	const char* face;
	const char* suit;
};
typedef struct card Card;

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[])
{
	int i;
	for (i = 0; i <= 51; i++) {
		wDeck[i].face = wFace[i % 13];
		wDeck[i].suit = wSuit[i / 13];
	}
}
void shuffle(Card* const wDeck) {
	int i, j;
	Card temp;
	
	for (i = 0; i <= 51; i++) {
		j = rand() % 52;
		temp = wDeck[i];
		wDeck[i] = wDeck[j];
		wDeck[j] = temp;
	}
}void deal(const Card* const wDeck)
{
	int i;
	for (i = 0; i <= 51; i++) {
		printf("%s of %s%s", wDeck[i].face, wDeck[i].suit,
			(i + 1) % 4 ? " ":"\n");
	}
}
int main(void) {
	Card deck[52];
	const char* face[] = { "A","2","3","4","5","6","7",
	"8","9","10","J","Q","K" };
	const char* suit[] = {"¬õ¤ß","¤è¶ô","±öªá","¶Â®ç"};

	srand(time(NULL));
	fillDeck(deck, face, suit);
	shuffle(deck);
	deal(deck);
	return 0;
}