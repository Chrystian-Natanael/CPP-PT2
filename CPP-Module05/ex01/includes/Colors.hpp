#ifndef COLORS_HPP
# define COLORS_HPP

// Cores
# define RST(text)			"\033[0m"					/* Reset to default color */
# define RED(text)			"\033[1;31m"				/* Bold Red */
# define G(text)			"\033[1;32m"				/* Bold Green */
# define Y(text)			"\033[1;33m"				/* Bold Yellow */
# define B(text)			"\033[1;34m"				/* Bold Blue */
# define M(text)			"\033[1;35m"				/* Bold Magenta */
# define C(text)			"\033[1;36m"				/* Bold Cyan */
# define W(text)			"\033[1;37m"				/* Bold White */
# define O(text)			"\001\033[38;5;208m\002"	/* Orange */

// Cores em negrito
#define BRED(text)			"\033[1;31m"	// Vermelho em negrito
#define BGRN(text)			"\033[1;32m"	// Verde em negrito
#define BYEL(text)			"\033[1;33m"	// Amarelo em negrito
#define BBLU(text)			"\033[1;34m"	// Azul em negrito
#define BMAG(text)			"\033[1;35m"	// Magenta em negrito
#define BCYN(text)			"\033[1;36m"	// Ciano em negrito
#define BWHT(text)			"\033[1;37m"	// Branco em negrito

// Fundo colorido
#define BGBLK(text)			"\033[40m"		// Fundo Preto
#define BGRED(text)			"\033[41m"		// Fundo Vermelho
#define BGGRN(text)			"\033[42m"		// Fundo Verde
#define BGYEL(text)			"\033[43m"		// Fundo Amarelo
#define BGBLU(text)			"\033[44m"		// Fundo Azul
#define BGMAG(text)			"\033[45m"		// Fundo Magenta
#define BGCYN(text)			"\033[46m"		// Fundo Ciano
#define BGWHT(text)			"\033[47m"		// Fundo Branco

// Fundo brilhante (claro)
#define BGBRED(text)		"\033[101m"		// Fundo Vermelho Claro
#define BGBGRN(text)		"\033[102m"		// Fundo Verde Claro
#define BGBYEL(text)		"\033[103m"		// Fundo Amarelo Claro
#define BGBBLU(text)		"\033[104m"		// Fundo Azul Claro
#define BGBMAG(text)		"\033[105m"		// Fundo Magenta Claro
#define BGBCYN(text)		"\033[106m"		// Fundo Ciano Claro
#define BGBWHT(text)		"\033[107m"		// Fundo Branco Claro

// Estilos adicionais
#define BOLD(text)			"\033[1m"		// Negrito
#define UNDL(text)			"\033[4m"		// Sublinhado
#define BLNK(text)			"\033[5m"		// Piscando
#define REV	(text)			"\033[7m"		// Invertido (fundo e texto)
#define HIDDEN(text)		"\033[8m"		// Texto oculto

// Emojis comuns
#define GRINNING(text)		"\U0001F600"	// 😀 - Rosto sorridente
#define SMILING(text)		"\U0001F642"	// 🙂 - Sorriso leve
#define LAUGHING(text)		"\U0001F606"	// 😆 - Rindo muito
#define WINK(text)			"\U0001F609"	// 😉 - Piscando
#define COOL(text)			"\U0001F60E"	// 😎 - Com óculos escuros
#define THINKING(text)		"\U0001F914"	// 🤔 - Pensando
#define SLEEPING(text)		"\U0001F634"	// 😴 - Emoji de rosto dormindo
#define WAVE(text)			"\U0001F44B"	// 👋 - Emoji de mão acenando (dando tchau)
#define CLAP(text)			"\U0001F44F"	// 👏 - Aplausos
#define OK_HAND(text)		"\U0001F44C"	// 👌 - Mão "OK"
#define CRYING(text)		"\U0001F622"	// 😢 - Chorando
#define ANGRY(text)			"\U0001F620"	// 😠 - Com raiva

// Emojis de animais
#define CAT_FACE(text)		"\U0001F431"	// 🐱 - Rosto de gato
#define DOG_FACE(text)		"\U0001F436"	// 🐶 - Rosto de cachorro
#define MOUSE_FACE(text)	"\U0001F42D"	// 🐭 - Rosto de rato
#define PANDA_FACE(text)	"\U0001F43C"	// 🐼 - Rosto de panda
#define KOALA(text)			"\U0001F428"	// 🐨 - Koala
#define MONKEY_FACE(text)	"\U0001F435"	// 🐵 - Rosto de macaco
#define TIGER_FACE(text)	"\U0001F42F"	// 🐯 - Rosto de tigre
#define ROSE(text)			"\U0001F339"	// 🌹 - Rosa
#define SUNFLOWER(text)		"\U0001F33B"	// 🌻 - Girassol
#define CACTUS(text)		"\U0001F335"	// 🌵 - Cacto

// Emojis de comida e bebida
#define PIZZA(text)			"\U0001F355"	// 🍕 - Pizza
#define BURGER(text)		"\U0001F354"	// 🍔 - Hambúrguer
#define TACO(text)			"\U0001F32E"	// 🌮 - Taco
#define ICE_CREAM(text)		"\U0001F368"	// 🍨 - Sorvete
#define CAKE(text)			"\U0001F370"	// 🍰 - Bolo
#define COFFEE(text)		"\U00002615"	// ☕ - Café
#define BEER(text)			"\U0001F37A"	// 🍺 - Cerveja
#define WINE(text)			"\U0001F377"	// 🍷 - Taça de vinho
#define APPLE(text)			"\U0001F34E"	// 🍎 - Maçã
#define BANANA(text)		"\U0001F34C"	// 🍌 - Banana

// Emojis de esportes
#define SOCCER(text)		"\U000026BD"	// ⚽ - Bola de futebol
#define BASKETBALL(text)	"\U0001F3C0"	// 🏀 - Bola de basquete
#define BASEBALL(text)		"\U000026BE"	// ⚾ - Bola de beisebol
#define TENNIS(text)		"\U0001F3BE"	// 🎾 - Bola de tênis
#define TROPHY(text)		"\U0001F3C6"	// 🏆 - Troféu
#define MEDAL(text)			"\U0001F3C5"	// 🏅 - Medalha
#define RUNNER(text)		"\U0001F3C3"	// 🏃 - Corredor
#define SWIMMER(text)		"\U0001F3CA"	// 🏊 - Nadador
#define DANCER(text)		"\U0001F483"	// 💃 - Dançarina
#define GUITAR(text)		"\U0001F3B8"	// 🎸 - Guitarra

#endif
