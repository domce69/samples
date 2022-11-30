/*Stored procedure not processed at an isolation level */

SPOOL solution3
SET ECHO ON
SET FEEDBACK ON
SET LINESIZE 100
SET PAGESIZE 200
SET SERVEROUTPUT ON

ALTER TABLE TEAM ADD TOTALHSCORE NUMBER(2);
ALTER TABLE TEAM ADD TOTALASCORE NUMBER(2);

CREATE OR REPLACE PROCEDURE TOTALSCORECALC
IS
  CURSOR total_points
  IS
    SELECT
    HTNAME, HTSCORE, ATNAME, ATSCORE
    FROM GAME;

BEGIN

    UPDATE TEAM SET TOTALHSCORE = 0;
    UPDATE TEAM SET TOTALASCORE = 0;

  FOR totalp IN total_points
  LOOP

    UPDATE TEAM SET TOTALHSCORE =  TOTALHSCORE + totalp.HTSCORE WHERE NAME = totalp.HTNAME;
    UPDATE TEAM SET TOTALASCORE =  TOTALASCORE + totalp.ATSCORE WHERE NAME = totalp.ATNAME;

  END LOOP;
END;
/

EXECUTE TOTALSCORECALC;

SELECT * FROM TEAM;

SPOOL OFF

ALTER TABLE TEAM DROP COLUMN TOTALHSCORE;
ALTER TABLE TEAM DROP COLUMN TOTALASCORE;
