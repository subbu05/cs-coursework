import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TMTest {

    TM tm1;
    TM tm2;
    TM tm3;
    TM tm4;

    @Before
    public void setup() {

        Rule[] rules1 = new Rule[9];
        rules1[0] = new Rule(0, 'B', 2, 'B', 1);
        rules1[1] = new Rule(0, 'a', 3, 'a', 1);
        rules1[2] = new Rule(0, 'b', 4, 'b', 1);
        rules1[3] = new Rule(3, 'a', 1, 'a', 1);
        rules1[4] = new Rule(3, 'b', 1, 'b', 1);
        rules1[5] = new Rule(3, 'B', 1, 'B', 1);
        rules1[6] = new Rule(4, 'a', 2, 'a', 1);
        rules1[7] = new Rule(4, 'b', 2, 'b', 1);
        rules1[8] = new Rule(4, 'B', 2, 'B', 1);
        tm1 = new TM(rules1, 10);

        Rule[] rules2 = new Rule[20];
        rules2[0] = new Rule(0, 'B', 2, 'B', 1);
        rules2[1] = new Rule(0, '#', 2, '#', 1);
        rules2[2] = new Rule(0, 'a', 3, 'B', 1);
        rules2[3] = new Rule(0, 'b', 2, 'b', 1);

        rules2[4] = new Rule(3, '#', 3, '#', 1);
        rules2[5] = new Rule(3, 'B', 1, 'B', 1);
        rules2[6] = new Rule(3, 'a', 4, '#', 1);
        rules2[7] = new Rule(3, 'b', 2, 'b', 1);

        rules2[8] = new Rule(4, '#', 4, '#', 1);
        rules2[9] = new Rule(4, 'a', 5, 'a', 1);
        rules2[10] = new Rule(4, 'B', 6, 'B', -1);
        rules2[11] = new Rule(4, 'b', 2, 'b', 1);

        rules2[12] = new Rule(5, '#', 5, '#', 1);
        rules2[13] = new Rule(5, 'a', 4, '#', 1);
        rules2[14] = new Rule(5, 'B', 2, 'B', 1);
        rules2[15] = new Rule(5, 'b', 2, 'b', 1);

        rules2[16] = new Rule(6, 'a', 6, 'a', -1);
        rules2[17] = new Rule(6, '#', 6, '#', -1);
        rules2[18] = new Rule(6, 'B', 3, 'B', 1);
        rules2[19] = new Rule(6, 'b', 2, 'b', 1);
        tm2 = new TM(rules2, 10);

        Rule[] rules3 = new Rule[5];
        rules3[0] = new Rule(0, 'a', 3, 'b', 1);
        rules3[1] = new Rule(0, 'b', 2, 'b', 1);
        rules3[2] = new Rule(3, 'a', 3, 'a', 1);
        rules3[3] = new Rule(3, 'B', 1, 'B', 1);
        rules3[4] = new Rule(3, 'b', 0, 'a', -1);
        tm3 = new TM(rules3, 10);
    }

    @Test
    public void runTest() {
        assertEquals(0, tm1.run("aaab"));
        assertEquals(1, tm1.run("ba"));
        assertEquals(1, tm1.run("b"));

        assertEquals(0, tm2.run("a"));
        assertEquals(0, tm2.run("aa"));
        assertEquals(-1, tm2.run("aaaaaaaa"));

        assertEquals(0, tm3.run("aaab"));
        assertEquals(-1, tm3.run("aaaaaaaaaaaaaaaaaab"));
        assertEquals(1, tm3.run("ababab"));
    }
}
