EXE = parse_hresult.exe
$(EXE): main.o mp_hresult_to_str.o facility_to_str.o
	$(CC) $^ -o $@
clean:
	$(RM) $(EXE) *.o
