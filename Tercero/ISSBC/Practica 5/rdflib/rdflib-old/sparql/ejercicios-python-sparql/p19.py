from rdflib.Namespace import Namespace
from rdflib import plugin,RDF,RDFS,URIRef, StringInputSource, Literal
from rdflib.Graph import Graph,ReadOnlyGraphAggregate,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint

 
text="""
# Named graph: http://example.org/foaf/aliceFoaf
@prefix  foaf:  <http://xmlns.com/foaf/0.1/> .
@prefix  rdf:    <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix  rdfs:   <http://www.w3.org/2000/01/rdf-schema#> .

_:a  foaf:name     "Alice" .
_:a  foaf:mbox     <mailto:alice@work.example> .
_:a  foaf:knows    _:b .

_:b  foaf:name     "Bob" .
_:b  foaf:mbox     <mailto:bob@work.example> .
_:b  foaf:nick     "Bobby" .
_:b  rdfs:seeAlso  <http://example.org/foaf/bobFoaf> .

<http://example.org/foaf/bobFoaf>
     rdf:type      foaf:PersonalProfileDocument .

# Named graph: http://example.org/foaf/bobFoaf
@prefix  foaf:  <http://xmlns.com/foaf/0.1/> .
@prefix  rdf:    <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix  rdfs:   <http://www.w3.org/2000/01/rdf-schema#> .

_:z  foaf:mbox     <mailto:bob@work.example> .
_:z  rdfs:seeAlso  <http://example.org/foaf/bobFoaf> .
_:z  foaf:nick     "Robert" .
<http://example.org/foaf/bobFoaf>
     rdf:type      foaf:PersonalProfileDocument .

""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')

test_query = """
PREFIX foaf: <http://xmlns.com/foaf/0.1/>

SELECT ?src ?bobNick
WHERE
  {
    GRAPH ?src
    { ?x foaf:mbox <mailto:bob@work.example> .
      ?x foaf:nick ?bobNick
    }
  }
""" 


print
print 'Value Constraints:'
print 
results = graph.query(test_query)
print results.serialize(format='xml')

 
