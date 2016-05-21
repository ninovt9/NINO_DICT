
#读取字典文件<br>

##version 0.1<br>

###语法

	START		:	NAME
				|	LINEBREAK
				|	PHONETIC
				|	MEANING
				|	EXAMPLE
				;
		
	NAME		: [ '-' ]'あ'..'う'+'\n';
	LINEBREAK	: '\n';
	PHONETIC	: [ '-' ]'a'..'z'+ | [ '‐' ]'あ'..'う'+'\n';
	MEANING		: \S+'\n';
	EXAMPLE		: '$'\S+'\n';


	word		: name linebreak phonetic meaning+ example+ linebreak+
	word		: meaning linebreak meaning meaning+ meaning+ linebreak+

	word_1		: word_2 linebreak+
	word_2		: meaning linebreak word_3
	word_3		: 

	expression	: term { linebreak };
	term		: factor

	