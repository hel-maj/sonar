/* ===== 23c61f120 license.hwid_generator:116 ===== */
/* ghidra_name=FUN_23c61f120 entry=23c61f120 size=9854 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

longlong * FUN_23c61f120(longlong param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  code *pcVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  longlong lVar7;
  code *pcVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  code *pcVar14;
  code *pcVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  undefined4 uVar19;
  code *pcVar20;
  code *pcStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  code *pcStack_d8;
  code *pcStack_c8;
  code *pcStack_c0;
  code *pcStack_a8;
  code *pcStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  code *pcStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar6 = _DAT_23ee29d68;
  if (_DAT_23ee29d68 == (longlong *)0x0) {
LAB_23c61f162:
    _DAT_23ee29d68 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29d60,_DAT_23ee29d98,0x38);
  }
  else {
    lVar7 = *_DAT_23ee29d68;
    if (1 < lVar7) {
      *_DAT_23ee29d68 = lVar7 + -1;
      goto LAB_23c61f162;
    }
    if (_DAT_23ee29d68[2] != 0) {
      *_DAT_23ee29d68 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      goto LAB_23c61f162;
    }
  }
  plVar18 = _DAT_23ee29d68;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar6 = _DAT_23ee29d68 + 9;
  lVar5 = *(longlong *)(lVar7 + 8);
  _DAT_23ee29d68[0xf] = lVar5;
  *(longlong **)(lVar7 + 8) = plVar6;
  if ((lVar5 != 0) &&
     (((*(char *)(lVar5 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar5 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar5 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar5 + 0x38))
       ) && (plVar18[0xe] != 0)))) {
    plVar6 = *(longlong **)(lVar5 + 0x28);
    *(longlong **)(plVar18[0xe] + 0x10) = plVar6;
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + 1;
    }
  }
  *plVar18 = *plVar18 + 1;
  *(undefined4 *)(plVar18 + 8) = 0;
  lVar5 = FUN_23ead6850();
  lVar7 = _DAT_23ee28e30;
  if (lVar5 == 0) {
    FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
    pcStack_c8 = pcStack_78;
    pcVar17 = pcStack_68;
    pcStack_c0 = pcStack_70;
  }
  else {
    *(undefined4 *)(plVar18 + 5) = 0x7c;
    plVar6 = (longlong *)FUN_23e915840(param_1,lVar5,_DAT_23ee28e28,*(undefined8 *)(lVar7 + 0x18));
    if (plVar6 != (longlong *)0x0) {
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      lVar7 = FUN_23ead6330();
      if (lVar7 == 0) {
        FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28e38);
        pcVar8 = (code *)0x0;
        pcVar17 = pcStack_68;
        pcVar15 = pcStack_78;
        pcVar20 = pcStack_70;
      }
      else {
        *(undefined4 *)(plVar18 + 5) = 0x7f;
        pcVar8 = (code *)FUN_23e91a870(param_1,lVar7);
        if (pcVar8 != (code *)0x0) {
          lVar7 = FUN_23ead61e0();
          if (lVar7 == 0) {
            FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28e40);
            pcStack_f0 = (code *)0x0;
            pcVar17 = pcStack_68;
            pcVar15 = pcStack_78;
            pcVar20 = pcStack_70;
          }
          else {
            *(undefined4 *)(plVar18 + 5) = 0x80;
            pcStack_f0 = (code *)FUN_23e91a870(param_1,lVar7);
            if (pcStack_f0 != (code *)0x0) {
              lVar7 = FUN_23ead6850();
              if (lVar7 == 0) {
                uVar19 = 0x82;
                FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
                plStack_e0 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
                pcStack_d8 = _PyRuntime_exref;
                plVar6 = (longlong *)0x0;
                pcVar17 = pcStack_68;
                pcVar15 = pcStack_78;
                pcVar20 = pcStack_70;
                goto LAB_23c61fa28;
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28e48);
              plVar6 = _DAT_23ee28e50;
              if (plVar9 == (longlong *)0x0) {
                pcVar15 = *(code **)(param_1 + 0x60);
                pcVar17 = *(code **)(param_1 + 0x70);
                plVar6 = (longlong *)0x0;
                pcStack_d8 = _PyRuntime_exref;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar19 = 0x82;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plStack_e0 = (longlong *)0x0;
                plStack_e8 = (longlong *)0x0;
                pcVar20 = *(code **)(param_1 + 0x68);
                goto LAB_23c61fa28;
              }
              lVar7 = *(longlong *)(param_1 + 0x10);
              plVar10 = *(longlong **)(lVar7 + 0xe20);
              if (plVar10 == (longlong *)0x0) {
                plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar5 = plVar10[3];
                *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                *(longlong *)(lVar7 + 0xe20) = lVar5;
                *plVar10 = 1;
              }
              pcStack_d8 = _PyRuntime_exref;
              plVar10[4] = 0;
              lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8)
              ;
              lVar5 = plVar10[-1];
              puVar1 = *(undefined8 **)(lVar7 + 8);
              *puVar1 = plVar10 + -2;
              plVar10[-2] = lVar7;
              plVar10[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar1;
              *(longlong **)(lVar7 + 8) = plVar10 + -2;
              plVar11 = DAT_23ed6a4c0;
              *plVar6 = *plVar6 + 1;
              plVar10[3] = (longlong)plVar6;
              pcVar20 = DAT_23ed6cd28;
              if (plVar11 == (longlong *)0x0) {
                plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                pcVar15 = pcVar8;
                if (plVar11 == (longlong *)0x0) goto LAB_23c621156;
                *plVar11 = *plVar11 + 1;
                DAT_23ed6a4c0 = plVar11;
              }
              pcStack_70 = pcVar20;
              pcStack_78 = pcVar8;
              lVar7 = FUN_23e94ed00(param_1,plVar11,&pcStack_78);
              if (lVar7 == 0) {
                pcVar15 = *(code **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x68);
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                lVar7 = *plVar9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar9 = lVar7 + -1;
                if (lVar7 + -1 == 0) {
                  (**(code **)(plVar9[1] + 0x30))();
                }
                *plVar10 = *plVar10 + -1;
                plVar6 = (longlong *)0x0;
                if (*plVar10 == 0) {
                  uVar19 = 0x82;
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                  plStack_e0 = (longlong *)0x0;
                  plStack_e8 = (longlong *)0x0;
                  goto LAB_23c61fa28;
                }
              }
              else {
                plVar10[4] = lVar7;
                plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar6 != (longlong *)0x0) {
                  *(undefined4 *)(plVar18 + 5) = 0x82;
                  plVar10 = (longlong *)FUN_23e914090(param_1,plVar9,plVar6);
                  lVar7 = *plVar9;
                  *plVar9 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *plVar6 = *plVar6 + -1;
                  if (*plVar6 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  if (plVar10 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    plVar6 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0x82;
                    plStack_e8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_e0 = (longlong *)0x0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                    goto LAB_23c61fa28;
                  }
                  lVar7 = *plVar10;
                  *plVar10 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar7 = FUN_23ead6850();
                  if (lVar7 == 0) {
                    uVar19 = 0x83;
                    FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
                    plStack_e0 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    plVar6 = (longlong *)0x0;
                    pcVar17 = pcStack_68;
                    pcVar15 = pcStack_78;
                    pcVar20 = pcStack_70;
                    goto LAB_23c61fa28;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28e48);
                  plVar6 = _DAT_23ee28e58;
                  if (plVar9 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    plVar6 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0x83;
                    plStack_e0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_e8 = (longlong *)0x0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                    goto LAB_23c61fa28;
                  }
                  lVar7 = *(longlong *)(param_1 + 0x10);
                  plVar10 = *(longlong **)(lVar7 + 0xe20);
                  if (plVar10 == (longlong *)0x0) {
                    plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  }
                  else {
                    lVar5 = plVar10[3];
                    *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
                    *(longlong *)(lVar7 + 0xe20) = lVar5;
                    *plVar10 = 1;
                  }
                  plVar10[4] = 0;
                  lVar7 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
                  lVar5 = plVar10[-1];
                  puVar1 = *(undefined8 **)(lVar7 + 8);
                  *puVar1 = plVar10 + -2;
                  plVar10[-2] = lVar7;
                  plVar10[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar1;
                  *(longlong **)(lVar7 + 8) = plVar10 + -2;
                  plVar11 = DAT_23ed6a4c0;
                  *plVar6 = *plVar6 + 1;
                  plVar10[3] = (longlong)plVar6;
                  pcVar20 = DAT_23ed6cd28;
                  if (plVar11 == (longlong *)0x0) {
                    plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    pcVar15 = pcStack_f0;
                    if (plVar11 == (longlong *)0x0) goto LAB_23c621156;
                    *plVar11 = *plVar11 + 1;
                    DAT_23ed6a4c0 = plVar11;
                  }
                  pcStack_70 = pcVar20;
                  pcStack_78 = pcStack_f0;
                  lVar7 = FUN_23e94ed00(param_1,plVar11,&pcStack_78);
                  if (lVar7 == 0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x68);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    lVar7 = *plVar9;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar9 = lVar7 + -1;
                    if (lVar7 + -1 == 0) {
                      (**(code **)(plVar9[1] + 0x30))();
                    }
                    *plVar10 = *plVar10 + -1;
                    plVar6 = (longlong *)0x0;
                    if (*plVar10 != 0) goto LAB_23c621169;
                    uVar19 = 0x83;
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                    plStack_e0 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    goto LAB_23c61fa28;
                  }
                  plVar10[4] = lVar7;
                  plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (plVar11 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x68);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    lVar7 = *plVar9;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar9 = lVar7 + -1;
                    plVar6 = (longlong *)0x0;
                    if (lVar7 + -1 != 0) goto LAB_23c621169;
                    uVar19 = 0x83;
                    (**(code **)(plVar9[1] + 0x30))();
                    plStack_e0 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    goto LAB_23c61fa28;
                  }
                  *(undefined4 *)(plVar18 + 5) = 0x83;
                  plVar6 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
                  lVar7 = *plVar9;
                  *plVar9 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar6 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    plVar6 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0x83;
                    plStack_e8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plStack_e0 = (longlong *)0x0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                    goto LAB_23c61fa28;
                  }
                  lVar7 = *plVar6;
                  *plVar6 = lVar7 + -1;
                  if (lVar7 + -1 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  iVar4 = FUN_23e913250(pcVar8,_DAT_23ee28cd0);
                  if (iVar4 == -1) {
LAB_23c621270:
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    plVar6 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0x85;
                    plStack_e0 = (longlong *)0x0;
                    plStack_e8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                    goto LAB_23c61fa28;
                  }
                  if (iVar4 == 1) {
                    iVar4 = FUN_23e913250(pcStack_f0,_DAT_23ee28db8);
                    if (iVar4 == -1) goto LAB_23c621270;
                    if (iVar4 != 1) goto LAB_23c61f5f3;
                    lVar7 = *(longlong *)(DAT_23ee28c48 + 0x20);
                    if (*(char *)(lVar7 + 10) == '\0') {
                      plVar6 = (longlong *)FUN_23a37a020(DAT_23ee28c48,_DAT_23ee28e60);
                      if (plVar6 == (longlong *)0x0) goto LAB_23c6216af;
                      lVar7 = *plVar6;
LAB_23c6216a6:
                      if (lVar7 == 0) goto LAB_23c6216af;
                    }
                    else {
                      iVar4 = *(int *)(lVar7 + 0xc);
                      if (*(int *)(lVar7 + 0xc) == 0) {
                        *(int *)(lVar7 + 0xc) = DAT_23ec12b10;
                        iVar4 = DAT_23ec12b10;
                        DAT_23ec12b10 = DAT_23ec12b10 + 1;
                      }
                      if (_DAT_23ec12b14 != iVar4) {
                        _DAT_23ec12b14 = iVar4;
                        _DAT_23ee29d58 =
                             FUN_23e8cbd60(lVar7,_DAT_23ee28e60,
                                           *(undefined8 *)(_DAT_23ee28e60 + 0x18));
                      }
                      if (-1 < _DAT_23ee29d58) {
                        lVar5 = lVar7 + 0x20 + (1L << (*(byte *)(lVar7 + 9) & 0x3f));
                        if (*(longlong *)(lVar5 + 8 + _DAT_23ee29d58 * 0x10) != 0)
                        goto LAB_23c621407;
                        _DAT_23ee29d58 =
                             FUN_23e8cbd60(lVar7,_DAT_23ee28e60,
                                           *(undefined8 *)(_DAT_23ee28e60 + 0x18));
                        if (-1 < _DAT_23ee29d58) {
                          lVar7 = *(longlong *)(lVar5 + 8 + _DAT_23ee29d58 * 0x10);
                          goto LAB_23c6216a6;
                        }
                      }
LAB_23c6216af:
                      plVar6 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23ee28e60);
                      if ((plVar6 == (longlong *)0x0) || (*plVar6 == 0)) {
                        plVar6 = (longlong *)0x0;
                        uVar19 = 0x86;
                        FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28e60);
                        plStack_e0 = (longlong *)0x0;
                        plStack_e8 = (longlong *)0x0;
                        pcVar17 = pcStack_68;
                        pcVar15 = pcStack_78;
                        pcVar20 = pcStack_70;
                        goto LAB_23c61fa28;
                      }
                    }
LAB_23c621407:
                    *(undefined4 *)(plVar18 + 5) = 0x86;
                    plVar6 = (longlong *)FUN_23e91a870(param_1);
                    plVar9 = _DAT_23ee28e68;
                    if (plVar6 == (longlong *)0x0) {
                      pcVar15 = *(code **)(param_1 + 0x60);
                      pcVar17 = *(code **)(param_1 + 0x70);
                      plStack_e0 = (longlong *)0x0;
                      uVar19 = 0x86;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_e8 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar20 = *(code **)(param_1 + 0x68);
                      goto LAB_23c61fa28;
                    }
                    plVar10 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                    *plVar9 = *plVar9 + 1;
                    plVar10[3] = (longlong)plVar9;
                    lVar7 = FUN_23e94f9d0(param_1,plVar6,DAT_23ed6cd28);
                    if (lVar7 == 0) {
                      pcVar15 = *(code **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x68);
                      pcVar17 = *(code **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar10 = *plVar10 + -1;
                      plStack_e8 = (longlong *)0x0;
                      if (*plVar10 == 0) {
                        FUN_23a334bc0(plVar10);
                      }
                    }
                    else {
                      plVar10[4] = lVar7;
                      plStack_e8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar10);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        FUN_23a334bc0(plVar10);
                      }
                      if (plStack_e8 != (longlong *)0x0) {
                        lVar7 = FUN_23ead6850();
                        if (lVar7 == 0) {
                          uVar19 = 0x88;
                          FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
                          plStack_e0 = (longlong *)0x0;
                          pcVar17 = pcStack_68;
                          pcVar15 = pcStack_78;
                          pcVar20 = pcStack_70;
                          goto LAB_23c61fa28;
                        }
                        *(undefined4 *)(plVar18 + 5) = 0x88;
                        plVar9 = (longlong *)FUN_23e915840(param_1,lVar7,_DAT_23ee28cc0);
                        if (plVar9 == (longlong *)0x0) {
                          pcVar15 = *(code **)(param_1 + 0x60);
                          pcVar17 = *(code **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          uVar19 = 0x88;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          plStack_e0 = (longlong *)0x0;
                          pcVar20 = *(code **)(param_1 + 0x68);
                          goto LAB_23c61fa28;
                        }
                        lVar7 = *plVar9;
                        *plVar9 = lVar7 + -1;
                        if (lVar7 + -1 == 0) {
                          FUN_23a334bc0();
                        }
                        goto LAB_23c61f73f;
                      }
                      pcVar17 = *(code **)(param_1 + 0x70);
                      pcVar15 = *(code **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    uVar19 = 0x87;
                    plStack_e0 = (longlong *)0x0;
                    goto LAB_23c61fa28;
                  }
LAB_23c61f5f3:
                  pcVar20 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    pcVar15 = pcVar8;
                    if (plVar9 == (longlong *)0x0) goto LAB_23c621156;
                    *plVar9 = *plVar9 + 1;
                    DAT_23ed6a4c0 = plVar9;
                  }
                  pcStack_70 = pcVar20;
                  pcStack_78 = pcVar8;
                  plVar6 = (longlong *)FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
                  if (plVar6 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    plStack_e0 = (longlong *)0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar19 = 0x8a;
                    plStack_e8 = (longlong *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                    goto LAB_23c61fa28;
                  }
                  lVar7 = *(longlong *)(param_1 + 0x10);
                  plVar9 = *(longlong **)(lVar7 + 0xe28);
                  if (plVar9 == (longlong *)0x0) {
                    plVar9 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar5 = plVar9[3];
                    *(int *)(lVar7 + 0xec0) = *(int *)(lVar7 + 0xec0) + -1;
                    *(longlong *)(lVar7 + 0xe28) = lVar5;
                    *plVar9 = 1;
                  }
                  plVar9[5] = 0;
                  lVar7 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
                  lVar5 = plVar9[-1];
                  puVar1 = *(undefined8 **)(lVar7 + 8);
                  *puVar1 = plVar9 + -2;
                  plVar10 = _DAT_23ee28df0;
                  plVar9[-2] = lVar7;
                  plVar9[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar1;
                  *(longlong **)(lVar7 + 8) = plVar9 + -2;
                  plVar9[3] = (longlong)plVar6;
                  *plVar10 = *plVar10 + 1;
                  plVar9[4] = (longlong)plVar10;
                  pcVar20 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    pcVar15 = pcStack_f0;
                    if (plVar10 == (longlong *)0x0) goto LAB_23c621156;
                    *plVar10 = *plVar10 + 1;
                    DAT_23ed6a4c0 = plVar10;
                  }
                  pcStack_70 = pcVar20;
                  pcStack_78 = pcStack_f0;
                  lVar7 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_78);
                  if (lVar7 == 0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x68);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar9 = *plVar9 + -1;
                    plVar6 = (longlong *)0x0;
                    if (*plVar9 == 0) {
                      uVar19 = 0x8a;
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                      plStack_e0 = (longlong *)0x0;
                      plStack_e8 = (longlong *)0x0;
                    }
                    else {
                      plStack_e0 = (longlong *)0x0;
                      uVar19 = 0x8a;
                      plStack_e8 = (longlong *)0x0;
                    }
                    goto LAB_23c61fa28;
                  }
                  plVar9[5] = lVar7;
                  plStack_e8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  plVar6 = (longlong *)0x0;
                  if (plStack_e8 == (longlong *)0x0) {
                    pcVar15 = *(code **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x70);
                    plStack_e0 = (longlong *)0x0;
                    uVar19 = 0x8a;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar20 = *(code **)(param_1 + 0x68);
                    goto LAB_23c61fa28;
                  }
LAB_23c61f73f:
                  lVar7 = FUN_23ead6480();
                  if (lVar7 == 0) {
                    uVar19 = 0x8c;
                    FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28df8);
                    plStack_e0 = (longlong *)0x0;
                    pcVar17 = pcStack_68;
                    pcVar15 = pcStack_78;
                    pcVar20 = pcStack_70;
                    goto LAB_23c61fa28;
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28e00);
                  if (plVar9 != (longlong *)0x0) {
                    plVar10 = (longlong *)FUN_23e8bc2f0(plStack_e8,_DAT_23ee28e78);
                    *(undefined4 *)(plVar18 + 5) = 0x8c;
                    plVar11 = (longlong *)FUN_23e94bb80(param_1,plVar10,_DAT_23ee28e80);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      FUN_23a334bc0(plVar10);
                    }
                    if (plVar11 == (longlong *)0x0) {
                      pcVar15 = *(code **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x68);
                      pcVar17 = *(code **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar19 = 0x8c;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *plVar9 = *plVar9 + -1;
                      lVar7 = *plVar9;
                      plVar10 = (longlong *)0x0;
joined_r0x00023c62162e:
                      plStack_e0 = plVar10;
                      if (lVar7 == 0) {
                        FUN_23a334bc0(plVar9);
                      }
                      goto LAB_23c61fa28;
                    }
                    *(undefined4 *)(plVar18 + 5) = 0x8c;
                    plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    lVar7 = *plVar11;
                    *plVar11 = lVar7 + -1;
                    if (lVar7 + -1 == 0) {
                      FUN_23a334bc0();
                    }
                    uVar13 = _DAT_23ee28e10;
                    if (plVar12 != (longlong *)0x0) {
                      *(undefined4 *)(plVar18 + 5) = 0x8c;
                      plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar12,uVar13);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0(plVar12);
                      }
                      plStack_e0 = plVar10;
                      if (plVar10 == (longlong *)0x0) {
                        pcVar15 = *(code **)(param_1 + 0x60);
                        pcVar17 = *(code **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        uVar19 = 0x8c;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        pcVar20 = *(code **)(param_1 + 0x68);
                        goto LAB_23c61fa28;
                      }
                      lVar7 = FUN_23ead6850();
                      if (lVar7 == 0) {
                        uVar19 = 0x8e;
                        FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
                        pcVar17 = pcStack_68;
                        pcVar15 = pcStack_78;
                        pcVar20 = pcStack_70;
                        goto LAB_23c61fa28;
                      }
                      plVar12 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28e28);
                      plVar11 = _DAT_23ee28e88;
                      if (plVar12 != (longlong *)0x0) {
                        plVar9 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                        *plVar11 = *plVar11 + 1;
                        plVar9[3] = (longlong)plVar11;
                        lVar7 = FUN_23e94f9d0(param_1,plVar10,DAT_23ed6cd28);
                        if (lVar7 == 0) {
                          pcVar15 = *(code **)(param_1 + 0x60);
                          pcVar20 = *(code **)(param_1 + 0x68);
                          pcVar17 = *(code **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          *plVar9 = *plVar9 + -1;
                          lVar7 = *plVar9;
                          uVar19 = 0x8e;
                          goto joined_r0x00023c62162e;
                        }
                        plVar9[4] = lVar7;
                        plVar11 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar9);
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          FUN_23a334bc0(plVar9);
                        }
                        if (plVar11 == (longlong *)0x0) {
                          pcVar15 = *(code **)(param_1 + 0x60);
                          pcVar20 = *(code **)(param_1 + 0x68);
                          pcVar17 = *(code **)(param_1 + 0x70);
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *plVar12 = *plVar12 + -1;
                          if (*plVar12 == 0) {
                            FUN_23a334bc0(plVar12);
                          }
                          uVar19 = 0x8e;
                          goto LAB_23c61fa28;
                        }
                        *(undefined4 *)(plVar18 + 5) = 0x8e;
                        plVar9 = (longlong *)FUN_23e914090(param_1,plVar12,plVar11);
                        *plVar12 = *plVar12 + -1;
                        if (*plVar12 == 0) {
                          FUN_23a334bc0(plVar12);
                        }
                        *plVar11 = *plVar11 + -1;
                        if (*plVar11 == 0) {
                          FUN_23a334bc0(plVar11);
                        }
                        if (plVar9 != (longlong *)0x0) {
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            FUN_23a334bc0(plVar9);
                          }
                          FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                          *plVar10 = *plVar10 + 1;
                          *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
                          if (*(longlong *)pcVar8 == 0) {
                            (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
                            plVar18 = (longlong *)0x0;
                            goto LAB_23c620094;
                          }
                          plVar18 = (longlong *)0x0;
                          lVar7 = *(longlong *)pcStack_f0;
                          *(longlong *)pcStack_f0 = lVar7 + -1;
                          if (lVar7 + -1 == 0) goto LAB_23c620ca8;
                          if (plVar6 != (longlong *)0x0) goto LAB_23c6200b6;
                          goto LAB_23c6200c8;
                        }
                      }
                      pcVar15 = *(code **)(param_1 + 0x60);
                      pcVar17 = *(code **)(param_1 + 0x70);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      uVar19 = 0x8e;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar20 = *(code **)(param_1 + 0x68);
                      goto LAB_23c61fa28;
                    }
                  }
                  pcVar15 = *(code **)(param_1 + 0x60);
                  pcVar17 = *(code **)(param_1 + 0x70);
                  plStack_e0 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar19 = 0x8c;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar20 = *(code **)(param_1 + 0x68);
                  goto LAB_23c61fa28;
                }
                pcVar15 = *(code **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x68);
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                lVar7 = *plVar9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar9 = lVar7 + -1;
                plVar6 = (longlong *)0x0;
                if (lVar7 + -1 == 0) {
                  uVar19 = 0x82;
                  (**(code **)(plVar9[1] + 0x30))();
                  plStack_e0 = (longlong *)0x0;
                  plStack_e8 = (longlong *)0x0;
                  goto LAB_23c61fa28;
                }
              }
              plVar6 = (longlong *)0x0;
              plStack_e0 = (longlong *)0x0;
              uVar19 = 0x82;
              plStack_e8 = (longlong *)0x0;
              goto LAB_23c61fa28;
            }
            pcVar15 = *(code **)(param_1 + 0x60);
            pcVar17 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar20 = *(code **)(param_1 + 0x68);
          }
          plVar6 = (longlong *)0x0;
          uVar19 = 0x80;
          plStack_e0 = (longlong *)0x0;
          plStack_e8 = (longlong *)0x0;
          pcStack_d8 = _PyRuntime_exref;
          goto LAB_23c61fa28;
        }
        pcVar17 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar15 = *(code **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar20 = *(code **)(param_1 + 0x68);
      }
      plVar6 = (longlong *)0x0;
      plStack_e0 = (longlong *)0x0;
      uVar19 = 0x7f;
      plStack_e8 = (longlong *)0x0;
      pcStack_f0 = (code *)0x0;
      pcStack_d8 = _PyRuntime_exref;
LAB_23c61fa28:
      do {
        plVar9 = *(longlong **)(param_1 + 0x138);
        auStack_98._8_8_ = pcVar20;
        auStack_98._0_8_ = pcVar15;
        if (plVar9 != (longlong *)0x0) {
          *plVar9 = *plVar9 + 1;
        }
        pcVar15 = DAT_23ed6a4f8;
        apcStack_88[0] = pcVar17;
        if (pcVar17 == (code *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar17 = *(code **)DAT_23ed6a4f8;
            *(undefined8 *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar17;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong *)(pcVar15 + 0x10) = 0;
          *(longlong **)(pcVar15 + 0x18) = plVar18;
          *plVar18 = *plVar18 + 1;
          lVar7 = *(longlong *)(pcStack_d8 + 0x1f8);
          *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
          lVar7 = *(longlong *)(lVar7 + 0x10);
          *(undefined4 *)(pcVar15 + 0x24) = uVar19;
          lVar7 = *(longlong *)(lVar7 + 0x2e8);
          lVar5 = *(longlong *)(pcVar15 + -8);
          plVar10 = *(longlong **)(lVar7 + 8);
          *plVar10 = (longlong)(pcVar15 + -0x10);
          *(longlong *)(pcVar15 + -0x10) = lVar7;
          *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)plVar10;
          *(code **)(lVar7 + 8) = pcVar15 + -0x10;
          if ((apcStack_88[0] != (code *)0x0) &&
             (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
             *(longlong *)apcStack_88[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar15 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar20 = *(code **)DAT_23ed6a4f8;
            *(undefined8 *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar20;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar15 + 0x18) = plVar18;
          *plVar18 = *plVar18 + 1;
          lVar7 = *(longlong *)(pcStack_d8 + 0x1f8);
          *(undefined4 *)(pcVar15 + 0x20) = 0xffffffff;
          *(undefined4 *)(pcVar15 + 0x24) = uVar19;
          lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
          lVar5 = *(longlong *)(pcVar15 + -8);
          plVar10 = *(longlong **)(lVar7 + 8);
          *plVar10 = (longlong)(pcVar15 + -0x10);
          *(longlong *)(pcVar15 + -0x10) = lVar7;
          *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)plVar10;
          *(code **)(lVar7 + 8) = pcVar15 + -0x10;
          *(code **)(pcVar15 + 0x10) = pcVar17;
          *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
          if ((apcStack_88[0] != (code *)0x0) &&
             (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
             *(longlong *)apcStack_88[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
          }
        }
        pcVar17 = _Py_NoneStruct_exref;
        apcStack_88[0] = pcVar15;
        if (((code *)auStack_98._0_8_ != (code *)0x0) &&
           ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref)) {
          FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
        }
        plVar10 = *(longlong **)(auStack_98._8_8_ + 0x28);
        if (apcStack_88[0] == pcVar17) {
          pcVar15 = (code *)0x0;
        }
        else {
          pcVar15 = apcStack_88[0];
          if (apcStack_88[0] != (code *)0x0) {
            *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
          }
        }
        *(code **)(auStack_98._8_8_ + 0x28) = pcVar15;
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        plVar10 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
        if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
          (**(code **)(plVar10[1] + 0x30))();
        }
        *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
        if (*(longlong *)auStack_98._0_8_ == 0) {
          (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
        }
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
        }
        pcVar15 = *(code **)(param_1 + 0x138);
        apcStack_88[0] = (code *)0x0;
        auStack_98 = (undefined1  [16])0x0;
        pcVar20 = *(code **)PyExc_Exception_exref;
        pcVar14 = *(code **)(pcVar15 + 8);
        if ((*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) & 0x4000000) == 0) {
          if (((int)*(uint *)(*(longlong *)(pcVar20 + 8) + 0xa8) < 0) &&
             (((byte)pcVar20[0xab] & 0x40) != 0)) {
            pcVar2 = *(code **)(pcVar14 + 8);
            if ((*(uint *)(pcVar2 + 0xa8) & 0x40000000) == 0) {
              pcVar3 = pcVar14;
              if (((int)*(uint *)(pcVar2 + 0xa8) < 0) && (((byte)pcVar14[0xab] & 0x40) != 0))
              goto LAB_23c620189;
            }
            else {
              pcVar14 = pcVar2;
              pcVar3 = pcVar2;
              if (*(int *)(*(longlong *)(pcVar2 + 8) + 0xa8) < 0) {
LAB_23c620189:
                lVar7 = *(longlong *)(pcVar14 + 0x158);
                if (lVar7 != 0) {
                  if (*(longlong *)(lVar7 + 0x10) < 1) goto LAB_23c61fca0;
                  lVar5 = 0;
                  while (pcVar20 != *(code **)(lVar7 + 0x18 + lVar5 * 8)) {
                    lVar5 = lVar5 + 1;
                    if (*(longlong *)(lVar7 + 0x10) == lVar5) goto LAB_23c61fca0;
                  }
                  goto LAB_23c61fd8d;
                }
                do {
                  if (pcVar20 == pcVar14) goto LAB_23c61fd8d;
                  pcVar14 = *(code **)(pcVar14 + 0x100);
                  pcVar3 = PyBaseObject_Type_exref;
                } while (pcVar14 != (code *)0x0);
              }
            }
            if (pcVar20 != pcVar3) goto LAB_23c61fca0;
          }
          else {
LAB_23c61fd20:
            plVar10 = *(longlong **)PyExc_TypeError_exref;
            uVar13 = PyUnicode_FromString
                               (
                               "catching classes that do not inherit from BaseException is not allowed"
                               );
            plVar11 = *(longlong **)(param_1 + 0x60);
            plVar12 = *(longlong **)(param_1 + 0x68);
            plVar16 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar10;
            *plVar10 = *plVar10 + 1;
            *(undefined8 *)(param_1 + 0x68) = uVar13;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
              (**(code **)(plVar11[1] + 0x30))();
            }
            if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if ((plVar16 == (longlong *)0x0) || (*plVar16 = *plVar16 + -1, *plVar16 != 0))
            goto LAB_23c61fd86;
            (**(code **)(plVar16[1] + 0x30))(plVar16);
            pcVar15 = *(code **)(param_1 + 0x138);
          }
        }
        else {
          lVar7 = *(longlong *)(pcVar20 + 0x10);
          if (lVar7 < 1) {
LAB_23c61fca0:
            if ((pcVar15 == (code *)0x0) || (pcVar15 == pcVar17)) {
              pcStack_c8 = *(code **)PyExc_RuntimeError_exref;
              pcStack_c0 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar15 = *(code **)(param_1 + 0x138);
              *(longlong *)pcStack_c8 = *(longlong *)pcStack_c8 + 1;
              *(longlong **)(param_1 + 0x138) = plVar9;
              if ((pcVar15 == (code *)0x0) ||
                 (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 != 0)) {
                plVar10 = (longlong *)0x0;
                iVar4 = 0x7e;
                goto LAB_23c620400;
              }
              plVar10 = (longlong *)0x0;
              iVar4 = 0x7e;
              pcVar17 = (code *)0x0;
              goto LAB_23c620880;
            }
            pcStack_c8 = *(code **)(pcVar15 + 8);
            pcVar17 = *(code **)(pcVar15 + 0x28);
            *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
            *(longlong *)pcStack_c8 = *(longlong *)pcStack_c8 + 1;
            pcStack_c0 = pcVar15;
            if (pcVar17 == (code *)0x0) {
              plVar10 = (longlong *)0x0;
              *(longlong **)(param_1 + 0x138) = plVar9;
              lVar7 = *(longlong *)pcVar15;
              *(longlong *)pcVar15 = lVar7 + -1;
              if (lVar7 + -1 != 0) goto LAB_23c6208aa;
              iVar4 = 0;
              goto LAB_23c620880;
            }
            *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
            if (plVar18 == *(longlong **)(pcVar17 + 0x18)) {
              *(undefined4 *)(plVar18 + 5) = *(undefined4 *)(pcVar17 + 0x24);
              *(longlong **)(param_1 + 0x138) = plVar9;
              *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
              if (*(longlong *)pcVar15 == 0) {
                plVar10 = (longlong *)0x0;
                iVar4 = 0;
                goto LAB_23c620880;
              }
            }
            else {
              *(longlong **)(param_1 + 0x138) = plVar9;
              *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
              if (*(longlong *)pcVar15 != 0) {
                plVar10 = (longlong *)0x0;
                if (plVar18 == *(longlong **)(pcVar17 + 0x18)) goto LAB_23c620650;
                goto LAB_23c6205ae;
              }
              (**(code **)(pcStack_c8 + 0x30))(pcVar15);
            }
            plVar10 = (longlong *)0x0;
            iVar4 = 0;
            goto LAB_23c62059c;
          }
          lVar5 = 0;
          do {
            if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar20 + lVar5 * 8 + 0x18) + 8) + 0xa8))
               || ((*(byte *)(*(longlong *)(pcVar20 + lVar5 * 8 + 0x18) + 0xab) & 0x40) == 0))
            goto LAB_23c61fd20;
            lVar5 = lVar5 + 1;
          } while (lVar7 != lVar5);
          lVar5 = 0;
          while (iVar4 = FUN_23a35ebd0(param_1,pcVar14,*(undefined8 *)(pcVar20 + lVar5 * 8 + 0x18)),
                iVar4 == 0) {
            lVar5 = lVar5 + 1;
            if (lVar7 == lVar5) {
              pcVar15 = *(code **)(param_1 + 0x138);
              goto LAB_23c61fca0;
            }
          }
LAB_23c61fd86:
          pcVar15 = *(code **)(param_1 + 0x138);
        }
LAB_23c61fd8d:
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
        lVar7 = FUN_23ead6850();
        if (lVar7 == 0) {
          FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
          iVar4 = 0x92;
          pcStack_c8 = pcStack_78;
          pcStack_c0 = pcStack_70;
          plVar10 = (longlong *)0x0;
          pcVar17 = pcStack_68;
          goto LAB_23c620560;
        }
        plVar11 = (longlong *)FUN_23e8bc2f0(lVar7,_DAT_23ee28e90);
        plVar10 = _DAT_23ee28e98;
        if (plVar11 == (longlong *)0x0) goto LAB_23c6208b8;
        lVar7 = *(longlong *)(param_1 + 0x10);
        plVar12 = *(longlong **)(lVar7 + 0xe20);
        if (plVar12 == (longlong *)0x0) {
          plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar5 = plVar12[3];
          *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
          *(longlong *)(lVar7 + 0xe20) = lVar5;
          *plVar12 = 1;
        }
        plVar12[4] = 0;
        lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_d8 + 0x1f8) + 0x10) + 0x2e8);
        lVar5 = plVar12[-1];
        puVar1 = *(undefined8 **)(lVar7 + 8);
        *puVar1 = plVar12 + -2;
        plVar12[-2] = lVar7;
        plVar12[-1] = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar1;
        *(longlong **)(lVar7 + 8) = plVar12 + -2;
        plVar16 = DAT_23ed6a4c0;
        *plVar10 = *plVar10 + 1;
        plVar12[3] = (longlong)plVar10;
        pcVar20 = DAT_23ed6cd28;
        if (plVar16 != (longlong *)0x0) goto LAB_23c61fe6b;
        plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar16 != (longlong *)0x0) goto code_r0x00023c620a93;
LAB_23c621156:
        pcVar17 = (code *)&DAT_23ed6cce0;
        PyErr_PrintEx(0,0);
        Py_Exit(1);
LAB_23c621169:
        plStack_e0 = (longlong *)0x0;
        uVar19 = 0x83;
        plStack_e8 = (longlong *)0x0;
      } while( true );
    }
    pcStack_c8 = *(code **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  pcStack_d8 = _PyRuntime_exref;
  if (pcVar17 == (code *)0x0) {
    plVar6 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    pcVar8 = (code *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_e8 = (longlong *)0x0;
    iVar4 = 0x7c;
    pcStack_f0 = (code *)0x0;
    goto LAB_23c620400;
  }
  plVar6 = (longlong *)0x0;
  if (plVar18 == *(longlong **)(pcVar17 + 0x18)) {
    plStack_e0 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    pcVar8 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    pcStack_f0 = (code *)0x0;
    goto LAB_23c620650;
  }
  plVar10 = (longlong *)0x0;
  pcVar8 = (code *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_e8 = (longlong *)0x0;
  iVar4 = 0x7c;
  pcStack_f0 = (code *)0x0;
  pcVar15 = pcVar17;
LAB_23c6205b4:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar20 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar20;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar17 + 0x18) = plVar18;
  *plVar18 = *plVar18 + 1;
  *(int *)(pcVar17 + 0x24) = iVar4;
  lVar7 = *(longlong *)(pcStack_d8 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
  lVar5 = *(longlong *)(pcVar17 + -8);
  puVar1 = *(undefined8 **)(lVar7 + 8);
  *puVar1 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar7;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar1;
  lVar5 = *(longlong *)pcVar15;
  *(code **)(lVar7 + 8) = pcVar17 + -0x10;
  *(code **)(pcVar17 + 0x10) = pcVar15;
  if (lVar5 == 0) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  goto LAB_23c620650;
code_r0x00023c620a93:
  *plVar16 = *plVar16 + 1;
  DAT_23ed6a4c0 = plVar16;
LAB_23c61fe6b:
  pcStack_a0 = pcVar20;
  pcStack_a8 = pcVar15;
  lVar7 = FUN_23e94ed00(param_1,plVar16,&pcStack_a8);
  if (lVar7 == 0) {
    pcStack_c8 = *(code **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
    }
    lVar7 = *plVar12;
    iVar4 = 0x92;
    *plVar12 = lVar7 + -1;
    plVar10 = (longlong *)0x0;
    if (lVar7 + -1 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
      iVar4 = 0x92;
    }
  }
  else {
    plVar12[4] = lVar7;
    plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (plVar10 != (longlong *)0x0) {
      *(undefined4 *)(plVar18 + 5) = 0x92;
      plVar12 = (longlong *)FUN_23e914090(param_1,plVar11,plVar10);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar12 == (longlong *)0x0) {
LAB_23c6208b8:
        pcStack_c8 = *(code **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar4 = 0x92;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c620560;
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar5 = FUN_23ead6480();
      lVar7 = _DAT_23ee28ea0;
      if (lVar5 == 0) {
        FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28df8);
        iVar4 = 0x93;
        pcStack_c8 = pcStack_78;
        pcStack_c0 = pcStack_70;
        plVar10 = (longlong *)0x0;
        pcVar17 = pcStack_68;
        goto LAB_23c620560;
      }
      *(undefined4 *)(plVar18 + 5) = 0x93;
      plVar11 = (longlong *)
                FUN_23e915840(param_1,lVar5,_DAT_23ee28e00,*(undefined8 *)(lVar7 + 0x18));
      if (plVar11 == (longlong *)0x0) {
        pcStack_c8 = *(code **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar4 = 0x93;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c620560;
      }
      *(undefined4 *)(plVar18 + 5) = 0x93;
      plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23ee28e10);
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      if (plVar10 == (longlong *)0x0) {
        pcStack_c8 = *(code **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        iVar4 = 0x93;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c620560;
      }
      lVar5 = FUN_23ead6850();
      lVar7 = _DAT_23ee28ea8;
      if (lVar5 == 0) {
        FUN_23e915740(param_1,&pcStack_78,_DAT_23ee28cb8);
        iVar4 = 0x94;
        pcStack_c8 = pcStack_78;
        pcStack_c0 = pcStack_70;
        pcVar17 = pcStack_68;
        goto LAB_23c620560;
      }
      *(undefined4 *)(plVar18 + 5) = 0x94;
      plVar11 = (longlong *)
                FUN_23e915840(param_1,lVar5,_DAT_23ee28cc0,*(undefined8 *)(lVar7 + 0x18));
      if (plVar11 == (longlong *)0x0) {
        pcStack_c8 = *(code **)(param_1 + 0x60);
        pcVar17 = *(code **)(param_1 + 0x70);
        iVar4 = 0x94;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_c0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c620560;
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      *plVar10 = *plVar10 + 1;
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
      if (*(longlong *)pcVar15 == 0) {
        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
      }
      plVar18 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar9;
      if ((plVar18 != (longlong *)0x0) && (*plVar18 = *plVar18 + -1, *plVar18 == 0)) {
        (**(code **)(plVar18[1] + 0x30))();
      }
      lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar18 = *(longlong **)(lVar7 + 0x28);
      plVar9 = (longlong *)plVar18[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
      *(undefined4 *)(plVar18 + 8) = 0xffffffff;
      if (plVar9 != (longlong *)0x0) {
        plVar18[2] = 0;
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))();
        }
      }
      *plVar18 = *plVar18 + -1;
      if (*plVar18 == 0) {
        (**(code **)(plVar18[1] + 0x30))(plVar18);
      }
      plVar18[0xf] = 0;
      if ((pcVar8 != (code *)0x0) &&
         (*(longlong *)pcVar8 = *(longlong *)pcVar8 + -1, *(longlong *)pcVar8 == 0)) {
        (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
      }
      plVar18 = plVar10;
      if (pcStack_f0 != (code *)0x0) {
LAB_23c620094:
        lVar7 = *(longlong *)pcStack_f0;
        *(longlong *)pcStack_f0 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
LAB_23c620ca8:
          (**(code **)(*(longlong *)(pcStack_f0 + 8) + 0x30))();
        }
      }
      if (plVar6 != (longlong *)0x0) {
LAB_23c6200b6:
        *plVar6 = *plVar6 + -1;
        if (*plVar6 == 0) {
          (**(code **)(plVar6[1] + 0x30))(plVar6);
        }
      }
      if (plStack_e8 == (longlong *)0x0) goto LAB_23c6200e5;
LAB_23c6200c8:
      lVar7 = *plStack_e8;
      *plStack_e8 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
      }
LAB_23c6200e5:
      if ((plStack_e0 != (longlong *)0x0) &&
         (lVar7 = *plStack_e0, *plStack_e0 = lVar7 + -1, lVar7 + -1 == 0)) {
        (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
      }
      if (plVar18 == (longlong *)0x0) {
        return plVar10;
      }
      *plVar18 = *plVar18 + -1;
      if (*plVar18 != 0) {
        return plVar10;
      }
      (**(code **)(plVar18[1] + 0x30))(plVar18);
      return plVar10;
    }
    pcStack_c8 = *(code **)(param_1 + 0x60);
    pcVar17 = *(code **)(param_1 + 0x70);
    iVar4 = 0x92;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_c0 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar7 = *plVar11;
    *plVar11 = lVar7 + -1;
    plVar10 = (longlong *)0x0;
    if (lVar7 + -1 == 0) {
      (**(code **)(plVar11[1] + 0x30))(plVar11);
      iVar4 = 0x92;
    }
  }
LAB_23c620560:
  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
  if (*(longlong *)pcVar15 == 0) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
    pcVar15 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar9;
    if (pcVar15 != (code *)0x0) goto LAB_23c620589;
    if (pcVar17 != (code *)0x0) {
      plVar9 = *(longlong **)(pcVar17 + 0x18);
      goto joined_r0x00023c620836;
    }
  }
  else {
    pcVar15 = *(code **)(param_1 + 0x138);
    *(longlong **)(param_1 + 0x138) = plVar9;
    if (pcVar15 == (code *)0x0) {
      if (pcVar17 != (code *)0x0) {
        plVar9 = *(longlong **)(pcVar17 + 0x18);
joined_r0x00023c620836:
        pcVar15 = pcVar17;
        if (plVar9 == plVar18) goto LAB_23c620650;
        goto LAB_23c6205b4;
      }
    }
    else {
LAB_23c620589:
      *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
      if (*(longlong *)pcVar15 == 0) {
LAB_23c620880:
        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
        if (pcVar17 != (code *)0x0) goto LAB_23c62059c;
        if (iVar4 == 0) {
LAB_23c6208aa:
          iVar4 = (int)plVar18[5];
        }
      }
      else if (pcVar17 != (code *)0x0) {
LAB_23c62059c:
        if (*(longlong **)(pcVar17 + 0x18) == plVar18) goto LAB_23c620650;
        pcVar15 = pcVar17;
        if (iVar4 == 0) {
LAB_23c6205ae:
          iVar4 = (int)plVar18[5];
          pcVar15 = pcVar17;
        }
        goto LAB_23c6205b4;
      }
    }
  }
LAB_23c620400:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar15 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar15;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar17 + 0x18) = plVar18;
  *(longlong *)(pcVar17 + 0x10) = 0;
  *plVar18 = *plVar18 + 1;
  *(int *)(pcVar17 + 0x24) = iVar4;
  lVar7 = *(longlong *)(pcStack_d8 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
  lVar5 = *(longlong *)(pcVar17 + -8);
  puVar1 = *(undefined8 **)(lVar7 + 8);
  *puVar1 = pcVar17 + -0x10;
  *(longlong *)(pcVar17 + -0x10) = lVar7;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar5 & 3) | (ulonglong)puVar1;
  *(code **)(lVar7 + 8) = pcVar17 + -0x10;
LAB_23c620650:
  FUN_23e8bba40(plVar18,"ooooooo",pcVar8,pcStack_f0,plVar6,plStack_e8,plStack_e0,0,plVar10);
  if (_DAT_23ee29d68 == plVar18) {
    *plVar18 = *plVar18 + -1;
    if (*plVar18 == 0) {
      (**(code **)(plVar18[1] + 0x30))(plVar18);
    }
    _DAT_23ee29d68 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar18 = *(longlong **)(lVar7 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  plVar9 = (longlong *)plVar18[2];
  *(undefined4 *)(plVar18 + 8) = 0xffffffff;
  if (plVar9 != (longlong *)0x0) {
    plVar18[2] = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
  }
  *plVar18 = *plVar18 + -1;
  if (*plVar18 == 0) {
    (**(code **)(plVar18[1] + 0x30))(plVar18);
  }
  plVar18[0xf] = 0;
  if ((pcVar8 != (code *)0x0) &&
     (*(longlong *)pcVar8 = *(longlong *)pcVar8 + -1, *(longlong *)pcVar8 == 0)) {
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
  }
  if ((pcStack_f0 != (code *)0x0) &&
     (lVar7 = *(longlong *)pcStack_f0, *(longlong *)pcStack_f0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_f0 + 8) + 0x30))(pcStack_f0);
  }
  if ((plVar6 != (longlong *)0x0) && (*plVar6 = *plVar6 + -1, *plVar6 == 0)) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar7 = *plStack_e8, *plStack_e8 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar7 = *plStack_e0, *plStack_e0 = lVar7 + -1, lVar7 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  FUN_23a33aa70(param_1,pcStack_c8,pcStack_c0,pcVar17);
  return (longlong *)0x0;
}
