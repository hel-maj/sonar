/* ===== 23e896660 workers.fishing.store_fish:362 ===== */
/* ghidra_name=FUN_23e896660 entry=23e896660 size=14790 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e896660(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong lVar10;
  undefined8 uVar11;
  code *pcVar12;
  code *pcVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  undefined4 uVar19;
  code *pcVar20;
  code *pcStack_108;
  code *pcStack_100;
  undefined1 *puStack_f8;
  code *pcStack_f0;
  longlong *plStack_e8;
  code *pcStack_e0;
  longlong *plStack_d8;
  longlong *plStack_c0;
  code *pcStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  undefined1 auStack_78 [16];
  code *apcStack_68 [5];
  
  plVar9 = _DAT_23eede5f8;
  plVar1 = (longlong *)*param_3;
  apcStack_68[0] = (code *)0x0;
  auStack_78._0_8_ = (code *)0x0;
  auStack_78._8_8_ = 0;
  if (_DAT_23eede5f8 == (longlong *)0x0) {
LAB_23e8966bd:
    _DAT_23eede5f8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede5f0,DAT_23eede708);
  }
  else {
    lVar10 = *_DAT_23eede5f8;
    if (1 < lVar10) {
      *_DAT_23eede5f8 = lVar10 + -1;
      goto LAB_23e8966bd;
    }
    if (_DAT_23eede5f8[2] != 0) {
      *_DAT_23eede5f8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e8966bd;
    }
  }
  plVar3 = _DAT_23eede5f8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede5f8 + 9;
  lVar2 = *(longlong *)(lVar10 + 8);
  _DAT_23eede5f8[0xf] = lVar2;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar11 = _DAT_23eedccd8;
  *(undefined4 *)(plVar3 + 8) = 0;
  *(undefined4 *)(plVar3 + 5) = 0x16c;
  plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar1,uVar11);
  if (plVar9 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    apcStack_68[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (apcStack_68[0] == (code *)0x0) goto LAB_23e897b00;
    if (plVar3 != *(longlong **)(apcStack_68[0] + 0x18)) {
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      pcVar12 = (code *)0x0;
      pcVar20 = (code *)0x0;
      iVar8 = 0x16c;
      pcStack_100 = _PyRuntime_exref;
      pcVar13 = (code *)0x0;
      goto LAB_23e89746a;
    }
LAB_23e897720:
    plVar9 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    pcVar12 = (code *)0x0;
    pcVar13 = (code *)0x0;
    pcVar20 = (code *)0x0;
    pcVar15 = apcStack_68[0];
    goto LAB_23e897523;
  }
  iVar8 = FUN_23a35f020();
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  if (iVar8 == -1) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    apcStack_68[0] = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (apcStack_68[0] != (code *)0x0) {
      if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      pcVar12 = (code *)0x0;
      pcVar13 = (code *)0x0;
      pcVar20 = (code *)0x0;
      iVar8 = 0x16c;
      pcStack_100 = _PyRuntime_exref;
      goto LAB_23e89746a;
    }
LAB_23e897b00:
    plVar9 = (longlong *)0x0;
    plStack_d8 = (longlong *)0x0;
    pcVar12 = (code *)0x0;
    pcVar13 = (code *)0x0;
    pcVar20 = (code *)0x0;
    iVar8 = 0x16c;
    pcStack_100 = _PyRuntime_exref;
LAB_23e897350:
    pcVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar18 = apcStack_68[0];
    }
    else {
      pcVar18 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar18 = (code *)0x0;
    }
    *(longlong *)(pcVar15 + 0x10) = 0;
    *(longlong **)(pcVar15 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcStack_100 + 0x1f8);
    *(int *)(pcVar15 + 0x24) = iVar8;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar2 = *(longlong *)(pcVar15 + -8);
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = pcVar15 + -0x10;
    *(longlong *)(pcVar15 + -0x10) = lVar10;
    *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(code **)(lVar10 + 8) = pcVar15 + -0x10;
    if ((pcVar18 != (code *)0x0) &&
       (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
    }
  }
  else {
    if (iVar8 == 0) {
      pcVar12 = (code *)0x0;
      pcVar20 = (code *)0x0;
      pcStack_108 = _Py_NoneStruct_exref;
      lVar10 = *(longlong *)_Py_NoneStruct_exref + 1;
      pcVar15 = (code *)0x0;
      goto LAB_23e8967ad;
    }
    uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x16f;
    plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcce0);
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      apcStack_68[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_68[0] != (code *)0x0) {
        if (*(longlong **)(apcStack_68[0] + 0x18) == plVar3) goto LAB_23e897720;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        pcVar12 = (code *)0x0;
        pcVar20 = (code *)0x0;
        iVar8 = 0x16f;
        pcStack_100 = _PyRuntime_exref;
        pcVar13 = (code *)0x0;
        goto LAB_23e89746a;
      }
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      pcVar12 = (code *)0x0;
      pcVar20 = (code *)0x0;
      iVar8 = 0x16f;
      pcStack_100 = _PyRuntime_exref;
      pcVar13 = (code *)0x0;
      apcStack_68[0] = (code *)0x0;
      goto LAB_23e897350;
    }
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
    *(undefined4 *)(plVar3 + 5) = 0x170;
    plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcce8);
    if (plVar9 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      apcStack_68[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_68[0] == (code *)0x0) {
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        pcVar12 = (code *)0x0;
        pcVar20 = (code *)0x0;
        iVar8 = 0x170;
        pcStack_100 = _PyRuntime_exref;
        pcVar13 = (code *)0x0;
        apcStack_68[0] = (code *)0x0;
        goto LAB_23e897350;
      }
      if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      pcVar12 = (code *)0x0;
      pcVar20 = (code *)0x0;
      iVar8 = 0x170;
      pcStack_100 = _PyRuntime_exref;
      pcVar13 = (code *)0x0;
    }
    else {
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
      *(undefined4 *)(plVar3 + 5) = 0x171;
      plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedccf0);
      if (plVar9 != (longlong *)0x0) {
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        pcVar12 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
        plVar14 = _DAT_23eedccf8;
        lVar10 = *(longlong *)(param_1 + 0x10);
        plVar9 = *(longlong **)(lVar10 + 0xe20);
        if (plVar9 == (longlong *)0x0) {
          plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar2 = plVar9[3];
          *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
          *(longlong *)(lVar10 + 0xe20) = lVar2;
          *plVar9 = 1;
        }
        pcStack_100 = _PyRuntime_exref;
        plVar9[4] = 0;
        lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_100 + 0x1f8) + 0x10) + 0x2e8);
        lVar2 = plVar9[-1];
        puVar4 = *(undefined8 **)(lVar10 + 8);
        *puVar4 = plVar9 + -2;
        plVar9[-2] = lVar10;
        plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
        *(longlong **)(lVar10 + 8) = plVar9 + -2;
        uVar11 = DAT_23eedca18;
        *plVar14 = *plVar14 + 1;
        plVar9[3] = (longlong)plVar14;
        pcVar13 = (code *)FUN_23e8bc2f0(plVar1,uVar11);
        uVar11 = DAT_23ed6cd28;
        if (pcVar13 == (code *)0x0) {
LAB_23e897760:
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          apcStack_68[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          if (apcStack_68[0] != (code *)0x0) {
            if (*(longlong **)(apcStack_68[0] + 0x18) == plVar3) goto LAB_23e897720;
            plVar9 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            pcVar12 = (code *)0x0;
            pcVar13 = (code *)0x0;
            pcVar20 = (code *)0x0;
            iVar8 = 0x172;
            goto LAB_23e89746a;
          }
        }
        else {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            pcVar20 = pcVar13;
            if (plVar14 == (longlong *)0x0) goto LAB_23e897be2;
            *plVar14 = *plVar14 + 1;
            DAT_23ed6a4c0 = plVar14;
          }
          puStack_f8 = auStack_98;
          auStack_98._8_8_ = uVar11;
          auStack_98._0_8_ = pcVar13;
          lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_f8);
          *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
          if (*(longlong *)pcVar13 == 0) {
            (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
          }
          pcStack_f0 = PyUnicode_Join_exref;
          if (lVar10 == 0) goto LAB_23e897760;
          plVar9[4] = lVar10;
          plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          if (plVar14 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0x172;
            plVar9 = (longlong *)FUN_23e914090(param_1,pcVar12,plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))();
            }
            if (plVar9 == (longlong *)0x0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              apcStack_68[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (apcStack_68[0] == (code *)0x0) goto LAB_23e897873;
              if (*(longlong **)(apcStack_68[0] + 0x18) == plVar3) goto LAB_23e897720;
              plVar9 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              pcVar13 = (code *)0x0;
              pcVar20 = (code *)0x0;
              iVar8 = 0x172;
              pcVar12 = (code *)0x0;
              goto LAB_23e89746a;
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            pcVar12 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
            plVar14 = _DAT_23eedcd00;
            lVar10 = *(longlong *)(param_1 + 0x10);
            plVar9 = *(longlong **)(lVar10 + 0xe50);
            if (plVar9 == (longlong *)0x0) {
              plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,8);
            }
            else {
              lVar2 = plVar9[3];
              *(int *)(lVar10 + 0xed4) = *(int *)(lVar10 + 0xed4) + -1;
              *(longlong *)(lVar10 + 0xe50) = lVar2;
              *plVar9 = 1;
            }
            *(undefined1 (*) [16])(plVar9 + 3) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(plVar9 + 5) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(plVar9 + 7) = (undefined1  [16])0x0;
            *(undefined1 (*) [16])(plVar9 + 9) = (undefined1  [16])0x0;
            lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_100 + 0x1f8) + 0x10) + 0x2e8)
            ;
            lVar2 = plVar9[-1];
            puVar4 = *(undefined8 **)(lVar10 + 8);
            *puVar4 = plVar9 + -2;
            plVar9[-2] = lVar10;
            plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
            *(longlong **)(lVar10 + 8) = plVar9 + -2;
            uVar11 = DAT_23eedca20;
            *plVar14 = *plVar14 + 1;
            plVar9[3] = (longlong)plVar14;
            plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
            if (plVar14 == (longlong *)0x0) {
LAB_23e8972e0:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              apcStack_68[0] = *(code **)(param_1 + 0x70);
              iVar8 = 0x173;
            }
            else {
              pcVar13 = (code *)FUN_23a38cc10(param_1,plVar14,DAT_23eedca70);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              uVar11 = DAT_23ed6cd28;
              if (pcVar13 == (code *)0x0) goto LAB_23e8972e0;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                pcVar20 = pcVar13;
                if (plVar14 == (longlong *)0x0) goto LAB_23e897be2;
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
              }
              auStack_98._8_8_ = uVar11;
              auStack_98._0_8_ = pcVar13;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_f8);
              *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
              if (*(longlong *)pcVar13 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
              }
              plVar14 = DAT_23eedcaf8;
              if (lVar10 == 0) goto LAB_23e8972e0;
              plVar9[4] = lVar10;
              uVar11 = DAT_23eedca20;
              *plVar14 = *plVar14 + 1;
              plVar9[5] = (longlong)plVar14;
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
              if (plVar14 == (longlong *)0x0) goto LAB_23e8972e0;
              pcVar13 = (code *)FUN_23a38cc10(param_1,plVar14,DAT_23eedcb00);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              uVar11 = DAT_23ed6cd28;
              if (pcVar13 == (code *)0x0) goto LAB_23e8972e0;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                pcVar20 = pcVar13;
                if (plVar14 == (longlong *)0x0) goto LAB_23e897be2;
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
              }
              auStack_98._8_8_ = uVar11;
              auStack_98._0_8_ = pcVar13;
              lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_f8);
              *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
              if (*(longlong *)pcVar13 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
              }
              plVar14 = _DAT_23eedcd08;
              if (lVar10 == 0) goto LAB_23e8972e0;
              plVar9[6] = lVar10;
              uVar11 = DAT_23eedca20;
              *plVar14 = *plVar14 + 1;
              plVar9[7] = (longlong)plVar14;
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
              if (plVar14 != (longlong *)0x0) {
                pcVar13 = (code *)FUN_23a38cc10(param_1,plVar14,DAT_23eedcb10);
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
                if (pcVar13 != (code *)0x0) {
                  pcVar20 = pcVar13;
                  uVar11 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e897bf5;
                  while( true ) {
                    auStack_98._8_8_ = uVar11;
                    auStack_98._0_8_ = pcVar20;
                    lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_f8);
                    *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                    if (*(longlong *)pcVar13 == 0) {
                      (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
                    }
                    plVar14 = _DAT_23eedcd10;
                    if (lVar10 == 0) goto LAB_23e897990;
                    plVar9[8] = lVar10;
                    uVar11 = DAT_23eedca20;
                    *plVar14 = *plVar14 + 1;
                    plVar9[9] = (longlong)plVar14;
                    plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
                    if (plVar14 == (longlong *)0x0) goto LAB_23e897990;
                    pcVar13 = (code *)FUN_23a38cc10(param_1,plVar14,DAT_23eedcb20);
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))();
                    }
                    uVar11 = DAT_23ed6cd28;
                    if (pcVar13 == (code *)0x0) goto LAB_23e897990;
                    if (DAT_23ed6a4c0 != (longlong *)0x0) break;
                    plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    pcVar20 = pcVar13;
                    if (plVar14 != (longlong *)0x0) {
                      *plVar14 = *plVar14 + 1;
                      DAT_23ed6a4c0 = plVar14;
                      break;
                    }
LAB_23e897be2:
                    do {
                      PyErr_PrintEx(0);
                      Py_Exit(1);
LAB_23e897bf5:
                      plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    } while (plVar14 == (longlong *)0x0);
                    *plVar14 = *plVar14 + 1;
                    DAT_23ed6a4c0 = plVar14;
                  }
                  auStack_98._8_8_ = uVar11;
                  auStack_98._0_8_ = pcVar13;
                  lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_f8);
                  *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
                  if (*(longlong *)pcVar13 == 0) {
                    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))();
                  }
                  uVar11 = DAT_23ed6cd28;
                  if (lVar10 != 0) {
                    plVar9[10] = lVar10;
                    plVar14 = (longlong *)(*pcStack_f0)(uVar11,plVar9);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))();
                    }
                    if (plVar14 == (longlong *)0x0) {
                      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                      apcStack_68[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (apcStack_68[0] == (code *)0x0) {
LAB_23e899198:
                        plVar9 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        pcVar12 = (code *)0x0;
                        pcVar13 = (code *)0x0;
                        pcVar20 = (code *)0x0;
                        iVar8 = 0x173;
                        goto LAB_23e897350;
                      }
                      if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
                      plVar9 = (longlong *)0x0;
                      plStack_d8 = (longlong *)0x0;
                      pcVar12 = (code *)0x0;
                      pcVar20 = (code *)0x0;
                      iVar8 = 0x173;
                      pcVar13 = (code *)0x0;
                    }
                    else {
                      *(undefined4 *)(plVar3 + 5) = 0x173;
                      plVar9 = (longlong *)FUN_23e914090(param_1,pcVar12,plVar14);
                      *plVar14 = *plVar14 + -1;
                      if (*plVar14 == 0) {
                        (**(code **)(plVar14[1] + 0x30))();
                      }
                      if (plVar9 == (longlong *)0x0) {
                        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                        apcStack_68[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        if (apcStack_68[0] == (code *)0x0) goto LAB_23e899198;
                        if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
                        plVar9 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        pcVar13 = (code *)0x0;
                        pcVar20 = (code *)0x0;
                        iVar8 = 0x173;
                        pcVar12 = (code *)0x0;
                      }
                      else {
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        pcVar13 = (code *)FUN_23a3a0d40(DAT_23ed6cf28);
                        plVar14 = _DAT_23eedcd18;
                        lVar10 = *(longlong *)(param_1 + 0x10);
                        plVar9 = *(longlong **)(lVar10 + 0xe20);
                        if (plVar9 == (longlong *)0x0) {
                          plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                        }
                        else {
                          lVar2 = plVar9[3];
                          *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                          *(longlong *)(lVar10 + 0xe20) = lVar2;
                          *plVar9 = 1;
                        }
                        plVar9[4] = 0;
                        lVar10 = *(longlong *)
                                  (*(longlong *)(*(longlong *)(pcStack_100 + 0x1f8) + 0x10) + 0x2e8)
                        ;
                        lVar2 = plVar9[-1];
                        puVar4 = *(undefined8 **)(lVar10 + 8);
                        *puVar4 = plVar9 + -2;
                        plVar9[-2] = lVar10;
                        plVar9[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
                        *(longlong **)(lVar10 + 8) = plVar9 + -2;
                        uVar11 = _DAT_23eedca28;
                        *plVar14 = *plVar14 + 1;
                        plVar9[3] = (longlong)plVar14;
                        plVar14 = (longlong *)FUN_23e8bc2f0(plVar1,uVar11);
                        if (plVar14 == (longlong *)0x0) {
LAB_23e897c4a:
                          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                          apcStack_68[0] = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))();
                          }
                          if (apcStack_68[0] == (code *)0x0) {
LAB_23e897d59:
                            plVar9 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            pcVar12 = (code *)0x0;
                            pcVar13 = (code *)0x0;
                            pcVar20 = (code *)0x0;
                            iVar8 = 0x175;
                            goto LAB_23e897350;
                          }
                          if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
                          plVar9 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          pcVar12 = (code *)0x0;
                          pcVar13 = (code *)0x0;
                          pcVar20 = (code *)0x0;
                          iVar8 = 0x175;
                        }
                        else {
                          pcVar12 = (code *)FUN_23e8bd600(param_1,plVar14);
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))();
                          }
                          uVar11 = DAT_23ed6cd28;
                          if (pcVar12 == (code *)0x0) goto LAB_23e897c4a;
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            pcVar20 = pcVar12;
                            if (plVar14 == (longlong *)0x0) goto LAB_23e897be2;
                            *plVar14 = *plVar14 + 1;
                            DAT_23ed6a4c0 = plVar14;
                          }
                          auStack_98._8_8_ = uVar11;
                          auStack_98._0_8_ = pcVar12;
                          lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,puStack_f8);
                          *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
                          if (*(longlong *)pcVar12 == 0) {
                            (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))();
                          }
                          if (lVar10 == 0) goto LAB_23e897c4a;
                          plVar9[4] = lVar10;
                          plVar14 = (longlong *)(*pcStack_f0)(DAT_23ed6cd28,plVar9);
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))();
                          }
                          if (plVar14 == (longlong *)0x0) {
                            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                            apcStack_68[0] = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            if (apcStack_68[0] == (code *)0x0) goto LAB_23e897d59;
                            if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
                            plVar9 = (longlong *)0x0;
                            plStack_d8 = (longlong *)0x0;
                            pcVar13 = (code *)0x0;
                            pcVar20 = (code *)0x0;
                            iVar8 = 0x175;
                            pcVar12 = (code *)0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x175;
                            plVar9 = (longlong *)FUN_23e914090(param_1,pcVar13,plVar14);
                            *plVar14 = *plVar14 + -1;
                            if (*plVar14 == 0) {
                              (**(code **)(plVar14[1] + 0x30))();
                            }
                            if (plVar9 == (longlong *)0x0) {
                              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                              apcStack_68[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_68[0] == (code *)0x0) goto LAB_23e897d59;
                              if (*(longlong **)(apcStack_68[0] + 0x18) == plVar3)
                              goto LAB_23e897720;
                              plVar9 = (longlong *)0x0;
                              plStack_d8 = (longlong *)0x0;
                              pcVar12 = (code *)0x0;
                              pcVar20 = (code *)0x0;
                              iVar8 = 0x175;
                              pcVar13 = (code *)0x0;
                            }
                            else {
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                              *(undefined4 *)(plVar3 + 5) = 0x176;
                              plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcd20);
                              if (plVar9 == (longlong *)0x0) {
                                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                apcStack_68[0] = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                if (apcStack_68[0] == (code *)0x0) {
                                  plVar9 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  pcVar20 = (code *)0x0;
                                  iVar8 = 0x176;
                                  pcVar13 = (code *)0x0;
                                  pcVar12 = (code *)0x0;
                                  apcStack_68[0] = (code *)0x0;
                                  goto LAB_23e897350;
                                }
                                if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18))
                                goto LAB_23e897720;
                                plVar9 = (longlong *)0x0;
                                plStack_d8 = (longlong *)0x0;
                                pcVar12 = (code *)0x0;
                                pcVar20 = (code *)0x0;
                                iVar8 = 0x176;
                                pcVar13 = (code *)0x0;
                              }
                              else {
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                *(undefined4 *)(plVar3 + 5) = 0x177;
                                plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11);
                                if (plVar9 == (longlong *)0x0) {
                                  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  if (apcStack_68[0] == (code *)0x0) {
                                    plVar9 = (longlong *)0x0;
                                    plStack_d8 = (longlong *)0x0;
                                    pcVar20 = (code *)0x0;
                                    iVar8 = 0x177;
                                    pcVar13 = (code *)0x0;
                                    pcVar12 = (code *)0x0;
                                    apcStack_68[0] = (code *)0x0;
                                    goto LAB_23e897350;
                                  }
                                  if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18))
                                  goto LAB_23e897720;
                                  plVar9 = (longlong *)0x0;
                                  plStack_d8 = (longlong *)0x0;
                                  pcVar12 = (code *)0x0;
                                  pcVar20 = (code *)0x0;
                                  iVar8 = 0x177;
                                  pcVar13 = (code *)0x0;
                                }
                                else {
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  uVar11 = DAT_23ed6cf28;
                                  pcVar20 = DAT_23ed6ccf0;
                                  *(longlong *)DAT_23ed6ccf0 = *(longlong *)DAT_23ed6ccf0 + 1;
                                  uVar11 = FUN_23a3a0d40(uVar11);
                                  *(undefined4 *)(plVar3 + 5) = 0x17d;
                                  plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11,_DAT_23eedcd30);
                                  if (plVar9 == (longlong *)0x0) {
                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                    auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                    auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                    plVar9 = (longlong *)0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_d8 = (longlong *)0x0;
                                    pcVar12 = (code *)0x0;
                                    uVar19 = 0x17d;
                                    pcStack_108 = _Py_NoneStruct_exref;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    pcVar13 = (code *)0x0;
                                    goto LAB_23e897e3e;
                                  }
                                  *plVar9 = *plVar9 + -1;
                                  if (*plVar9 == 0) {
                                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                                  }
                                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1);
                                  if (plVar9 != (longlong *)0x0) {
                                    *(undefined4 *)(plVar3 + 5) = 0x17e;
                                    pcVar13 = (code *)FUN_23e91bfe0(param_1,plVar9,DAT_23eedca10);
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      FUN_23a334bc0(plVar9);
                                    }
                                    pcVar15 = _Py_NoneStruct_exref;
                                    if (pcVar13 == (code *)0x0) goto LAB_23e897dfb;
                                    pcStack_108 = _Py_NoneStruct_exref;
                                    if (pcVar13 != _Py_NoneStruct_exref) {
                                      *(undefined4 *)(plVar3 + 5) = 0x184;
                                      pcVar12 = (code *)FUN_23e915840(param_1,plVar1,_DAT_23eedcd40)
                                      ;
                                      if (pcVar12 == (code *)0x0) {
                                        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        apcStack_68[0] = *(code **)(param_1 + 0x70);
                                        plVar9 = (longlong *)0x0;
                                        plStack_d8 = (longlong *)0x0;
                                        uVar19 = 0x184;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                      }
                                      else {
                                        iVar8 = FUN_23a35f020(pcVar12);
                                        if (iVar8 == -1) {
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          apcStack_68[0] = *(code **)(param_1 + 0x70);
                                          plVar9 = (longlong *)0x0;
                                          plStack_d8 = (longlong *)0x0;
                                          uVar19 = 0x186;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else if (iVar8 == 0) {
                                          uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                          *(undefined4 *)(plVar3 + 5) = 0x187;
                                          plVar9 = (longlong *)
                                                   FUN_23e94bb80(param_1,uVar11,_DAT_23eedcd48);
                                          if (plVar9 != (longlong *)0x0) {
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            lVar10 = *(longlong *)pcVar15 + 1;
                                            pcVar15 = pcVar13;
                                            goto LAB_23e8967ad;
                                          }
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          apcStack_68[0] = *(code **)(param_1 + 0x70);
                                          plVar9 = (longlong *)0x0;
                                          uVar19 = 0x187;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          plStack_d8 = (longlong *)0x0;
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        }
                                        else {
                                          uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                          plVar9 = _DAT_23eedcd50;
                                          plVar14 = (longlong *)
                                                    FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2)
                                          ;
                                          *plVar9 = *plVar9 + 1;
                                          plVar14[3] = (longlong)plVar9;
                                          plVar9 = (longlong *)FUN_23e8bd600(param_1,pcVar12);
                                          if (plVar9 == (longlong *)0x0) {
LAB_23e8990bf:
                                            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            apcStack_68[0] = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                          }
                                          else {
                                            lVar10 = FUN_23e94f9d0(param_1,plVar9,DAT_23ed6cd28);
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            if (lVar10 == 0) goto LAB_23e8990bf;
                                            plVar14[4] = lVar10;
                                            plVar9 = (longlong *)
                                                     (*pcStack_f0)(DAT_23ed6cd28,plVar14);
                                            *plVar14 = *plVar14 + -1;
                                            if (*plVar14 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            if (plVar9 == (longlong *)0x0) {
                                              auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                              auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                              apcStack_68[0] = *(code **)(param_1 + 0x70);
                                              plVar9 = (longlong *)0x0;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              uVar19 = 0x18a;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_d8 = (longlong *)0x0;
                                              goto LAB_23e897e3e;
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0x18a;
                                            plVar14 = (longlong *)
                                                      FUN_23e914090(param_1,uVar11,plVar9);
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0(plVar9);
                                            }
                                            if (plVar14 != (longlong *)0x0) {
                                              *plVar14 = *plVar14 + -1;
                                              if (*plVar14 == 0) {
                                                FUN_23a334bc0(plVar14);
                                              }
                                              uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                              *(undefined4 *)(plVar3 + 5) = 0x18b;
                                              plVar9 = (longlong *)FUN_23e94bb80(param_1,uVar11);
                                              if (plVar9 == (longlong *)0x0) {
                                                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                                apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                plVar9 = (longlong *)0x0;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                uVar19 = 0x18b;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                plStack_d8 = (longlong *)0x0;
                                              }
                                              else {
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0(plVar9);
                                                }
                                                *(undefined4 *)(plVar3 + 5) = 0x18e;
                                                auStack_98._8_8_ = DAT_23ed6ccf8;
                                                auStack_98._0_8_ = pcVar12;
                                                plVar9 = (longlong *)
                                                         FUN_23e94ed00(param_1,PyEnum_Type_exref,
                                                                       puStack_f8);
                                                if (plVar9 == (longlong *)0x0) {
                                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60)
                                                  ;
                                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68)
                                                  ;
                                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                  plVar9 = (longlong *)0x0;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uVar19 = 0x18e;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_d8 = (longlong *)0x0;
                                                }
                                                else {
                                                  plVar14 = (longlong *)FUN_23ebf7180(plVar9);
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  if (plVar14 == (longlong *)0x0) {
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    plVar9 = (longlong *)0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    uVar19 = 0x18e;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plStack_c0 = (longlong *)0x0;
                                                    plStack_d8 = (longlong *)0x0;
                                                    plVar9 = (longlong *)0x0;
                                                    do {
                                                      plVar16 = (longlong *)FUN_23a388450(plVar14);
                                                      if (plVar16 == (longlong *)0x0) {
                                                        cVar7 = FUN_23a3591a0(param_1,*(undefined8 *
                                                                                       )
                                                  PyExc_StopIteration_exref);
                                                  if (cVar7 == '\0') {
                                                    pcStack_e0 = *(code **)(param_1 + 0x70);
                                                    pcVar15 = *(code **)(param_1 + 0x60);
                                                    uVar11 = *(undefined8 *)(param_1 + 0x68);
                                                    uVar19 = 0x18e;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    apcStack_68[0] = (code *)0x0;
                                                    auStack_78 = (undefined1  [16])0x0;
                                                    if (plStack_c0 == (longlong *)0x0)
                                                    goto LAB_23e8992a0;
                                                    goto LAB_23e899280;
                                                  }
                                                  if ((plStack_c0 != (longlong *)0x0) &&
                                                     (*plStack_c0 = *plStack_c0 + -1,
                                                     *plStack_c0 == 0)) {
                                                    FUN_23a334bc0(plStack_c0);
                                                  }
                                                  lVar10 = *plVar14;
                                                  *plVar14 = lVar10 + -1;
                                                  if (lVar10 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  *(undefined4 *)(plVar3 + 5) = 0x198;
                                                  plVar14 = (longlong *)
                                                            FUN_23e94bb80(param_1,uVar11,
                                                                          _DAT_23eedcce0);
                                                  if (plVar14 == (longlong *)0x0) {
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    uVar19 = 0x198;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e897e3e;
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0(plVar14);
                                                  }
                                                  uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  *(undefined4 *)(plVar3 + 5) = 0x199;
                                                  plVar14 = (longlong *)
                                                            FUN_23e94bb80(param_1,uVar11,
                                                                          _DAT_23eedcd98);
                                                  if (plVar14 == (longlong *)0x0) {
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    uVar19 = 0x199;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e897e3e;
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0(plVar14);
                                                  }
                                                  uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  *(undefined4 *)(plVar3 + 5) = 0x19a;
                                                  plVar14 = (longlong *)
                                                            FUN_23e94bb80(param_1,uVar11);
                                                  if (plVar14 == (longlong *)0x0) {
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    uVar19 = 0x19a;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e897e3e;
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0(plVar14);
                                                  }
                                                  uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  plVar14 = _DAT_23eedcda0;
                                                  plVar16 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),4);
                                                  *plVar14 = *plVar14 + 1;
                                                  plVar16[3] = (longlong)plVar14;
                                                  if (pcVar20 == (code *)0x0) {
                                                    FUN_23e8ba2b0(auStack_78,_DAT_23eedcd78);
                                                    if (((code *)auStack_78._0_8_ != (code *)0x0) &&
                                                       ((code *)auStack_78._0_8_ != pcVar15)) {
                                                      FUN_23e91b1b0(param_1,auStack_78,
                                                                    auStack_78 + 8,apcStack_68);
                                                    }
                                                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),
                                                                  auStack_78._8_8_);
LAB_23e899e28:
                                                    lVar10 = *plVar16;
                                                    *plVar16 = lVar10 + -1;
                                                    if (lVar10 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                  }
                                                  else {
                                                    lVar10 = FUN_23e94f9d0(param_1,pcVar20,
                                                                           DAT_23ed6cd28);
                                                    if (lVar10 == 0) {
LAB_23e899e01:
                                                      apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                      auStack_78._0_8_ =
                                                           *(undefined8 *)(param_1 + 0x60);
                                                      auStack_78._8_8_ =
                                                           *(undefined8 *)(param_1 + 0x68);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e899e28;
                                                    }
                                                    plVar16[4] = lVar10;
                                                    plVar14 = _DAT_23eedcda8;
                                                    *_DAT_23eedcda8 = *_DAT_23eedcda8 + 1;
                                                    plVar16[5] = (longlong)plVar14;
                                                    plVar14 = (longlong *)
                                                              FUN_23e8bd600(param_1,pcVar12);
                                                    if (plVar14 == (longlong *)0x0)
                                                    goto LAB_23e899e01;
                                                    lVar10 = FUN_23e94f9d0(param_1,plVar14,
                                                                           DAT_23ed6cd28);
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (lVar10 == 0) goto LAB_23e899e01;
                                                    plVar16[6] = lVar10;
                                                    plVar14 = (longlong *)
                                                              (*pcStack_f0)(DAT_23ed6cd28);
                                                    lVar10 = *plVar16;
                                                    *plVar16 = lVar10 + -1;
                                                    if (lVar10 + -1 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar14 == (longlong *)0x0) {
                                                      auStack_78._0_8_ =
                                                           *(undefined8 *)(param_1 + 0x60);
                                                      auStack_78._8_8_ =
                                                           *(undefined8 *)(param_1 + 0x68);
                                                      apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      uVar19 = 0x19b;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e897e3e;
                                                    }
                                                    *(undefined4 *)(plVar3 + 5) = 0x19b;
                                                    plVar16 = (longlong *)
                                                              FUN_23e914090(param_1,uVar11);
                                                    *plVar14 = *plVar14 + -1;
                                                    if (*plVar14 == 0) {
                                                      FUN_23a334bc0(plVar14);
                                                    }
                                                    if (plVar16 != (longlong *)0x0) {
                                                      *plVar16 = *plVar16 + -1;
                                                      if (*plVar16 == 0) {
                                                        FUN_23a334bc0(plVar16);
                                                      }
                                                      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                      *(undefined4 *)(plVar3 + 5) = 0x19c;
                                                      plVar14 = (longlong *)
                                                                FUN_23e94bb80(param_1,uVar11,
                                                                              _DAT_23eedccf0);
                                                      if (plVar14 != (longlong *)0x0) {
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0(plVar14);
                                                        }
                                                        goto LAB_23e8983b2;
                                                      }
                                                      auStack_78._0_8_ =
                                                           *(undefined8 *)(param_1 + 0x60);
                                                      auStack_78._8_8_ =
                                                           *(undefined8 *)(param_1 + 0x68);
                                                      apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                      uVar19 = 0x19c;
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e897e3e;
                                                    }
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  uVar19 = 0x19b;
                                                  goto LAB_23e897e3e;
                                                  }
                                                  if ((plStack_c0 != (longlong *)0x0) &&
                                                     (*plStack_c0 = *plStack_c0 + -1,
                                                     *plStack_c0 == 0)) {
                                                    FUN_23a334bc0(plStack_c0);
                                                  }
                                                  plVar17 = (longlong *)FUN_23a388310(plVar16);
                                                  plStack_c0 = plVar16;
                                                  if (plVar17 == (longlong *)0x0) {
                                                    pcStack_e0 = *(code **)(param_1 + 0x70);
                                                    pcVar15 = *(code **)(param_1 + 0x60);
                                                    uVar11 = *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
LAB_23e8998f5:
                                                    uVar19 = 0x18e;
                                                    apcStack_68[0] = pcStack_e0;
                                                    plStack_e8 = plVar9;
                                                    auStack_78._0_8_ = pcVar15;
                                                    auStack_78._8_8_ = uVar11;
                                                    goto LAB_23e899241;
                                                  }
                                                  plVar16 = (longlong *)
                                                            FUN_23a3c1d30(param_1,auStack_78,plVar17
                                                                          ,0,2);
                                                  if (plVar16 == (longlong *)0x0) {
                                                    pcStack_e0 = apcStack_68[0];
                                                    plStack_e8 = (longlong *)0x0;
                                                    *plVar17 = *plVar17 + -1;
                                                    pcVar15 = (code *)auStack_78._0_8_;
                                                    uVar11 = auStack_78._8_8_;
                                                    if (*plVar17 != 0) goto LAB_23e8998f5;
LAB_23e899970:
                                                    auStack_78._8_8_ = 0;
                                                    auStack_78._0_8_ = 0;
                                                    apcStack_68[0] = (code *)0x0;
                                                    FUN_23a334bc0(plVar17);
                                                    apcStack_68[0] = (code *)0x0;
                                                    auStack_78._0_8_ = 0;
                                                    auStack_78._8_8_ = 0;
                                                    if (plVar16 != (longlong *)0x0) {
LAB_23e8998a3:
                                                      auStack_78._8_8_ = 0;
                                                      auStack_78._0_8_ = 0;
                                                      apcStack_68[0] = (code *)0x0;
                                                      lVar10 = *plVar16;
                                                      *plVar16 = lVar10 + -1;
                                                      if (lVar10 + -1 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                    }
                                                    if ((plStack_e8 != (longlong *)0x0) &&
                                                       (lVar10 = *plStack_e8,
                                                       *plStack_e8 = lVar10 + -1, lVar10 + -1 == 0))
                                                    {
                                                      FUN_23a334bc0();
                                                    }
                                                    goto LAB_23e8998f5;
                                                  }
                                                  plStack_e8 = (longlong *)
                                                               FUN_23a3c1d30(param_1,auStack_78,
                                                                             plVar17,1,2);
                                                  if (plStack_e8 == (longlong *)0x0) {
                                                    lVar10 = *plVar17;
LAB_23e899858:
                                                    pcStack_e0 = apcStack_68[0];
                                                    *plVar17 = lVar10 + -1;
                                                    pcVar15 = (code *)auStack_78._0_8_;
                                                    uVar11 = auStack_78._8_8_;
                                                    if (lVar10 + -1 == 0) goto LAB_23e899970;
                                                    goto LAB_23e8998a3;
                                                  }
                                                  cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar17,2
                                                                       );
                                                  lVar10 = *plVar17;
                                                  if (cVar7 == '\0') goto LAB_23e899858;
                                                  *plVar17 = lVar10 + -1;
                                                  if (lVar10 + -1 == 0) {
                                                    FUN_23a334bc0(plVar17);
                                                  }
                                                  *plVar16 = *plVar16 + 1;
                                                  if ((plStack_d8 != (longlong *)0x0) &&
                                                     (*plStack_d8 = *plStack_d8 + -1,
                                                     *plStack_d8 == 0)) {
                                                    FUN_23a334bc0(plStack_d8);
                                                  }
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  *plStack_e8 = *plStack_e8 + 1;
                                                  if ((plVar9 != (longlong *)0x0) &&
                                                     (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  *plStack_e8 = *plStack_e8 + -1;
                                                  if (*plStack_e8 == 0) {
                                                    FUN_23a334bc0(plStack_e8);
                                                  }
                                                  uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  plVar9 = _DAT_23eedcd58;
                                                  plVar17 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),5);
                                                  *plVar9 = *plVar9 + 1;
                                                  plVar17[3] = (longlong)plVar9;
                                                  lVar10 = FUN_23e94f9d0(param_1,plVar16);
                                                  plStack_d8 = plVar16;
                                                  if (lVar10 == 0) {
LAB_23e8997eb:
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar17 = *plVar17 + -1;
                                                    if (*plVar17 == 0) {
                                                      FUN_23a334bc0(plVar17);
                                                    }
LAB_23e8997e1:
                                                    uVar19 = 399;
                                                    goto LAB_23e899241;
                                                  }
                                                  plVar17[4] = lVar10;
                                                  plVar9 = DAT_23ed6cea0;
                                                  *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
                                                  plVar17[5] = (longlong)plVar9;
                                                  plVar9 = (longlong *)
                                                           FUN_23e8bd600(param_1,pcVar12);
                                                  if (plVar9 == (longlong *)0x0) goto LAB_23e8997eb;
                                                  lVar10 = FUN_23e94f9d0(param_1,plVar9);
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  if (lVar10 == 0) goto LAB_23e8997eb;
                                                  plVar17[6] = lVar10;
                                                  plVar9 = _DAT_23eedcd60;
                                                  *_DAT_23eedcd60 = *_DAT_23eedcd60 + 1;
                                                  plVar17[7] = (longlong)plVar9;
                                                  lVar10 = (*pcStack_f0)(DAT_23ed6cd28,plVar17);
                                                  *plVar17 = *plVar17 + -1;
                                                  if (*plVar17 == 0) {
                                                    FUN_23a334bc0(plVar17);
                                                  }
                                                  if (lVar10 == 0) {
LAB_23e8997a0:
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e8997e1;
                                                  }
                                                  plVar9 = (longlong *)
                                                           FUN_23e916ad0(*(undefined8 *)
                                                                          (param_1 + 0x10),1);
                                                  uVar5 = _DAT_23eedcd68;
                                                  plVar9[3] = lVar10;
                                                  plVar16 = (longlong *)FUN_23e8d7870(param_1,uVar5)
                                                  ;
                                                  *(undefined4 *)(plVar3 + 5) = 399;
                                                  plVar17 = (longlong *)
                                                            FUN_23a334c60(param_1,uVar11,plVar9,
                                                                          plVar16);
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  if (plVar17 == (longlong *)0x0)
                                                  goto LAB_23e8997a0;
                                                  *plVar17 = *plVar17 + -1;
                                                  if (*plVar17 == 0) {
                                                    FUN_23a334bc0(plVar17);
                                                  }
                                                  if (plVar1 == (longlong *)0x0) {
                                                    FUN_23e8ba2b0(auStack_78,DAT_23eedc830);
                                                    if (((code *)auStack_78._0_8_ != pcVar15) &&
                                                       ((code *)auStack_78._0_8_ != (code *)0x0)) {
                                                      FUN_23e91b1b0(param_1,auStack_78,
                                                                    auStack_78 + 8,apcStack_68);
                                                    }
                                                    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),
                                                                  auStack_78._8_8_);
LAB_23e8996d8:
                                                    uVar19 = 0x191;
                                                    goto LAB_23e899241;
                                                  }
                                                  *(undefined4 *)(plVar3 + 5) = 0x191;
                                                  plVar9 = (longlong *)FUN_23e915840(param_1,plVar1)
                                                  ;
                                                  if (plVar9 == (longlong *)0x0) {
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e8996d8;
                                                  }
                                                  iVar8 = FUN_23a35f020(plVar9);
                                                  lVar10 = *plVar9 + -1;
                                                  if (iVar8 == -1) {
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar9 = lVar10;
                                                    if (lVar10 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    goto LAB_23e8996d8;
                                                  }
                                                  *plVar9 = lVar10;
                                                  if (lVar10 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  if (iVar8 != 0) {
                                                    if (pcVar20 == (code *)0x0) {
                                                      FUN_23e8ba2b0(auStack_78,_DAT_23eedcd78);
                                                      if (((code *)auStack_78._0_8_ != pcVar15) &&
                                                         ((code *)auStack_78._0_8_ != (code *)0x0))
                                                      {
                                                        FUN_23e91b1b0(param_1,auStack_78,
                                                                      auStack_78 + 8,apcStack_68);
                                                      }
                                                      FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138)
                                                                    ,auStack_78._8_8_);
                                                    }
                                                    else {
                                                      auStack_98._0_8_ = pcVar20;
                                                      cVar7 = FUN_23e8c72f0(puStack_f8);
                                                      if (cVar7 != '\0') {
                                                        pcVar20 = (code *)auStack_98._0_8_;
                                                        uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                        plVar9 = _DAT_23eedcd80;
                                                        plVar16 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (param_1 + 0x10),4)
                                                        ;
                                                        *plVar9 = *plVar9 + 1;
                                                        plVar16[3] = (longlong)plVar9;
                                                        lVar10 = FUN_23e94f9d0(param_1,pcVar20);
                                                        if (lVar10 == 0) {
LAB_23e8992ea:
                                                          auStack_78._0_8_ =
                                                               *(undefined8 *)(param_1 + 0x60);
                                                          auStack_78._8_8_ =
                                                               *(undefined8 *)(param_1 + 0x68);
                                                          apcStack_68[0] =
                                                               *(code **)(param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar16 = *plVar16 + -1;
                                                          if (*plVar16 == 0) {
                                                            FUN_23a334bc0(plVar16);
                                                          }
                                                        }
                                                        else {
                                                          plVar16[4] = lVar10;
                                                          plVar9 = DAT_23ed6cea0;
                                                          *DAT_23ed6cea0 = *DAT_23ed6cea0 + 1;
                                                          plVar16[5] = (longlong)plVar9;
                                                          plVar9 = (longlong *)
                                                                   FUN_23e8bd600(param_1,pcVar12);
                                                          if (plVar9 == (longlong *)0x0)
                                                          goto LAB_23e8992ea;
                                                          lVar10 = FUN_23e94f9d0(param_1,plVar9);
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0(plVar9);
                                                          }
                                                          if (lVar10 == 0) goto LAB_23e8992ea;
                                                          plVar16[6] = lVar10;
                                                          plVar9 = (longlong *)
                                                                   (*pcStack_f0)(DAT_23ed6cd28,
                                                                                 plVar16);
                                                          *plVar16 = *plVar16 + -1;
                                                          if (*plVar16 == 0) {
                                                            FUN_23a334bc0(plVar16);
                                                          }
                                                          if (plVar9 != (longlong *)0x0) {
                                                            *(undefined4 *)(plVar3 + 5) = 0x193;
                                                            plVar16 = (longlong *)
                                                                      FUN_23e914090(param_1,uVar11);
                                                            *plVar9 = *plVar9 + -1;
                                                            if (*plVar9 == 0) {
                                                              FUN_23a334bc0(plVar9);
                                                            }
                                                            if (plVar16 != (longlong *)0x0) {
                                                              *plVar16 = *plVar16 + -1;
                                                              if (*plVar16 == 0) {
                                                                FUN_23a334bc0(plVar16);
                                                              }
                                                              lVar10 = FUN_23e8dbb80();
                                                              if (lVar10 == 0) {
                                                                FUN_23e915740(param_1,auStack_78);
                                                              }
                                                              else {
                                                                *(undefined4 *)(plVar3 + 5) = 0x194;
                                                                plVar9 = (longlong *)
                                                                         FUN_23e915840(param_1,
                                                  lVar10);
                                                  if (plVar9 != (longlong *)0x0) {
                                                    *plVar9 = *plVar9 + -1;
                                                    lVar10 = *plVar9;
                                                    goto joined_r0x00023e898ed6;
                                                  }
                                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60)
                                                  ;
                                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68)
                                                  ;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  uVar19 = 0x194;
                                                  goto LAB_23e899241;
                                                  }
                                                  }
                                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60)
                                                  ;
                                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68)
                                                  ;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  uVar19 = 0x193;
                                                  goto LAB_23e899241;
                                                  }
                                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60)
                                                  ;
                                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68)
                                                  ;
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  uVar19 = 0x192;
                                                  goto LAB_23e899241;
                                                  }
                                                  uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                  plVar9 = _DAT_23eedcd90;
                                                  plVar16 = (longlong *)
                                                            FUN_23e916ad0(*(undefined8 *)
                                                                           (param_1 + 0x10),2);
                                                  *plVar9 = *plVar9 + 1;
                                                  plVar16[3] = (longlong)plVar9;
                                                  plVar9 = (longlong *)
                                                           FUN_23a38cc10(param_1,plStack_e8);
                                                  if (plVar9 == (longlong *)0x0) {
LAB_23e899637:
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar16 = *plVar16 + -1;
                                                    if (*plVar16 == 0) {
                                                      FUN_23a334bc0(plVar16);
                                                    }
LAB_23e89962d:
                                                    uVar19 = 0x196;
                                                    goto LAB_23e899241;
                                                  }
                                                  lVar10 = FUN_23e94f9d0(param_1,plVar9);
                                                  *plVar9 = *plVar9 + -1;
                                                  if (*plVar9 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  if (lVar10 == 0) goto LAB_23e899637;
                                                  plVar16[4] = lVar10;
                                                  plVar17 = (longlong *)
                                                            (*pcStack_f0)(DAT_23ed6cd28,plVar16);
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  if (plVar17 == (longlong *)0x0) {
LAB_23e8995ed:
                                                    apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                    auStack_78._0_8_ =
                                                         *(undefined8 *)(param_1 + 0x60);
                                                    auStack_78._8_8_ =
                                                         *(undefined8 *)(param_1 + 0x68);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e89962d;
                                                  }
                                                  *(undefined4 *)(plVar3 + 5) = 0x196;
                                                  plVar9 = (longlong *)FUN_23e914090(param_1,uVar11)
                                                  ;
                                                  *plVar17 = *plVar17 + -1;
                                                  if (*plVar17 == 0) {
                                                    FUN_23a334bc0(plVar17);
                                                  }
                                                  if (plVar9 == (longlong *)0x0) goto LAB_23e8995ed;
                                                  *plVar9 = *plVar9 + -1;
                                                  lVar10 = *plVar9;
joined_r0x00023e898ed6:
                                                  if (lVar10 == 0) {
                                                    FUN_23a334bc0(plVar9);
                                                  }
                                                  cVar7 = FUN_23a3a5fe0(param_1);
                                                  plVar9 = plStack_e8;
                                                  } while (cVar7 != '\0');
                                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60)
                                                  ;
                                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uVar19 = 0x18e;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68)
                                                  ;
LAB_23e899241:
                                                  pcStack_e0 = apcStack_68[0];
                                                  plVar9 = plStack_e8;
                                                  pcVar15 = (code *)auStack_78._0_8_;
                                                  uVar11 = auStack_78._8_8_;
LAB_23e899280:
                                                  apcStack_68[0] = (code *)0x0;
                                                  auStack_78 = (undefined1  [16])0x0;
                                                  *plStack_c0 = *plStack_c0 + -1;
                                                  if (*plStack_c0 == 0) {
                                                    FUN_23a334bc0(plStack_c0);
                                                  }
LAB_23e8992a0:
                                                  lVar10 = *plVar14;
                                                  *plVar14 = lVar10 + -1;
                                                  if (lVar10 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  apcStack_68[0] = pcStack_e0;
                                                  auStack_78._0_8_ = pcVar15;
                                                  auStack_78._8_8_ = uVar11;
                                                  }
                                                }
                                              }
                                              goto LAB_23e897e3e;
                                            }
                                            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            apcStack_68[0] = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          uVar19 = 0x18a;
                                          plVar9 = (longlong *)0x0;
                                          plStack_d8 = (longlong *)0x0;
                                        }
                                      }
                                      goto LAB_23e897e3e;
                                    }
                                    uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x180;
                                    plVar9 = (longlong *)
                                             FUN_23e94bb80(param_1,uVar11,_DAT_23eedcd38);
                                    if (plVar9 == (longlong *)0x0) {
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      apcStack_68[0] = *(code **)(param_1 + 0x70);
                                      plVar9 = (longlong *)0x0;
                                      plStack_d8 = (longlong *)0x0;
                                      uVar19 = 0x180;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      pcVar12 = (code *)0x0;
                                      goto LAB_23e897e3e;
                                    }
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      FUN_23a334bc0(plVar9);
                                    }
                                    pcVar12 = (code *)0x0;
                                    lVar10 = *(longlong *)pcVar15 + 1;
LAB_23e8967ad:
                                    *(longlong *)pcStack_108 = lVar10;
                                    lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                    plVar9 = *(longlong **)(lVar10 + 0x28);
                                    plVar3 = (longlong *)plVar9[2];
                                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                         *(undefined8 *)(lVar10 + 0x30);
                                    *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                                    if (plVar3 != (longlong *)0x0) {
                                      plVar9[2] = 0;
                                      *plVar3 = *plVar3 + -1;
                                      if (*plVar3 == 0) {
                                        (**(code **)(plVar3[1] + 0x30))();
                                      }
                                    }
                                    *plVar9 = *plVar9 + -1;
                                    if (*plVar9 == 0) {
                                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                                    }
                                    plVar9[0xf] = 0;
                                    plVar9 = (longlong *)0x0;
                                    plStack_d8 = (longlong *)0x0;
                                    pcVar13 = pcVar15;
                                    if (pcVar20 == (code *)0x0) {
                                      if ((pcVar15 == (code *)0x0) ||
                                         (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1,
                                         *(longlong *)pcVar15 != 0)) {
                                        if ((pcVar12 != (code *)0x0) &&
                                           (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1,
                                           *(longlong *)pcVar12 == 0)) {
                                          (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
                                        }
                                        goto LAB_23e89685c;
                                      }
LAB_23e8972b0:
                                      (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                                    }
                                    else {
LAB_23e896815:
                                      *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
                                      if (*(longlong *)pcVar20 == 0) {
                                        (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
                                      }
                                      if ((pcVar13 != (code *)0x0) &&
                                         (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1,
                                         pcVar15 = pcVar13, *(longlong *)pcVar13 == 0))
                                      goto LAB_23e8972b0;
                                    }
                                    if ((pcVar12 != (code *)0x0) &&
                                       (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1,
                                       *(longlong *)pcVar12 == 0)) {
                                      (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
                                    }
                                    if ((plStack_d8 != (longlong *)0x0) &&
                                       (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
                                      (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                                    }
                                    if ((plVar9 != (longlong *)0x0) &&
                                       (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                                    }
LAB_23e89685c:
                                    *plVar1 = *plVar1 + -1;
                                    if (*plVar1 != 0) {
                                      return pcStack_108;
                                    }
                                    (**(code **)(plVar1[1] + 0x30))(plVar1);
                                    return pcStack_108;
                                  }
LAB_23e897dfb:
                                  apcStack_68[0] = *(code **)(param_1 + 0x70);
                                  auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                  auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                  plVar9 = (longlong *)0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  plStack_d8 = (longlong *)0x0;
                                  uVar19 = 0x17e;
                                  pcVar12 = (code *)0x0;
                                  pcVar13 = (code *)0x0;
                                  pcStack_108 = _Py_NoneStruct_exref;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e897e3e:
                                  pcVar15 = apcStack_68[0];
                                  auStack_98._8_8_ = auStack_78._8_8_;
                                  auStack_98._0_8_ = auStack_78._0_8_;
                                  apcStack_68[0] = (code *)0x0;
                                  auStack_78._0_8_ = (code *)0x0;
                                  auStack_78._8_8_ = 0;
                                  apcStack_88[0] = pcVar15;
                                  plVar14 = *(longlong **)(param_1 + 0x138);
                                  if (plVar14 != (longlong *)0x0) {
                                    *plVar14 = *plVar14 + 1;
                                  }
                                  pcVar18 = DAT_23ed6a4f8;
                                  if (pcVar15 == (code *)0x0) {
                                    pcVar18 = (code *)FUN_23e8d6280(plVar3);
                                    if ((apcStack_88[0] != (code *)0x0) &&
                                       (*(longlong *)apcStack_88[0] =
                                             *(longlong *)apcStack_88[0] + -1,
                                       *(longlong *)apcStack_88[0] == 0)) {
                                      FUN_23a334bc0();
                                    }
                                  }
                                  else {
                                    if (DAT_23ed6a4f8 == (code *)0x0) {
                                      pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                    }
                                    else {
                                      pcVar6 = *(code **)DAT_23ed6a4f8;
                                      *(longlong *)DAT_23ed6a4f8 = 1;
                                      DAT_23ed6a4f8 = pcVar6;
                                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                    }
                                    *(longlong **)(pcVar18 + 0x18) = plVar3;
                                    *plVar3 = *plVar3 + 1;
                                    *(undefined4 *)(pcVar18 + 0x24) = uVar19;
                                    lVar10 = *(longlong *)(pcStack_100 + 0x1f8);
                                    *(undefined4 *)(pcVar18 + 0x20) = 0xffffffff;
                                    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
                                    puVar4 = *(undefined8 **)(lVar10 + 8);
                                    *puVar4 = pcVar18 + -0x10;
                                    *(longlong *)(pcVar18 + -0x10) = lVar10;
                                    *(ulonglong *)(pcVar18 + -8) =
                                         (ulonglong)puVar4 |
                                         (ulonglong)((uint)*(longlong *)(pcVar18 + -8) & 3);
                                    *(code **)(lVar10 + 8) = pcVar18 + -0x10;
                                    *(code **)(pcVar18 + 0x10) = pcVar15;
                                    *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                                    if ((apcStack_88[0] != (code *)0x0) &&
                                       (*(longlong *)apcStack_88[0] =
                                             *(longlong *)apcStack_88[0] + -1,
                                       *(longlong *)apcStack_88[0] == 0)) {
                                      FUN_23a334bc0(apcStack_88[0]);
                                    }
                                  }
                                  apcStack_88[0] = pcVar18;
                                  if (((code *)auStack_98._0_8_ != (code *)0x0) &&
                                     ((code *)auStack_98._0_8_ != pcStack_108)) {
                                    FUN_23e91b1b0(param_1,puStack_f8,auStack_98 + 8,apcStack_88);
                                  }
                                  plVar16 = *(longlong **)(auStack_98._8_8_ + 0x28);
                                  if (apcStack_88[0] == pcStack_108) {
                                    pcVar15 = (code *)0x0;
                                  }
                                  else {
                                    pcVar15 = apcStack_88[0];
                                    if (apcStack_88[0] != (code *)0x0) {
                                      *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
                                    }
                                  }
                                  *(code **)(auStack_98._8_8_ + 0x28) = pcVar15;
                                  if ((plVar16 != (longlong *)0x0) &&
                                     (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                    (**(code **)(plVar16[1] + 0x30))();
                                  }
                                  plVar16 = *(longlong **)(param_1 + 0x138);
                                  *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
                                  if ((plVar16 != (longlong *)0x0) &&
                                     (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                    (**(code **)(plVar16[1] + 0x30))();
                                  }
                                  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1
                                  ;
                                  if (*(longlong *)auStack_98._0_8_ == 0) {
                                    (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
                                  }
                                  if ((apcStack_88[0] != (code *)0x0) &&
                                     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1
                                     , *(longlong *)apcStack_88[0] == 0)) {
                                    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
                                  }
                                  apcStack_88[0] = (code *)0x0;
                                  auStack_98 = (undefined1  [16])0x0;
                                  iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                                 (*(longlong *)(param_1 + 0x138) + 8
                                                                 ),
                                                        *(undefined8 *)PyExc_KeyboardInterrupt_exref
                                                       );
                                  if (iVar8 == 0) {
                                    cVar7 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),
                                                          auStack_78);
                                    iVar8 = 0;
                                    if (cVar7 == '\0') {
                                      iVar8 = 0x17b;
                                    }
                                    if ((apcStack_68[0] != (code *)0x0) &&
                                       (*(longlong **)(apcStack_68[0] + 0x18) == plVar3)) {
                                      *(undefined4 *)(plVar3 + 5) =
                                           *(undefined4 *)(apcStack_68[0] + 0x24);
                                    }
                                  }
                                  else {
                                    uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                    *(undefined4 *)(plVar3 + 5) = 0x19f;
                                    plVar16 = (longlong *)
                                              FUN_23e94bb80(param_1,uVar11,_DAT_23eedcdb0);
                                    if (plVar16 == (longlong *)0x0) {
                                      apcStack_68[0] = *(code **)(param_1 + 0x70);
                                      auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                      auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                      iVar8 = 0x19f;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                    }
                                    else {
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        FUN_23a334bc0(plVar16);
                                      }
                                      uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                      *(undefined4 *)(plVar3 + 5) = 0x1a0;
                                      plVar16 = (longlong *)
                                                FUN_23e94bb80(param_1,uVar11,_DAT_23eedcdb8);
                                      if (plVar16 == (longlong *)0x0) {
                                        auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                        auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                        apcStack_68[0] = *(code **)(param_1 + 0x70);
                                        iVar8 = 0x1a0;
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                      }
                                      else {
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          FUN_23a334bc0(plVar16);
                                        }
                                        uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                        *(undefined4 *)(plVar3 + 5) = 0x1a1;
                                        plVar16 = (longlong *)
                                                  FUN_23e94bb80(param_1,uVar11,_DAT_23eedccf0);
                                        if (plVar16 == (longlong *)0x0) {
                                          auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                          auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                          apcStack_68[0] = *(code **)(param_1 + 0x70);
                                          iVar8 = 0x1a1;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            FUN_23a334bc0(plVar16);
                                          }
                                          puStack_f8 = (undefined1 *)FUN_23a3a0d40(DAT_23ed6cf28);
                                          plVar17 = _DAT_23eedcdc0;
                                          lVar10 = *(longlong *)(param_1 + 0x10);
                                          plVar16 = *(longlong **)(lVar10 + 0xe20);
                                          if (plVar16 == (longlong *)0x0) {
                                            plVar16 = (longlong *)
                                                      FUN_23e916a20(PyTuple_Type_exref,2);
                                          }
                                          else {
                                            lVar2 = plVar16[3];
                                            *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1
                                            ;
                                            *(longlong *)(lVar10 + 0xe20) = lVar2;
                                            *plVar16 = 1;
                                          }
                                          plVar16[4] = 0;
                                          lVar10 = *(longlong *)
                                                    (*(longlong *)
                                                      (*(longlong *)(pcStack_100 + 0x1f8) + 0x10) +
                                                    0x2e8);
                                          lVar2 = plVar16[-1];
                                          puVar4 = *(undefined8 **)(lVar10 + 8);
                                          *puVar4 = plVar16 + -2;
                                          plVar16[-2] = lVar10;
                                          plVar16[-1] = (ulonglong)((uint)lVar2 & 3) |
                                                        (ulonglong)puVar4;
                                          *(longlong **)(lVar10 + 8) = plVar16 + -2;
                                          *plVar17 = *plVar17 + 1;
                                          plVar16[3] = (longlong)plVar17;
                                          uVar11 = DAT_23ed6cd28;
                                          if (pcVar20 == (code *)0x0) {
                                            FUN_23e8ba2b0(auStack_78,_DAT_23eedcd78);
                                            if (((code *)auStack_78._0_8_ != pcStack_108) &&
                                               ((code *)auStack_78._0_8_ != (code *)0x0)) {
                                              FUN_23e91b1b0(param_1,auStack_78,auStack_78 + 8,
                                                            apcStack_68);
                                            }
                                            FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),
                                                          auStack_78._8_8_);
LAB_23e8986fd:
                                            *plVar16 = *plVar16 + -1;
                                            if (*plVar16 == 0) {
                                              FUN_23a334bc0(plVar16);
                                            }
                                          }
                                          else {
                                            if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                              plVar17 = (longlong *)
                                                        PyDict_GetItemString(DAT_23ed6ccc0,"format")
                                              ;
                                              if (plVar17 == (longlong *)0x0) goto LAB_23e897be2;
                                              *plVar17 = *plVar17 + 1;
                                              DAT_23ed6a4c0 = plVar17;
                                            }
                                            uStack_a0 = uVar11;
                                            pcStack_a8 = pcVar20;
                                            lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_a8
                                                                  );
                                            if (lVar10 == 0) {
                                              apcStack_68[0] = *(code **)(param_1 + 0x70);
                                              auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                              auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e8986fd;
                                            }
                                            plVar16[4] = lVar10;
                                            plVar17 = (longlong *)
                                                      (*pcStack_f0)(DAT_23ed6cd28,plVar16);
                                            *plVar16 = *plVar16 + -1;
                                            if (*plVar16 == 0) {
                                              FUN_23a334bc0(plVar16);
                                            }
                                            if (plVar17 != (longlong *)0x0) {
                                              *(undefined4 *)(plVar3 + 5) = 0x1a2;
                                              plVar16 = (longlong *)
                                                        FUN_23e914090(param_1,puStack_f8);
                                              *plVar17 = *plVar17 + -1;
                                              if (*plVar17 == 0) {
                                                FUN_23a334bc0(plVar17);
                                              }
                                              if (plVar16 != (longlong *)0x0) {
                                                *plVar16 = *plVar16 + -1;
                                                if (*plVar16 == 0) {
                                                  FUN_23a334bc0(plVar16);
                                                }
                                                uVar11 = FUN_23a3a0d40(DAT_23ed6cf28);
                                                *(undefined4 *)(plVar3 + 5) = 0x1a3;
                                                plVar16 = (longlong *)
                                                          FUN_23e94bb80(param_1,uVar11,
                                                                        _DAT_23eedccf0);
                                                if (plVar16 != (longlong *)0x0) {
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    FUN_23a334bc0(plVar16);
                                                  }
                                                  FUN_23ebf6ae0(param_1,plVar14);
LAB_23e8983b2:
                                                  FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                                  *(longlong *)pcStack_108 =
                                                       *(longlong *)pcStack_108 + 1;
                                                  goto LAB_23e896815;
                                                }
                                                auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                                apcStack_68[0] = *(code **)(param_1 + 0x70);
                                                iVar8 = 0x1a3;
                                                *(undefined8 *)(param_1 + 0x70) = 0;
                                                *(undefined1 (*) [16])(param_1 + 0x60) =
                                                     (undefined1  [16])0x0;
                                                goto LAB_23e8984b6;
                                              }
                                            }
                                            auStack_78._0_8_ = *(undefined8 *)(param_1 + 0x60);
                                            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                                            apcStack_68[0] = *(code **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          iVar8 = 0x1a2;
                                        }
                                      }
                                    }
                                  }
LAB_23e8984b6:
                                  pcVar15 = apcStack_68[0];
                                  uVar5 = auStack_78._8_8_;
                                  uVar11 = auStack_78._0_8_;
                                  plVar16 = *(longlong **)(param_1 + 0x138);
                                  auStack_78 = (undefined1  [16])0x0;
                                  apcStack_68[0] = (code *)0x0;
                                  *(longlong **)(param_1 + 0x138) = plVar14;
                                  if ((plVar16 != (longlong *)0x0) &&
                                     (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                    (**(code **)(plVar16[1] + 0x30))();
                                  }
                                  auStack_78 = CONCAT88(uVar5,uVar11);
                                  apcStack_68[0] = pcVar15;
                                  if (pcVar15 == (code *)0x0) {
                                    if (iVar8 == 0) {
                                      iVar8 = (int)plVar3[5];
                                    }
                                    goto LAB_23e897350;
                                  }
                                  if (*(longlong **)(pcVar15 + 0x18) == plVar3) goto LAB_23e897523;
                                  if (iVar8 == 0) {
                                    iVar8 = (int)plVar3[5];
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                    goto LAB_23e89746a;
                  }
                }
              }
LAB_23e897990:
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              apcStack_68[0] = *(code **)(param_1 + 0x70);
              iVar8 = 0x174;
            }
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))();
            }
            if (apcStack_68[0] == (code *)0x0) {
              plVar9 = (longlong *)0x0;
              plStack_d8 = (longlong *)0x0;
              pcVar12 = (code *)0x0;
              pcVar13 = (code *)0x0;
              pcVar20 = (code *)0x0;
              apcStack_68[0] = (code *)0x0;
              goto LAB_23e897350;
            }
            if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
            plVar9 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            pcVar12 = (code *)0x0;
            pcVar13 = (code *)0x0;
            pcVar20 = (code *)0x0;
            goto LAB_23e89746a;
          }
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          apcStack_68[0] = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (apcStack_68[0] != (code *)0x0) {
            if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
            plVar9 = (longlong *)0x0;
            plStack_d8 = (longlong *)0x0;
            pcVar12 = (code *)0x0;
            pcVar20 = (code *)0x0;
            iVar8 = 0x172;
            pcVar13 = (code *)0x0;
            goto LAB_23e89746a;
          }
        }
LAB_23e897873:
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        pcVar12 = (code *)0x0;
        pcVar13 = (code *)0x0;
        pcVar20 = (code *)0x0;
        iVar8 = 0x172;
        goto LAB_23e897350;
      }
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      apcStack_68[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_68[0] == (code *)0x0) {
        pcStack_100 = _PyRuntime_exref;
        plVar9 = (longlong *)0x0;
        plStack_d8 = (longlong *)0x0;
        pcVar12 = (code *)0x0;
        pcVar20 = (code *)0x0;
        iVar8 = 0x171;
        pcVar13 = (code *)0x0;
        apcStack_68[0] = (code *)0x0;
        goto LAB_23e897350;
      }
      if (plVar3 == *(longlong **)(apcStack_68[0] + 0x18)) goto LAB_23e897720;
      pcStack_100 = _PyRuntime_exref;
      plVar9 = (longlong *)0x0;
      plStack_d8 = (longlong *)0x0;
      pcVar12 = (code *)0x0;
      pcVar20 = (code *)0x0;
      iVar8 = 0x171;
      pcVar13 = (code *)0x0;
    }
LAB_23e89746a:
    pcVar18 = apcStack_68[0];
    pcVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar6 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar6;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar15 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar10 = *(longlong *)(pcStack_100 + 0x1f8);
    *(int *)(pcVar15 + 0x24) = iVar8;
    *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
    lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
    lVar2 = *(longlong *)(pcVar15 + -8);
    puVar4 = *(undefined8 **)(lVar10 + 8);
    *puVar4 = pcVar15 + -0x10;
    *(longlong *)(pcVar15 + -0x10) = lVar10;
    *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(code **)(lVar10 + 8) = pcVar15 + -0x10;
    *(code **)(pcVar15 + 0x10) = pcVar18;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
    if ((apcStack_68[0] != (code *)0x0) &&
       (*(longlong *)apcStack_68[0] = *(longlong *)apcStack_68[0] + -1,
       *(longlong *)apcStack_68[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_68[0] + 8) + 0x30))();
    }
  }
LAB_23e897523:
  apcStack_68[0] = pcVar15;
  FUN_23e8bba40(plVar3,"oooooo",plVar1,pcVar20,pcVar13,pcVar12,plStack_d8,plVar9);
  if (_DAT_23eede5f8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede5f8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar14 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar14 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar15 = apcStack_68[0];
  plVar3[0xf] = 0;
  uVar11 = auStack_78._0_8_;
  uVar5 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  apcStack_68[0] = (code *)0x0;
  if ((pcVar20 != (code *)0x0) &&
     (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
  if ((pcVar12 != (code *)0x0) &&
     (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
    (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
  }
  if ((plStack_d8 != (longlong *)0x0) && (*plStack_d8 = *plStack_d8 + -1, *plStack_d8 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  *plVar1 = *plVar1 + -1;
  apcStack_68[0] = pcVar15;
  auStack_78._0_8_ = uVar11;
  auStack_78._8_8_ = uVar5;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,apcStack_68[0]);
  return (code *)0x0;
}
