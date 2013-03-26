Question 1

<SuccessfulClassifications>
	for c in distinct-values(document("University.xml")) // Classification
	let s1 := document("University.xml") // Student[Classification = c.Classification]
	let s2 := document("University.xml") // Student[Classification = c.Classification and c/GPA >= 3.0]
	where count(s2) >= count(s1) * 0.20
	return {<Classification_GPA>
		c
		<AvgGPA> avg(s1/GPA) </AvgGPA>
		<Classification_GPA>}

Question 2

for $q in distinct_values document("bib.xml") // Author
<AuthorBib>
	$a,
	for $x in document("bib.xml")/* // * is a book or paper [Author = $a]
	return {
		if Tag($x) = "Paper" {<APaper> $x/Title </APaper>}
		else { <ABook> $x/Title </ABook> }
	}
</AuthorBib>

Question 3

<html>
	<table>
		<tr><td> Name </td>
			<td> DName </td>
			<td> Salary </td>
		</tr>
	for $e in document("Emp.xml") // Entry
	return {<tr><td> $e/Name </td>
				<td> $e/DName </td>
				<td> $e/Salary </td>
			</tr> }
	</table>
</html>

Question 4

A:  DEFGH DE>F
	12345
	12367

B:  DEFGH
	12345
	12867

C:  D>E
	H>DEFG

D:	(DEF, DEGH)

E:	(DE, EFGH)
	E!>DE
	E!>EFGH

F:	DE>F, F>D
	(FD, EFGH)

G:	DF>F
	FG>H
	G>D
	Keys: EG

H:	EG

I:	EGD

J:	DEFGH
		- DE>F
		- DEF
		- DEGH
			- D>G
			- DG
			- DEH
	(DEF, DG, DEH)

Question 5

AutoSales(Dealer, Month, Model, Color, Count, Amount)
A:	1 * 12 * 1 * 1
	1 * 12 * 5 * 10
	500 * 12 * 5 * 1

B:	SELECT Month, Model, A/C
	FROM AutoSales(*, Month, Model, *, C, A)