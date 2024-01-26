# OOP I. Paradigma

## Programovaci Paradigma
- Imperativni (posloupnost prikazu) - C, Pascal
- Funkcionalni (rekurze) - Lisp, Haskel
- Dalsi (Logicke paradigma - Prolog, Paralelni paradigma - Java, Rust, Go, SmallTalk)

## Vztah stroje, jazyka a programu
- Programovaci jazyk rozsiruje moznosti stroje
- Programovaci jazyk je mezivrstva pc a programatorem

## Programovaci Paradigma
- Zakladni programovaci styl
- Vytvari predstavu o krocich vypoctu
- C: nelze a pracuje jako PC
- Java: ma svuj vyrtualni pocitac a tvoji si svoje tridy

## Hybridni (podporuje vice paradigmat)
- C++, Java - imperativni (rozloz problem na podproblemy), objektove
- Lisp, Scheme - Funkcionalni, objektove (+ nektere imperativni rysy)

## Strukturovane prikazy
- strukturovane prikazy a strukturovana data (podminky, cykly)
- Vyhybat se prikazu **GOTO** (zpusobuje desive chyby)

## Strukturovane programovani
- **Program = datove struktury + algoritmy**

## Funkcionalni programovani
- vypocet je zalozen na postupnem aplikovani funkci
- Obrovsky vyznam ma rekurze (Rekurze je Turingovsky kompletni)


## Objektove orientovane paradigma
- Objekty realneho sveta, ktere si spolu povidaji (napr. predmety, osoby, udalosti)
- **Program = Objekty + zpravy (podprogramy)**

## Vyhody OOP
- Hlavni duraz klade na navrh datovych typu
    * trida = pokrocilejsi datova strukturovane
    * objekt = promenna typu trida
- Metody jsou unitr trid/objektu a nevidi do jinych trid/objektu -> **zapouzdreni**
- Vyssi bezpecnost programu
- Prirozena modularita (ke tridam jde pridavat funkcnost pomoci mechanismu dedicnosti)
- **Plymorfismus** - pomoci jej jde ovladat ruzne druhy pribuznych objektu
    * ```dvere.otevri() a x.let()```

## Nevyhody OOP
- mene efektivni - vetsi, pomalejsi (nez C)
- nekdy zbytecne slozite programy
- vede k tendenci hledat pribuzenske vztahy, kde v realnem svete nejsou
    * vlastovka, raketa - schopny letu (takze - spolecny predek???)

## Reseni nevyhod 
- **Navrhove vzory**
    * casem proverene navrhy strktur trid
    * opakovane pouzivane v ruznych realnych projektech
- Systemovy analytik, softwarovy architekt

## Navrh programu
- "Neptej se nejdirve CO ma program delat, ptej se S CIM to ma delat"
- **Zahrnuje**: analyzu, navrh, implementaci programu
- **Modeluje**: objekty realneho (nebo virtualniho) sveta, jejich vzajemne vazby a vztahy, jejich vzajemne interakce
- **Program je simulaci tohoto modelu
- Program vymyslime jako divadelni hru (nezaciname s scenami, ale z vrchu)
