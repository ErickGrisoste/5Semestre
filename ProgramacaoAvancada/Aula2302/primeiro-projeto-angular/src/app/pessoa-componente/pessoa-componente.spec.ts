import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PessoaComponente } from './pessoa-componente';

describe('PessoaComponente', () => {
  let component: PessoaComponente;
  let fixture: ComponentFixture<PessoaComponente>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [PessoaComponente]
    })
    .compileComponents();

    fixture = TestBed.createComponent(PessoaComponente);
    component = fixture.componentInstance;
    await fixture.whenStable();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
