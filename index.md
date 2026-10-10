---
title: CSE425 Compiler Design Lab
---

<div class="term">
  <div class="term-bar"><i></i><i></i><i></i>sudhamsh@iitbhu: ~/CSE425_Compiler_Design_Lab</div>
  <div class="term-body">
    <span class="term-stars">****************************************************************************************************************************************</span>
    <h1 class="term-title">Compiler Design Lab</h1>
    <span class="term-line term-sub">CSE425 · IIT (BHU) · seven labs, from gcc's intermediate files to an LR parser</span>
    <span class="term-line"><span class="term-prompt">$</span> <span class="term-path">ls</span></span>
    <div class="term-ls">
      <a href="{{ 'Lab1/' | relative_url }}">Lab1</a>
      <a href="{{ 'Lab2/' | relative_url }}">Lab2</a>
      <a href="{{ 'Lab3/' | relative_url }}">Lab3</a>
      <a href="{{ 'Lab4/' | relative_url }}">Lab4</a>
      <a href="{{ 'Lab5/' | relative_url }}">Lab5</a>
      <a href="{{ 'Lab6/' | relative_url }}">Lab6</a>
      <a href="{{ 'Lab7/' | relative_url }}">Lab7</a>
    </div>
    <span class="term-line"><span class="term-prompt">$</span> <span class="term-path">./clp</span> "(id+id)*id+id"</span>
    <span class="term-line"><span class="term-ok">Accepted</span></span>
    <span class="term-stars">****************************************************************************************************************************************</span>
  </div>
</div>

<div class="intro">
  <img src="{{ 'misc/home.jpg' | relative_url }}" alt="Cover of Principles of Compiler Design by Aho and Ullman: a knight fighting the complexity-of-compiler-design dragon" width="265" height="375">
  <div class="intro-text" markdown="1">

```
This repository contains my workings for the lab assignments of the compiler design course at IIT (BHU).
```
{: .quote}

Every lab is a small program written in C++, LEX or YACC. Each one comes with its input,
the exact commands to build and run it, and a screenshot of what the terminal printed.

  </div>
</div>

<ol class="phases">
  <li>
    <strong>The whole pipeline</strong>
    <span>Preprocess, compile, assemble and link a C program with gcc.</span>
    <div class="labs"><a href="{{ 'Lab1/' | relative_url }}">Lab1</a></div>
  </li>
  <li>
    <strong>Lexical analysis</strong>
    <span>Turn a stream of characters into keywords, identifiers, numbers and operators.</span>
    <div class="labs"><a href="{{ 'Lab2/' | relative_url }}">Lab2</a><a href="{{ 'Lab3/' | relative_url }}">Lab3</a></div>
  </li>
  <li>
    <strong>Syntax analysis</strong>
    <span>Check the tokens against a grammar, top-down and bottom-up.</span>
    <div class="labs"><a href="{{ 'Lab4/' | relative_url }}">Lab4</a><a href="{{ 'Lab5/' | relative_url }}">Lab5</a><a href="{{ 'Lab6/' | relative_url }}">Lab6</a></div>
  </li>
  <li>
    <strong>Translation</strong>
    <span>Attach actions to grammar rules with LEX and YACC.</span>
    <div class="labs"><a href="{{ 'Lab7/' | relative_url }}">Lab7</a></div>
  </li>
</ol>

---

###### 1 `A compiler is a pipeline: source → preprocessed file → assembly → object code → executable`

- [**`Lab 1 · Phases of compiling a C program`**][lab1]

---

###### 2 `The lexer reads characters and groups them into lexemes, each one tagged as a token`

- [**`Lab 2 · Lexical analyser in C++`**][lab2]
- [**`Lab 3 · Lexical analysis with LEX`**][lab3]

---

###### 3 `Top-down parsers grow the parse tree from the start symbol towards the input`

- [**`Lab 4 · Recursive descent parser`**][lab4]
- [**`Lab 5 · Predictive parser`**][lab5]

---

###### 4 `Bottom-up parsers shift input onto a stack and reduce it back to the start symbol`

- [**`Lab 6 · Canonical LR parser`**][lab6]

---

###### 5 `LEX hands tokens to YACC, and YACC runs an action whenever a grammar rule matches`

- [**`Lab 7 · 3-D array declarations with LEX and YACC`**][lab7]

---

## Straight from the terminal

<div class="shots">
  <figure class="shot">
    <a href="{{ 'Lab6/' | relative_url }}"><img src="{{ 'Lab6/output.png' | relative_url }}" alt="Canonical LR parser trace: state stack, symbols, remaining input and shift/reduce actions, ending in Accepted" width="1289" height="944" loading="lazy"></a>
    <figcaption><b>Lab 6</b> · canonical LR parse of <code>(id+id)*id+id</code></figcaption>
  </figure>
  <figure class="shot">
    <a href="{{ 'Lab5/' | relative_url }}"><img src="{{ 'Lab5/output.png' | relative_url }}" alt="Predictive parser trace with matched, stack, input and action columns" width="1294" height="784" loading="lazy"></a>
    <figcaption><b>Lab 5</b> · predictive parse of <code>id*(id+id)</code></figcaption>
  </figure>
  <figure class="shot">
    <a href="{{ 'Lab4/' | relative_url }}"><img src="{{ 'Lab4/output.png' | relative_url }}" alt="Parse tree drawn in the terminal by the recursive descent parser" width="467" height="731" loading="lazy"></a>
    <figcaption><b>Lab 4</b> · parse tree from recursive descent</figcaption>
  </figure>
  <figure class="shot">
    <a href="{{ 'Lab3/' | relative_url }}"><img src="{{ 'Lab3/rules.png' | relative_url }}" alt="LEX rules for keywords, integers, identifiers, strings, comments and operators" width="1114" height="460" loading="lazy"></a>
    <figcaption><b>Lab 3</b> · the LEX rules behind the lexer</figcaption>
  </figure>
</div>

The `color_*.cpp` builds of Labs 4–6 print in 256 colours. The colours mean:

<ul class="legend">
  <li class="c-lime">matched / state</li>
  <li class="c-mint">stack / symbol</li>
  <li class="c-violet">remaining input</li>
  <li class="c-pink">shift · reduce</li>
  <li class="c-orange">messages</li>
</ul>

---

## Run any lab

```
git clone https://github.com/repsick3r/CSE425_Compiler_Design_Lab.git
cd CSE425_Compiler_Design_Lab/Lab6
g++ canonicalLRParser.cpp -o clp
./clp input.txt
```

Labs 3 and 7 also need `flex` and `bison` (`sudo apt-get install bison flex`). Each lab page has its exact commands.

---

- [**`Code on GitHub`**][code]

[lab1]: Lab1/README.md
[lab2]: Lab2/README.md
[lab3]: Lab3/README.md
[lab4]: Lab4/README.md
[lab5]: Lab5/README.md
[lab6]: Lab6/README.md
[lab7]: Lab7/README.md
[code]: https://github.com/repsick3r/CSE425_Compiler_Design_Lab
