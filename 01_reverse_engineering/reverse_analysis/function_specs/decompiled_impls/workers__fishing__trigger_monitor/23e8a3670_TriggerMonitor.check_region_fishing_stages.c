/* ===== 23e8a3670 workers.fishing.trigger_monitor:375 ===== */
/* ghidra_name=FUN_23e8a3670 entry=23e8a3670 size=22828 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e8a3670(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong lVar4;
  code *pcVar5;
  undefined8 uVar6;
  char cVar7;
  int iVar8;
  code *pcVar9;
  longlong *plVar10;
  code *pcVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong lVar17;
  longlong lVar18;
  longlong *plVar19;
  code *pcVar20;
  longlong *plVar21;
  longlong *plVar22;
  code *pcVar23;
  code *pcVar24;
  longlong lVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  ulonglong uVar28;
  undefined8 uVar29;
  longlong *plStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  code *pcStack_d8;
  code *pcStack_d0;
  code *pcStack_c8;
  code *pcStack_c0;
  code *pcStack_b8;
  code *pcStack_b0;
  code *pcStack_88;
  code *pcStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar1 = (longlong *)*param_3;
  lVar17 = *(longlong *)(param_1 + 0x10);
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (*(int *)(lVar17 + 0x1188) == 0) {
    pcVar20 = (code *)FUN_23a33a530(PyList_Type_exref);
  }
  else {
    iVar8 = *(int *)(lVar17 + 0x1188) + -1;
    *(int *)(lVar17 + 0x1188) = iVar8;
    pcVar20 = *(code **)(lVar17 + 0xf08 + (longlong)iVar8 * 8);
    *(longlong *)pcVar20 = 1;
  }
  pcVar13 = _PyRuntime_exref;
  *(longlong *)(pcVar20 + 0x10) = 0;
  *(longlong *)(pcVar20 + 0x20) = 0;
  pcVar9 = _DAT_23eede410;
  lVar17 = *(longlong *)(pcVar13 + 0x1f8);
  *(longlong *)(pcVar20 + 0x18) = 0;
  lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
  lVar18 = *(longlong *)(pcVar20 + -8);
  puVar2 = *(undefined8 **)(lVar17 + 8);
  *puVar2 = pcVar20 + -0x10;
  *(longlong *)(pcVar20 + -0x10) = lVar17;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
  *(code **)(lVar17 + 8) = pcVar20 + -0x10;
  if (pcVar9 == (code *)0x0) {
LAB_23e8a375b:
    pcVar9 = (code *)FUN_23e91f3b0(param_1,_DAT_23eede408,DAT_23eede5a0);
    _DAT_23eede410 = pcVar9;
  }
  else {
    lVar17 = *(longlong *)pcVar9;
    if (1 < lVar17) {
      *(longlong *)pcVar9 = lVar17 + -1;
      goto LAB_23e8a375b;
    }
    if (*(longlong *)(pcVar9 + 0x10) != 0) {
      *(longlong *)pcVar9 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
      }
      goto LAB_23e8a375b;
    }
  }
  lVar17 = *(longlong *)(param_1 + 0x38);
  lVar18 = *(longlong *)(lVar17 + 8);
  *(longlong *)(pcVar9 + 0x78) = lVar18;
  *(code **)(lVar17 + 8) = pcVar9 + 0x48;
  if ((lVar18 != 0) &&
     (((*(char *)(lVar18 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar18 + 0x38))) && (*(longlong *)(pcVar9 + 0x70) != 0)))) {
    plVar10 = *(longlong **)(lVar18 + 0x28);
    *(longlong **)(*(longlong *)(pcVar9 + 0x70) + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
  *(undefined4 *)(pcVar9 + 0x40) = 0;
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed6ce40);
  pcVar13 = _DAT_23eedc2c8;
  lVar17 = DAT_23ed6cce8;
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    pcVar16 = (code *)0x0;
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar14 = (code *)0x0;
    pcVar13 = (code *)0x0;
    uVar26 = 0x17c;
    pcStack_d0 = (code *)0x0;
    pcStack_d8 = (code *)0x0;
    plStack_e8 = (longlong *)0x0;
    plStack_e0 = (longlong *)0x0;
    plStack_f0 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plStack_f8 = (longlong *)0x0;
    goto LAB_23e8a50b5;
  }
  lVar18 = *(longlong *)(param_1 + 0x10);
  iVar8 = *(int *)(lVar18 + 0x1410);
  plVar15 = *(longlong **)(DAT_23ed6cce8 + 0x20);
  *plVar15 = *plVar15 + 1;
  if (iVar8 == 0) {
    pcVar14 = (code *)FUN_23a33a530(PyDict_Type_exref);
    plVar15 = *(longlong **)(lVar17 + 0x20);
  }
  else {
    iVar8 = iVar8 + -1;
    *(int *)(lVar18 + 0x1410) = iVar8;
    pcVar14 = *(code **)(lVar18 + 0x1190 + (longlong)iVar8 * 8);
    *(longlong *)pcVar14 = 1;
  }
  lVar17 = *(longlong *)(lVar17 + 0x28);
  *(longlong *)(pcVar14 + 0x10) = 0;
  *(longlong **)(pcVar14 + 0x20) = plVar15;
  *(longlong *)(pcVar14 + 0x28) = lVar17;
  *(longlong *)(pcVar14 + 0x18) = 1;
  *(undefined4 *)(pcVar9 + 0x28) = 0x17c;
  pcStack_88 = pcVar13;
  pcStack_80 = pcVar14;
  plStack_f0 = (longlong *)FUN_23e94ed00(param_1,plVar10,&pcStack_88);
  lVar17 = *plVar10;
  *plVar10 = lVar17 + -1;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
  if (*(longlong *)pcVar14 == 0) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  if (plStack_f0 != (longlong *)0x0) {
    iVar8 = FUN_23a35f020(plStack_f0);
    if (iVar8 == -1) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plVar15 = *(longlong **)(param_1 + 0x70);
      uVar26 = 0x17d;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a506f;
    }
    plStack_f8 = (longlong *)0x0;
    if (iVar8 != 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(plStack_f0,_DAT_23eedc378);
      if (plVar10 != (longlong *)0x0) {
        *(undefined4 *)(pcVar9 + 0x28) = 0x17e;
        plVar15 = (longlong *)FUN_23e91a870(param_1,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar15 != (longlong *)0x0) {
          plStack_e8 = (longlong *)FUN_23ebf7180(plVar15);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (plStack_e8 != (longlong *)0x0) {
            lVar17 = *(longlong *)(param_1 + 0x10);
            if (*(int *)(lVar17 + 0x1188) == 0) {
              plStack_f8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
            }
            else {
              iVar8 = *(int *)(lVar17 + 0x1188) + -1;
              *(int *)(lVar17 + 0x1188) = iVar8;
              plStack_f8 = *(longlong **)(lVar17 + 0xf08 + (longlong)iVar8 * 8);
              *plStack_f8 = 1;
            }
            pcVar13 = _PyRuntime_exref;
            plStack_f8[2] = 0;
            plStack_f8[4] = 0;
            lVar17 = *(longlong *)(pcVar13 + 0x1f8);
            plStack_f8[3] = 0;
            lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
            lVar18 = plStack_f8[-1];
            puVar2 = *(undefined8 **)(lVar17 + 8);
            *puVar2 = plStack_f8 + -2;
            plStack_f8[-2] = lVar17;
            plStack_f8[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar17 + 8) = plStack_f8 + -2;
            plVar10 = (longlong *)0x0;
            plStack_e0 = (longlong *)0x0;
            pcVar11 = (code *)0x0;
            while( true ) {
              pcVar13 = *(code **)(plStack_e8[1] + 0xe0);
              if (pcVar13 == (code *)0x0) break;
              plVar21 = (longlong *)(*pcVar13)(plStack_e8);
              if (plVar21 == (longlong *)0x0) goto LAB_23e8a61db;
              if ((plStack_e0 != (longlong *)0x0) &&
                 (*plStack_e0 = *plStack_e0 + -1, *plStack_e0 == 0)) {
                (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
              }
              plVar22 = (longlong *)FUN_23a388310(plVar21);
              if (plVar22 == (longlong *)0x0) {
                plVar15 = *(longlong **)(param_1 + 0x70);
                lVar17 = *(longlong *)(param_1 + 0x60);
                uVar29 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plStack_e0 = plVar21;
                goto LAB_23e8a5557;
              }
              plVar19 = (longlong *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
              plStack_e0 = (longlong *)auStack_78;
              if ((plVar19 == (longlong *)0x0) &&
                 (plVar19 = (longlong *)FUN_23a3c1b70(param_1,plStack_e0,0,2),
                 plVar19 == (longlong *)0x0)) {
                pcVar13 = (code *)0x0;
                lVar18 = *plVar22;
LAB_23e8a63de:
                plVar15 = plStack_68;
                lVar17 = auStack_78._0_8_;
                uVar29 = auStack_78._8_8_;
                auStack_78 = (undefined1  [16])0x0;
                plStack_68 = (longlong *)0x0;
                *plVar22 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(plVar22[1] + 0x30))(plVar22);
                }
                plStack_68 = (longlong *)0x0;
                auStack_78 = (undefined1  [16])0x0;
                if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                  (**(code **)(plVar19[1] + 0x30))(plVar19);
                }
                plStack_e0 = plVar21;
                if ((pcVar13 != (code *)0x0) &&
                   (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
                  (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                }
                goto LAB_23e8a5557;
              }
              pcVar13 = (code *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
              if ((pcVar13 == (code *)0x0) &&
                 (pcVar13 = (code *)FUN_23a3c1b70(param_1,plStack_e0,1,2), pcVar13 == (code *)0x0))
              {
                lVar18 = *plVar22;
                goto LAB_23e8a63de;
              }
              cVar7 = FUN_23a3884a0(param_1,plStack_e0,plVar22);
              lVar18 = *plVar22;
              if (cVar7 == '\0') goto LAB_23e8a63de;
              *plVar22 = lVar18 + -1;
              if (lVar18 + -1 == 0) {
                (**(code **)(plVar22[1] + 0x30))(plVar22);
              }
              lVar17 = *plVar19;
              *plVar19 = lVar17 + 1;
              if (plVar10 != (longlong *)0x0) {
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                lVar17 = *plVar19 + -1;
              }
              *plVar19 = lVar17;
              if (lVar17 == 0) {
                (**(code **)(plVar19[1] + 0x30))(plVar19);
              }
              lVar17 = *(longlong *)pcVar13;
              *(longlong *)pcVar13 = lVar17 + 1;
              if (pcVar11 != (code *)0x0) {
                *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
                if (*(longlong *)pcVar11 == 0) {
                  (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
                }
                lVar17 = *(longlong *)pcVar13 + -1;
              }
              *(longlong *)pcVar13 = lVar17;
              if (lVar17 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
              }
              pcVar23 = (code *)FUN_23e8bc2f0(plVar19,_DAT_23eedc380);
              plVar10 = plVar19;
              if (pcVar23 == (code *)0x0) {
LAB_23e8a553e:
                plVar15 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                lVar17 = *(longlong *)(param_1 + 0x60);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar11 = pcVar13;
                uVar29 = *(undefined8 *)(param_1 + 0x68);
                plStack_e0 = plVar21;
                goto LAB_23e8a5557;
              }
              *(undefined4 *)(pcVar9 + 0x28) = 0x17e;
              pcVar12 = (code *)FUN_23e91a870(param_1,pcVar23);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              }
              pcVar14 = DAT_23ed6cd28;
              if (pcVar12 == (code *)0x0) goto LAB_23e8a553e;
              pcStack_d8 = pcVar9;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
                *plVar15 = *plVar15 + 1;
                DAT_23ed6a4c0 = plVar15;
              }
              pcStack_80 = pcVar14;
              pcStack_88 = pcVar12;
              lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
              if (*(longlong *)pcVar12 == 0) {
                (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
              }
              if (lVar17 == 0) goto LAB_23e8a553e;
              lVar18 = *(longlong *)(param_1 + 0x10);
              pcVar14 = *(code **)(lVar18 + 0xe28);
              if (pcVar14 == (code *)0x0) {
                pcVar14 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
              }
              else {
                lVar4 = *(longlong *)(pcVar14 + 0x18);
                *(int *)(lVar18 + 0xec0) = *(int *)(lVar18 + 0xec0) + -1;
                *(longlong *)(lVar18 + 0xe28) = lVar4;
                *(longlong *)pcVar14 = 1;
              }
              pcVar16 = _PyRuntime_exref;
              *(longlong *)(pcVar14 + 0x28) = 0;
              lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
              lVar4 = *(longlong *)(pcVar14 + -8);
              puVar2 = *(undefined8 **)(lVar18 + 8);
              *puVar2 = pcVar14 + -0x10;
              plVar15 = _DAT_23eedc388;
              uVar29 = _DAT_23eedc288;
              *(longlong *)(pcVar14 + -0x10) = lVar18;
              *(ulonglong *)(pcVar14 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
              *(code **)(lVar18 + 8) = pcVar14 + -0x10;
              *(longlong *)(pcVar14 + 0x18) = lVar17;
              *plVar15 = *plVar15 + 1;
              *(longlong **)(pcVar14 + 0x20) = plVar15;
              pcVar23 = (code *)FUN_23a38cc10(param_1,pcVar13,uVar29);
              pcVar16 = _DAT_23eedc390;
              if (pcVar23 == (code *)0x0) {
LAB_23e8a6cc8:
                auStack_78._0_8_ = *(longlong *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
                plVar15 = plStack_68;
                pcVar11 = pcVar13;
                lVar17 = auStack_78._0_8_;
                uVar29 = auStack_78._8_8_;
                plStack_e0 = plVar21;
                if (*(longlong *)pcVar14 == 0) {
                  (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
                  plVar15 = plStack_68;
                  lVar17 = auStack_78._0_8_;
                  uVar29 = auStack_78._8_8_;
                }
                goto LAB_23e8a5557;
              }
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                pcVar11 = pcVar14;
                if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
                *plVar15 = *plVar15 + 1;
                DAT_23ed6a4c0 = plVar15;
              }
              pcStack_80 = pcVar16;
              pcStack_88 = pcVar23;
              lVar17 = FUN_23e94ed00(param_1);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              }
              if (lVar17 == 0) goto LAB_23e8a6cc8;
              *(longlong *)(pcVar14 + 0x28) = lVar17;
              lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcVar14);
              *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
              if (*(longlong *)pcVar14 == 0) {
                (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
              }
              if (lVar17 == 0) goto LAB_23e8a553e;
              lVar4 = plStack_f8[2];
              lVar25 = plStack_f8[3];
              lVar18 = lVar4 + 1;
              if ((plStack_f8[4] < lVar18) || (lVar18 < plStack_f8[4] >> 1)) {
                if (lVar18 == 0) {
                  uVar28 = 0;
                }
                else {
                  uVar28 = lVar4 + 7 + (lVar18 >> 3) & 0xfffffffffffffffc;
                }
                lVar25 = (*DAT_23ed6e610)(0);
                if (lVar25 == 0) {
                  PyErr_NoMemory();
                  goto LAB_23e8a553e;
                }
                plStack_f8[3] = lVar25;
                plStack_f8[2] = lVar18;
                plStack_f8[4] = uVar28;
              }
              else {
                plStack_f8[2] = lVar18;
              }
              *(longlong *)(lVar25 + lVar4 * 8) = lVar17;
              lVar18 = *(longlong *)(param_1 + 0x10);
              if ((((*(int *)(*(longlong *)(lVar18 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar18 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
                 (lVar17 = *(longlong *)(param_1 + 0x60), lVar17 != 0)) goto LAB_23e8a5737;
              if (*(int *)(lVar18 + 0x68) == 0) {
                plVar15 = *(longlong **)(param_1 + 0x90);
              }
              else {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
                plVar15 = *(longlong **)(param_1 + 0x90);
              }
              plStack_e0 = plVar21;
              pcVar11 = pcVar13;
              if (plVar15 != (longlong *)0x0) goto LAB_23e8a56af;
            }
            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                         *(undefined8 *)(plStack_e8[1] + 0x18));
LAB_23e8a61db:
            cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar7 == '\0') {
              lVar17 = *(longlong *)(param_1 + 0x60);
              uVar29 = *(undefined8 *)(param_1 + 0x68);
              plVar15 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e8a5557;
            }
            *plStack_f8 = *plStack_f8 + 1;
            lVar17 = *plStack_e8;
            *plStack_e8 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
            }
            lVar17 = *plStack_f8;
            *plStack_f8 = lVar17 + -1;
            if (lVar17 + -1 == 0) {
              (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
            }
            if ((plStack_e0 != (longlong *)0x0) &&
               (*plStack_e0 = *plStack_e0 + -1, *plStack_e0 == 0)) {
              (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
            }
            if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if ((pcVar11 != (code *)0x0) &&
               (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
              (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
            }
            plVar15 = _DAT_23eedc398;
            lVar17 = *(longlong *)(param_1 + 0x10);
            plVar10 = *(longlong **)(lVar17 + 0xe28);
            if (plVar10 == (longlong *)0x0) {
              plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
            }
            else {
              lVar18 = plVar10[3];
              *(int *)(lVar17 + 0xec0) = *(int *)(lVar17 + 0xec0) + -1;
              *(longlong *)(lVar17 + 0xe28) = lVar18;
              *plVar10 = 1;
            }
            pcVar13 = _PyRuntime_exref;
            *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
            lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
            lVar18 = plVar10[-1];
            puVar2 = *(undefined8 **)(lVar17 + 8);
            *puVar2 = plVar10 + -2;
            plVar10[-2] = lVar17;
            plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar17 + 8) = plVar10 + -2;
            *plVar15 = *plVar15 + 1;
            uVar29 = _DAT_23eedc3a0;
            plVar10[3] = (longlong)plVar15;
            lVar17 = PyUnicode_Join(uVar29,plStack_f8);
            if (lVar17 == 0) {
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
            }
            else {
              plVar10[4] = lVar17;
              plVar15 = _DAT_23eedc3a8;
              *_DAT_23eedc3a8 = *_DAT_23eedc3a8 + 1;
              plVar10[5] = (longlong)plVar15;
              lVar17 = PyUnicode_Join(DAT_23ed6cd28,plVar10);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (lVar17 != 0) {
                FUN_23e8ba4b0(pcVar20,lVar17);
                goto LAB_23e8a3917;
              }
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            plStack_e0 = (longlong *)0x0;
            pcVar16 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            pcVar14 = (code *)0x0;
            pcVar13 = (code *)0x0;
            pcStack_d0 = (code *)0x0;
            uVar26 = 0x17f;
            pcStack_d8 = (code *)0x0;
            plStack_e8 = (longlong *)0x0;
            goto LAB_23e8a50b5;
          }
        }
      }
      plVar15 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      lVar17 = *(longlong *)(param_1 + 0x60);
      uVar29 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a5059;
    }
LAB_23e8a3917:
    pcVar11 = (code *)FUN_23e8bc2f0(plVar1,DAT_23ed6ce40);
    pcVar13 = _DAT_23eedc2d8;
    lVar17 = DAT_23ed6cce8;
    if (pcVar11 == (code *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      uVar26 = 0x182;
      pcStack_d0 = (code *)0x0;
      pcStack_d8 = (code *)0x0;
      plStack_e0 = (longlong *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plStack_e8 = (longlong *)0x0;
    }
    else {
      lVar18 = *(longlong *)(param_1 + 0x10);
      iVar8 = *(int *)(lVar18 + 0x1410);
      plVar10 = *(longlong **)(DAT_23ed6cce8 + 0x20);
      *plVar10 = *plVar10 + 1;
      if (iVar8 == 0) {
        pcVar14 = (code *)FUN_23a33a530(PyDict_Type_exref);
        plVar10 = *(longlong **)(lVar17 + 0x20);
      }
      else {
        iVar8 = iVar8 + -1;
        *(int *)(lVar18 + 0x1410) = iVar8;
        pcVar14 = *(code **)(lVar18 + 0x1190 + (longlong)iVar8 * 8);
        *(longlong *)pcVar14 = 1;
      }
      lVar17 = *(longlong *)(lVar17 + 0x28);
      *(longlong *)(pcVar14 + 0x10) = 0;
      *(longlong **)(pcVar14 + 0x20) = plVar10;
      *(longlong *)(pcVar14 + 0x28) = lVar17;
      *(longlong *)(pcVar14 + 0x18) = 1;
      *(undefined4 *)(pcVar9 + 0x28) = 0x182;
      pcStack_88 = pcVar13;
      pcStack_80 = pcVar14;
      plStack_e0 = (longlong *)FUN_23e94ed00(param_1,pcVar11,&pcStack_88);
      lVar17 = *(longlong *)pcVar11;
      *(longlong *)pcVar11 = lVar17 + -1;
      if (lVar17 + -1 == 0) {
        (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
      }
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
      if (*(longlong *)pcVar14 == 0) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
      }
      if (plStack_e0 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        pcVar16 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar14 = (code *)0x0;
        pcVar13 = (code *)0x0;
        uVar26 = 0x182;
        pcStack_d0 = (code *)0x0;
        pcStack_d8 = (code *)0x0;
        plStack_e8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        iVar8 = FUN_23a35f020(plStack_e0);
        if (iVar8 == -1) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar15 = *(longlong **)(param_1 + 0x70);
          uVar26 = 0x183;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          plStack_e8 = (longlong *)0x0;
          if (iVar8 == 0) goto LAB_23e8a3a45;
          plVar10 = (longlong *)FUN_23e8bc2f0(plStack_e0,_DAT_23eedc378);
          if (plVar10 == (longlong *)0x0) {
LAB_23e8a6698:
            lVar17 = *(longlong *)(param_1 + 0x60);
            uVar29 = *(undefined8 *)(param_1 + 0x68);
            plVar15 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            *(undefined4 *)(pcVar9 + 0x28) = 0x184;
            plVar15 = (longlong *)FUN_23e91a870(param_1,plVar10);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar15 == (longlong *)0x0) goto LAB_23e8a6698;
            pcStack_d8 = (code *)FUN_23ebf7180(plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (pcStack_d8 == (code *)0x0) goto LAB_23e8a6698;
            lVar17 = *(longlong *)(param_1 + 0x10);
            if (*(int *)(lVar17 + 0x1188) == 0) {
              plStack_e8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
            }
            else {
              iVar8 = *(int *)(lVar17 + 0x1188) + -1;
              *(int *)(lVar17 + 0x1188) = iVar8;
              plStack_e8 = *(longlong **)(lVar17 + 0xf08 + (longlong)iVar8 * 8);
              *plStack_e8 = 1;
            }
            pcVar13 = _PyRuntime_exref;
            plStack_e8[2] = 0;
            plStack_e8[4] = 0;
            lVar17 = *(longlong *)(pcVar13 + 0x1f8);
            plStack_e8[3] = 0;
            lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
            lVar18 = plStack_e8[-1];
            puVar2 = *(undefined8 **)(lVar17 + 8);
            *puVar2 = plStack_e8 + -2;
            plStack_e8[-2] = lVar17;
            plStack_e8[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
            *(longlong **)(lVar17 + 8) = plStack_e8 + -2;
            pcVar23 = (code *)0x0;
            pcStack_b0 = (code *)0x0;
            pcVar11 = (code *)0x0;
            do {
              lVar17 = *(longlong *)(pcStack_d8 + 8);
              pcStack_c0 = pcVar9;
              pcStack_b8 = pcVar20;
              if (*(code **)(lVar17 + 0xe0) == (code *)0x0) goto LAB_23e8a68e8;
              pcStack_d0 = (code *)(**(code **)(lVar17 + 0xe0))(pcStack_d8);
              if (pcStack_d0 == (code *)0x0) goto LAB_23e8a691b;
              if ((pcVar23 != (code *)0x0) &&
                 (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
                (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              }
              plVar10 = (longlong *)FUN_23a388310(pcStack_d0);
              if (plVar10 == (longlong *)0x0) {
                plVar15 = *(longlong **)(param_1 + 0x70);
                lVar17 = *(longlong *)(param_1 + 0x60);
                uVar29 = *(undefined8 *)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                goto LAB_23e8a5f57;
              }
              pcVar13 = (code *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
              if ((pcVar13 == (code *)0x0) &&
                 (pcVar13 = (code *)FUN_23a3c1b70(param_1,auStack_78,0,2), pcVar13 == (code *)0x0))
              {
                lVar18 = *plVar10;
                pcVar14 = (code *)0x0;
LAB_23e8a6b41:
                plVar15 = plStack_68;
                lVar17 = auStack_78._0_8_;
                uVar29 = auStack_78._8_8_;
                auStack_78 = (undefined1  [16])0x0;
                plStack_68 = (longlong *)0x0;
                *plVar10 = lVar18 + -1;
                if (lVar18 + -1 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                plStack_68 = (longlong *)0x0;
                auStack_78 = (undefined1  [16])0x0;
                if ((pcVar13 != (code *)0x0) &&
                   (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
                  (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
                }
                if ((pcVar14 != (code *)0x0) &&
                   (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
                  (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
                }
                goto LAB_23e8a5f57;
              }
              pcVar14 = (code *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
              if ((pcVar14 == (code *)0x0) &&
                 (pcVar14 = (code *)FUN_23a3c1b70(param_1,auStack_78,1,2), pcVar14 == (code *)0x0))
              {
                lVar18 = *plVar10;
                goto LAB_23e8a6b41;
              }
              cVar7 = FUN_23a3884a0(param_1,auStack_78,plVar10);
              lVar18 = *plVar10;
              if (cVar7 == '\0') goto LAB_23e8a6b41;
              *plVar10 = lVar18 + -1;
              if (lVar18 + -1 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              lVar17 = *(longlong *)pcVar13;
              *(longlong *)pcVar13 = lVar17 + 1;
              if (pcVar11 != (code *)0x0) {
                *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
                if (*(longlong *)pcVar11 == 0) {
                  (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
                }
                lVar17 = *(longlong *)pcVar13 + -1;
              }
              *(longlong *)pcVar13 = lVar17;
              if (lVar17 == 0) {
                (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
              }
              lVar17 = *(longlong *)pcVar14;
              *(longlong *)pcVar14 = lVar17 + 1;
              if (pcStack_b0 != (code *)0x0) {
                *(longlong *)pcStack_b0 = *(longlong *)pcStack_b0 + -1;
                if (*(longlong *)pcStack_b0 == 0) {
                  (**(code **)(*(longlong *)(pcStack_b0 + 8) + 0x30))(pcStack_b0);
                }
                lVar17 = *(longlong *)pcVar14 + -1;
              }
              *(longlong *)pcVar14 = lVar17;
              if (lVar17 == 0) {
                (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
              }
              pcVar23 = (code *)FUN_23e8bc2f0(pcVar13,_DAT_23eedc380);
              pcStack_b0 = pcVar14;
              if (pcVar23 == (code *)0x0) {
LAB_23e8a5f3e:
                plVar15 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                lVar17 = *(longlong *)(param_1 + 0x60);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar11 = pcVar13;
                uVar29 = *(undefined8 *)(param_1 + 0x68);
                goto LAB_23e8a5f57;
              }
              *(undefined4 *)(pcVar9 + 0x28) = 0x184;
              pcVar12 = (code *)FUN_23e91a870(param_1,pcVar23);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              }
              pcVar16 = DAT_23ed6cd28;
              if (pcVar12 == (code *)0x0) goto LAB_23e8a5f3e;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar10 == (longlong *)0x0) goto LAB_23e8a68d0;
                *plVar10 = *plVar10 + 1;
                DAT_23ed6a4c0 = plVar10;
              }
              pcStack_80 = pcVar16;
              pcStack_88 = pcVar12;
              lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
              if (*(longlong *)pcVar12 == 0) {
                (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
              }
              if (lVar17 == 0) goto LAB_23e8a5f3e;
              lVar18 = *(longlong *)(param_1 + 0x10);
              pcVar12 = *(code **)(lVar18 + 0xe28);
              if (pcVar12 == (code *)0x0) {
                pcVar12 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
              }
              else {
                lVar4 = *(longlong *)(pcVar12 + 0x18);
                *(int *)(lVar18 + 0xec0) = *(int *)(lVar18 + 0xec0) + -1;
                *(longlong *)(lVar18 + 0xe28) = lVar4;
                *(longlong *)pcVar12 = 1;
              }
              pcVar16 = _PyRuntime_exref;
              *(longlong *)(pcVar12 + 0x28) = 0;
              lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10) + 0x2e8);
              lVar4 = *(longlong *)(pcVar12 + -8);
              puVar2 = *(undefined8 **)(lVar18 + 8);
              *puVar2 = pcVar12 + -0x10;
              plVar10 = _DAT_23eedc388;
              uVar29 = _DAT_23eedc288;
              *(longlong *)(pcVar12 + -0x10) = lVar18;
              *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
              *(code **)(lVar18 + 8) = pcVar12 + -0x10;
              *(longlong *)(pcVar12 + 0x18) = lVar17;
              *plVar10 = *plVar10 + 1;
              *(longlong **)(pcVar12 + 0x20) = plVar10;
              pcVar23 = (code *)FUN_23a38cc10(param_1,pcVar14,uVar29);
              pcVar14 = _DAT_23eedc390;
              if (pcVar23 == (code *)0x0) {
LAB_23e8a773a:
                auStack_78._0_8_ = *(longlong *)(param_1 + 0x60);
                auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
                plVar15 = plStack_68;
                pcVar11 = pcVar13;
                lVar17 = auStack_78._0_8_;
                uVar29 = auStack_78._8_8_;
                if (*(longlong *)pcVar12 == 0) {
                  (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
                  plVar15 = plStack_68;
                  lVar17 = auStack_78._0_8_;
                  uVar29 = auStack_78._8_8_;
                }
                goto LAB_23e8a5f57;
              }
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar10 == (longlong *)0x0) goto LAB_23e8a68d0;
                *plVar10 = *plVar10 + 1;
                DAT_23ed6a4c0 = plVar10;
              }
              pcStack_80 = pcVar14;
              pcStack_88 = pcVar23;
              lVar17 = FUN_23e94ed00(param_1);
              *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
              if (*(longlong *)pcVar23 == 0) {
                (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
              }
              if (lVar17 == 0) goto LAB_23e8a773a;
              *(longlong *)(pcVar12 + 0x28) = lVar17;
              lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcVar12);
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
              if (*(longlong *)pcVar12 == 0) {
                (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
              }
              if (lVar17 == 0) goto LAB_23e8a5f3e;
              lVar4 = plStack_e8[2];
              lVar25 = plStack_e8[3];
              lVar18 = lVar4 + 1;
              if ((plStack_e8[4] < lVar18) || (lVar18 < plStack_e8[4] >> 1)) {
                if (lVar18 == 0) {
                  uVar28 = 0;
                }
                else {
                  uVar28 = lVar4 + 7 + (lVar18 >> 3) & 0xfffffffffffffffc;
                }
                lVar25 = (*DAT_23ed6e610)(0);
                if (lVar25 == 0) {
                  PyErr_NoMemory();
                  goto LAB_23e8a5f3e;
                }
                plStack_e8[3] = lVar25;
                plStack_e8[2] = lVar18;
                plStack_e8[4] = uVar28;
              }
              else {
                plStack_e8[2] = lVar18;
              }
              *(longlong *)(lVar25 + lVar4 * 8) = lVar17;
              lVar18 = *(longlong *)(param_1 + 0x10);
              if ((((*(int *)(*(longlong *)(lVar18 + 0x28) + 0x160) != 0) ||
                   (*(int *)(lVar18 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
                 (lVar17 = *(longlong *)(param_1 + 0x60), lVar17 != 0)) goto LAB_23e8a6189;
              if (*(int *)(lVar18 + 0x68) == 0) {
                plVar10 = *(longlong **)(param_1 + 0x90);
              }
              else {
                PyEval_SaveThread();
                PyEval_AcquireThread(param_1);
                plVar10 = *(longlong **)(param_1 + 0x90);
              }
              pcVar23 = pcStack_d0;
              pcVar11 = pcVar13;
            } while (plVar10 == (longlong *)0x0);
            plVar15 = *(longlong **)(param_1 + 0x60);
            plVar21 = *(longlong **)(param_1 + 0x68);
            plVar22 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar10;
            *(undefined8 *)(param_1 + 0x90) = 0;
            *plVar10 = *plVar10 + 1;
            *(undefined8 *)(param_1 + 0x68) = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))();
            }
            if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
              (**(code **)(plVar22[1] + 0x30))(plVar22);
            }
            lVar17 = *(longlong *)(param_1 + 0x60);
LAB_23e8a6189:
            plVar15 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar11 = pcVar13;
            uVar29 = *(undefined8 *)(param_1 + 0x68);
LAB_23e8a5f57:
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            lVar18 = *(longlong *)pcStack_d8;
            *(longlong *)pcStack_d8 = lVar18 + -1;
            if (lVar18 + -1 == 0) {
              (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))();
            }
            lVar18 = *plStack_e8;
            *plStack_e8 = lVar18 + -1;
            if (lVar18 + -1 == 0) {
              (**(code **)(plStack_e8[1] + 0x30))();
            }
            if ((pcStack_d0 != (code *)0x0) &&
               (lVar18 = *(longlong *)pcStack_d0, *(longlong *)pcStack_d0 = lVar18 + -1,
               lVar18 + -1 == 0)) {
              (**(code **)(*(longlong *)(pcStack_d0 + 8) + 0x30))();
            }
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            if ((pcVar11 != (code *)0x0) &&
               (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
              (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
            }
            if ((pcStack_b0 != (code *)0x0) &&
               (*(longlong *)pcStack_b0 = *(longlong *)pcStack_b0 + -1, *(longlong *)pcStack_b0 == 0
               )) {
              (**(code **)(*(longlong *)(pcStack_b0 + 8) + 0x30))(pcStack_b0);
            }
          }
          uVar26 = 0x184;
          auStack_78._8_8_ = uVar29;
          auStack_78._0_8_ = lVar17;
        }
        pcVar16 = (code *)0x0;
        plVar10 = (longlong *)0x0;
        pcVar14 = (code *)0x0;
        pcVar13 = (code *)0x0;
        pcStack_d0 = (code *)0x0;
        pcStack_d8 = (code *)0x0;
        plStack_e8 = (longlong *)0x0;
        plStack_68 = plVar15;
      }
    }
    goto LAB_23e8a50b5;
  }
  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  plStack_68 = *(longlong **)(param_1 + 0x70);
  pcVar16 = (code *)0x0;
  plVar10 = (longlong *)0x0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  pcVar14 = (code *)0x0;
  pcVar13 = (code *)0x0;
  uVar27 = 0x17c;
  uVar26 = 0x17c;
  pcStack_d0 = (code *)0x0;
  pcStack_d8 = (code *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  if (plStack_68 == (longlong *)0x0) {
    plStack_68 = (longlong *)0x0;
    goto LAB_23e8a44a0;
  }
  goto LAB_23e8a50be;
LAB_23e8a56af:
  plVar22 = *(longlong **)(param_1 + 0x60);
  plVar19 = *(longlong **)(param_1 + 0x68);
  plVar3 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar15;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *plVar15 = *plVar15 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
    (**(code **)(plVar22[1] + 0x30))();
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  lVar17 = *(longlong *)(param_1 + 0x60);
LAB_23e8a5737:
  plVar15 = *(longlong **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  pcVar11 = pcVar13;
  uVar29 = *(undefined8 *)(param_1 + 0x68);
  plStack_e0 = plVar21;
LAB_23e8a5557:
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  lVar18 = *plStack_e8;
  *plStack_e8 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plStack_e8[1] + 0x30))();
  }
  lVar18 = *plStack_f8;
  *plStack_f8 = lVar18 + -1;
  if (lVar18 + -1 == 0) {
    (**(code **)(plStack_f8[1] + 0x30))();
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar18 = *plStack_e0, *plStack_e0 = lVar18 + -1, lVar18 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))();
  }
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcVar11 != (code *)0x0) &&
     (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
    (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
  }
LAB_23e8a5059:
  uVar26 = 0x17e;
  auStack_78._8_8_ = uVar29;
  auStack_78._0_8_ = lVar17;
LAB_23e8a506f:
  pcStack_d0 = (code *)0x0;
  pcVar16 = (code *)0x0;
  plVar10 = (longlong *)0x0;
  pcVar14 = (code *)0x0;
  pcStack_d8 = (code *)0x0;
  pcVar13 = (code *)0x0;
  plStack_e8 = (longlong *)0x0;
  plStack_e0 = (longlong *)0x0;
  plStack_f8 = (longlong *)0x0;
  plStack_68 = plVar15;
  goto LAB_23e8a50b5;
LAB_23e8a68d0:
  do {
    lVar17 = 0;
    PyErr_PrintEx(0);
    Py_Exit(1);
    pcStack_b0 = pcVar12;
LAB_23e8a68e8:
    PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                 *(undefined8 *)(lVar17 + 0x18));
LAB_23e8a691b:
    cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
    pcVar9 = pcStack_c0;
    pcVar20 = pcStack_b8;
    if (cVar7 == '\0') {
      lVar17 = *(longlong *)(param_1 + 0x60);
      plVar15 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      uVar29 = *(undefined8 *)(param_1 + 0x68);
      pcStack_d0 = pcVar23;
      goto LAB_23e8a5f57;
    }
    *plStack_e8 = *plStack_e8 + 1;
    lVar17 = *(longlong *)pcStack_d8;
    *(longlong *)pcStack_d8 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
    }
    lVar17 = *plStack_e8;
    *plStack_e8 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
    }
    if ((pcVar23 != (code *)0x0) &&
       (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)) {
      (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
    }
    if ((pcVar11 != (code *)0x0) &&
       (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
      (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
    }
    if ((pcStack_b0 != (code *)0x0) &&
       (lVar17 = *(longlong *)pcStack_b0, *(longlong *)pcStack_b0 = lVar17 + -1, lVar17 + -1 == 0))
    {
      (**(code **)(*(longlong *)(pcStack_b0 + 8) + 0x30))(pcStack_b0);
    }
    plVar15 = _DAT_23eedc3b0;
    lVar17 = *(longlong *)(param_1 + 0x10);
    plVar10 = *(longlong **)(lVar17 + 0xe28);
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
    }
    else {
      lVar18 = plVar10[3];
      *(int *)(lVar17 + 0xec0) = *(int *)(lVar17 + 0xec0) + -1;
      *(longlong *)(lVar17 + 0xe28) = lVar18;
      *plVar10 = 1;
    }
    pcVar13 = _PyRuntime_exref;
    *(undefined1 (*) [16])(plVar10 + 4) = (undefined1  [16])0x0;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
    lVar18 = plVar10[-1];
    puVar2 = *(undefined8 **)(lVar17 + 8);
    *puVar2 = plVar10 + -2;
    plVar10[-2] = lVar17;
    plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar17 + 8) = plVar10 + -2;
    *plVar15 = *plVar15 + 1;
    uVar29 = _DAT_23eedc3a0;
    plVar10[3] = (longlong)plVar15;
    lVar17 = PyUnicode_Join(uVar29,plStack_e8);
    if (lVar17 == 0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        FUN_23a334bc0(plVar10);
      }
LAB_23e8a8b93:
      pcStack_d8 = (code *)0x0;
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      pcStack_d0 = (code *)0x0;
      uVar26 = 0x185;
      goto LAB_23e8a50b5;
    }
    plVar10[4] = lVar17;
    plVar15 = _DAT_23eedc3a8;
    *_DAT_23eedc3a8 = *_DAT_23eedc3a8 + 1;
    plVar10[5] = (longlong)plVar15;
    lVar17 = PyUnicode_Join(DAT_23ed6cd28,plVar10);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (lVar17 == 0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a8b93;
    }
    FUN_23e8ba4b0(pcStack_b8,lVar17);
LAB_23e8a3a45:
    pcVar12 = (code *)FUN_23e8bc2f0(plVar1,DAT_23ed6ce40);
    pcVar13 = _DAT_23eedc198;
    lVar17 = DAT_23ed6cce8;
    if (pcVar12 == (code *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar14 = (code *)0x0;
      uVar26 = 0x188;
      pcStack_d0 = (code *)0x0;
      pcStack_d8 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar13 = (code *)0x0;
      goto LAB_23e8a50b5;
    }
    lVar18 = *(longlong *)(param_1 + 0x10);
    iVar8 = *(int *)(lVar18 + 0x1410);
    plVar10 = *(longlong **)(DAT_23ed6cce8 + 0x20);
    *plVar10 = *plVar10 + 1;
    if (iVar8 == 0) {
      pcVar14 = (code *)FUN_23a33a530(PyDict_Type_exref);
      plVar10 = *(longlong **)(lVar17 + 0x20);
    }
    else {
      iVar8 = iVar8 + -1;
      *(int *)(lVar18 + 0x1410) = iVar8;
      pcVar14 = *(code **)(lVar18 + 0x1190 + (longlong)iVar8 * 8);
      *(longlong *)pcVar14 = 1;
    }
    lVar17 = *(longlong *)(lVar17 + 0x28);
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x20) = plVar10;
    *(longlong *)(pcVar14 + 0x28) = lVar17;
    *(longlong *)(pcVar14 + 0x18) = 1;
    *(undefined4 *)(pcVar9 + 0x28) = 0x188;
    pcStack_88 = pcVar13;
    pcStack_80 = pcVar14;
    pcStack_d8 = (code *)FUN_23e94ed00(param_1,pcVar12,&pcStack_88);
    *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
    if (*(longlong *)pcVar12 == 0) {
      (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))(pcVar12);
    }
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
    if (*(longlong *)pcVar14 == 0) {
      (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
    }
    if (pcStack_d8 == (code *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      uVar26 = 0x188;
      pcStack_d0 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    iVar8 = FUN_23a35f020(pcStack_d8);
    plVar10 = _DAT_23eedc3b8;
    if (iVar8 == -1) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      uVar26 = 0x189;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8a6ca8:
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      pcStack_d0 = (code *)0x0;
      goto LAB_23e8a50b5;
    }
    if (iVar8 != 0) {
      lVar17 = *(longlong *)(param_1 + 0x10);
      plVar15 = *(longlong **)(lVar17 + 0xe28);
      if (plVar15 == (longlong *)0x0) {
        plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
      }
      else {
        lVar18 = plVar15[3];
        *(int *)(lVar17 + 0xec0) = *(int *)(lVar17 + 0xec0) + -1;
        *(longlong *)(lVar17 + 0xe28) = lVar18;
        *plVar15 = 1;
      }
      pcVar13 = _PyRuntime_exref;
      *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
      lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar13 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = plVar15[-1];
      puVar2 = *(undefined8 **)(lVar17 + 8);
      *puVar2 = plVar15 + -2;
      pcVar13 = _DAT_23eedc198;
      plVar15[-2] = lVar17;
      plVar15[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar17 + 8) = plVar15 + -2;
      *plVar10 = *plVar10 + 1;
      plVar15[3] = (longlong)plVar10;
      plVar10 = (longlong *)FUN_23a38cc10(param_1,pcStack_d8,pcVar13);
      if (plVar10 != (longlong *)0x0) {
        pcVar23 = (code *)FUN_23a38cc10(param_1,plVar10,_DAT_23eedc288);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        pcVar13 = _DAT_23eedc390;
        if (pcVar23 != (code *)0x0) {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar10 == (longlong *)0x0) goto LAB_23e8a68d0;
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a4c0 = plVar10;
          }
          pcStack_80 = pcVar13;
          pcStack_88 = pcVar23;
          lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
          if (*(longlong *)pcVar23 == 0) {
            (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
          }
          plVar10 = _DAT_23eedc3a8;
          if (lVar17 != 0) {
            plVar15[4] = lVar17;
            *plVar10 = *plVar10 + 1;
            plVar15[5] = (longlong)plVar10;
            lVar17 = PyUnicode_Join(DAT_23ed6cd28,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (lVar17 != 0) {
              FUN_23e8ba4b0(pcVar20,lVar17);
              goto LAB_23e8a3b53;
            }
            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            pcVar16 = (code *)0x0;
            plVar10 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcVar14 = (code *)0x0;
            uVar26 = 0x18a;
            pcStack_d0 = (code *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar13 = (code *)0x0;
            goto LAB_23e8a50b5;
          }
        }
      }
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      uVar26 = 0x18a;
      goto LAB_23e8a6ca8;
    }
LAB_23e8a3b53:
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed6ce40);
    pcVar13 = _DAT_23eedc2f0;
    lVar17 = DAT_23ed6cce8;
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      uVar26 = 0x18d;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcStack_d0 = (code *)0x0;
      goto LAB_23e8a50b5;
    }
    lVar18 = *(longlong *)(param_1 + 0x10);
    iVar8 = *(int *)(lVar18 + 0x1410);
    plVar15 = *(longlong **)(DAT_23ed6cce8 + 0x20);
    *plVar15 = *plVar15 + 1;
    if (iVar8 == 0) {
      pcVar14 = (code *)FUN_23a33a530(PyDict_Type_exref);
      plVar15 = *(longlong **)(lVar17 + 0x20);
    }
    else {
      iVar8 = iVar8 + -1;
      *(int *)(lVar18 + 0x1410) = iVar8;
      pcVar14 = *(code **)(lVar18 + 0x1190 + (longlong)iVar8 * 8);
      *(longlong *)pcVar14 = 1;
    }
    lVar17 = *(longlong *)(lVar17 + 0x28);
    *(longlong *)(pcVar14 + 0x10) = 0;
    *(longlong **)(pcVar14 + 0x20) = plVar15;
    *(longlong *)(pcVar14 + 0x28) = lVar17;
    *(longlong *)(pcVar14 + 0x18) = 1;
    *(undefined4 *)(pcVar9 + 0x28) = 0x18d;
    pcStack_88 = pcVar13;
    pcStack_80 = pcVar14;
    pcVar13 = (code *)FUN_23e94ed00(param_1,plVar10,&pcStack_88);
    lVar17 = *plVar10;
    *plVar10 = lVar17 + -1;
    if (lVar17 + -1 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
    if (*(longlong *)pcVar14 == 0) {
      (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
    }
    if (pcVar13 == (code *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar14 = (code *)0x0;
      uVar26 = 0x18d;
      pcStack_d0 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    iVar8 = FUN_23a35f020(pcVar13);
    if (iVar8 == -1) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar26 = 0x18e;
      pcVar14 = (code *)0x0;
      pcStack_d0 = (code *)0x0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    pcStack_d0 = (code *)0x0;
    if (iVar8 != 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(pcVar13,_DAT_23eedc378);
      if (plVar10 == (longlong *)0x0) {
LAB_23e8a76b0:
        lVar17 = *(longlong *)(param_1 + 0x60);
        uVar29 = *(undefined8 *)(param_1 + 0x68);
        plVar15 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(pcVar9 + 0x28) = 399;
        plVar15 = (longlong *)FUN_23e91a870(param_1,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar15 == (longlong *)0x0) goto LAB_23e8a76b0;
        pcStack_c0 = (code *)FUN_23ebf7180(plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (pcStack_c0 == (code *)0x0) goto LAB_23e8a76b0;
        lVar17 = *(longlong *)(param_1 + 0x10);
        if (*(int *)(lVar17 + 0x1188) == 0) {
          pcStack_d0 = (code *)FUN_23a33a530(PyList_Type_exref);
        }
        else {
          iVar8 = *(int *)(lVar17 + 0x1188) + -1;
          *(int *)(lVar17 + 0x1188) = iVar8;
          pcStack_d0 = *(code **)(lVar17 + 0xf08 + (longlong)iVar8 * 8);
          *(longlong *)pcStack_d0 = 1;
        }
        pcVar14 = _PyRuntime_exref;
        *(longlong *)((longlong)pcStack_d0 + 0x10) = 0;
        *(longlong *)((longlong)pcStack_d0 + 0x20) = 0;
        lVar17 = *(longlong *)(pcVar14 + 0x1f8);
        *(longlong *)((longlong)pcStack_d0 + 0x18) = 0;
        lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
        pcStack_b8 = *(code **)((longlong)pcStack_d0 + -8);
        puVar2 = *(undefined8 **)(lVar17 + 8);
        *puVar2 = (longlong *)((longlong)pcStack_d0 + -0x10);
        *(longlong *)((longlong)pcStack_d0 + -0x10) = lVar17;
        *(ulonglong *)((longlong)pcStack_d0 + -8) =
             (ulonglong)((uint)pcStack_b8 & 3) | (ulonglong)puVar2;
        *(longlong **)(lVar17 + 8) = (longlong *)((longlong)pcStack_d0 + -0x10);
        plVar10 = (longlong *)0x0;
        pcVar14 = (code *)0x0;
        pcVar11 = (code *)0x0;
        while( true ) {
          pcVar16 = *(code **)(*(longlong *)(pcStack_c0 + 8) + 0xe0);
          pcStack_c8 = (code *)plVar10;
          if (pcVar16 == (code *)0x0) break;
          pcVar12 = (code *)(*pcVar16)(pcStack_c0);
          if (pcVar12 == (code *)0x0) goto LAB_23e8a7b33;
          if ((pcVar14 != (code *)0x0) &&
             (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
          }
          plVar21 = (longlong *)FUN_23a388310(pcVar12);
          if (plVar21 == (longlong *)0x0) {
            lVar17 = *(longlong *)(param_1 + 0x60);
            plVar15 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar29 = *(undefined8 *)(param_1 + 0x68);
            pcStack_b8 = pcVar12;
            goto LAB_23e8a6e76;
          }
          pcStack_c8 = (code *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
          pcStack_b8 = (code *)auStack_78;
          if ((pcStack_c8 == (code *)0x0) &&
             (pcStack_c8 = (code *)FUN_23a3c1b70(param_1,pcStack_b8,0,2), pcStack_c8 == (code *)0x0)
             ) {
            lVar18 = *plVar21;
            pcVar23 = (code *)0x0;
LAB_23e8a7ced:
            plVar15 = plStack_68;
            lVar17 = auStack_78._0_8_;
            uVar29 = auStack_78._8_8_;
            auStack_78 = (undefined1  [16])0x0;
            plStack_68 = (longlong *)0x0;
            *plVar21 = lVar18 + -1;
            if (lVar18 + -1 == 0) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            if ((pcStack_c8 != (code *)0x0) &&
               (lVar18 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar18 + -1,
               lVar18 + -1 == 0)) {
              (**(code **)(*(longlong *)((longlong)pcStack_c8 + 8) + 0x30))(pcStack_c8);
            }
            pcStack_c8 = (code *)plVar10;
            pcStack_b8 = pcVar12;
            if ((pcVar23 != (code *)0x0) &&
               (lVar18 = *(longlong *)pcVar23, *(longlong *)pcVar23 = lVar18 + -1, lVar18 + -1 == 0)
               ) {
              (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
            }
            goto LAB_23e8a6e76;
          }
          pcVar23 = (code *)(**(code **)(plVar21[1] + 0xe0))(plVar21);
          if ((pcVar23 == (code *)0x0) &&
             (pcVar23 = (code *)FUN_23a3c1b70(param_1,pcStack_b8,1,2), pcVar23 == (code *)0x0)) {
            lVar18 = *plVar21;
            goto LAB_23e8a7ced;
          }
          cVar7 = FUN_23a3884a0(param_1,pcStack_b8,plVar21);
          lVar18 = *plVar21;
          if (cVar7 == '\0') goto LAB_23e8a7ced;
          *plVar21 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            (**(code **)(plVar21[1] + 0x30))(plVar21);
          }
          lVar17 = *(longlong *)pcStack_c8;
          *(longlong *)pcStack_c8 = lVar17 + 1;
          if (plVar10 != (longlong *)0x0) {
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            lVar17 = *(longlong *)pcStack_c8 + -1;
          }
          *(longlong *)pcStack_c8 = lVar17;
          if (lVar17 == 0) {
            (**(code **)(*(longlong *)((longlong)pcStack_c8 + 8) + 0x30))(pcStack_c8);
          }
          lVar17 = *(longlong *)pcVar23;
          *(longlong *)pcVar23 = lVar17 + 1;
          if (pcVar11 != (code *)0x0) {
            *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
            if (*(longlong *)pcVar11 == 0) {
              (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
            }
            lVar17 = *(longlong *)pcVar23 + -1;
          }
          *(longlong *)pcVar23 = lVar17;
          if (lVar17 == 0) {
            (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(pcStack_c8,_DAT_23eedc380);
          if (plVar10 == (longlong *)0x0) goto LAB_23e8a6e5d;
          *(undefined4 *)(pcVar9 + 0x28) = 399;
          pcVar14 = (code *)FUN_23e91a870(param_1,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          pcVar16 = DAT_23ed6cd28;
          if (pcVar14 == (code *)0x0) goto LAB_23e8a6e5d;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar10 == (longlong *)0x0) goto LAB_23e8a68d0;
            *plVar10 = *plVar10 + 1;
            DAT_23ed6a4c0 = plVar10;
          }
          pcStack_80 = pcVar16;
          pcStack_88 = pcVar14;
          lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
          *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
          if (*(longlong *)pcVar14 == 0) {
            (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
          }
          if (lVar17 == 0) goto LAB_23e8a6e5d;
          lVar18 = *(longlong *)(param_1 + 0x10);
          plVar10 = *(longlong **)(lVar18 + 0xe28);
          if (plVar10 == (longlong *)0x0) {
            plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar4 = plVar10[3];
            *(int *)(lVar18 + 0xec0) = *(int *)(lVar18 + 0xec0) + -1;
            *(longlong *)(lVar18 + 0xe28) = lVar4;
            *plVar10 = 1;
          }
          pcVar14 = _PyRuntime_exref;
          plVar10[5] = 0;
          lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar14 + 0x1f8) + 0x10) + 0x2e8);
          lVar4 = plVar10[-1];
          puVar2 = *(undefined8 **)(lVar18 + 8);
          *puVar2 = plVar10 + -2;
          plVar15 = _DAT_23eedc388;
          uVar29 = _DAT_23eedc288;
          plVar10[-2] = lVar18;
          plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar18 + 8) = plVar10 + -2;
          plVar10[3] = lVar17;
          *plVar15 = *plVar15 + 1;
          plVar10[4] = (longlong)plVar15;
          pcVar16 = (code *)FUN_23a38cc10(param_1,pcVar23,uVar29);
          pcVar14 = _DAT_23eedc390;
          if (pcVar16 == (code *)0x0) {
LAB_23e8a88b6:
            auStack_78._0_8_ = *(longlong *)(param_1 + 0x60);
            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar10 = *plVar10 + -1;
            plVar15 = plStack_68;
            pcVar11 = pcVar23;
            lVar17 = auStack_78._0_8_;
            uVar29 = auStack_78._8_8_;
            pcStack_b8 = pcVar12;
            if (*plVar10 == 0) {
              FUN_23a334bc0(plVar10);
              plVar15 = plStack_68;
              lVar17 = auStack_78._0_8_;
              uVar29 = auStack_78._8_8_;
            }
            goto LAB_23e8a6e76;
          }
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
            *plVar15 = *plVar15 + 1;
            DAT_23ed6a4c0 = plVar15;
          }
          pcStack_80 = pcVar14;
          pcStack_88 = pcVar16;
          lVar17 = FUN_23e94ed00(param_1);
          *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
          if (*(longlong *)pcVar16 == 0) {
            (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
          }
          if (lVar17 == 0) goto LAB_23e8a88b6;
          plVar10[5] = lVar17;
          lVar17 = PyUnicode_Join(DAT_23ed6cd28,plVar10);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (lVar17 == 0) goto LAB_23e8a6e5d;
          lVar4 = *(longlong *)((longlong)pcStack_d0 + 0x10);
          lVar25 = *(longlong *)((longlong)pcStack_d0 + 0x18);
          lVar18 = lVar4 + 1;
          if ((*(longlong *)((longlong)pcStack_d0 + 0x20) < lVar18) ||
             (lVar18 < *(longlong *)((longlong)pcStack_d0 + 0x20) >> 1)) {
            if (lVar18 == 0) {
              pcStack_b8 = (code *)0x0;
            }
            else {
              pcStack_b8 = (code *)(lVar4 + 7 + (lVar18 >> 3) & 0xfffffffffffffffc);
            }
            lVar25 = (*DAT_23ed6e610)(0);
            if (lVar25 == 0) {
              PyErr_NoMemory();
              goto LAB_23e8a6e5d;
            }
            *(longlong *)((longlong)pcStack_d0 + 0x18) = lVar25;
            *(longlong *)((longlong)pcStack_d0 + 0x10) = lVar18;
            *(code **)((longlong)pcStack_d0 + 0x20) = pcStack_b8;
          }
          else {
            *(longlong *)((longlong)pcStack_d0 + 0x10) = lVar18;
          }
          *(longlong *)(lVar25 + lVar4 * 8) = lVar17;
          lVar17 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar17 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e8a6e5d;
          if (*(int *)(lVar17 + 0x68) == 0) {
            plVar15 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar15 = *(longlong **)(param_1 + 0x90);
          }
          plVar10 = (longlong *)pcStack_c8;
          pcVar14 = pcVar12;
          pcVar11 = pcVar23;
          if (plVar15 != (longlong *)0x0) {
            plVar10 = *(longlong **)(param_1 + 0x60);
            plVar21 = *(longlong **)(param_1 + 0x68);
            plVar22 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar15;
            *(undefined8 *)(param_1 + 0x90) = 0;
            *plVar15 = *plVar15 + 1;
            *(undefined8 *)(param_1 + 0x68) = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
              (**(code **)(plVar10[1] + 0x30))();
            }
            if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
              (**(code **)(plVar22[1] + 0x30))(plVar22);
            }
LAB_23e8a6e5d:
            plVar15 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            lVar17 = *(longlong *)(param_1 + 0x60);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar11 = pcVar23;
            uVar29 = *(undefined8 *)(param_1 + 0x68);
            pcStack_b8 = pcVar12;
            goto LAB_23e8a6e76;
          }
        }
        PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                     *(undefined8 *)(*(longlong *)(pcStack_c0 + 8) + 0x18));
LAB_23e8a7b33:
        cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
        if (cVar7 != '\0') {
          *(longlong *)pcStack_d0 = *(longlong *)pcStack_d0 + 1;
          lVar17 = *(longlong *)pcStack_c0;
          *(longlong *)pcStack_c0 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            FUN_23a334bc0(pcStack_c0);
          }
          lVar17 = *(longlong *)pcStack_d0;
          *(longlong *)pcStack_d0 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            FUN_23a334bc0(pcStack_d0);
          }
          if ((pcVar14 != (code *)0x0) &&
             (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
            FUN_23a334bc0(pcVar14);
          }
          if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
            FUN_23a334bc0(plVar10);
          }
          if ((pcVar11 != (code *)0x0) &&
             (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
            FUN_23a334bc0(pcVar11);
          }
          plVar10 = _DAT_23eedc3c0;
          plVar15 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
          *plVar10 = *plVar10 + 1;
          plVar15[3] = (longlong)plVar10;
          lVar17 = PyUnicode_Join(_DAT_23eedc3a0,pcStack_d0);
          if (lVar17 == 0) {
            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar15 = *plVar15 + -1;
            pcVar14 = (code *)0x0;
            if (*plVar15 == 0) {
              pcVar16 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              FUN_23a334bc0(plVar15);
              uVar26 = 400;
            }
            else {
              pcVar16 = (code *)0x0;
              plVar10 = (longlong *)0x0;
              uVar26 = 400;
            }
          }
          else {
            plVar15[4] = lVar17;
            plVar10 = _DAT_23eedc3a8;
            *_DAT_23eedc3a8 = *_DAT_23eedc3a8 + 1;
            plVar15[5] = (longlong)plVar10;
            lVar17 = PyUnicode_Join(DAT_23ed6cd28,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              FUN_23a334bc0(plVar15);
            }
            if (lVar17 != 0) {
              FUN_23e8ba4b0(pcVar20,lVar17);
              goto LAB_23e8a3c70;
            }
            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            pcVar16 = (code *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar10 = (longlong *)0x0;
            uVar26 = 400;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar14 = (code *)0x0;
          }
          goto LAB_23e8a50b5;
        }
        lVar17 = *(longlong *)(param_1 + 0x60);
        plVar15 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar29 = *(undefined8 *)(param_1 + 0x68);
        pcStack_b8 = pcVar14;
LAB_23e8a6e76:
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        lVar18 = *(longlong *)pcStack_c0;
        *(longlong *)pcStack_c0 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))(pcStack_c0);
        }
        lVar18 = *(longlong *)pcStack_d0;
        *(longlong *)pcStack_d0 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(*(longlong *)((longlong)pcStack_d0 + 8) + 0x30))(pcStack_d0);
        }
        if ((pcStack_b8 != (code *)0x0) &&
           (lVar18 = *(longlong *)pcStack_b8, *(longlong *)pcStack_b8 = lVar18 + -1,
           lVar18 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
        }
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        if ((pcStack_c8 != (code *)0x0) &&
           (lVar18 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar18 + -1,
           lVar18 + -1 == 0)) {
          (**(code **)(*(longlong *)((longlong)pcStack_c8 + 8) + 0x30))(pcStack_c8);
        }
        if ((pcVar11 != (code *)0x0) &&
           (lVar18 = *(longlong *)pcVar11, *(longlong *)pcVar11 = lVar18 + -1, lVar18 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
        }
      }
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      pcVar14 = (code *)0x0;
      auStack_78._8_8_ = uVar29;
      auStack_78._0_8_ = lVar17;
      uVar26 = 399;
      pcStack_d0 = (code *)0x0;
      plStack_68 = plVar15;
      goto LAB_23e8a50b5;
    }
LAB_23e8a3c70:
    plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed6ce40);
    pcVar14 = _DAT_23eedc300;
    lVar17 = DAT_23ed6cce8;
    if (plVar10 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      pcVar14 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar26 = 0x193;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = (longlong *)0x0;
      goto LAB_23e8a50b5;
    }
    lVar18 = *(longlong *)(param_1 + 0x10);
    iVar8 = *(int *)(lVar18 + 0x1410);
    plVar15 = *(longlong **)(DAT_23ed6cce8 + 0x20);
    *plVar15 = *plVar15 + 1;
    if (iVar8 == 0) {
      pcVar23 = (code *)FUN_23a33a530(PyDict_Type_exref);
      plVar15 = *(longlong **)(lVar17 + 0x20);
    }
    else {
      iVar8 = iVar8 + -1;
      *(int *)(lVar18 + 0x1410) = iVar8;
      pcVar23 = *(code **)(lVar18 + 0x1190 + (longlong)iVar8 * 8);
      *(longlong *)pcVar23 = 1;
    }
    lVar17 = *(longlong *)(lVar17 + 0x28);
    *(longlong *)(pcVar23 + 0x10) = 0;
    *(longlong **)(pcVar23 + 0x20) = plVar15;
    *(longlong *)(pcVar23 + 0x28) = lVar17;
    *(longlong *)(pcVar23 + 0x18) = 1;
    *(undefined4 *)(pcVar9 + 0x28) = 0x193;
    pcStack_88 = pcVar14;
    pcStack_80 = pcVar23;
    pcVar14 = (code *)FUN_23e94ed00(param_1,plVar10,&pcStack_88);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
    if (*(longlong *)pcVar23 == 0) {
      (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
    }
    if (pcVar14 == (code *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar26 = 0x193;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    iVar8 = FUN_23a35f020(pcVar14);
    if (iVar8 == -1) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar26 = 0x194;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    plVar10 = (longlong *)0x0;
    if (iVar8 != 0) {
      plVar10 = (longlong *)FUN_23e8bc2f0(pcVar14,_DAT_23eedc378);
      if (plVar10 == (longlong *)0x0) {
LAB_23e8a7f0d:
        lVar17 = *(longlong *)(param_1 + 0x60);
        uVar29 = *(undefined8 *)(param_1 + 0x68);
        plVar15 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      else {
        *(undefined4 *)(pcVar9 + 0x28) = 0x195;
        plVar15 = (longlong *)FUN_23e91a870(param_1,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar15 == (longlong *)0x0) goto LAB_23e8a7f0d;
        pcStack_c0 = (code *)FUN_23ebf7180(plVar15);
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        if (pcStack_c0 == (code *)0x0) goto LAB_23e8a7f0d;
        lVar17 = *(longlong *)(param_1 + 0x10);
        if (*(int *)(lVar17 + 0x1188) == 0) {
          plVar10 = (longlong *)FUN_23a33a530(PyList_Type_exref);
        }
        else {
          iVar8 = *(int *)(lVar17 + 0x1188) + -1;
          *(int *)(lVar17 + 0x1188) = iVar8;
          plVar10 = *(longlong **)(lVar17 + 0xf08 + (longlong)iVar8 * 8);
          *plVar10 = 1;
        }
        pcVar16 = _PyRuntime_exref;
        plVar10[2] = 0;
        plVar10[4] = 0;
        lVar17 = *(longlong *)(*(longlong *)(pcVar16 + 0x1f8) + 0x10);
        plVar10[3] = 0;
        lVar17 = *(longlong *)(lVar17 + 0x2e8);
        lVar18 = plVar10[-1];
        puVar2 = *(undefined8 **)(lVar17 + 8);
        *puVar2 = plVar10 + -2;
        plVar10[-2] = lVar17;
        plVar10[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
        *(longlong **)(lVar17 + 8) = plVar10 + -2;
        pcStack_c8 = (code *)0x0;
        plVar21 = (longlong *)0x0;
        pcVar16 = (code *)0x0;
        while( true ) {
          pcVar11 = *(code **)(*(longlong *)(pcStack_c0 + 8) + 0xe0);
          pcStack_b0 = (code *)plVar21;
          if (pcVar11 == (code *)0x0) break;
          pcVar12 = (code *)(*pcVar11)(pcStack_c0);
          if (pcVar12 == (code *)0x0) goto LAB_23e8a84b2;
          if ((pcStack_c8 != (code *)0x0) &&
             (*(longlong *)pcStack_c8 = *(longlong *)pcStack_c8 + -1, *(longlong *)pcStack_c8 == 0))
          {
            (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))(pcStack_c8);
          }
          plVar22 = (longlong *)FUN_23a388310(pcVar12);
          pcStack_c8 = pcVar12;
          if (plVar22 == (longlong *)0x0) {
            lVar17 = *(longlong *)(param_1 + 0x60);
            plVar15 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar29 = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e8a7889;
          }
          pcStack_b0 = (code *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
          if ((pcStack_b0 == (code *)0x0) &&
             (pcStack_b0 = (code *)FUN_23a3c1b70(param_1,auStack_78,0,2), plVar15 = plStack_68,
             pcStack_b0 == (code *)0x0)) {
            lVar17 = auStack_78._0_8_;
            uVar29 = auStack_78._8_8_;
            auStack_78 = (undefined1  [16])0x0;
            plStack_68 = (longlong *)0x0;
            *plVar22 = *plVar22 + -1;
            pcStack_b0 = (code *)plVar21;
            if (*plVar22 == 0) {
              FUN_23a334bc0(plVar22);
            }
            goto LAB_23e8a7889;
          }
          pcVar23 = (code *)(**(code **)(plVar22[1] + 0xe0))(plVar22);
          if ((pcVar23 == (code *)0x0) &&
             (pcVar23 = (code *)FUN_23a3c1b70(param_1,auStack_78,1,2), pcVar23 == (code *)0x0)) {
            lVar18 = *plVar22;
LAB_23e8a876e:
            plVar15 = plStack_68;
            lVar17 = auStack_78._0_8_;
            uVar29 = auStack_78._8_8_;
            auStack_78 = (undefined1  [16])0x0;
            plStack_68 = (longlong *)0x0;
            *plVar22 = lVar18 + -1;
            if (lVar18 + -1 == 0) {
              FUN_23a334bc0(plVar22);
            }
            plStack_68 = (longlong *)0x0;
            auStack_78 = (undefined1  [16])0x0;
            lVar18 = *(longlong *)pcStack_b0;
            *(longlong *)pcStack_b0 = lVar18 + -1;
            if (lVar18 + -1 == 0) {
              FUN_23a334bc0();
            }
            pcStack_b0 = (code *)plVar21;
            if ((pcVar23 != (code *)0x0) &&
               (lVar18 = *(longlong *)pcVar23, *(longlong *)pcVar23 = lVar18 + -1, lVar18 + -1 == 0)
               ) {
              FUN_23a334bc0(pcVar23);
            }
            goto LAB_23e8a7889;
          }
          cVar7 = FUN_23a3884a0(param_1,auStack_78);
          lVar18 = *plVar22;
          if (cVar7 == '\0') goto LAB_23e8a876e;
          *plVar22 = lVar18 + -1;
          if (lVar18 + -1 == 0) {
            (**(code **)(plVar22[1] + 0x30))(plVar22);
          }
          lVar17 = *(longlong *)pcStack_b0;
          *(longlong *)pcStack_b0 = lVar17 + 1;
          if (plVar21 != (longlong *)0x0) {
            *plVar21 = *plVar21 + -1;
            if (*plVar21 == 0) {
              (**(code **)(plVar21[1] + 0x30))(plVar21);
            }
            lVar17 = *(longlong *)pcStack_b0 + -1;
          }
          *(longlong *)pcStack_b0 = lVar17;
          if (lVar17 == 0) {
            (**(code **)(*(longlong *)((longlong)pcStack_b0 + 8) + 0x30))(pcStack_b0);
          }
          lVar17 = *(longlong *)pcVar23;
          *(longlong *)pcVar23 = lVar17 + 1;
          if (pcVar16 != (code *)0x0) {
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
            if (*(longlong *)pcVar16 == 0) {
              (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
            }
            lVar17 = *(longlong *)pcVar23 + -1;
          }
          *(longlong *)pcVar23 = lVar17;
          if (lVar17 == 0) {
            (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(pcStack_b0,_DAT_23eedc380);
          pcVar16 = pcVar23;
          if (plVar15 == (longlong *)0x0) goto LAB_23e8a7870;
          *(undefined4 *)(pcVar9 + 0x28) = 0x195;
          pcVar11 = (code *)FUN_23e91a870(param_1,plVar15);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          pcVar5 = DAT_23ed6cd28;
          if (pcVar11 == (code *)0x0) goto LAB_23e8a7870;
          pcStack_b8 = pcVar9;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
            *plVar15 = *plVar15 + 1;
            DAT_23ed6a4c0 = plVar15;
          }
          pcStack_80 = pcVar5;
          pcStack_88 = pcVar11;
          lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
          *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
          if (*(longlong *)pcVar11 == 0) {
            (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          }
          if (lVar17 == 0) goto LAB_23e8a7870;
          lVar18 = *(longlong *)(param_1 + 0x10);
          pcVar11 = *(code **)(lVar18 + 0xe28);
          if (pcVar11 == (code *)0x0) {
            pcVar11 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar4 = *(longlong *)(pcVar11 + 0x18);
            *(int *)(lVar18 + 0xec0) = *(int *)(lVar18 + 0xec0) + -1;
            *(longlong *)(lVar18 + 0xe28) = lVar4;
            *(longlong *)pcVar11 = 1;
          }
          pcVar5 = _PyRuntime_exref;
          *(longlong *)(pcVar11 + 0x28) = 0;
          lVar18 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
          lVar4 = *(longlong *)(pcVar11 + -8);
          puVar2 = *(undefined8 **)(lVar18 + 8);
          *puVar2 = pcVar11 + -0x10;
          plVar15 = _DAT_23eedc388;
          uVar29 = _DAT_23eedc288;
          *(longlong *)(pcVar11 + -0x10) = lVar18;
          *(ulonglong *)(pcVar11 + -8) = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar2;
          *(code **)(lVar18 + 8) = pcVar11 + -0x10;
          *(longlong *)(pcVar11 + 0x18) = lVar17;
          *plVar15 = *plVar15 + 1;
          *(longlong **)(pcVar11 + 0x20) = plVar15;
          pcVar24 = (code *)FUN_23a38cc10(param_1,pcVar23,uVar29);
          pcVar5 = _DAT_23eedc390;
          if (pcVar24 == (code *)0x0) {
LAB_23e8a8be1:
            auStack_78._0_8_ = *(longlong *)(param_1 + 0x60);
            auStack_78._8_8_ = *(undefined8 *)(param_1 + 0x68);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
            plVar15 = plStack_68;
            lVar17 = auStack_78._0_8_;
            uVar29 = auStack_78._8_8_;
            if (*(longlong *)pcVar11 == 0) {
              FUN_23a334bc0(pcVar11);
              plVar15 = plStack_68;
              lVar17 = auStack_78._0_8_;
              uVar29 = auStack_78._8_8_;
            }
            goto LAB_23e8a7889;
          }
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
            *plVar15 = *plVar15 + 1;
            DAT_23ed6a4c0 = plVar15;
          }
          pcStack_80 = pcVar5;
          pcStack_88 = pcVar24;
          lVar17 = FUN_23e94ed00();
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
          if (*(longlong *)pcVar24 == 0) {
            (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))();
          }
          if (lVar17 == 0) goto LAB_23e8a8be1;
          *(longlong *)(pcVar11 + 0x28) = lVar17;
          lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcVar11);
          *(longlong *)pcVar11 = *(longlong *)pcVar11 + -1;
          if (*(longlong *)pcVar11 == 0) {
            (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
          }
          if (lVar17 == 0) goto LAB_23e8a7870;
          lVar4 = plVar10[2];
          lVar25 = plVar10[3];
          lVar18 = lVar4 + 1;
          if ((plVar10[4] < lVar18) || (lVar18 < plVar10[4] >> 1)) {
            if (lVar18 == 0) {
              uVar28 = 0;
            }
            else {
              uVar28 = lVar4 + 7 + (lVar18 >> 3) & 0xfffffffffffffffc;
            }
            lVar25 = (*DAT_23ed6e610)(0);
            if (lVar25 == 0) {
              PyErr_NoMemory();
              goto LAB_23e8a7870;
            }
            plVar10[3] = lVar25;
            plVar10[2] = lVar18;
            plVar10[4] = uVar28;
          }
          else {
            plVar10[2] = lVar18;
          }
          *(longlong *)(lVar25 + lVar4 * 8) = lVar17;
          lVar17 = *(longlong *)(param_1 + 0x10);
          if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) != 0) ||
               (*(int *)(lVar17 + 0x78) != 0)) && (iVar8 = Py_MakePendingCalls(), iVar8 < 0)) &&
             (*(longlong *)(param_1 + 0x60) != 0)) goto LAB_23e8a7870;
          if (*(int *)(lVar17 + 0x68) == 0) {
            plVar15 = *(longlong **)(param_1 + 0x90);
          }
          else {
            PyEval_SaveThread();
            PyEval_AcquireThread(param_1);
            plVar15 = *(longlong **)(param_1 + 0x90);
          }
          plVar21 = (longlong *)pcStack_b0;
          if (plVar15 != (longlong *)0x0) {
            plVar21 = *(longlong **)(param_1 + 0x60);
            plVar22 = *(longlong **)(param_1 + 0x68);
            plVar19 = *(longlong **)(param_1 + 0x70);
            *(longlong **)(param_1 + 0x60) = plVar15;
            *(undefined8 *)(param_1 + 0x90) = 0;
            *plVar15 = *plVar15 + 1;
            *(undefined8 *)(param_1 + 0x68) = 0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            if ((plVar21 != (longlong *)0x0) && (*plVar21 = *plVar21 + -1, *plVar21 == 0)) {
              (**(code **)(plVar21[1] + 0x30))();
            }
            if ((plVar22 != (longlong *)0x0) && (*plVar22 = *plVar22 + -1, *plVar22 == 0)) {
              (**(code **)(plVar22[1] + 0x30))(plVar22);
            }
            if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
              (**(code **)(plVar19[1] + 0x30))(plVar19);
            }
LAB_23e8a7870:
            plVar15 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            lVar17 = *(longlong *)(param_1 + 0x60);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            uVar29 = *(undefined8 *)(param_1 + 0x68);
            goto LAB_23e8a7889;
          }
        }
        PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                     *(undefined8 *)(*(longlong *)(pcStack_c0 + 8) + 0x18));
LAB_23e8a84b2:
        cVar7 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
        if (cVar7 != '\0') {
          *plVar10 = *plVar10 + 1;
          lVar17 = *(longlong *)pcStack_c0;
          *(longlong *)pcStack_c0 = lVar17 + -1;
          if (lVar17 + -1 == 0) {
            FUN_23a334bc0(pcStack_c0);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            FUN_23a334bc0(plVar10);
          }
          if ((pcStack_c8 != (code *)0x0) &&
             (*(longlong *)pcStack_c8 = *(longlong *)pcStack_c8 + -1, *(longlong *)pcStack_c8 == 0))
          {
            FUN_23a334bc0(pcStack_c8);
          }
          if ((plVar21 != (longlong *)0x0) &&
             (lVar17 = *plVar21, *plVar21 = lVar17 + -1, lVar17 + -1 == 0)) {
            FUN_23a334bc0(plVar21);
          }
          if ((pcVar16 != (code *)0x0) &&
             (lVar17 = *(longlong *)pcVar16, *(longlong *)pcVar16 = lVar17 + -1, lVar17 + -1 == 0))
          {
            FUN_23a334bc0(pcVar16);
          }
          plVar15 = _DAT_23eedc3c8;
          pcStack_b8 = (code *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),3);
          *plVar15 = *plVar15 + 1;
          *(longlong **)(pcStack_b8 + 0x18) = plVar15;
          lVar17 = PyUnicode_Join(_DAT_23eedc3a0,plVar10);
          if (lVar17 == 0) {
            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            uVar26 = 0x196;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1;
            pcVar16 = (code *)0x0;
            if (*(longlong *)pcStack_b8 == 0) {
              FUN_23a334bc0(pcStack_b8);
              uVar26 = 0x196;
            }
          }
          else {
            *(longlong *)(pcStack_b8 + 0x20) = lVar17;
            plVar15 = _DAT_23eedc3a8;
            *_DAT_23eedc3a8 = *_DAT_23eedc3a8 + 1;
            *(longlong **)(pcStack_b8 + 0x28) = plVar15;
            lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcStack_b8);
            *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1;
            if (*(longlong *)pcStack_b8 == 0) {
              FUN_23a334bc0(pcStack_b8);
            }
            if (lVar17 != 0) {
              FUN_23e8ba4b0(pcVar20,lVar17);
              goto LAB_23e8a3d75;
            }
            auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
            plStack_68 = *(longlong **)(param_1 + 0x70);
            uVar26 = 0x196;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            pcVar16 = (code *)0x0;
          }
          goto LAB_23e8a50b5;
        }
        lVar17 = *(longlong *)(param_1 + 0x60);
        plVar15 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        uVar29 = *(undefined8 *)(param_1 + 0x68);
LAB_23e8a7889:
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        lVar18 = *(longlong *)pcStack_c0;
        *(longlong *)pcStack_c0 = lVar18 + -1;
        if (lVar18 + -1 == 0) {
          (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))();
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if ((pcStack_c8 != (code *)0x0) &&
           (lVar18 = *(longlong *)pcStack_c8, *(longlong *)pcStack_c8 = lVar18 + -1,
           lVar18 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_c8 + 8) + 0x30))(pcStack_c8);
        }
        plStack_68 = (longlong *)0x0;
        auStack_78 = (undefined1  [16])0x0;
        if ((pcStack_b0 != (code *)0x0) &&
           (lVar18 = *(longlong *)pcStack_b0, *(longlong *)pcStack_b0 = lVar18 + -1,
           lVar18 + -1 == 0)) {
          (**(code **)(*(longlong *)((longlong)pcStack_b0 + 8) + 0x30))(pcStack_b0);
        }
        if ((pcVar16 != (code *)0x0) &&
           (lVar18 = *(longlong *)pcVar16, *(longlong *)pcVar16 = lVar18 + -1, lVar18 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
        }
      }
      uVar26 = 0x195;
      pcVar16 = (code *)0x0;
      plVar10 = (longlong *)0x0;
      auStack_78._8_8_ = uVar29;
      auStack_78._0_8_ = lVar17;
      plStack_68 = plVar15;
      goto LAB_23e8a50b5;
    }
LAB_23e8a3d75:
    plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ed6ce40);
    if (plVar15 == (longlong *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      pcVar16 = (code *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar26 = 0x199;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    *(undefined4 *)(pcVar9 + 0x28) = 0x199;
    pcVar16 = (code *)FUN_23e9557e0(param_1,plVar15,_DAT_23eedc3d0);
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    plVar15 = _DAT_23eedc3d8;
    if (pcVar16 == (code *)0x0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      uVar26 = 0x199;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    lVar17 = *(longlong *)(param_1 + 0x10);
    pcStack_c0 = *(code **)(lVar17 + 0xe20);
    if (pcStack_c0 == (code *)0x0) {
      pcStack_c0 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar18 = *(longlong *)(pcStack_c0 + 0x18);
      *(int *)(lVar17 + 0xebc) = *(int *)(lVar17 + 0xebc) + -1;
      *(longlong *)(lVar17 + 0xe20) = lVar18;
      *(longlong *)pcStack_c0 = 1;
    }
    pcVar11 = _PyRuntime_exref;
    *(longlong *)(pcStack_c0 + 0x20) = 0;
    pcVar5 = _DAT_23eedc3e0;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar11 + 0x1f8) + 0x10) + 0x2e8);
    lVar18 = *(longlong *)(pcStack_c0 + -8);
    puVar2 = *(undefined8 **)(lVar17 + 8);
    *puVar2 = pcStack_c0 + -0x10;
    *(longlong *)(pcStack_c0 + -0x10) = lVar17;
    *(ulonglong *)(pcStack_c0 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(code **)(lVar17 + 8) = pcStack_c0 + -0x10;
    plVar21 = DAT_23ed6a4c0;
    *plVar15 = *plVar15 + 1;
    *(longlong **)(pcStack_c0 + 0x18) = plVar15;
    pcVar11 = pcVar14;
    pcVar12 = pcVar13;
    if (plVar21 == (longlong *)0x0) {
      plVar21 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar21 == (longlong *)0x0) goto LAB_23e8a68d0;
      *plVar21 = *plVar21 + 1;
      DAT_23ed6a4c0 = plVar21;
    }
    pcStack_80 = pcVar5;
    pcStack_88 = pcVar16;
    lVar17 = FUN_23e94ed00(param_1,plVar21,&pcStack_88);
    if (lVar17 == 0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      uVar26 = 0x19a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + -1;
      if (*(longlong *)pcStack_c0 == 0) {
        (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))(pcStack_c0);
        uVar26 = 0x19a;
      }
      goto LAB_23e8a50b5;
    }
    *(longlong *)(pcStack_c0 + 0x20) = lVar17;
    pcVar23 = PyUnicode_Join_exref;
    lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcStack_c0);
    *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + -1;
    if (*(longlong *)pcStack_c0 == 0) {
      (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))(pcStack_c0);
    }
    if (lVar17 == 0) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      uVar26 = 0x19a;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e8a50b5;
    }
    FUN_23e8ba4b0(pcVar20,lVar17);
    plVar15 = (longlong *)FUN_23e8bd600(param_1,pcVar20);
    lVar17 = *plVar15 + -1;
    if (plVar15[2] != 1) {
      *plVar15 = lVar17;
LAB_23e8a3f39:
      if (lVar17 == 0) {
        (**(code **)(plVar15[1] + 0x30))();
      }
      plVar15 = _DAT_23eedc3e8;
      lVar17 = *(longlong *)(param_1 + 0x10);
      pcStack_b8 = *(code **)(lVar17 + 0xe30);
      if (pcStack_b8 == (code *)0x0) {
        pcStack_b8 = (code *)FUN_23e916a20(PyTuple_Type_exref,4);
      }
      else {
        lVar18 = *(longlong *)(pcStack_b8 + 0x18);
        *(int *)(lVar17 + 0xec4) = *(int *)(lVar17 + 0xec4) + -1;
        *(longlong *)(lVar17 + 0xe30) = lVar18;
        *(longlong *)pcStack_b8 = 1;
      }
      pcVar5 = _PyRuntime_exref;
      *(longlong *)(pcStack_b8 + 0x30) = 0;
      *(undefined1 (*) [16])(pcStack_b8 + 0x20) = (undefined1  [16])0x0;
      lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
      lVar18 = *(longlong *)(pcStack_b8 + -8);
      puVar2 = *(undefined8 **)(lVar17 + 8);
      *puVar2 = pcStack_b8 + -0x10;
      *(longlong *)(pcStack_b8 + -0x10) = lVar17;
      *(ulonglong *)(pcStack_b8 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
      *(code **)(lVar17 + 8) = pcStack_b8 + -0x10;
      *plVar15 = *plVar15 + 1;
      *(longlong **)(pcStack_b8 + 0x18) = plVar15;
      lVar18 = FUN_23e8db3c0();
      lVar17 = _DAT_23eedc3f8;
      if (lVar18 == 0) {
        FUN_23e915740(param_1,auStack_78,_DAT_23eedc100);
      }
      else {
        *(undefined4 *)(pcVar9 + 0x28) = 0x19f;
        pcStack_c0 = (code *)FUN_23e915840(param_1,lVar18,_DAT_23eedc3f0,
                                           *(undefined8 *)(lVar17 + 0x18));
        pcVar5 = DAT_23ed6cd28;
        if (pcStack_c0 == (code *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        else {
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
            *plVar15 = *plVar15 + 1;
            DAT_23ed6a4c0 = plVar15;
          }
          pcStack_80 = pcVar5;
          pcStack_88 = pcStack_c0;
          lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
          *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + -1;
          if (*(longlong *)pcStack_c0 == 0) {
            (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))(pcStack_c0);
          }
          if (lVar17 != 0) {
            *(longlong *)(pcStack_b8 + 0x20) = lVar17;
            uVar29 = _DAT_23eedc410;
            plVar15 = _DAT_23eedc408;
            *_DAT_23eedc408 = *_DAT_23eedc408 + 1;
            *(longlong **)(pcStack_b8 + 0x28) = plVar15;
            lVar17 = PyUnicode_Join(uVar29,pcVar20);
            if (lVar17 != 0) {
              *(longlong *)(pcStack_b8 + 0x30) = lVar17;
              lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcStack_b8);
              *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1;
              if (*(longlong *)pcStack_b8 == 0) {
                (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
              }
              if (lVar17 != 0) goto LAB_23e8a4148;
              auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
              plStack_68 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uVar26 = 0x19f;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e8a50b5;
            }
          }
          plStack_68 = *(longlong **)(param_1 + 0x70);
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
      }
      *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1;
      if (*(longlong *)pcStack_b8 == 0) {
        (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
      }
      uVar26 = 0x19f;
      goto LAB_23e8a50b5;
    }
    *plVar15 = lVar17;
    if ((int)plVar15[3] != 1) goto LAB_23e8a3f39;
    if (lVar17 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
    plVar15 = _DAT_23eedc3e8;
    lVar17 = *(longlong *)(param_1 + 0x10);
    pcStack_b8 = *(code **)(lVar17 + 0xe30);
    if (pcStack_b8 == (code *)0x0) {
      pcStack_b8 = (code *)FUN_23e916a20(PyTuple_Type_exref,4);
    }
    else {
      lVar18 = *(longlong *)(pcStack_b8 + 0x18);
      *(int *)(lVar17 + 0xec4) = *(int *)(lVar17 + 0xec4) + -1;
      *(longlong *)(lVar17 + 0xe30) = lVar18;
      *(longlong *)pcStack_b8 = 1;
    }
    pcVar5 = _PyRuntime_exref;
    *(longlong *)(pcStack_b8 + 0x30) = 0;
    *(undefined1 (*) [16])(pcStack_b8 + 0x20) = (undefined1  [16])0x0;
    lVar17 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar5 + 0x1f8) + 0x10) + 0x2e8);
    lVar18 = *(longlong *)(pcStack_b8 + -8);
    puVar2 = *(undefined8 **)(lVar17 + 8);
    *puVar2 = pcStack_b8 + -0x10;
    *(longlong *)(pcStack_b8 + -0x10) = lVar17;
    *(ulonglong *)(pcStack_b8 + -8) = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(code **)(lVar17 + 8) = pcStack_b8 + -0x10;
    *plVar15 = *plVar15 + 1;
    *(longlong **)(pcStack_b8 + 0x18) = plVar15;
    lVar18 = FUN_23e8db3c0();
    lVar17 = _DAT_23eedc3f8;
    if (lVar18 == 0) {
      FUN_23e915740(param_1,auStack_78,_DAT_23eedc100);
      goto LAB_23e8a8995;
    }
    *(undefined4 *)(pcVar9 + 0x28) = 0x19d;
    pcStack_c0 = (code *)FUN_23e915840(param_1,lVar18,_DAT_23eedc3f0,*(undefined8 *)(lVar17 + 0x18))
    ;
    pcVar5 = DAT_23ed6cd28;
    if (pcStack_c0 == (code *)0x0) {
      plStack_68 = *(longlong **)(param_1 + 0x70);
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e8a8995;
    }
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar15 == (longlong *)0x0) goto LAB_23e8a68d0;
      *plVar15 = *plVar15 + 1;
      DAT_23ed6a4c0 = plVar15;
    }
    pcStack_80 = pcVar5;
    pcStack_88 = pcStack_c0;
    lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
    *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + -1;
    if (*(longlong *)pcStack_c0 == 0) {
      (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))(pcStack_c0);
    }
    if (lVar17 == 0) goto LAB_23e8a896c;
    *(longlong *)(pcStack_b8 + 0x20) = lVar17;
    plVar15 = _DAT_23eedc400;
    *_DAT_23eedc400 = *_DAT_23eedc400 + 1;
    *(longlong **)(pcStack_b8 + 0x28) = plVar15;
    pcStack_c0 = (code *)FUN_23a388650(param_1,pcVar20,DAT_23ed6ccf0,0);
    pcVar5 = DAT_23ed6cd28;
    if (pcStack_c0 == (code *)0x0) goto LAB_23e8a896c;
    if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23e8a82e1;
    plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
  } while (plVar15 == (longlong *)0x0);
  *plVar15 = *plVar15 + 1;
  DAT_23ed6a4c0 = plVar15;
LAB_23e8a82e1:
  pcStack_80 = pcVar5;
  pcStack_88 = pcStack_c0;
  lVar17 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&pcStack_88);
  *(longlong *)pcStack_c0 = *(longlong *)pcStack_c0 + -1;
  if (*(longlong *)pcStack_c0 == 0) {
    (**(code **)(*(longlong *)(pcStack_c0 + 8) + 0x30))(pcStack_c0);
  }
  if (lVar17 == 0) {
LAB_23e8a896c:
    plStack_68 = *(longlong **)(param_1 + 0x70);
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e8a8995:
    *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1;
    if (*(longlong *)pcStack_b8 == 0) {
      (**(code **)(*(longlong *)(pcStack_b8 + 8) + 0x30))(pcStack_b8);
    }
    uVar26 = 0x19d;
  }
  else {
    *(longlong *)(pcStack_b8 + 0x30) = lVar17;
    lVar17 = PyUnicode_Join(DAT_23ed6cd28,pcStack_b8);
    *(longlong *)pcStack_b8 = *(longlong *)pcStack_b8 + -1;
    if (*(longlong *)pcStack_b8 == 0) {
      FUN_23a334bc0(pcStack_b8);
    }
    if (lVar17 != 0) {
LAB_23e8a4148:
      lVar18 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar15 = *(longlong **)(lVar18 + 0x28);
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar18 + 0x30);
      plVar21 = (longlong *)plVar15[2];
      *(undefined4 *)(plVar15 + 8) = 0xffffffff;
      if (plVar21 != (longlong *)0x0) {
        plVar15[2] = 0;
        *plVar21 = *plVar21 + -1;
        if (*plVar21 == 0) {
          (**(code **)(plVar21[1] + 0x30))();
        }
      }
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      plVar15[0xf] = 0;
      *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
      if (*(longlong *)pcVar20 == 0) {
        (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
      }
      lVar18 = *plStack_f0;
      *plStack_f0 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(plStack_f0[1] + 0x30))(plStack_f0);
      }
      if ((plStack_f8 != (longlong *)0x0) &&
         (lVar18 = *plStack_f8, *plStack_f8 = lVar18 + -1, lVar18 + -1 == 0)) {
        (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
      }
      lVar18 = *plStack_e0;
      *plStack_e0 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
      }
      if ((plStack_e8 != (longlong *)0x0) &&
         (lVar18 = *plStack_e8, *plStack_e8 = lVar18 + -1, lVar18 + -1 == 0)) {
        (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
      }
      lVar18 = *(longlong *)pcStack_d8;
      *(longlong *)pcStack_d8 = lVar18 + -1;
      if (lVar18 + -1 == 0) {
        (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
      }
      *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
      if (*(longlong *)pcVar13 == 0) {
        (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
      }
      if ((pcStack_d0 != (code *)0x0) &&
         (lVar18 = *(longlong *)pcStack_d0, *(longlong *)pcStack_d0 = lVar18 + -1, lVar18 + -1 == 0)
         ) {
        (**(code **)(*(longlong *)((longlong)pcStack_d0 + 8) + 0x30))(pcStack_d0);
      }
      *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
      if (*(longlong *)pcVar14 == 0) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
      }
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + -1;
      if (*(longlong *)pcVar16 == 0) {
        (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
      }
      lVar18 = *plVar1;
      *plVar1 = lVar18 + -1;
      if (lVar18 + -1 != 0) {
        return lVar17;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return lVar17;
    }
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    uVar26 = 0x19d;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
LAB_23e8a50b5:
  uVar27 = uVar26;
  if (plStack_68 == (longlong *)0x0) {
LAB_23e8a44a0:
    plVar15 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar21 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar11 = _PyRuntime_exref;
    plVar15[2] = 0;
    plVar15[3] = (longlong)pcVar9;
    *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
    lVar17 = *(longlong *)(pcVar11 + 0x1f8);
    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar26;
    lVar17 = *(longlong *)(lVar17 + 0x10);
    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
    lVar17 = *(longlong *)(lVar17 + 0x2e8);
    lVar18 = plVar15[-1];
    puVar2 = *(undefined8 **)(lVar17 + 8);
    *puVar2 = plVar15 + -2;
    plVar15[-2] = lVar17;
    plVar15[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar17 + 8) = plVar15 + -2;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else {
LAB_23e8a50be:
    plVar15 = plStack_68;
    plVar21 = DAT_23ed6a4f8;
    if ((code *)plStack_68[3] != pcVar9) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar21 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar22 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar11 = _PyRuntime_exref;
      plVar21[3] = (longlong)pcVar9;
      *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
      lVar17 = *(longlong *)(pcVar11 + 0x1f8);
      *(undefined4 *)((longlong)plVar21 + 0x24) = uVar27;
      *(undefined4 *)(plVar21 + 4) = 0xffffffff;
      lVar17 = *(longlong *)(*(longlong *)(lVar17 + 0x10) + 0x2e8);
      lVar18 = plVar21[-1];
      puVar2 = *(undefined8 **)(lVar17 + 8);
      *puVar2 = plVar21 + -2;
      plVar21[-2] = lVar17;
      plVar21[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar17 + 8) = plVar21 + -2;
      plVar21[2] = (longlong)plVar15;
      *plVar15 = *plVar15 + 1;
      plVar15 = plVar21;
      if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
        (**(code **)(plStack_68[1] + 0x30))(plStack_68);
      }
    }
  }
  plStack_68 = plVar15;
  FUN_23e8bba40(pcVar9,"oooooooooooo",plVar1,pcVar20,plStack_f0,plStack_f8,plStack_e0,plStack_e8,
                pcStack_d8,pcVar13,pcStack_d0,pcVar14,plVar10,pcVar16);
  if (_DAT_23eede410 == pcVar9) {
    *(longlong *)pcVar9 = *(longlong *)pcVar9 + -1;
    if (*(longlong *)pcVar9 == 0) {
      (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
    }
    _DAT_23eede410 = (code *)0x0;
  }
  lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar15 = *(longlong **)(lVar17 + 0x28);
  plVar21 = (longlong *)plVar15[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar17 + 0x30);
  *(undefined4 *)(plVar15 + 8) = 0xffffffff;
  if (plVar21 != (longlong *)0x0) {
    plVar15[2] = 0;
    *plVar21 = *plVar21 + -1;
    if (*plVar21 == 0) {
      (**(code **)(plVar21[1] + 0x30))();
    }
  }
  *plVar15 = *plVar15 + -1;
  if (*plVar15 == 0) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  plVar21 = plStack_68;
  plVar15[0xf] = 0;
  uVar29 = auStack_78._0_8_;
  uVar6 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  *(longlong *)pcVar20 = *(longlong *)pcVar20 + -1;
  if (*(longlong *)pcVar20 == 0) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
  }
  if ((plStack_f0 != (longlong *)0x0) &&
     (lVar17 = *plStack_f0, *plStack_f0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_f0[1] + 0x30))();
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar17 = *plStack_f8, *plStack_f8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar17 = *plStack_e0, *plStack_e0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))();
  }
  if ((plStack_e8 != (longlong *)0x0) &&
     (lVar17 = *plStack_e8, *plStack_e8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(plStack_e8[1] + 0x30))(plStack_e8);
  }
  if ((pcStack_d8 != (code *)0x0) &&
     (lVar17 = *(longlong *)pcStack_d8, *(longlong *)pcStack_d8 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_d8 + 8) + 0x30))(pcStack_d8);
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)(pcVar13 + 8) + 0x30))(pcVar13);
  }
  if ((pcStack_d0 != (code *)0x0) &&
     (lVar17 = *(longlong *)pcStack_d0, *(longlong *)pcStack_d0 = lVar17 + -1, lVar17 + -1 == 0)) {
    (**(code **)(*(longlong *)((longlong)pcStack_d0 + 8) + 0x30))();
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((pcVar16 != (code *)0x0) &&
     (*(longlong *)pcVar16 = *(longlong *)pcVar16 + -1, *(longlong *)pcVar16 == 0)) {
    (**(code **)(*(longlong *)(pcVar16 + 8) + 0x30))(pcVar16);
  }
  lVar17 = *plVar1;
  *plVar1 = lVar17 + -1;
  plStack_68 = plVar21;
  auStack_78._0_8_ = uVar29;
  auStack_78._8_8_ = uVar6;
  if (lVar17 + -1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68);
  return 0;
}
