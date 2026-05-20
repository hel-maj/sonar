/* ===== 23aaff5a0 __parents_main__:419 ===== */
/* ghidra_name=FUN_23aaff5a0 entry=23aaff5a0 size=8593 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23aaff5a0(longlong param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong *plVar6;
  undefined1 auVar7 [16];
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  undefined8 uVar17;
  code *pcVar18;
  longlong lVar19;
  code *pcVar20;
  code *pcVar21;
  int iVar22;
  code *pcVar23;
  code *pcVar24;
  code *unaff_R12;
  longlong *plVar25;
  longlong *unaff_R15;
  undefined8 uVar26;
  longlong *plStack_100;
  longlong *plStack_f8;
  code *pcStack_f0;
  undefined1 auStack_c8 [16];
  code *apcStack_b8 [2];
  undefined1 auStack_a8 [16];
  code *pcStack_98;
  longlong lStack_88;
  longlong *plStack_80;
  code *pcStack_78;
  code *pcStack_70;
  undefined8 uStack_68;
  
  pcVar20 = _Py_NoneStruct_exref;
  pcStack_98 = (code *)0x0;
  auStack_a8 = (undefined1  [16])0x0;
  if ((DAT_23ed6a210 == (longlong *)0x0) &&
     (DAT_23ed6a210 = (longlong *)PyImport_ImportModule(&DAT_23ec31700),
     DAT_23ed6a210 == (longlong *)0x0)) goto LAB_23ab00cc5;
  plVar5 = DAT_23ed6a210;
  *DAT_23ed6a210 = *DAT_23ed6a210 + 1;
  if ((DAT_23ed7bc00 == (longlong *)0x0) &&
     (DAT_23ed7bc00 = (longlong *)PyImport_ImportModule("builtins"),
     DAT_23ed7bc00 == (longlong *)0x0)) goto LAB_23ab00d07;
  plVar9 = _DAT_23ed90a10;
  plVar6 = DAT_23ed7bc00;
  *DAT_23ed7bc00 = *DAT_23ed7bc00 + 1;
  if (plVar9 == (longlong *)0x0) {
LAB_23aaff652:
    plVar9 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ed90a08,DAT_23ed90b40,0x40);
    _DAT_23ed90a10 = plVar9;
  }
  else {
    lVar19 = *plVar9;
    if (1 < lVar19) {
      *plVar9 = lVar19 + -1;
      goto LAB_23aaff652;
    }
    if (plVar9[2] != 0) {
      *plVar9 = lVar19 + -1;
      if (lVar19 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23aaff652;
    }
  }
  lVar19 = *(longlong *)(param_1 + 0x38);
  lVar16 = *(longlong *)(lVar19 + 8);
  plVar9[0xf] = lVar16;
  *(longlong **)(lVar19 + 8) = plVar9 + 9;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar9[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar9[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *(undefined4 *)(plVar9 + 8) = 0;
  lStack_88 = _DAT_23ed8f8a8;
  *plVar9 = *plVar9 + 1;
  uStack_68 = DAT_23ed6ccf0;
  plVar10 = DAT_23ed6a498;
  *(undefined4 *)(plVar9 + 5) = 0x1a8;
  pcStack_78 = pcVar20;
  pcStack_70 = pcVar20;
  plStack_80 = DAT_23ed8f338;
  if (plVar10 != (longlong *)0x0) {
LAB_23aaff721:
    unaff_R15 = &lStack_88;
    plStack_100 = (longlong *)FUN_23e95b390(param_1,plVar10,unaff_R15);
    if (plStack_100 == (longlong *)0x0) {
      auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      pcStack_98 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_98 == (code *)0x0) {
        pcStack_f0 = _PyRuntime_exref;
        plVar25 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        unaff_R12 = (code *)0x0;
        iVar22 = 0x1a8;
        goto LAB_23ab0114a;
      }
      if (plVar9 != *(longlong **)(pcStack_98 + 0x18)) {
        plVar25 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        unaff_R12 = (code *)0x0;
        iVar22 = 0x1a8;
        pcStack_f0 = _PyRuntime_exref;
        goto LAB_23ab00060;
      }
LAB_23ab00c80:
      plVar25 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      unaff_R12 = (code *)0x0;
      plStack_f8 = (longlong *)0x0;
      pcVar20 = pcStack_98;
      goto LAB_23ab00109;
    }
    plVar10 = (longlong *)
              FUN_23e93e1e0(0,DAT_23ed8f8b0,DAT_23ed8f8b8,_DAT_23ed90a00,0,0,DAT_23ed90b40,0,0,0);
    plVar11 = (longlong *)FUN_23e8bc2f0(plStack_100,_DAT_23ed8f8c0);
    if (plVar11 != (longlong *)0x0) {
      cVar8 = FUN_23e8d9ac0(plVar11,_DAT_23ed8f8c8,plVar10);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      lVar19 = DAT_23ed6cce8;
      if (cVar8 == '\0') {
        auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_98 == (code *)0x0) goto LAB_23ab01120;
        if (plVar9 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23ab00c80;
        plVar25 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        plStack_f8 = (longlong *)0x0;
        unaff_R12 = (code *)0x0;
        iVar22 = 0x1a9;
        pcStack_f0 = _PyRuntime_exref;
        goto LAB_23ab00060;
      }
      lVar16 = *(longlong *)(param_1 + 0x10);
      iVar22 = *(int *)(lVar16 + 0x1410);
      plVar10 = *(longlong **)(DAT_23ed6cce8 + 0x20);
      *plVar10 = *plVar10 + 1;
      if (iVar22 == 0) {
        unaff_R12 = (code *)FUN_23a33a530(PyDict_Type_exref);
        lVar16 = *(longlong *)(param_1 + 0x10);
        plVar10 = *(longlong **)(lVar19 + 0x20);
      }
      else {
        iVar22 = iVar22 + -1;
        *(int *)(lVar16 + 0x1410) = iVar22;
        unaff_R12 = *(code **)(lVar16 + 0x1190 + (longlong)iVar22 * 8);
        *(longlong *)unaff_R12 = 1;
      }
      lVar19 = *(longlong *)(lVar19 + 0x28);
      *(longlong *)(unaff_R12 + 0x10) = 0;
      *(longlong **)(unaff_R12 + 0x20) = plVar10;
      *(longlong *)(unaff_R12 + 0x28) = lVar19;
      iVar22 = *(int *)(lVar16 + 0x1188);
      *(longlong *)(unaff_R12 + 0x18) = 1;
      if (iVar22 == 0) {
        plStack_f8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
      }
      else {
        iVar22 = iVar22 + -1;
        *(int *)(lVar16 + 0x1188) = iVar22;
        plStack_f8 = *(longlong **)(lVar16 + 0xf08 + (longlong)iVar22 * 8);
        *plStack_f8 = 1;
      }
      pcStack_f0 = _PyRuntime_exref;
      plStack_f8[2] = 0;
      plStack_f8[4] = 0;
      lVar19 = *(longlong *)(pcStack_f0 + 0x1f8);
      plStack_f8[3] = 0;
      lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
      lVar16 = plStack_f8[-1];
      puVar2 = *(undefined8 **)(lVar19 + 8);
      *puVar2 = plStack_f8 + -2;
      plStack_f8[-2] = lVar19;
      plStack_f8[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar19 + 8) = plStack_f8 + -2;
      if ((DAT_23ed7bc00 == (longlong *)0x0) &&
         (DAT_23ed7bc00 = (longlong *)PyImport_ImportModule("builtins"),
         DAT_23ed7bc00 == (longlong *)0x0)) {
        DAT_23ed7bc00 = (longlong *)0x0;
        goto LAB_23ab00d07;
      }
      iVar22 = FUN_23e8be270(param_1,DAT_23ed7bc00,_DAT_23ed8f8d0);
      if (iVar22 == -1) {
        auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_98 == (code *)0x0) {
          plVar25 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          iVar22 = 0x1a5;
          goto LAB_23ab0114a;
        }
        if (plVar9 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23ab014d0;
        plVar25 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        iVar22 = 0x1a5;
        goto LAB_23ab00060;
      }
      if (iVar22 == 0) goto LAB_23aaff922;
      if ((DAT_23ed7bc00 == (longlong *)0x0) &&
         (DAT_23ed7bc00 = (longlong *)PyImport_ImportModule("builtins"),
         DAT_23ed7bc00 == (longlong *)0x0)) {
        DAT_23ed7bc00 = (longlong *)0x0;
        goto LAB_23ab00d07;
      }
      plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed7bc00,_DAT_23ed8f8d0);
      if (plVar10 == (longlong *)0x0) {
        auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_98 != (code *)0x0) {
          if (*(longlong **)(pcStack_98 + 0x18) != plVar9) {
            plVar25 = (longlong *)0x0;
            plVar11 = (longlong *)0x0;
            iVar22 = 0x1b1;
            plVar10 = (longlong *)0x0;
            goto LAB_23ab00060;
          }
          goto LAB_23ab014d0;
        }
      }
      else {
        if ((DAT_23ed6a210 == (longlong *)0x0) &&
           (DAT_23ed6a210 = (longlong *)PyImport_ImportModule(&DAT_23ec31700),
           DAT_23ed6a210 == (longlong *)0x0)) {
          DAT_23ed6a210 = (longlong *)0x0;
          goto LAB_23ab00cc5;
        }
        cVar8 = FUN_23e8d9ac0(DAT_23ed6a210,DAT_23ed8f3f0,plVar10);
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (cVar8 != '\0') {
          if (DAT_23ed7bc00 == (longlong *)0x0) goto LAB_23ab015d7;
          goto LAB_23ab00f10;
        }
        auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_98 != (code *)0x0) {
          if (plVar9 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23ab014d0;
          plVar25 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          iVar22 = 0x1b1;
          goto LAB_23ab00060;
        }
      }
      plVar25 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      iVar22 = 0x1b1;
      goto LAB_23ab0114a;
    }
    auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    pcStack_98 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
      if (pcStack_98 != (code *)0x0) {
        plVar10 = *(longlong **)(pcStack_98 + 0x18);
joined_r0x00023ab00f8d:
        if (plVar10 != plVar9) {
          plVar25 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          plVar10 = (longlong *)0x0;
          plStack_f8 = (longlong *)0x0;
          iVar22 = 0x1a9;
          unaff_R12 = (code *)0x0;
          pcStack_f0 = _PyRuntime_exref;
          goto LAB_23ab00060;
        }
        goto LAB_23ab00c80;
      }
    }
    else if (pcStack_98 != (code *)0x0) {
      plVar10 = *(longlong **)(pcStack_98 + 0x18);
      goto joined_r0x00023ab00f8d;
    }
LAB_23ab01120:
    plVar25 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plStack_f8 = (longlong *)0x0;
    unaff_R12 = (code *)0x0;
    iVar22 = 0x1a9;
    pcStack_f0 = _PyRuntime_exref;
    goto LAB_23ab0114a;
  }
  plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
  if (plVar10 != (longlong *)0x0) {
    *plVar10 = *plVar10 + 1;
    DAT_23ed6a498 = plVar10;
    goto LAB_23aaff721;
  }
  PyErr_PrintEx(0,0);
  Py_Exit(1);
LAB_23ab015d7:
  DAT_23ed7bc00 = (longlong *)PyImport_ImportModule("builtins");
  if (DAT_23ed7bc00 == (longlong *)0x0) {
    DAT_23ed7bc00 = (longlong *)0x0;
LAB_23ab00d07:
    FUN_23e9364c0("%s : %s\n","IMPORT_HARD_BUILTINS",
                  "\"Unexpected failure of hard import of \'builtins\'\"");
                    /* WARNING: Subroutine does not return */
    abort();
  }
LAB_23ab00f10:
  iVar22 = PyObject_SetAttr(DAT_23ed7bc00,_DAT_23ed8f8d0,0);
  if (iVar22 == -1) {
    auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
    pcStack_98 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_98 == (code *)0x0) {
      plVar25 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      iVar22 = 0x1b2;
      goto LAB_23ab0114a;
    }
    plVar25 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    iVar22 = 0x1b2;
    pcVar20 = pcStack_98;
    if (plVar9 == *(longlong **)(pcStack_98 + 0x18)) goto LAB_23ab00109;
  }
  else {
LAB_23aaff922:
    if ((DAT_23ed6a210 == (longlong *)0x0) &&
       (DAT_23ed6a210 = (longlong *)PyImport_ImportModule(&DAT_23ec31700),
       DAT_23ed6a210 == (longlong *)0x0)) {
      DAT_23ed6a210 = (longlong *)0x0;
      goto LAB_23ab00cc5;
    }
    plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,DAT_23ed8f3f0);
    if (plVar10 == (longlong *)0x0) {
      auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
      pcStack_98 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_98 == (code *)0x0) {
LAB_23ab01258:
        plVar25 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        iVar22 = 0x1b4;
        goto LAB_23ab0114a;
      }
      if (*(longlong **)(pcStack_98 + 0x18) == plVar9) goto LAB_23ab014d0;
      plVar25 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      iVar22 = 0x1b4;
      plVar10 = (longlong *)0x0;
    }
    else {
      plVar11 = (longlong *)FUN_23a38cc10(param_1,plVar10,_DAT_23ed8f8d8);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar11 == (longlong *)0x0) {
        auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_98 == (code *)0x0) goto LAB_23ab01258;
        plVar10 = *(longlong **)(pcStack_98 + 0x18);
      }
      else {
        plVar10 = (longlong *)FUN_23ebf7180(plVar11);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        plVar11 = (longlong *)0x0;
        plVar25 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        if (plVar10 != (longlong *)0x0) {
          while( true ) {
            pcVar21 = *(code **)(plVar10[1] + 0xe0);
            if (pcVar21 == (code *)0x0) break;
            plVar12 = (longlong *)(*pcVar21)(plVar10);
            if (plVar12 == (longlong *)0x0) goto LAB_23ab0090b;
            if (plVar13 == (longlong *)0x0) {
              *plVar12 = *plVar12 + 1;
            }
            else {
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
                lVar19 = *plVar12;
              }
              else {
                lVar19 = *plVar12;
              }
              *plVar12 = lVar19 + 1;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
            }
            plVar13 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23ed6d020);
            if (plVar13 == (longlong *)0x0) {
LAB_23ab00308:
              uVar17 = *(undefined8 *)(param_1 + 0x60);
              uVar26 = *(undefined8 *)(param_1 + 0x68);
              pcVar21 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23aaffb9f:
              plVar13 = *(longlong **)(param_1 + 0x138);
              pcStack_98 = (code *)0x0;
              auStack_c8._8_8_ = uVar26;
              auStack_c8._0_8_ = uVar17;
              auStack_a8 = (undefined1  [16])0x0;
              if (plVar13 != (longlong *)0x0) {
                *plVar13 = *plVar13 + 1;
              }
              pcVar18 = DAT_23ed6a4f8;
              apcStack_b8[0] = pcVar21;
              if (pcVar21 == (code *)0x0) {
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar21 = *(code **)DAT_23ed6a4f8;
                  *(longlong *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar21;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong *)(pcVar18 + 0x10) = 0;
                *(longlong **)(pcVar18 + 0x18) = plVar9;
                *plVar9 = *plVar9 + 1;
                *(longlong *)(pcVar18 + 0x20) = 0x1b6ffffffff;
                lVar19 = *(longlong *)
                          (*(longlong *)(*(longlong *)(pcStack_f0 + 0x1f8) + 0x10) + 0x2e8);
                lVar16 = *(longlong *)(pcVar18 + -8);
                puVar2 = *(undefined8 **)(lVar19 + 8);
                *puVar2 = pcVar18 + -0x10;
                *(longlong *)(pcVar18 + -0x10) = lVar19;
                *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
                *(code **)(lVar19 + 8) = pcVar18 + -0x10;
              }
              else {
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar23 = *(code **)DAT_23ed6a4f8;
                  *(longlong *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar23;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong **)(pcVar18 + 0x18) = plVar9;
                *plVar9 = *plVar9 + 1;
                *(longlong *)(pcVar18 + 0x20) = 0x1b6ffffffff;
                lVar19 = *(longlong *)
                          (*(longlong *)(*(longlong *)(pcStack_f0 + 0x1f8) + 0x10) + 0x2e8);
                lVar16 = *(longlong *)(pcVar18 + -8);
                puVar2 = *(undefined8 **)(lVar19 + 8);
                *puVar2 = pcVar18 + -0x10;
                *(longlong *)(pcVar18 + -0x10) = lVar19;
                *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
                *(code **)(lVar19 + 8) = pcVar18 + -0x10;
                *(code **)(pcVar18 + 0x10) = pcVar21;
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
              }
              if ((apcStack_b8[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + -1,
                 *(longlong *)apcStack_b8[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_b8[0] + 8) + 0x30))();
              }
              apcStack_b8[0] = pcVar18;
              if (((code *)auStack_c8._0_8_ != pcVar20) && ((code *)auStack_c8._0_8_ != (code *)0x0)
                 ) {
                FUN_23e91b1b0(param_1,auStack_c8,auStack_c8 + 8,apcStack_b8);
              }
              plVar14 = *(longlong **)(auStack_c8._8_8_ + 0x28);
              if (apcStack_b8[0] == pcVar20) {
                pcVar21 = (code *)0x0;
              }
              else {
                pcVar21 = apcStack_b8[0];
                if (apcStack_b8[0] != (code *)0x0) {
                  *(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + 1;
                }
              }
              *(code **)(auStack_c8._8_8_ + 0x28) = pcVar21;
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              plVar14 = *(longlong **)(param_1 + 0x138);
              *(undefined8 *)(param_1 + 0x138) = auStack_c8._8_8_;
              if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                (**(code **)(plVar14[1] + 0x30))();
              }
              *(longlong *)auStack_c8._0_8_ = *(longlong *)auStack_c8._0_8_ + -1;
              if (*(longlong *)auStack_c8._0_8_ == 0) {
                (**(code **)(*(longlong *)(auStack_c8._0_8_ + 8) + 0x30))();
              }
              if ((apcStack_b8[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_b8[0] = *(longlong *)apcStack_b8[0] + -1,
                 *(longlong *)apcStack_b8[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_b8[0] + 8) + 0x30))();
              }
              pcVar21 = *(code **)(param_1 + 0x138);
              apcStack_b8[0] = (code *)0x0;
              auStack_c8 = (undefined1  [16])0x0;
              pcVar18 = *(code **)PyExc_ValueError_exref;
              pcVar23 = *(code **)(pcVar21 + 8);
              if ((*(uint *)(*(longlong *)(pcVar18 + 8) + 0xa8) & 0x4000000) == 0) {
                if (((int)*(uint *)(*(longlong *)(pcVar18 + 8) + 0xa8) < 0) &&
                   (((byte)pcVar18[0xab] & 0x40) != 0)) {
                  pcVar24 = *(code **)(pcVar23 + 8);
                  pcVar1 = pcVar24 + 0xa8;
                  if ((*(uint *)pcVar1 & 0x40000000) == 0) {
                    pcVar24 = pcVar23;
                    if ((-1 < (int)*(uint *)pcVar1) || (((byte)pcVar23[0xab] & 0x40) == 0))
                    goto LAB_23ab00889;
                  }
                  else {
                    pcVar23 = pcVar24;
                    if (-1 < *(int *)(*(longlong *)(pcVar24 + 8) + 0xa8)) {
LAB_23ab00889:
                      if (pcVar18 != pcVar24) goto LAB_23aaffe40;
                      goto LAB_23ab00450;
                    }
                  }
                  lVar19 = *(longlong *)(pcVar23 + 0x158);
                  if (lVar19 == 0) {
                    do {
                      if (pcVar18 == pcVar23) goto LAB_23ab00450;
                      pcVar23 = *(code **)(pcVar23 + 0x100);
                    } while (pcVar23 != (code *)0x0);
                    if (pcVar18 == PyBaseObject_Type_exref) goto LAB_23ab00450;
LAB_23ab003a4:
                    pcVar21 = *(code **)(param_1 + 0x138);
                  }
                  else if (0 < *(longlong *)(lVar19 + 0x10)) {
                    lVar16 = 0;
                    while (pcVar18 != *(code **)(lVar19 + 0x18 + lVar16 * 8)) {
                      lVar16 = lVar16 + 1;
                      if (*(longlong *)(lVar19 + 0x10) == lVar16) goto LAB_23ab003a4;
                    }
                    goto LAB_23ab00450;
                  }
LAB_23aaffe40:
                  auStack_a8._8_8_ = pcVar21;
                  if ((pcVar21 == pcVar20) || (pcVar21 == (code *)0x0)) {
                    plVar14 = *(longlong **)PyExc_RuntimeError_exref;
                    pcVar21 = (code *)PyUnicode_FromString("No active exception to reraise");
                    pcVar18 = *(code **)(param_1 + 0x138);
                    iVar22 = 0x1b5;
                    *plVar14 = *plVar14 + 1;
                    *(longlong **)(param_1 + 0x138) = plVar13;
                    pcVar20 = (code *)0x0;
                    if (pcVar18 == (code *)0x0) goto LAB_23aafff00;
                    iVar22 = 0x1b5;
                    pcVar20 = (code *)0x0;
                  }
                  else {
                    plVar14 = *(longlong **)(pcVar21 + 8);
                    pcVar20 = *(code **)(pcVar21 + 0x28);
                    *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
                    *plVar14 = *plVar14 + 1;
                    pcVar18 = pcVar21;
                    if (pcVar20 == (code *)0x0) {
                      *(longlong **)(param_1 + 0x138) = plVar13;
                      iVar22 = 0;
                    }
                    else {
                      *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                      if (*(longlong **)(pcVar20 + 0x18) == plVar9) {
                        *(undefined4 *)(plVar9 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                      }
                      *(longlong **)(param_1 + 0x138) = plVar13;
                      iVar22 = 0;
                    }
                  }
                  pcStack_98 = (code *)0x0;
                  auStack_a8 = (undefined1  [16])0x0;
                  *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
                  if (*(longlong *)pcVar18 == 0) {
                    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
                  }
                  goto LAB_23aafff00;
                }
                plVar15 = *(longlong **)PyExc_TypeError_exref;
                uVar17 = PyUnicode_FromString
                                   (
                                   "catching classes that do not inherit from BaseException is not allowed"
                                   );
                plVar4 = *(longlong **)(param_1 + 0x60);
                plVar14 = *(longlong **)(param_1 + 0x70);
                plVar3 = *(longlong **)(param_1 + 0x68);
                *(longlong **)(param_1 + 0x60) = plVar15;
                *plVar15 = *plVar15 + 1;
                *(undefined8 *)(param_1 + 0x68) = uVar17;
                *(undefined8 *)(param_1 + 0x70) = 0;
                if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
                  (**(code **)(plVar4[1] + 0x30))();
                }
                if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                  (**(code **)(plVar3[1] + 0x30))(plVar3);
                }
LAB_23ab00430:
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
              }
              else {
                lVar19 = *(longlong *)(pcVar18 + 0x10);
                if (lVar19 < 1) goto LAB_23aaffe40;
                lVar16 = 0;
                do {
                  if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar18 + lVar16 * 8 + 0x18) + 8) +
                                    0xa8)) ||
                     ((*(byte *)(*(longlong *)(pcVar18 + lVar16 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
                    plVar15 = *(longlong **)PyExc_TypeError_exref;
                    uVar17 = PyUnicode_FromString
                                       (
                                       "catching classes that do not inherit from BaseException is not allowed"
                                       );
                    plVar4 = *(longlong **)(param_1 + 0x60);
                    plVar3 = *(longlong **)(param_1 + 0x68);
                    plVar14 = *(longlong **)(param_1 + 0x70);
                    *(longlong **)(param_1 + 0x60) = plVar15;
                    *plVar15 = *plVar15 + 1;
                    *(undefined8 *)(param_1 + 0x68) = uVar17;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
                      (**(code **)(plVar4[1] + 0x30))();
                    }
                    if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                      (**(code **)(plVar3[1] + 0x30))(plVar3);
                    }
                    goto LAB_23ab00430;
                  }
                  lVar16 = lVar16 + 1;
                } while (lVar19 != lVar16);
                lVar16 = 0;
                while( true ) {
                  iVar22 = FUN_23a35ebd0(param_1,pcVar23,
                                         *(undefined8 *)(pcVar18 + lVar16 * 8 + 0x18));
                  if (iVar22 != 0) break;
                  lVar16 = lVar16 + 1;
                  if (lVar19 == lVar16) {
                    pcVar21 = *(code **)(param_1 + 0x138);
                    goto LAB_23aaffe40;
                  }
                }
              }
LAB_23ab00450:
              plVar14 = _DAT_23ed8f8e8;
              *_DAT_23ed8f8e8 = *_DAT_23ed8f8e8 + 1;
              if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar12 = *plVar12 + 1;
              if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
                (**(code **)(plVar25[1] + 0x30))(plVar25);
              }
              plVar11 = *(longlong **)(param_1 + 0x138);
              *(longlong **)(param_1 + 0x138) = plVar13;
              plVar15 = plVar12;
              if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                (**(code **)(plVar11[1] + 0x30))();
              }
            }
            else {
              *(undefined4 *)(plVar9 + 5) = 0x1b6;
              plVar14 = (longlong *)FUN_23e94bb80(param_1,plVar13,_DAT_23ed8f8e0);
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              if (plVar14 == (longlong *)0x0) goto LAB_23ab00308;
              plVar13 = (longlong *)FUN_23a388310(plVar14);
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar13 == (longlong *)0x0) goto LAB_23ab00308;
              plVar14 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
              if (plVar14 == (longlong *)0x0) {
                plVar14 = (longlong *)FUN_23a3c1b70(param_1,auStack_a8,0,2);
                plVar15 = (longlong *)0x0;
                if (plVar14 != (longlong *)0x0) goto LAB_23aaffabf;
LAB_23aaffb14:
                pcVar21 = pcStack_98;
                uVar17 = auStack_a8._0_8_;
                uVar26 = auStack_a8._8_8_;
                pcStack_98 = (code *)0x0;
                auStack_a8 = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                pcStack_98 = (code *)0x0;
                auStack_a8 = (undefined1  [16])0x0;
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                goto LAB_23aaffb9f;
              }
LAB_23aaffabf:
              plVar15 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
              if (((plVar15 == (longlong *)0x0) &&
                  (plVar15 = (longlong *)FUN_23a3c1b70(param_1,auStack_a8,1,2),
                  plVar15 == (longlong *)0x0)) ||
                 (cVar8 = FUN_23a3884a0(param_1,auStack_a8,plVar13,2), cVar8 == '\0'))
              goto LAB_23aaffb14;
              *plVar13 = *plVar13 + -1;
              if (*plVar13 == 0) {
                (**(code **)(plVar13[1] + 0x30))(plVar13);
              }
              lVar19 = *plVar14;
              *plVar14 = lVar19 + 1;
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                lVar19 = *plVar14 + -1;
              }
              *plVar14 = lVar19;
              if (lVar19 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              lVar19 = *plVar15;
              *plVar15 = lVar19 + 1;
              if (plVar25 != (longlong *)0x0) {
                *plVar25 = *plVar25 + -1;
                if (*plVar25 == 0) {
                  (**(code **)(plVar25[1] + 0x30))(plVar25);
                  lVar19 = *plVar15 + -1;
                }
                else {
                  lVar19 = *plVar15 + -1;
                }
              }
              *plVar15 = lVar19;
              if (lVar19 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
            }
            iVar22 = FUN_23e913250(plVar15,_DAT_23ed8f8f0);
            plVar11 = plVar14;
            plVar25 = plVar15;
            if (iVar22 == -1) {
              plVar14 = *(longlong **)(param_1 + 0x60);
              pcVar21 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              iVar22 = 0x1bb;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aafff00;
            }
            if (iVar22 != 1) {
              plVar13 = (longlong *)PyNumber_Long(plVar15);
              if (plVar13 != (longlong *)0x0) {
                iVar22 = PyDict_SetItem(unaff_R12,plVar14,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (iVar22 == 0) goto LAB_23ab00517;
              }
              plVar14 = *(longlong **)(param_1 + 0x60);
              pcVar21 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              iVar22 = 0x1be;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aafff00;
            }
            iVar22 = PyDict_SetItem(unaff_R12,plVar14,pcVar20);
            if (iVar22 != 0) {
              plVar14 = *(longlong **)(param_1 + 0x60);
              pcVar21 = *(code **)(param_1 + 0x68);
              pcVar20 = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              iVar22 = 0x1bc;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23aafff00;
            }
LAB_23ab00517:
            lVar19 = *(longlong *)(param_1 + 0x10);
            if ((((*(int *)(*(longlong *)(lVar19 + 0x28) + 0x160) != 0) ||
                 (*(int *)(lVar19 + 0x78) != 0)) && (iVar22 = Py_MakePendingCalls(), iVar22 < 0)) &&
               (plVar14 = *(longlong **)(param_1 + 0x60), plVar14 != (longlong *)0x0))
            goto LAB_23ab00686;
            if (*(int *)(lVar19 + 0x68) == 0) {
              plVar14 = *(longlong **)(param_1 + 0x90);
            }
            else {
              PyEval_SaveThread();
              PyEval_AcquireThread(param_1);
              plVar14 = *(longlong **)(param_1 + 0x90);
            }
            plVar13 = plVar12;
            if (plVar14 != (longlong *)0x0) goto LAB_23ab0060f;
          }
          PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                       *(undefined8 *)(plVar10[1] + 0x18));
LAB_23ab0090b:
          cVar8 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
          if (cVar8 == '\0') {
            plVar14 = *(longlong **)(param_1 + 0x60);
            pcVar21 = *(code **)(param_1 + 0x68);
            pcStack_98 = (code *)0x0;
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            auStack_a8 = (undefined1  [16])0x0;
            if (plVar13 != (longlong *)0x0) {
              iVar22 = 0x1b4;
              plVar12 = plVar13;
              goto LAB_23aafff00;
            }
            plVar13 = (longlong *)0x0;
            iVar22 = 0x1b4;
            goto LAB_23aafff39;
          }
          if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          lVar19 = *plVar10;
          *plVar10 = lVar19 + -1;
          if (lVar19 + -1 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if ((DAT_23ed6a210 == (longlong *)0x0) &&
             (DAT_23ed6a210 = (longlong *)PyImport_ImportModule(&DAT_23ec31700),
             DAT_23ed6a210 == (longlong *)0x0)) {
            DAT_23ed6a210 = (longlong *)0x0;
LAB_23ab00cc5:
            FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS",
                          "\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
            abort();
          }
          plVar12 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,_DAT_23ed8f900);
          plVar10 = plVar13;
          if (plVar12 == (longlong *)0x0) {
LAB_23ab015f9:
            auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
            pcStack_98 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
joined_r0x00023ab01792:
            if (pcStack_98 == (code *)0x0) {
LAB_23ab01798:
              iVar22 = 0x1c1;
              goto LAB_23ab0114a;
            }
            plVar12 = *(longlong **)(pcStack_98 + 0x18);
          }
          else {
            plVar14 = (longlong *)FUN_23a38cc10(param_1,plVar12,DAT_23ed8f908);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar14 == (longlong *)0x0) goto LAB_23ab015f9;
            if ((DAT_23ed6a210 == (longlong *)0x0) &&
               (DAT_23ed6a210 = (longlong *)PyImport_ImportModule(&DAT_23ec31700),
               DAT_23ed6a210 == (longlong *)0x0)) {
              DAT_23ed6a210 = (longlong *)0x0;
              goto LAB_23ab00cc5;
            }
            plVar12 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,_DAT_23ed8f900);
            if (plVar12 != (longlong *)0x0) {
              cVar8 = FUN_23a39bc50(param_1,plVar12,uRam000000023ed6cfd0,plVar14);
              *plVar12 = *plVar12 + -1;
              if (*plVar12 == 0) {
                (**(code **)(plVar12[1] + 0x30))(plVar12);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (cVar8 == '\0') goto LAB_23ab015f9;
              plVar12 = (longlong *)FUN_23e8bc2f0(plStack_100,_DAT_23ed8f8c0);
              if (plVar12 == (longlong *)0x0) {
LAB_23ab0174a:
                auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                pcStack_98 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcStack_98 == (code *)0x0) {
LAB_23ab017ff:
                  iVar22 = 0x1c3;
                  goto LAB_23ab0114a;
                }
                plVar12 = *(longlong **)(pcStack_98 + 0x18);
              }
              else {
                lVar19 = FUN_23e8bc2f0(plVar12,_DAT_23ed8f910);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (lVar19 == 0) goto LAB_23ab0174a;
                *plStack_f8 = *plStack_f8 + 1;
                *(longlong *)unaff_R12 = *(longlong *)unaff_R12 + 1;
                plStack_80 = plStack_f8;
                lStack_88 = lVar19;
                pcStack_78 = unaff_R12;
                plVar12 = (longlong *)FUN_23aafe700(param_1,unaff_R15);
                if (plVar12 != (longlong *)0x0) {
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                  plVar9 = *(longlong **)(lVar19 + 0x28);
                  plVar10 = (longlong *)plVar9[2];
                  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                       *(undefined8 *)(lVar19 + 0x30);
                  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                  if (plVar10 != (longlong *)0x0) {
                    plVar9[2] = 0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))();
                    }
                  }
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  plVar9[0xf] = 0;
                  *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                  lVar19 = *plVar5;
                  *plVar5 = lVar19 + -1;
                  if (lVar19 + -1 == 0) {
                    (**(code **)(plVar5[1] + 0x30))(plVar5);
                  }
                  lVar19 = *plVar6;
                  *plVar6 = lVar19 + -1;
                  if (lVar19 + -1 == 0) {
                    (**(code **)(plVar6[1] + 0x30))(plVar6);
                  }
                  lVar19 = *plStack_100;
                  *plStack_100 = lVar19 + -1;
                  if (lVar19 + -1 == 0) {
                    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
                  }
                  *(longlong *)unaff_R12 = *(longlong *)unaff_R12 + -1;
                  if (*(longlong *)unaff_R12 == 0) {
                    (**(code **)(*(longlong *)(unaff_R12 + 8) + 0x30))(unaff_R12);
                  }
                  lVar19 = *plStack_f8;
                  *plStack_f8 = lVar19 + -1;
                  if (lVar19 + -1 == 0) {
                    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
                  }
                  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar25 == (longlong *)0x0) {
                    return pcVar20;
                  }
                  *plVar25 = *plVar25 + -1;
                  if (*plVar25 != 0) {
                    return pcVar20;
                  }
                  (**(code **)(plVar25[1] + 0x30))(plVar25);
                  return pcVar20;
                }
                auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
                pcStack_98 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (pcStack_98 == (code *)0x0) goto LAB_23ab017ff;
                plVar12 = *(longlong **)(pcStack_98 + 0x18);
              }
              pcVar20 = pcStack_98;
              if (plVar9 == plVar12) goto LAB_23ab00109;
              iVar22 = 0x1c3;
              goto LAB_23ab00060;
            }
            auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
            pcStack_98 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *plVar14 = *plVar14 + -1;
            if (*plVar14 != 0) goto joined_r0x00023ab01792;
            (**(code **)(plVar14[1] + 0x30))(plVar14);
            if (pcStack_98 == (code *)0x0) goto LAB_23ab01798;
            plVar12 = *(longlong **)(pcStack_98 + 0x18);
          }
          pcVar20 = pcStack_98;
          if (plVar9 == plVar12) goto LAB_23ab00109;
          iVar22 = 0x1c1;
          goto LAB_23ab00060;
        }
        auStack_a8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcStack_98 == (code *)0x0) goto LAB_23ab01258;
        plVar10 = *(longlong **)(pcStack_98 + 0x18);
      }
      if (plVar9 == plVar10) {
LAB_23ab014d0:
        plVar25 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar13 = (longlong *)0x0;
        pcVar20 = pcStack_98;
        goto LAB_23ab00109;
      }
      plVar11 = (longlong *)0x0;
      plVar25 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      iVar22 = 0x1b4;
    }
  }
LAB_23ab00060:
  pcVar21 = pcStack_98;
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar18 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar18;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar20 + 0x18) = plVar9;
  *plVar9 = *plVar9 + 1;
  lVar19 = *(longlong *)(pcStack_f0 + 0x1f8);
  *(int *)(pcVar20 + 0x24) = iVar22;
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar19 = *(longlong *)(*(longlong *)(lVar19 + 0x10) + 0x2e8);
  lVar16 = *(longlong *)(pcVar20 + -8);
  puVar2 = *(undefined8 **)(lVar19 + 8);
  *puVar2 = pcVar20 + -0x10;
  *(longlong *)(pcVar20 + -0x10) = lVar19;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
  *(code **)(lVar19 + 8) = pcVar20 + -0x10;
  *(code **)(pcVar20 + 0x10) = pcVar21;
  *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
  pcVar21 = pcStack_98;
  plVar13 = plVar10;
  goto joined_r0x00023ab011db;
LAB_23ab0060f:
  plVar13 = *(longlong **)(param_1 + 0x60);
  plVar15 = *(longlong **)(param_1 + 0x68);
  *(undefined8 *)(param_1 + 0x90) = 0;
  plVar4 = *(longlong **)(param_1 + 0x70);
  *(longlong **)(param_1 + 0x60) = plVar14;
  *plVar14 = *plVar14 + 1;
  *(undefined8 *)(param_1 + 0x68) = 0;
  *(undefined8 *)(param_1 + 0x70) = 0;
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))();
  }
  if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
    (**(code **)(plVar15[1] + 0x30))(plVar15);
  }
  if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar14 = *(longlong **)(param_1 + 0x60);
LAB_23ab00686:
  pcVar21 = *(code **)(param_1 + 0x68);
  pcVar20 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  iVar22 = 0x1b4;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23aafff00:
  pcStack_98 = (code *)0x0;
  auStack_a8 = (undefined1  [16])0x0;
  *plVar12 = *plVar12 + -1;
  plVar13 = plVar12;
  if (*plVar12 == 0) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
LAB_23aafff39:
  lVar19 = *plVar10;
  *plVar10 = lVar19 + -1;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  auStack_a8._8_8_ = pcVar21;
  auStack_a8._0_8_ = plVar14;
  pcStack_98 = pcVar20;
  if (pcVar20 != (code *)0x0) {
    if (*(longlong **)(pcVar20 + 0x18) == plVar9) goto LAB_23ab00109;
    plVar10 = plVar13;
    if (iVar22 == 0) {
      iVar22 = (int)plVar9[5];
    }
    goto LAB_23ab00060;
  }
  if (iVar22 == 0) {
    iVar22 = (int)plVar9[5];
  }
LAB_23ab0114a:
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar21 = pcStack_98;
  }
  else {
    pcVar21 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar21;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar21 = (code *)0x0;
  }
  *(longlong *)(pcVar20 + 0x10) = 0;
  *(longlong **)(pcVar20 + 0x18) = plVar9;
  *plVar9 = *plVar9 + 1;
  lVar19 = *(longlong *)(pcStack_f0 + 0x1f8);
  *(int *)(pcVar20 + 0x24) = iVar22;
  lVar19 = *(longlong *)(lVar19 + 0x10);
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar19 = *(longlong *)(lVar19 + 0x2e8);
  lVar16 = *(longlong *)(pcVar20 + -8);
  puVar2 = *(undefined8 **)(lVar19 + 8);
  *puVar2 = pcVar20 + -0x10;
  *(longlong *)(pcVar20 + -0x10) = lVar19;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
  *(code **)(lVar19 + 8) = pcVar20 + -0x10;
joined_r0x00023ab011db:
  if ((pcVar21 != (code *)0x0) &&
     (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0)) {
    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))();
  }
LAB_23ab00109:
  pcStack_98 = pcVar20;
  FUN_23e8bba40(plVar9,"oooooooo",plVar5,plVar6,plStack_100,unaff_R12,plStack_f8,plVar13,plVar11,
                plVar25);
  if (_DAT_23ed90a10 == plVar9) {
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    _DAT_23ed90a10 = (longlong *)0x0;
  }
  lVar19 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar19 + 0x28);
  plVar10 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar19 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar10 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  pcVar20 = pcStack_98;
  auVar7 = auStack_a8;
  uVar17 = auStack_a8._0_8_;
  uVar26 = auStack_a8._8_8_;
  plVar9[0xf] = 0;
  auStack_a8 = (undefined1  [16])0x0;
  lVar19 = *plVar5;
  pcStack_98 = (code *)0x0;
  *plVar5 = lVar19 + -1;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  lVar19 = *plVar6;
  *plVar6 = lVar19 + -1;
  if (lVar19 + -1 == 0) {
    (**(code **)(plVar6[1] + 0x30))(plVar6);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar19 = *plStack_100, *plStack_100 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((unaff_R12 != (code *)0x0) &&
     (*(longlong *)unaff_R12 = *(longlong *)unaff_R12 + -1, *(longlong *)unaff_R12 == 0)) {
    (**(code **)(*(longlong *)(unaff_R12 + 8) + 0x30))(unaff_R12);
  }
  if ((plStack_f8 != (longlong *)0x0) &&
     (lVar19 = *plStack_f8, *plStack_f8 = lVar19 + -1, lVar19 + -1 == 0)) {
    (**(code **)(plStack_f8[1] + 0x30))(plStack_f8);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
    (**(code **)(plVar25[1] + 0x30))(plVar25);
  }
  auStack_a8 = auVar7;
  pcStack_98 = pcVar20;
  FUN_23a33aa70(param_1,uVar17,uVar26,pcVar20);
  return (code *)0x0;
}
