# Object-Oriented-Programming-OOP-Personal-Projects
Cateva proiecte OOP care implica Friend & Overloading,Template,STL, Mostenire,Clase abstracte, Interfete, Exceptii, etc.

   1) Proiect Tonomat: Primul proiect este despre un tonomat de dulciuri, se pot cumpăra diferite produse (croissante, ciocolată, suc, etc.). Fiecare produs este identificat prin cod, nume și preț. Un client poate achizitiona un produs folosind doar monezi de anumite valori. Dacă clientul introduce o bancnota de X lei, solicită un produs de Y lei, tonomatul îi va putea da rest (X - Y lei) doar dacă dispune de această sumă în monezi de valori corespunzătoare. Aceasta aplicație permite achiziția unui produs.

   2) Proiect Cheltuieli de familie
O familie dorește să își organizeze cheltuielile lunare și are nevoie de o aplicație care să permită stocarea tuturor cheltuielilor dintr-o anumită lună. Pentru fiecare cheltuială se cunosc ziua din lună în care a fost efectuată (între 1 și 28/29/30/31), suma de bani (întreg pozitiv) și tipul (menaj, mâncare, transport, haine, internet, altele). Familia are nevoie de o aplicație cu următoarele funcționalități:
 adăugarea unei cheltuieli în lista (add, insert)
o ex. adaugă 10 internet - adaugă pentru ziua curentă o cheltuială de 10 RON
pentru internet
o ex. inserează 25 100 mâncare - inserează pentru ziua 25 a lunii curente o
cheltuială de 100 RON pentru mâncare  modificarea cheltuielilor din listă
o ex. elimină 15 - elimină toate cheltuielile din ziua 15
o ex. elimină 2 la 9 - elimină toate cheltuielile pentru zilele 2,3, ..., 9
o ex. elimină mâncare - elimină totate cheltuielile pentru mâncare din luna
curentă.
 stabilirea cheltuielilor cu anumite proprietăți
o ex. listează - afișarea tuturor cheltuielilor din luna curentă
o ex. listează mancare - afișarea tuturor cheltuielilor pentru mâncare
o ex. listează mâncare > 5 - afișarea tuturor cheltuielilor pentru mâncare mai
mari de 5 RON
o ex. listează internet = 44 - afișarea tuturor cheltuielilor pentru internet în
valoare de 44 RON
 obținerea unor proprietăți a diferitelor subliste
o ex. suma mâncare - suma tuturor cheltuielilor din categoria mâncare
o ex. max zi - afișarea zilei cu cele mai mari cheltuieli
o ex. sortare zi - afișarea sumelor cheltuite zilnic în ordine descrescătoare
o ex. sortează mâncare - afișarea sumelor cheltuite zilnic pentru mâncare,
ordonate crescător  filtrarea listei de cheltuieli
o ex. filtrare mâncare - păstrează doar cheltuielile pentru mâncare
o ex. filtrare menaj < 100 - păstrează doar cheltuielile pentru menaj mai mici
decât 100 RON
o ex. filtrare haine = 59 - păstrează doar cheltuielile pentru haine egale cu 59
RON
 undo - reface ultima operație. Aplicația trebuie să permită revenirea (prin undo) l
starea inițială.
