﻿import unittest

from rdflib import *
from rdflib.Graph import Graph
from rdflib import RDF
from rdflib.StringInputSource import StringInputSource

FOAF = Namespace("http://xmlns.com/foaf/0.1/")


rdfxml = """\
<?xml version="1.0" encoding="utf-8"?>
<rdf:RDF
  xmlns:xml='http://www.w3.org/XML/1998/namespace'
  xmlns:foaf='http://xmlns.com/foaf/0.1/'
  xmlns:rdf='http://www.w3.org/1999/02/22-rdf-syntax-ns#'
  xmlns:dc='http://http://purl.org/dc/elements/1.1/'
  xmlns:rdfs='http://www.w3.org/2000/01/rdf-schema#'
>
  <foaf:Person>
    <foaf:name>Donná Fales</foaf:name>
    <foaf:nick>donna</foaf:nick>
  </foaf:Person>
</rdf:RDF>"""

class RDFTestCase():
    backend = 'default'
    path = 'store'

    def setUp(self):
        self.store = Graph(store=self.backend)
        self.store.open(self.path)
        self.store.bind("dc", "http://http://purl.org/dc/elements/1.1/")
        self.store.bind("foaf", "http://xmlns.com/foaf/0.1/")
        return self.store

    def tearDown(self):
        self.store.close()
        print self.store.serialize()

    def addDonna(self):
        self.donna = donna = BNode()
        print 'Identificador:', donna.n3()
        self.store.add((donna, RDF.type, FOAF["Person"]))
        self.store.add((donna, FOAF["nick"], Literal("donna")))
        self.store.add((donna, FOAF["name"], Literal("Donna Fales")))
        return self.store

    def testRDFXML(self):
        self.addDonna()
        g = Graph()
        g.parse(StringInputSource(self.store.serialize(format="pretty-xml")))
        #self.assertEquals(self.store.isomorphic(g), True)
        print g.serialize()
def test_suite():
    return unittest.makeSuite(RDFTestCase)


rdf=RDFTestCase()
r=rdf.setUp()
print r.serialize()
rdf.tearDown()
r=rdf.addDonna()
print r.serialize()
rdf.testRDFXML()
g = Graph()
g.parse(StringInputSource(rdfxml))
print g.serialize()

