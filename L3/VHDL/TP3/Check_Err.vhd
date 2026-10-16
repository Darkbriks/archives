library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Check_Err is
    Port (e11 : in STD_LOGIC; -- And
          e12 : in STD_LOGIC; -- Or
          e13 : in STD_LOGIC; -- Not
          e14 : in STD_LOGIC; -- Xor
          e15 : in STD_LOGIC; -- Nand
          e16 : in STD_LOGIC; -- Nor
          err : out STD_LOGIC); -- 0 if exactly 1 switch is up, else 1
end Check_Err;

architecture Behavioral of Check_Err is
begin
    process(e11, e12, e13, e14, e15, e16)
        variable count : integer := 0;
    begin
        count := 0;
        
        if e11 = '1' then count := count + 1; end if;
        if e12 = '1' then count := count + 1; end if;
        if e13 = '1' then count := count + 1; end if;
        if e14 = '1' then count := count + 1; end if;
        if e15 = '1' then count := count + 1; end if;
        if e16 = '1' then count := count + 1; end if;
        
        if count /= 1 then err <= '1'; else err <= '0'; end if;
    end process;
end Behavioral;
