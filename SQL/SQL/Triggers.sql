@dbdrop
@dbcreate
SPOOL solution2
SET ECHO ON
SET FEEDBACK ON
SET LINESIZE 100
SET PAGESIZE 200
SET SERVEROUTPUT ON

/* my triggers checks wether theres an entry of a HTNAME and ATNAME  */
/* equal to the HTNAME and ATNAME which is trying to be inserted or updated   */
/* If there is a game with the same HTNAME and ATNAME a application error is raised */
/* This is because two teams verse eachother 2 times only, one at their home town and one away */

CREATE OR REPLACE TRIGGER insertgame
before insert on GAME
for each row
DECLARE

  CURSOR names
  IS
    SELECT
    HTNAME, ATNAME
    FROM GAME;


BEGIN

  FOR n IN names
  LOOP

   IF :new.HTNAME = n.HTNAME AND :new.ATNAME = n.ATNAME THEN
   RAISE_APPLICATION_ERROR(-20001, 'the two teams cant verse eachother at the same location twice');

    END IF;
  END LOOP;

END;
/

INSERT INTO GAME VALUES ('17-NOV-2020:10:00:00', 'sydney showground', 'sydney', 'roosters', 20, 'dragons', 12);

SELECT * FROM GAME;


CREATE OR REPLACE TRIGGER updategame
before update on GAME
for each row
DECLARE
pragma autonomous_transaction;

  CURSOR names
  IS
    SELECT
    HTNAME, ATNAME
    FROM GAME;

BEGIN

  FOR n IN names
  LOOP

   IF :new.HTNAME = n.HTNAME AND :new.ATNAME = n.ATNAME THEN
   RAISE_APPLICATION_ERROR(-20001, 'the teams cant verse eachother at this location');

    END IF;
  END LOOP;

END;
/

UPDATE GAME SET HTNAME = 'roosters', ATNAME = 'dragons'
WHERE VENUE = 'sydney showground';

SELECT * FROM GAME;

SPOOL OFF
