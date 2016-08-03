========================================================================
    CONSOLE APPLICATION : botBrain Project Overview
========================================================================


botbrain.cpp
    This is the main application source file.

trie.cpp
    This class implements a simple Trie data structure that serves as the knowledge Db.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

include/trieinterface.h, include/trie.h, include/botqa.h, include/botbrain.h

    The interface trieinterface.h is implemented by the class defined in trie.h
    The botbrain.h defines a botbrain type which uses a trie class instance to access the knowledgebase
    this bot is familair with.
    botqa contains the knowledge entries that we train this botbrain with.

/////////////////////////////////////////////////////////////////////////////
Other notes:


/////////////////////////////////////////////////////////////////////////////
