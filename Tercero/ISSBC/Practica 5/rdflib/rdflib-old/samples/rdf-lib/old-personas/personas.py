#! /usr/bin/python
# makeTriples.py: demonstrate the creation of an RDFLib TripleStore

from rdflib.Graph import ConjunctiveGraph, Graph
from rdflib.Literal import Literal
from rdflib.Namespace import Namespace
from rdflib.sparql import sparqlGraph
 
ns_fich=Namespace('fich="http://siva.uco.es/onto/owl/fichas-01#')
            
ns_rdf=Namespace("http://www.w3.org/1999/02/22-rdf-syntax-ns#")
ns_xs=Namespace("http://www.w3.org/2001/XMLSchema#")
 
ns_rdfs=Namespace("http://www.w3.org/2000/01/rdf-schema#")
ns_owl=Namespace("http://siva.uco.es/onto/owl/personas-01#")
ns_dam=Namespace("http://www.daml.org/2001/03/daml+oil#")
ns_dc=Namespace("http://purl.org/dc/elements/1.1/")
ns_per=Namespace("http://siva.uco.es/onto/owl/personas-01#")
ns_idp=Namespace("http://siva.uco.es/onto/owl/identificacion-personajes#")

store = Graph()

#store.parse('identificacion-personajes.rdf')
store.parse('identificacion-personajes.rdf')
store.parse('personas.rdf')

#print store.serialize()

 
 
def objetos():
        
    for o in store.objects(subject=ns_owl['Hombre'], predicate=ns_rdfs['subClassOf']):
#    for o in store.objects(subject=None, predicate=None):        
        print "objeto:",o, "\n"
        pass

def sujetos():
    for s in store.subjects(predicate=ns_per['identificacion'],object=None):
        print "sujeto:",s,"\n"
        pass
        #for o in store.objects(subject=s, predicate=None):
        #    print o
        #print '---------------------------------'
        #pass
def predicados():
    for p in store.predicates():
        #print p
        pass

def idPersonas():
    for o in store.objects(subject=ns_idp['Hombre_felipe-v'], 
                           predicate=ns_per['esEsposoDe']):
        print "objeto:",o, "\n"
        pass

idPersonas() 
#sujetos()



    
#store.close()
