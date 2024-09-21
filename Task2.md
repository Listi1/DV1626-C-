# Examination modul 2 - Booking System

Modul 2 har introducerat klasser och objekt. Denna examinationsuppgift ämnar därför examinera dessa koncept.

---

Din uppgift är att implementera två klasser för ett bokningssystem: `BookingSystem` och `Reservation`.
Båda dessa klasser är redan definierade i sina headerfiler (.hpp), men deras källfiler (.cpp) är tomma och behöver fyllas i av dig. 
Samtliga medlemsfunktioner från klasserna behöver definieras här.

Klassen 'Reservation' innehåller nödvändig information för en specifik bokning.
En bokning består av ett refererens-id, exempelvis namnet på ett föremål som ska bokas, 
samt start- och slutdatum. Utöver detta har klassen även viss funktionalitet för att kunna jämföras med andra bokningar eller avgöra om
två bokningar överlappar. Om en ogiltig bokning försöker konstrueras, dvs. dess slutdatum är före dess startdatum, ska dess konstruktor
kasta ett undantag av typen `std::invalid_argument` (se konstruktor i `Date.cpp` för exempel).

Klassen 'BookingSystem' skapar ett gränssnitt för att göra bokningar och lagrar alla tidigare skapade bokningar.
Med denna klass är det möjligt att försöka göra en bokning, och få resultat om det var möjligt eller inte. 
Det är inte möjligt att ta bort en redan existerande bokning i detta bokningssystem.     <--------!!!!!!!!!!!!

När ett bokningssystem skapas måste en kapacitet anges som argument till dess konstruktor. 
Bokningssystemet ska innehålla en *dynamiskt allokerad array av 'Reservation'-pekare*, där arrayens kapacitet är värdet som skickas 
till dess konstruktor. Arrayen ska fyllas från start till slut utan "hål". När en giltig bokning ska läggas till ska den allokeras 
dynamiskt på heapen, och dess adress ska lagras i arrayens nästa tillgängliga plats. Om en ogiltig bokning försöker skapas ska 
bokningssystemet inte tillåta detta. Om en giltig bokning ska utföras, men bokningssystemets kapacitet är full från tidigare bokningar, 
ska bokningssystemet *expandera*. Bokningssystemet expanderar genom att dynamiskt allokera en ny, större array dit alla tidigare 
reservationer kopieras till.

Det finns vissa regler för att göra en ny bokning. En bokning är giltig om och endast om:
    1. Dess slutdatum inte är före dess startdatum.
    2. Ingen annan bokning existerar med samma referens-id under samma tidsperiod.
        - Två bokningar tillåts dock att dela samma tidsperiod om de har olika refererens-id.

Notera att denna koduppgift arbetar med *datum*. Datum är en väldefinierad klass som följer med koduppgiften och inget du ska implementera själv.
I filerna `Date.hpp` och `Date.cpp` hittar du implemetationen för klassen `Date`.

## Kriterier vid inlämning:
- Klasser ska följa beskrivningar ovan.
- Inga fler `#include` får användas mer än de som redan finns i filerna.
    - Det är ok att använda andra `#include` under utveckling, men dessa måste rensas (inte utkommenteras) innan inlämning.
- Alla funktionsdefinitioner ska finnas i klassernas respektive källfiler (.cpp).
- Kod ska vara skriven på engelska, och hålla en god struktur som är tydlig att läsa.
- Förklarande namn på variabler och funktioner ska användas.
- Ingen utkommenterad kod ska finnas i filerna.
- Globala variabler är ej tillåtna.



ATT GÖRA:
1. fylla bookingsystem.cpp och Reservation.cpp (ingen annan fil får röras)

2. Reservation --> referensid ( namn på saken ) och start och slut datum (slut datum får inte vara innan start datum).  Kolla efter bokningar.   Kolla så bokningar inte overlappar (bara med samma referensid). Om något fel ska den kasta en error ( beskrivs över )

3. Bookingsystem --> används för att skapa bokningarna och förvarar dem.   Resultat om bokningen gick genom eller inte.   GÅR INTE ATT TA BORT BOKNINGAR.

4.  bookingsystem --> dynamisk allokerad array med reservationspekare.   Skapar ny array med större storlek när nya saker läggs till, delete den gamla.

5. vad gör date?
