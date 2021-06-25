# CS50 - Week - 10 - Ethics

Resources:
- [CS50 2020 - Lecture 10 - Ethics](https://youtu.be/eNxMn7slmwI)

- [Lecture Notes](https://cs50.harvard.edu/x/2021/notes/10/)

- [Lecture Slides](https://docs.google.com/presentation/d/1PGkigilY9bl0_1aUJAbxxmhkpdoOm-Duhtw03PzKz40/edit?usp=sharing)

- [Lecture Transcript](http://cdn.cs50.net/2020/fall/lectures/10/lang/en/lecture10.txt)

---

## [Looking Back](https://www.youtube.com/watch?v=eNxMn7slmwI&t=303s)

---

## [Ethics](https://www.youtube.com/watch?v=eNxMn7slmwI&t=1445s)

- We might think of ethics as whether we should do something, or how we go about doing it, even when we have the ability to.

- Before Facebook, the website, there was another website, [Facemash](https://www.thecrimson.com/article/2003/11/19/facemash-creator-survives-ad-board-the/), where code was used to scrape, or download, images of Harvard students and use them without prior permission.

## [Guest Lecture on Ethics](https://cs50.harvard.edu/x/2021/labs/10/lecture/)

- In order to use technology to create solutions to the problems we are facing today, we’ll need to make informed decisions about design choices, and this requires some critical thinking about ethics and philosophy to figure out the best way to do this.

Behind the idea of democracy is an ideal of what political society should be. 

1. The idea of a democratic society, a society in which the political culture views individuals as free and equal;

2. Is the idea of a democratic political regime, which is characterized by regular elections, rights of participation, along with associative and expressive rights that make participation both informed and effective;

3. The idea of deliberative democracy—according to which political discussion should appeal to reason that are suitable for cooperation amongst free and equal persons.

Five Rights and Opportunities for a Democratic Public Sphere

1. **Rights.** As citizens of a democracy, we have rights to basic liberties, such as liberties of expression and association. The right to expressive liberty is important not only for the freedom of the individual, so that he or she is not censored, but also for democracy itself. It enables citizens to bring their ideas into conversation with one another, and to criticize and hold accountable those who exercise power.
   
2. **Opportunity for Expression.** Not only should we be free of censorship but we should have fair opportunity to participate in public discussion. It shouldn’t be the case that because someone is wealthier or more powerful that they should have more opportunity to participate.
   
3. **Access.** Each person should have good and equal access to quality and reliable information on public matters. That is, IF we make the effort, we should be able to acquire this information. Effective participation in decision making on public matters requires being informed.
   
4. **Diversity.** Each person should have good and equal chances to hear a wide range of views. We need access to competing views in order to have a more informed and reasoned position.
   
5. **Communicative Power.** Citizens should have good and equal chances to explore interests and ideas in association with others, and through these associations, to develop new concerns that challenge the mainstream view.

---

## [Looking Forward](https://www.youtube.com/watch?v=eNxMn7slmwI&t=2746s)

- [Brian's Workshop on Git](https://www.youtube.com/watch?v=MJUJ4wbFm_A)

- Web hosts (static):
  
    - https://pages.github.com/
      
    - https://www.netlify.com/
    
- Web app hosts include:
  
    - https://www.heroku.com/platform
      
    - https://aws.amazon.com/education/awseducate/

    - https://azure.microsoft.com/en-us/free/students/

    - https://edu.google.com/programs/students/
    
- News sources for technology and programming include:

    - https://www.reddit.com/r/learnprogramming/

    - https://www.reddit.com/r/programming/

    - https://stackoverflow.com/

    - https://serverfault.com/

    - https://techcrunch.com/

    - https://news.ycombinator.com/
    
- CS50 Communities:

    - https://discord.gg/cs50

    - https://www.facebook.com/groups/cs50

    - https://www.facebook.com/cs50

    - https://gitter.im/cs50/x

    - https://github.com/cs50

    - https://www.instagram.com/cs50/

    - https://www.linkedin.com/groups/7437240/

    - https://www.linkedin.com/school/CS50/

    - https://www.quora.com/topic/CS50

    - https://www.reddit.com/r/cs50

    - https://cs50x.slack.com/

    - https://www.snapchat.com/add/cs50

    - https://soundcloud.com/cs50

    - http://cs50.stackexchange.com/

    - https://twitter.com/cs50

    - http://www.youtube.com/cs50

---

## [Quiz Show](https://www.youtube.com/watch?v=eNxMn7slmwI&t=3387s)

1. What are the steps for compiling source code into machine code?

    - [x] Preprocessing, compiling, assembling, linking
      > Preprocessing first, then compiling, assembling and linking. All of this is what happens behind the scenes, and you don't think about it when you are compiling source code, but these are all the steps involoved, and the order they are done in.
    - [ ] Writing, compiling, debugging, testing
    - [ ] Preprocessing, creating, asserting, clang
    - [ ] Make

2. What is the runtime of binary search?

    - [ ] O(1)
    - [x] O(log n)
    - [ ] O(n)
    - [ ] O(n<sup>2</sup>)

3. Which of these animals was the first to be mentioned in a CS50 lecture?

    - [ ] Llama
    - [ ] Python
    - [ ] Duck
    - [x] Cat
      > The first language we were introduced to was Scratch and the main character in Scratch is a Cat.

4. Every time you `malloc` memory, you should also be sure to…

    - [ ] `realloc`
    - [ ] `return`
    - [x] `free`
      > When you allocate memory, you need to free that memory. 
    - [ ] `exit`

5. What is a race condition?

    - [ ] When conditions outside are nice for racing
    - [x] When two things happen at the same time and produce an unexpected result
      > Was referred to during the lecture on SQL
    - [ ] When a line of code is executed too quickly
    - [ ] When a line of code is executed too slowly

6. Does zooming in on a photo let you “enhance” it to generate more detail?

    - [ ] Yes, just like in CSI
    - [x] No, a photo only has a certain amount of detail
      > A photo only has a certain number of pixels and if you keep zooming in on the same pixel you will not be able to generate additional detail that was not there before.

7. Which of the following is not a characteristic of a good hash function?

    - [ ] Deterministic Output
    - [x] Randomness
      > You want your hash function to always give you the same output, given the same input. That way you can rely on the output to match when using it again.
    - [ ] Uniform Distribution
    - [ ] Efficiency

8. What does FIFO stand for?

    - [ ] A common dog's name
    - [ ] Your credit score
    - [x] First in, first out
      > How a `queue` is described... the first thing into a queue is the first thing out of the queue, like a line at the store.
    - [ ] Function input, File output

9. Which of the following would represent pink using RGB values?

    - [ ] `#0054e7`
    - [ ] `#9012a2`
    - [ ] `#e5d600`
    - [x] `#ffd0e0`
      > Hexadecimal value = 2 digits (red), 2 digits (green), 2 digits (blue)... ff being the highest in hexadecimal for red would mean this was most likely the pink one.

10. In C, which of the following lines of code allocates enough memory for a copy of the string s?

    - [ ] `malloc(s)`
    - [ ] `malloc(sizeof(s))`
    - [ ] `malloc(strlen(s))`
    - [x] `malloc(strlen(s) + 1)`
      > `malloc` takes the number of bytes of memory you want to allocate, so if you have a string you want to allocate memory for, you have to know how long the string is, then add 1 for the "null terminating" character.

11. How should you organize your clothes to be cool?

    - [ ] stack
    - [x] queue
    - [ ] dictionary
    - [ ] binary tree

12. What is a segmentation fault?

    - [ ] When a computer runs out of memory
    - [ ] When a program tries to read an empty file
    - [x] When a program tries to access memory that it shouldn’t
      > When you are trying to touch memory that you're not supposed to have access to inside a program.
    - [ ] When an earthquake happens

13. Which of the following types of overflow can result from recursion without a base case?

    - [ ] heap overflow
    - [ ] integer overflow
    - [x] stack overflow
      > Everytime you call a function, a little piece of that function gets added to the stack. If you keep calling that function over and over again, you will run out of room on the stack and cause a stack overflow
    - [ ] buffer overflow

14. In the town of Fiftyville, what were the names of the three people who witnessed the rubber duck robbery?

    - [ ] Rain, Emmett, and Riley
    - [ ] Robin, Earl, and Ryan
    - [ ] Rachel, Ernest, and Roger
    - [x] Ruth, Eugene, and Raymond

15. Which of these command-line programs check your code for memory leaks?

    - [x] `valgrind`
    - [ ] `clang`
    - [ ] `mkdir`
    - [ ] `make`

16. Which of the following exists in C, but not Python?

    - [ ] Boolean expressions
    - [x] do-while loops
    - [ ] recursive functions
    - [ ] floating-point numbers

17. What HTTP request method should you use when sending private information, like a password?

    - [ ] GET
    - [x] POST
      > With GET sensitive information will be exposed in the url
    - [ ] SELECT
    - [ ] TEXT

18. What data structure allows for constant-time lookup for words in a dictionary?

    - [ ] linked list
    - [ ] binary search tree
    - [ ] array
    - [x] trie
      > Only depends on the length of the word you are looking up. A trie uses more memory than any of the other options though

19. What is a cookie?

    - [ ] data used to identify your computer to websites
    - [ ] a delicious snack
    - [x] both of the above
    - [ ] none of the above

20. What’s your comfort level now?

    - [x] I’m among those more comfortable
    - [x] I’m among those more comfortable
    - [x] I’m among those more comfortable
    - [x] I’m among those more comfortable
