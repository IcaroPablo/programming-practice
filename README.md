# programming-practice

Programming challenges and snippets I've written myself to exercise the use of
a programming language. One directory per language, no build system tying them
together — each file stands on its own and is meant to be read, compiled or run
by itself.

This repository gathers what used to live in four separate ones —
`java-practice`, `c-language-practice`, `java-dump` and `python-practice`. Their
commit history was merged in rather than the files being copied fresh, so
`git log --follow` still reaches back to where each file came from. The four
original repositories have been deleted; this is now the only copy.

## What's here

### [`c/`](c/)

A small set of challenges written in C, from an old attempt at improving my C
with increasingly harder problems.

| File | What it is |
| --- | --- |
| [`bank-simulator-challenge.c`](c/bank-simulator-challenge.c) | A menu-driven bank simulator over 50 accounts, with balances and statements |
| [`fila.c`](c/fila.c) | A queue of numbered tickets, priority and ordinary |
| [`simple-PID-algorithm.c`](c/simple-PID-algorithm.c) | A generic PID controller correcting the speed of two wheels |
| [`sorting-practice.c`](c/sorting-practice.c) | Sorting methods applied to a ten-element array |
| [`struct-practice.c`](c/struct-practice.c) | A first exercise with `struct`, registering names and enrolment numbers |

### [`java/`](java/)

Two small projects and three loose snippets. The snippets are fragments pulled
out of larger code, not compilable classes.

| File | What it is |
| --- | --- |
| [`robo/`](java/robo/) | A finite state machine walking a robot around a grid, one class per orientation |
| [`jarray/`](java/jarray/) | A menu-driven array manipulation exercise (Maven) |
| [`Ordenacao.java`](java/Ordenacao.java) | Sorting a word list several ways with comparators and streams |
| [`almightyStreamReduce.java`](java/almightyStreamReduce.java) | An SVG merging service built out of a single, unreasonable `reduce` |
| [`string2map.java`](java/string2map.java) | Parsing a `Map`'s `toString` output back into a nested `Map` |

### [`python/`](python/)

Scripts written as I learned the language, in a pretty bad Python honestly. The
older ones are Python 2 — they use `print` as a statement and `raw_input`, and
some carry QPython headers from when I was writing them on a phone. The newer
ones ([`dijkstra.py`](python/dijkstra.py), [`pascal.py`](python/pascal.py) and
[`update dijkstra/`](python/update%20dijkstra/)) are Python 3.

Beyond the syntax exercises (`class test.py`, `dict test.py`, `string test.py`
and friends), the larger ones are [`jogo da forca.py`](python/jogo%20da%20forca.py)
(hangman), [`lista telefonica.py`](python/lista%20telefonica.py) (a phone book),
[`pascal.py`](python/pascal.py) (Pascal's triangle),
[`dijkstra.py`](python/dijkstra.py) (a maze solver, later revisited in
[`update dijkstra/`](python/update%20dijkstra/)) and
[`zed.py`](python/zed.py), a pygame simulation of a sweeping robot covering a
floor.

### [`haskell/`](haskell/) and [`joy/`](joy/)

One file each so far.
[`calendar-weeks.hs`](haskell/calendar-weeks.hs) builds an infinite calendar
from the Monday before today and groups it into weeks and months.
[`common-prefix.joy`](joy/common-prefix.joy) is an unfinished attempt at the
longest-common-prefix problem in Joy, a concatenative language.

## Branches

`main` is everything above. [`python-practice-remake`][remake] holds a rewrite
of the hangman and Pascal's triangle scripts that split off from
`python-practice` and was never merged back; it is kept only so that work isn't
lost.

## Author

Hello! I'm Ícaro Pablo. I'd be happy if you could give me any feedback about
this repository's code or structure, or anything that could make me a better
developer. You can reach me through the links on [my GitHub page][me].

## License

MIT, see [LICENSE](LICENSE).

[remake]: https://github.com/IcaroPablo/programming-practice/tree/python-practice-remake
[me]: https://www.github.com/IcaroPablo
