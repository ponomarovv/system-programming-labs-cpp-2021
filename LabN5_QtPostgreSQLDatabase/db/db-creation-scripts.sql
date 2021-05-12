CREATE TABLE "Types" (
	id SERIAL PRIMARY KEY,
	title VARCHAR(20) NOT NULL
);

CREATE TABLE "Quizzes" (
	id SERIAL PRIMARY KEY,
	title VARCHAR(30) NOT NULL
);

CREATE TABLE "Questions" (
	id SERIAL PRIMARY KEY,
	title VARCHAR(256) NOT NULL,
	type_id INT NOT NULL,
	quiz_id INT NOT NULL,
	CONSTRAINT fk_question_type
		FOREIGN KEY (type_id)
			REFERENCES "Types"(id),
	CONSTRAINT fk_question_quiz
		FOREIGN KEY (quiz_id)
			REFERENCES "Quizzes"(id)
);

CREATE TABLE "Variants" (
	id SERIAL PRIMARY KEY,
	question_id INT NOT NULL,
	variant VARCHAR(256) NOT NULL,
	CONSTRAINT fk_variant_question
		FOREIGN KEY (question_id)
			REFERENCES "Questions"(id)
);

CREATE TABLE "Answers" (
	id SERIAL PRIMARY KEY,
	variant_id INT NOT NULL,
	CONSTRAINT fk_answer_variant
		FOREIGN KEY (variant_id)
			REFERENCES "Variants"(id)
);

DROP TABLE "Answers";

ALTER TABLE "Variants"
	ADD COLUMN is_answer BOOLEAN DEFAULT false;

ALTER TABLE "Questions"
	ADD COLUMN score INT NOT NULL DEFAULT 0;

INSERT INTO "Quizzes"(title) VALUES('Simple quiz');
INSERT INTO "Quizzes"(title) VALUES('A little bit harder quiz');
INSERT INTO "Quizzes"(title) VALUES('One question quiz');

INSERT INTO "Types"(title) VALUES('multiple');
INSERT INTO "Types"(title) VALUES('non-multiple');
INSERT INTO "Types"(title) VALUES('text-field');

INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('Виберіть студентів групи ІТ-93', 1, 1, 5);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('Найбільш популярна кількість коліс в автомобілі', 2, 1, 10);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('Третій день тижня?', 3, 1, 10);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('На якій мові Ви пишете код на цій дисципліні(використовуйте малі літери та англійську мову)?', 3, 1, 10);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('Виберіть кафедри ФІОТу:', 1, 2, 10);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('Виберіть мови програмування:', 1, 2, 20);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('АУТС існує?', 2, 2, 5);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('if (canUnderstandProgrammingLanguage) type("Yes")', 3, 2, 1);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('Виберіть правильну відповідь:', 2, 2, 10);
INSERT INTO "Questions"(title, type_id, quiz_id, score) VALUES('?', 2, 3, 100);

INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Босик Андрій', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Тонкошкур Олег', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Кравчук Іван', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Комаренко Іван', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Цимбал Олександр', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Пономарьов Олексій', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Ткаченко Віктор', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Муравинець Михайло', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(1, 'Бастило Іван', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(2, '1', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(2, '2', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(2, '3', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(2, '4', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(2, '5', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(3, 'середа', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(4, 'c++', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(5, 'ФІОТу не існує', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(5, 'ОТ', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(5, 'АУТС', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(5, 'ТК', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(5, 'АСОІУ', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Ruby', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'HTML', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'CSS', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'JS', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'PHP', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Pascal', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'C#', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Java', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Python', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'English', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Ukrainian', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Brainfuck', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(6, 'Polish', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(7, 'Так', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(7, 'Ні', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(8, 'Yes', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(9, '1', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(9, '0', false);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(10, '1', true);
INSERT INTO "Variants"(question_id, variant, is_answer) VALUES(10, '0', true);