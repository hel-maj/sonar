/* ===== 23c61c640 license.activation_dialog:348 ===== */
/* ghidra_name=FUN_23c61c640 entry=23c61c640 size=2620 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23c61c640(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong *plVar7;
  longlong lVar8;
  code *pcVar9;
  code *pcVar10;
  undefined8 *puVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong lVar16;
  longlong lVar17;
  undefined8 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined8 *puVar21;
  code *pcVar22;
  longlong lStack_198;
  undefined8 uStack_180;
  longlong lStack_178;
  code *pcStack_170;
  undefined8 uStack_168;
  undefined8 uStack_160;
  undefined8 uStack_150;
  longlong lStack_148;
  code *pcStack_140;
  undefined8 uStack_138;
  undefined8 uStack_130;
  undefined8 uStack_120;
  longlong lStack_118;
  code *pcStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  longlong *plStack_e8;
  longlong lStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  undefined8 *puStack_c0;
  longlong *plStack_b8;
  undefined8 *puStack_b0;
  undefined8 uStack_88;
  undefined4 uStack_7c;
  longlong *plStack_78;
  undefined8 uStack_70;
  code *pcStack_68;
  
  plVar5 = _DAT_23ee29e98;
  plVar12 = (longlong *)*param_3;
  plVar14 = (longlong *)param_3[1];
  if (_DAT_23ee29e98 == (longlong *)0x0) {
LAB_23c61c683:
    puStack_b0 = (undefined8 *)0x23c61c69f;
    _DAT_23ee29e98 = (longlong *)FUN_23e91f3b0(param_1,DAT_23ee29e90,DAT_23ee29f70,0x10);
  }
  else {
    lVar8 = *_DAT_23ee29e98;
    if (1 < lVar8) {
      *_DAT_23ee29e98 = lVar8 + -1;
      goto LAB_23c61c683;
    }
    if (_DAT_23ee29e98[2] != 0) {
      *_DAT_23ee29e98 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        puStack_b0 = (undefined8 *)0x23c61cc72;
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      goto LAB_23c61c683;
    }
  }
  plVar15 = _DAT_23ee29e98;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar5 = _DAT_23ee29e98 + 9;
  lVar13 = *(longlong *)(lVar8 + 8);
  _DAT_23ee29e98[0xf] = lVar13;
  *(longlong **)(lVar8 + 8) = plVar5;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar15[0xe] != 0)))) {
    plVar5 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar15[0xe] + 0x10) = plVar5;
    if (plVar5 != (longlong *)0x0) {
      *plVar5 = *plVar5 + 1;
    }
  }
  lVar13 = DAT_23ee29728;
  *plVar15 = *plVar15 + 1;
  *(undefined4 *)(plVar15 + 8) = 0;
  lVar8 = *(longlong *)(lVar13 + 0x20);
  if (*(char *)(lVar8 + 10) == '\0') {
    puStack_b0 = (undefined8 *)0x23c61cf14;
    plVar5 = (longlong *)FUN_23a37a020(lVar13,DAT_23ee29528);
    if (plVar5 == (longlong *)0x0) goto LAB_23c61ca91;
    lVar13 = *plVar5;
LAB_23c61cf20:
    if (lVar13 == 0) goto LAB_23c61ca91;
  }
  else {
    iVar4 = *(int *)(lVar8 + 0xc);
    if (*(int *)(lVar8 + 0xc) == 0) {
      *(int *)(lVar8 + 0xc) = DAT_23ec12b2c;
      iVar4 = DAT_23ec12b2c;
      DAT_23ec12b2c = DAT_23ec12b2c + 1;
    }
    if (_DAT_23ec12b1c != iVar4) {
      puStack_b0 = (undefined8 *)0x23c61ca81;
      _DAT_23ec12b1c = iVar4;
      _DAT_23ee29e80 = FUN_23e8cbd60(lVar8,DAT_23ee29528,*(undefined8 *)(DAT_23ee29528 + 0x18));
    }
    if (-1 < _DAT_23ee29e80) {
      lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
      lVar13 = *(longlong *)(lVar1 + 8 + _DAT_23ee29e80 * 0x10);
      if (lVar13 != 0) goto LAB_23c61c773;
      puStack_b0 = (undefined8 *)0x23c61cffb;
      _DAT_23ee29e80 = FUN_23e8cbd60(lVar8,DAT_23ee29528,*(undefined8 *)(DAT_23ee29528 + 0x18));
      if (-1 < _DAT_23ee29e80) {
        lVar13 = *(longlong *)(lVar1 + 8 + _DAT_23ee29e80 * 0x10);
        goto LAB_23c61cf20;
      }
    }
LAB_23c61ca91:
    puStack_b0 = (undefined8 *)0x23c61caa7;
    plVar5 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ee29528);
    if ((plVar5 == (longlong *)0x0) || (lVar13 = *plVar5, lVar13 == 0)) {
      puStack_b0 = (undefined8 *)0x23c61cacc;
      FUN_23e915740(param_1,&plStack_78,DAT_23ee29528);
      pcVar10 = DAT_23ed6a4f8;
      uStack_88 = uStack_70;
      uVar20 = uStack_7c;
      uVar19 = 0x15e;
      plVar6 = plStack_78;
      pcVar9 = pcStack_68;
      goto joined_r0x00023c61cd1c;
    }
  }
LAB_23c61c773:
  puStack_b0 = (undefined8 *)0x23c61c77f;
  plVar5 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23ee29530);
  if (plVar5 == (longlong *)0x0) {
LAB_23c61ce10:
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plVar6 = *(longlong **)(param_1 + 0x60);
    pcVar9 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar10 = DAT_23ed6a4f8;
    uVar20 = uStack_7c;
    uVar19 = 0x15e;
    goto joined_r0x00023c61cd1c;
  }
  lVar8 = *(longlong *)(DAT_23ee29728 + 0x20);
  if (*(char *)(lVar8 + 10) == '\0') {
    puStack_b0 = (undefined8 *)0x23c61cf3c;
    plVar6 = (longlong *)FUN_23a37a020(DAT_23ee29728,DAT_23ee29538);
    if (plVar6 == (longlong *)0x0) goto LAB_23c61cca9;
    lVar13 = *plVar6;
LAB_23c61cf48:
    if (lVar13 == 0) goto LAB_23c61cca9;
LAB_23c61c7fc:
    *(undefined4 *)(plVar15 + 5) = 0x15e;
    puStack_b0 = (undefined8 *)0x23c61c80e;
    plVar6 = (longlong *)FUN_23e914090(param_1,lVar13,plVar14);
    if (plVar6 == (longlong *)0x0) {
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      plVar6 = *(longlong **)(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23c61ccf8;
    }
    *(undefined4 *)(plVar15 + 5) = 0x15e;
    puStack_b0 = (undefined8 *)0x23c61c82f;
    plVar7 = (longlong *)FUN_23e914090(param_1,plVar5,plVar6);
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      puStack_b0 = (undefined8 *)0x23c61c842;
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    *plVar6 = *plVar6 + -1;
    if (*plVar6 == 0) {
      puStack_b0 = (undefined8 *)0x23c61c853;
      (**(code **)(plVar6[1] + 0x30))(plVar6);
    }
    if (plVar7 == (longlong *)0x0) goto LAB_23c61ce10;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_b0 = (undefined8 *)0x23c61c86c;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    puStack_b0 = (undefined8 *)0x23c61c871;
    lVar8 = FUN_23ead6980();
    if (lVar8 == 0) {
      puStack_b0 = (undefined8 *)0x23c61cfc4;
      FUN_23e915740(param_1,&plStack_78,DAT_23ee294b0);
      pcVar10 = DAT_23ed6a4f8;
      uStack_88 = uStack_70;
      uVar20 = uStack_7c;
      uVar19 = 0x15f;
      plVar6 = plStack_78;
      pcVar9 = pcStack_68;
      goto joined_r0x00023c61cd1c;
    }
    puStack_b0 = (undefined8 *)0x23c61c889;
    plVar7 = (longlong *)FUN_23e8bc2f0(lVar8,_DAT_23ee294d0);
    plVar6 = _DAT_23ee29540;
    if (plVar7 == (longlong *)0x0) {
LAB_23c61ce60:
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      plVar6 = *(longlong **)(param_1 + 0x60);
      pcVar9 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar10 = DAT_23ed6a4f8;
      uVar20 = uStack_7c;
      uVar19 = 0x15f;
      goto joined_r0x00023c61cd1c;
    }
    lVar8 = *(longlong *)(param_1 + 0x10);
    plVar5 = *(longlong **)(lVar8 + 0xe20);
    if (plVar5 == (longlong *)0x0) {
      puStack_b0 = (undefined8 *)0x23c61ce51;
      plVar5 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar13 = plVar5[3];
      *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
      *(longlong *)(lVar8 + 0xe20) = lVar13;
      *plVar5 = 1;
    }
    pcVar9 = _PyRuntime_exref;
    plVar5[4] = 0;
    lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar9 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = plVar5[-1];
    puVar21 = *(undefined8 **)(lVar8 + 8);
    *puVar21 = plVar5 + -2;
    plVar5[-2] = lVar8;
    plVar5[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar21;
    *(longlong **)(lVar8 + 8) = plVar5 + -2;
    pcVar9 = DAT_23ed6a4c0;
    *plVar6 = *plVar6 + 1;
    plVar5[3] = (longlong)plVar6;
    uVar18 = DAT_23ed6cd28;
    if (pcVar9 == (code *)0x0) {
      puStack_b0 = (undefined8 *)0x23c61cf77;
      pcVar9 = (code *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (pcVar9 == (code *)0x0) {
        puStack_b0 = (undefined8 *)0x23c61d0cc;
        PyErr_PrintEx(0);
        lVar8 = 1;
        puStack_b0 = (undefined8 *)0x23c61d0d7;
        Py_Exit();
        puStack_b0 = &DAT_23ed6a4c0;
        puStack_c0 = &DAT_23ed6cce0;
        _DAT_23ee29e48 = *(longlong *)(pcVar9 + 0x10);
        _DAT_23ee29e50 = pcVar9;
        plStack_e8 = plVar15;
        lStack_e0 = param_1;
        plStack_d8 = plVar5;
        plStack_d0 = plVar14;
        plStack_c8 = plVar12;
        plStack_b8 = plVar7;
        if (DAT_23ee29e41 == '\0') {
          if (DAT_23ee29e40 == '\0') {
            FUN_23e97f860(lVar8,&DAT_23ee29dc0,"license");
            DAT_23ee29e40 = '\x01';
          }
          _DAT_23ee29db0 = FUN_23e8bdab0(_DAT_23ee29e30);
          _DAT_23ee29da8 = FUN_23e8d36c0(_DAT_23ee29db0,1,0,_DAT_23ee29e38,_DAT_23ee29e38,0,0);
          DAT_23ee29e41 = '\x01';
        }
        FUN_23a3880f0(_DAT_23ee29e48,DAT_23ed6cdd0,DAT_23ed6a4a8);
        puVar11 = (undefined8 *)FUN_23a37a020(_DAT_23ee29e48,DAT_23ed6cd48);
        uVar18 = 0;
        if (puVar11 != (undefined8 *)0x0) {
          uVar18 = *puVar11;
        }
        FUN_23a3880f0(_DAT_23ee29e48,DAT_23ed6cd50,uVar18);
        plVar12 = (longlong *)FUN_23a37a020(_DAT_23ee29e48,DAT_23ed6cda0);
        if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
          uVar18 = PyModule_GetDict(DAT_23ed6a4a0);
          FUN_23a3880f0(_DAT_23ee29e48,DAT_23ed6cda0,uVar18);
          puVar11 = DAT_23ed6a470;
          if (DAT_23ed6a470 != (undefined8 *)0x0) goto LAB_23c61d1fa;
LAB_23c61d899:
          puVar11 = (undefined8 *)FUN_23a33a530(&DAT_23ec0f940);
        }
        else {
          puVar11 = DAT_23ed6a470;
          if (DAT_23ed6a470 == (undefined8 *)0x0) goto LAB_23c61d899;
LAB_23c61d1fa:
          DAT_23ed6a470 = (undefined8 *)*puVar11;
          *puVar11 = 1;
          DAT_23ed6a468 = DAT_23ed6a468 + -1;
        }
        lVar13 = *(longlong *)
                  (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
        uVar18 = puVar11[-1];
        puVar2 = *(undefined8 **)(lVar13 + 8);
        *puVar2 = puVar11 + -2;
        puVar11[-2] = lVar13;
        puVar11[-1] = (ulonglong)((uint)uVar18 & 3) | (ulonglong)puVar2;
        *(undefined8 **)(lVar13 + 8) = puVar11 + -2;
        lVar13 = _DAT_23ee29e48;
        puVar11[2] = puVar21;
        FUN_23a3880f0(lVar13,DAT_23ed6cdc8);
        if (DAT_23ed6a478 == 0) {
          DAT_23ed6a478 = PyImport_ImportModule("importlib._bootstrap");
        }
        plVar12 = (longlong *)PyObject_GetAttrString(DAT_23ed6a478,"_spec_from_module");
        lVar13 = FUN_23e914090(lVar8,plVar12,_DAT_23ee29e50);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        pcVar9 = _Py_TrueStruct_exref;
        if (lVar13 == 0) {
          PyErr_PrintEx(0);
                    /* WARNING: Subroutine does not return */
          abort();
        }
        FUN_23e8d9ac0(lVar13,DAT_23ed6cfa8,_Py_TrueStruct_exref);
        FUN_23a3881f0(_DAT_23ee29e48,DAT_23ed6cfa0,lVar13);
        pcVar10 = _Py_NoneStruct_exref;
        FUN_23a3880f0(_DAT_23ee29e48,DAT_23ed6cd78,_Py_NoneStruct_exref);
        FUN_23a3880f0(_DAT_23ee29e48,DAT_23ed6cd80,_DAT_23ee29db0);
        plVar12 = (longlong *)FUN_23e9354d0(_DAT_23ee29da8,_DAT_23ee29e50);
        lVar13 = *(longlong *)(lVar8 + 0x38);
        lVar1 = *(longlong *)(lVar13 + 8);
        plVar12[0xf] = lVar1;
        *(longlong **)(lVar13 + 8) = plVar12 + 9;
        if ((lVar1 != 0) &&
           (((*(char *)(lVar1 + 0x45) == '\x01' ||
             ((ulonglong)
              (*(longlong *)(lVar1 + 0x20) + 0xb8 +
              (longlong)*(int *)(*(longlong *)(lVar1 + 0x20) + 0xa8) * 2) <=
              *(ulonglong *)(lVar1 + 0x38))) && (plVar12[0xe] != 0)))) {
          plVar14 = *(longlong **)(lVar1 + 0x28);
          *(longlong **)(plVar12[0xe] + 0x10) = plVar14;
          if (plVar14 != (longlong *)0x0) {
            *plVar14 = *plVar14 + 1;
          }
        }
        *plVar12 = *plVar12 + 1;
        *(undefined4 *)(plVar12 + 8) = 0;
        lVar13 = DAT_23ed6a4b8;
        *(undefined4 *)(plVar12 + 5) = 1;
        if ((lVar13 == 0) &&
           (lVar13 = PyImport_ImportModule(&DAT_23ec47932), DAT_23ed6a4b8 = lVar13, lVar13 == 0)) {
          DAT_23ed6a4b8 = 0;
LAB_23c61da0b:
          FUN_23e9364c0("%s : %s\n","IMPORT_HARD_OS",
                        "\"Unexpected failure of hard import of \'os\'\"");
                    /* WARNING: Subroutine does not return */
          abort();
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,DAT_23ed6ceb0);
        if (plVar14 != (longlong *)0x0) {
          plVar5 = (longlong *)FUN_23e8bc2f0(plVar14,DAT_23ed6cec0);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar5 != (longlong *)0x0) {
            *(undefined4 *)(plVar12 + 5) = 1;
            lVar13 = FUN_23e914090(lVar8,plVar5,_DAT_23ee29db0);
            *plVar5 = *plVar5 + -1;
            if (*plVar5 == 0) {
              (**(code **)(plVar5[1] + 0x30))(plVar5);
            }
            if (lVar13 != 0) {
              plVar14 = (longlong *)FUN_23e8d6340(*(undefined8 *)(lVar8 + 0x10),2);
              *(longlong *)plVar14[3] = lVar13;
              *(undefined4 *)(plVar12 + 5) = 1;
              if ((DAT_23ed6a4b8 == 0) &&
                 (DAT_23ed6a4b8 = PyImport_ImportModule(&DAT_23ec47932), DAT_23ed6a4b8 == 0))
              goto LAB_23c61da0b;
              plVar5 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a4b8,_DAT_23ee29dc0);
              if (plVar5 != (longlong *)0x0) {
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar5,DAT_23ed6ce40);
                *plVar5 = *plVar5 + -1;
                if (*plVar5 == 0) {
                  (**(code **)(plVar5[1] + 0x30))(plVar5);
                }
                if (plVar15 != (longlong *)0x0) {
                  *(undefined4 *)(plVar12 + 5) = 1;
                  plVar5 = (longlong *)FUN_23e9557e0(lVar8,plVar15,_DAT_23ee29dc8);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  lVar13 = _DAT_23ee29e48;
                  if (plVar5 != (longlong *)0x0) {
                    *(longlong **)(plVar14[3] + 8) = plVar5;
                    FUN_23a3881f0(lVar13,DAT_23ed6cd88,plVar14);
                    uVar18 = _DAT_23ee29db0;
                    plVar14 = (longlong *)FUN_23a37a020(_DAT_23ee29e48,DAT_23ed6cfa0);
                    if ((plVar14 == (longlong *)0x0) || (lVar13 = *plVar14, lVar13 == 0)) {
                      lVar13 = FUN_23a3a6140();
                    }
                    cVar3 = FUN_23e8d9ac0(lVar13,_DAT_23ee29dd0,uVar18);
                    if (cVar3 != '\0') {
                      plVar14 = (longlong *)FUN_23a37a020(_DAT_23ee29e48,DAT_23ed6cfa0);
                      if ((plVar14 == (longlong *)0x0) || (lVar13 = *plVar14, lVar13 == 0)) {
                        lVar13 = FUN_23a3a6140();
                      }
                      cVar3 = FUN_23e8d9ac0(lVar13,_DAT_23ee29dd8,pcVar9);
                      if (cVar3 != '\0') {
                        plVar14 = (longlong *)FUN_23a37a020(_DAT_23ee29e48,DAT_23ed6cd88);
                        if (((plVar14 == (longlong *)0x0) ||
                            (pcVar22 = (code *)*plVar14, pcVar22 == (code *)0x0)) &&
                           ((plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cd88),
                            plVar14 == (longlong *)0x0 ||
                            (pcVar22 = (code *)*plVar14, pcVar22 == (code *)0x0)))) {
                          FUN_23e915740(lVar8,&uStack_120,DAT_23ed6cd88);
                          uVar20 = 1;
                          pcVar9 = pcStack_110;
                          uVar18 = uStack_120;
                          lVar13 = lStack_118;
                          pcVar10 = DAT_23ed6a4f8;
                          goto joined_r0x00023c61d714;
                        }
                        plVar14 = (longlong *)FUN_23a37a020(_DAT_23ee29e48,DAT_23ed6cfa0);
                        if ((plVar14 == (longlong *)0x0) || (lVar13 = *plVar14, lVar13 == 0)) {
                          lVar13 = FUN_23a3a6140();
                        }
                        cVar3 = FUN_23e8d9ac0(lVar13,_DAT_23ee29de0,pcVar22);
                        if (cVar3 == '\0') goto LAB_23c61d6f0;
                        FUN_23a3880f0(_DAT_23ee29e48,DAT_23ed6cf20,pcVar10);
                        uStack_168 = _DAT_23ee29df0;
                        uStack_180 = _DAT_23ee29de8;
                        uStack_160 = DAT_23ed6ccf8;
                        pcStack_170 = pcVar10;
                        *(undefined4 *)(plVar12 + 5) = 2;
                        lStack_178 = _DAT_23ee29e48;
                        if (DAT_23ed6a498 == (longlong *)0x0) {
                          plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
                          if (plVar14 == (longlong *)0x0) goto LAB_23c61dfc8;
                          *plVar14 = *plVar14 + 1;
                          DAT_23ed6a498 = plVar14;
                        }
                        plVar5 = (longlong *)FUN_23e95b390(lVar8,DAT_23ed6a498,&uStack_180);
                        pcVar22 = PyModule_Type_exref;
                        if (plVar5 == (longlong *)0x0) {
LAB_23c61d6c5:
                          uVar18 = *(undefined8 *)(lVar8 + 0x60);
                          uVar20 = 2;
                          pcVar9 = *(code **)(lVar8 + 0x70);
                          *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(lVar8 + 0x70) = 0;
                          lVar13 = *(longlong *)(lVar8 + 0x68);
                          pcVar10 = DAT_23ed6a4f8;
                        }
                        else {
                          if (((code *)plVar5[1] == PyModule_Type_exref) ||
                             (iVar4 = PyType_IsSubtype((code *)plVar5[1],PyModule_Type_exref),
                             pcVar9 = PyObject_GetAttr_exref, lVar13 = _DAT_23ee29df8, iVar4 != 0))
                          {
                            pcVar9 = PyObject_GetAttr_exref;
                            lVar17 = _DAT_23ee29e48;
                            lVar1 = _DAT_23ee29df8;
                            lVar13 = DAT_23ed6ccf0;
                            lStack_198 = DAT_23ed6ccf0;
                            lVar16 = PyObject_GetAttr(plVar5);
                            if (lVar16 != 0) goto LAB_23c61da6a;
                            lVar16 = FUN_23e970390(lVar8,plVar5,lVar17,lVar1,lVar13);
LAB_23c61d6a2:
                            *plVar5 = *plVar5 + -1;
                            if (*plVar5 == 0) {
                              (**(code **)(plVar5[1] + 0x30))(plVar5);
                              lStack_198 = lVar16;
                            }
                            if (lVar16 == 0) goto LAB_23c61d6c5;
                          }
                          else {
                            lStack_198 = _DAT_23ee29df8;
                            lVar16 = PyObject_GetAttr(plVar5,_DAT_23ee29df8);
                            if (lVar16 == 0) {
                              lVar16 = FUN_23e8d2cf0(lVar8,plVar5,lVar13);
                              goto LAB_23c61d6a2;
                            }
LAB_23c61da6a:
                            *plVar5 = *plVar5 + -1;
                            if (*plVar5 == 0) {
                              (**(code **)(plVar5[1] + 0x30))(plVar5);
                              lStack_198 = lVar16;
                            }
                          }
                          FUN_23a3881f0(_DAT_23ee29e48,_DAT_23ee29df8,lVar16);
                          uStack_138 = _DAT_23ee29e08;
                          uStack_150 = _DAT_23ee29e00;
                          uStack_130 = DAT_23ed6ccf8;
                          pcStack_140 = pcVar10;
                          *(undefined4 *)(plVar12 + 5) = 3;
                          lStack_148 = _DAT_23ee29e48;
                          if (DAT_23ed6a498 == (longlong *)0x0) {
                            plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
                            if (plVar14 == (longlong *)0x0) goto LAB_23c61dfc8;
                            *plVar14 = *plVar14 + 1;
                            DAT_23ed6a498 = plVar14;
                          }
                          plVar5 = (longlong *)FUN_23e95b390(lVar8,DAT_23ed6a498,&uStack_150);
                          if (plVar5 != (longlong *)0x0) {
                            if (((code *)plVar5[1] == pcVar22) ||
                               (iVar4 = PyType_IsSubtype((code *)plVar5[1],pcVar22), iVar4 != 0)) {
                              lVar17 = _DAT_23ee29e48;
                              lVar1 = _DAT_23ee29e10;
                              lVar13 = DAT_23ed6ccf0;
                              lStack_198 = DAT_23ed6ccf0;
                              lVar16 = (*pcVar9)(plVar5);
                              if (lVar16 == 0) {
                                lVar16 = FUN_23e970390(lVar8,plVar5,lVar17,lVar1,lVar13);
                                goto LAB_23c61dd95;
                              }
                            }
                            else {
                              lStack_198 = _DAT_23ee29e10;
                              lVar16 = (*pcVar9)(plVar5,_DAT_23ee29e10);
                              if (lVar16 == 0) goto LAB_23c61dfdb;
                            }
                            *plVar5 = *plVar5 + -1;
                            if (*plVar5 == 0) {
                              (**(code **)(plVar5[1] + 0x30))(plVar5);
                              lStack_198 = lVar16;
                            }
                            do {
                              FUN_23a3881f0(_DAT_23ee29e48,_DAT_23ee29e10,lVar16);
                              uStack_108 = _DAT_23ee29e20;
                              uStack_120 = _DAT_23ee29e18;
                              uStack_100 = DAT_23ed6ccf8;
                              *(undefined4 *)(plVar12 + 5) = 4;
                              pcStack_110 = pcVar10;
                              lStack_118 = _DAT_23ee29e48;
                              if (DAT_23ed6a498 != (longlong *)0x0) {
LAB_23c61dbbb:
                                plVar14 = (longlong *)FUN_23e95b390(lVar8,DAT_23ed6a498,&uStack_120)
                                ;
                                if (plVar14 != (longlong *)0x0) {
                                  if (((code *)plVar14[1] == pcVar22) ||
                                     (iVar4 = PyType_IsSubtype((code *)plVar14[1],pcVar22),
                                     uVar18 = _DAT_23ee29e28, iVar4 != 0)) {
                                    lVar1 = _DAT_23ee29e48;
                                    uVar18 = _DAT_23ee29e28;
                                    lVar13 = DAT_23ed6ccf0;
                                    lVar17 = (*pcVar9)(plVar14,_DAT_23ee29e28);
                                    if (lVar17 == 0) {
                                      lVar17 = FUN_23e970390(lVar8,plVar14,lVar1,uVar18,lVar13);
                                      goto LAB_23c61dea0;
                                    }
                                  }
                                  else {
                                    lVar17 = (*pcVar9)(plVar14,_DAT_23ee29e28);
                                    if (lVar17 == 0) {
                                      lVar17 = FUN_23e8d2cf0(lVar8,plVar14,uVar18);
LAB_23c61dea0:
                                      *plVar14 = *plVar14 + -1;
                                      if (*plVar14 == 0) {
                                        (**(code **)(plVar14[1] + 0x30))(plVar14);
                                      }
                                      if (lVar17 != 0) goto LAB_23c61dc21;
                                      goto LAB_23c61deb9;
                                    }
                                  }
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                                  }
LAB_23c61dc21:
                                  FUN_23a3881f0(_DAT_23ee29e48,_DAT_23ee29e28,lVar17);
                                  lVar13 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 8);
                                  plVar12 = *(longlong **)(lVar13 + 0x28);
                                  plVar14 = (longlong *)plVar12[2];
                                  *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8) =
                                       *(undefined8 *)(lVar13 + 0x30);
                                  *(undefined4 *)(plVar12 + 8) = 0xffffffff;
                                  if (plVar14 != (longlong *)0x0) {
                                    plVar12[2] = 0;
                                    *plVar14 = *plVar14 + -1;
                                    if (*plVar14 == 0) {
                                      (**(code **)(plVar14[1] + 0x30))();
                                    }
                                  }
                                  *plVar12 = *plVar12 + -1;
                                  if (*plVar12 == 0) {
                                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                                  }
                                  plVar12[0xf] = 0;
                                  uVar18 = FUN_23e8d8bc0(*(undefined8 *)(lVar8 + 0x10),
                                                         _DAT_23ee29df8,_DAT_23ee29e10,
                                                         _DAT_23ee29e28);
                                  FUN_23a3881f0(_DAT_23ee29e48,DAT_23ed6cda8,uVar18);
                                  pcVar9 = _DAT_23ee29e50;
                                  *(longlong *)_DAT_23ee29e50 = *(longlong *)_DAT_23ee29e50 + 1;
                                  return pcVar9;
                                }
LAB_23c61deb9:
                                uVar18 = *(undefined8 *)(lVar8 + 0x60);
                                uVar20 = 4;
                                pcVar9 = *(code **)(lVar8 + 0x70);
                                *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(lVar8 + 0x70) = 0;
                                lVar13 = *(longlong *)(lVar8 + 0x68);
                                pcVar10 = DAT_23ed6a4f8;
                                goto joined_r0x00023c61d714;
                              }
                              plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__")
                              ;
                              if (plVar14 != (longlong *)0x0) {
                                *plVar14 = *plVar14 + 1;
                                DAT_23ed6a498 = plVar14;
                                goto LAB_23c61dbbb;
                              }
LAB_23c61dfc8:
                              PyErr_PrintEx(0,0);
                              Py_Exit(1);
LAB_23c61dfdb:
                              lVar16 = FUN_23e8d2cf0(lVar8,plVar5,lStack_198);
LAB_23c61dd95:
                              *plVar5 = *plVar5 + -1;
                              if (*plVar5 == 0) {
                                (**(code **)(plVar5[1] + 0x30))(plVar5);
                                lStack_198 = lVar16;
                              }
                            } while (lVar16 != 0);
                          }
                          uVar18 = *(undefined8 *)(lVar8 + 0x60);
                          uVar20 = 3;
                          pcVar9 = *(code **)(lVar8 + 0x70);
                          *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
                          *(undefined8 *)(lVar8 + 0x70) = 0;
                          lVar13 = *(longlong *)(lVar8 + 0x68);
                          pcVar10 = DAT_23ed6a4f8;
                        }
                        goto joined_r0x00023c61d714;
                      }
                    }
                    goto LAB_23c61d6f0;
                  }
                }
              }
              uVar18 = *(undefined8 *)(lVar8 + 0x60);
              lVar13 = *(longlong *)(lVar8 + 0x68);
              uVar20 = 1;
              pcVar9 = *(code **)(lVar8 + 0x70);
              *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(lVar8 + 0x70) = 0;
              *plVar14 = *plVar14 + -1;
              pcVar10 = DAT_23ed6a4f8;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
                uVar20 = 1;
                pcVar10 = DAT_23ed6a4f8;
              }
              goto joined_r0x00023c61d714;
            }
          }
        }
LAB_23c61d6f0:
        pcVar9 = *(code **)(lVar8 + 0x70);
        *(undefined8 *)(lVar8 + 0x70) = 0;
        uVar20 = 1;
        uVar18 = *(undefined8 *)(lVar8 + 0x60);
        *(undefined1 (*) [16])(lVar8 + 0x60) = (undefined1  [16])0x0;
        lVar13 = *(longlong *)(lVar8 + 0x68);
        pcVar10 = DAT_23ed6a4f8;
joined_r0x00023c61d714:
        DAT_23ed6a4f8 = pcVar10;
        if (pcVar9 == (code *)0x0) {
          if (pcVar10 == (code *)0x0) {
            pcVar10 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            DAT_23ed6a4f8 = *(code **)pcVar10;
            *(longlong *)pcVar10 = 1;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          pcVar9 = _PyRuntime_exref;
          *(longlong **)(pcVar10 + 0x18) = plVar12;
          *(longlong *)(pcVar10 + 0x10) = 0;
          *plVar12 = *plVar12 + 1;
          lVar1 = *(longlong *)(pcVar9 + 0x1f8);
          *(undefined4 *)(pcVar10 + 0x24) = uVar20;
          *(undefined4 *)(pcVar10 + 0x20) = 0xffffffff;
          lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x2e8);
          lVar17 = *(longlong *)(pcVar10 + -8);
          puVar21 = *(undefined8 **)(lVar1 + 8);
          *puVar21 = pcVar10 + -0x10;
          *(longlong *)(pcVar10 + -0x10) = lVar1;
          *(ulonglong *)(pcVar10 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar21;
          *(code **)(lVar1 + 8) = pcVar10 + -0x10;
          pcVar22 = pcVar10;
        }
        else {
          pcVar22 = pcVar9;
          if (*(longlong **)(pcVar9 + 0x18) != plVar12) {
            if (pcVar10 == (code *)0x0) {
              pcVar10 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              DAT_23ed6a4f8 = *(code **)pcVar10;
              *(longlong *)pcVar10 = 1;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            pcVar22 = _PyRuntime_exref;
            *(longlong **)(pcVar10 + 0x18) = plVar12;
            *plVar12 = *plVar12 + 1;
            lVar1 = *(longlong *)(pcVar22 + 0x1f8);
            *(undefined4 *)(pcVar10 + 0x24) = uVar20;
            *(undefined4 *)(pcVar10 + 0x20) = 0xffffffff;
            lVar1 = *(longlong *)(*(longlong *)(lVar1 + 0x10) + 0x2e8);
            lVar17 = *(longlong *)(pcVar10 + -8);
            puVar21 = *(undefined8 **)(lVar1 + 8);
            *puVar21 = pcVar10 + -0x10;
            *(longlong *)(pcVar10 + -0x10) = lVar1;
            *(ulonglong *)(pcVar10 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar21;
            lVar17 = *(longlong *)pcVar9;
            *(code **)(lVar1 + 8) = pcVar10 + -0x10;
            *(code **)(pcVar10 + 0x10) = pcVar9;
            pcVar22 = pcVar10;
            if (lVar17 == 0) {
              (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
            }
          }
        }
        lVar1 = *(longlong *)(*(longlong *)(lVar8 + 0x38) + 8);
        plVar12 = *(longlong **)(lVar1 + 0x28);
        plVar14 = (longlong *)plVar12[2];
        *(undefined8 *)(*(longlong *)(lVar8 + 0x38) + 8) = *(undefined8 *)(lVar1 + 0x30);
        *(undefined4 *)(plVar12 + 8) = 0xffffffff;
        if (plVar14 != (longlong *)0x0) {
          plVar12[2] = 0;
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))();
          }
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plVar12[0xf] = 0;
        FUN_23a33aa70(lVar8,uVar18,lVar13,pcVar22);
        return (code *)0x0;
      }
      *(longlong *)pcVar9 = *(longlong *)pcVar9 + 1;
      DAT_23ed6a4c0 = pcVar9;
    }
    uStack_70 = uVar18;
    puStack_b0 = (undefined8 *)0x23c61c954;
    plStack_78 = plVar14;
    lVar8 = FUN_23e94ed00(param_1,pcVar9,&plStack_78);
    if (lVar8 != 0) {
      plVar5[4] = lVar8;
      puStack_b0 = (undefined8 *)0x23c61c96e;
      plVar6 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar5);
      *plVar5 = *plVar5 + -1;
      if (*plVar5 == 0) {
        puStack_b0 = (undefined8 *)0x23c61cdca;
        (**(code **)(plVar5[1] + 0x30))(plVar5);
      }
      if (plVar6 == (longlong *)0x0) {
        uStack_88 = *(undefined8 *)(param_1 + 0x68);
        plVar6 = *(longlong **)(param_1 + 0x60);
        pcVar9 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar7 = *plVar7 + -1;
        pcVar10 = DAT_23ed6a4f8;
        uVar20 = uStack_7c;
        uVar19 = 0x15f;
        if (*plVar7 == 0) {
          uStack_7c = 0x15f;
          puStack_b0 = (undefined8 *)0x23c61d05e;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
          pcVar10 = DAT_23ed6a4f8;
          uVar20 = uStack_7c;
          uVar19 = uStack_7c;
        }
        goto joined_r0x00023c61cd1c;
      }
      *(undefined4 *)(plVar15 + 5) = 0x15f;
      puStack_b0 = (undefined8 *)0x23c61c999;
      plVar5 = (longlong *)FUN_23e914090(param_1,plVar7,plVar6);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        puStack_b0 = (undefined8 *)0x23c61c9ac;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      *plVar6 = *plVar6 + -1;
      if (*plVar6 == 0) {
        puStack_b0 = (undefined8 *)0x23c61cdda;
        (**(code **)(plVar6[1] + 0x30))(plVar6);
      }
      if (plVar5 != (longlong *)0x0) {
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          puStack_b0 = (undefined8 *)0x23c61c9d0;
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar5 = *(longlong **)(lVar8 + 0x28);
        plVar15 = (longlong *)plVar5[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
        *(undefined4 *)(plVar5 + 8) = 0xffffffff;
        if (plVar15 != (longlong *)0x0) {
          plVar5[2] = 0;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            puStack_b0 = (undefined8 *)0x23c61ca09;
            (**(code **)(plVar15[1] + 0x30))();
          }
        }
        *plVar5 = *plVar5 + -1;
        if (*plVar5 == 0) {
          puStack_b0 = (undefined8 *)0x23c61ca19;
          (**(code **)(plVar5[1] + 0x30))(plVar5);
        }
        plVar5[0xf] = 0;
        pcVar9 = _Py_NoneStruct_exref;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          puStack_b0 = (undefined8 *)0x23c61ca3e;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar14 = *plVar14 + -1;
        if (*plVar14 != 0) {
          return pcVar9;
        }
        puStack_b0 = (undefined8 *)0x23c61cdea;
        (**(code **)(plVar14[1] + 0x30))(plVar14);
        return pcVar9;
      }
      goto LAB_23c61ce60;
    }
    uStack_88 = *(undefined8 *)(param_1 + 0x68);
    plVar6 = *(longlong **)(param_1 + 0x60);
    pcVar9 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_b0 = (undefined8 *)0x23c61cef1;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    *plVar5 = *plVar5 + -1;
    lVar8 = *plVar5;
    uVar19 = 0x15f;
    uVar20 = uStack_7c;
    uStack_7c = 0x15f;
  }
  else {
    iVar4 = *(int *)(lVar8 + 0xc);
    if (*(int *)(lVar8 + 0xc) == 0) {
      *(int *)(lVar8 + 0xc) = DAT_23ec12b2c;
      iVar4 = DAT_23ec12b2c;
      DAT_23ec12b2c = DAT_23ec12b2c + 1;
    }
    if (_DAT_23ec12b20 != iVar4) {
      puStack_b0 = (undefined8 *)0x23c61cc99;
      _DAT_23ec12b20 = iVar4;
      _DAT_23ee29e88 = FUN_23e8cbd60(lVar8,DAT_23ee29538,*(undefined8 *)(DAT_23ee29538 + 0x18));
    }
    if (-1 < _DAT_23ee29e88) {
      lVar1 = lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f));
      lVar13 = *(longlong *)(lVar1 + 8 + _DAT_23ee29e88 * 0x10);
      if (lVar13 != 0) goto LAB_23c61c7fc;
      puStack_b0 = (undefined8 *)0x23c61d083;
      _DAT_23ee29e88 = FUN_23e8cbd60(lVar8,DAT_23ee29538,*(undefined8 *)(DAT_23ee29538 + 0x18));
      if (-1 < _DAT_23ee29e88) {
        lVar13 = *(longlong *)(lVar1 + 8 + _DAT_23ee29e88 * 0x10);
        goto LAB_23c61cf48;
      }
    }
LAB_23c61cca9:
    puStack_b0 = (undefined8 *)0x23c61ccbf;
    plVar6 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ee29538);
    if ((plVar6 != (longlong *)0x0) && (lVar13 = *plVar6, lVar13 != 0)) goto LAB_23c61c7fc;
    puStack_b0 = (undefined8 *)0x23c61cce4;
    FUN_23e915740(param_1,&plStack_78,DAT_23ee29538);
    uStack_88 = uStack_70;
    plVar6 = plStack_78;
LAB_23c61ccf8:
    *plVar5 = *plVar5 + -1;
    lVar8 = *plVar5;
    uVar19 = 0x15e;
    pcVar9 = pcStack_68;
    uVar20 = uStack_7c;
    uStack_7c = 0x15e;
  }
  pcVar10 = DAT_23ed6a4f8;
  if (lVar8 == 0) {
    puStack_b0 = (undefined8 *)0x23c61cd15;
    (**(code **)(plVar5[1] + 0x30))(plVar5);
    pcVar10 = DAT_23ed6a4f8;
    uVar20 = uStack_7c;
    uVar19 = uStack_7c;
  }
joined_r0x00023c61cd1c:
  uStack_7c = uVar19;
  DAT_23ed6a4f8 = pcVar10;
  if (pcVar9 == (code *)0x0) {
    if (pcVar10 == (code *)0x0) {
      puStack_b0 = (undefined8 *)0x23c61d0b8;
      pcVar10 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar20 = uStack_7c;
      uVar19 = uStack_7c;
    }
    else {
      DAT_23ed6a4f8 = *(code **)pcVar10;
      *(longlong *)pcVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      uVar19 = uStack_7c;
    }
    uStack_7c = uVar20;
    pcVar9 = _PyRuntime_exref;
    *(longlong *)(pcVar10 + 0x10) = 0;
    *(longlong **)(pcVar10 + 0x18) = plVar15;
    *plVar15 = *plVar15 + 1;
    lVar8 = *(longlong *)(pcVar9 + 0x1f8);
    *(undefined4 *)(pcVar10 + 0x24) = uVar19;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(pcVar10 + 0x20) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar13 = *(longlong *)(pcVar10 + -8);
    puVar21 = *(undefined8 **)(lVar8 + 8);
    *puVar21 = pcVar10 + -0x10;
    *(longlong *)(pcVar10 + -0x10) = lVar8;
    *(ulonglong *)(pcVar10 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar21;
    *(code **)(lVar8 + 8) = pcVar10 + -0x10;
    pcVar22 = pcVar10;
    uVar20 = uStack_7c;
  }
  else {
    pcVar22 = pcVar9;
    if (*(longlong **)(pcVar9 + 0x18) != plVar15) {
      if (pcVar10 == (code *)0x0) {
        puStack_b0 = (undefined8 *)0x23c61cfa0;
        pcVar10 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar20 = uStack_7c;
        uVar19 = uStack_7c;
      }
      else {
        DAT_23ed6a4f8 = *(code **)pcVar10;
        *(longlong *)pcVar10 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        uVar19 = uStack_7c;
      }
      uStack_7c = uVar20;
      pcVar22 = _PyRuntime_exref;
      *(longlong **)(pcVar10 + 0x18) = plVar15;
      *plVar15 = *plVar15 + 1;
      lVar8 = *(longlong *)(pcVar22 + 0x1f8);
      *(undefined4 *)(pcVar10 + 0x24) = uVar19;
      *(undefined4 *)(pcVar10 + 0x20) = 0xffffffff;
      lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
      lVar13 = *(longlong *)(pcVar10 + -8);
      puVar21 = *(undefined8 **)(lVar8 + 8);
      *puVar21 = pcVar10 + -0x10;
      *(longlong *)(pcVar10 + -0x10) = lVar8;
      *(ulonglong *)(pcVar10 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar21;
      lVar13 = *(longlong *)pcVar9;
      *(code **)(lVar8 + 8) = pcVar10 + -0x10;
      *(code **)(pcVar10 + 0x10) = pcVar9;
      pcVar22 = pcVar10;
      uVar20 = uStack_7c;
      if (lVar13 == 0) {
        puStack_b0 = (undefined8 *)0x23c61cb97;
        (**(code **)(*(longlong *)(pcVar9 + 8) + 0x30))(pcVar9);
        uVar20 = uStack_7c;
      }
    }
  }
  uStack_7c = uVar20;
  puStack_b0 = (undefined8 *)0x23c61cbaf;
  FUN_23e8bba40(plVar15,&DAT_23ec47929,plVar12,plVar14);
  if (_DAT_23ee29e98 == plVar15) {
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      puStack_b0 = (undefined8 *)0x23c61ce00;
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    _DAT_23ee29e98 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar5 = *(longlong **)(lVar8 + 0x28);
  plVar15 = (longlong *)plVar5[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  *(undefined4 *)(plVar5 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar5[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      puStack_b0 = (undefined8 *)0x23c61cbf5;
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar5 = *plVar5 + -1;
  if (*plVar5 == 0) {
    puStack_b0 = (undefined8 *)0x23c61cc05;
    (**(code **)(plVar5[1] + 0x30))(plVar5);
  }
  plVar5[0xf] = 0;
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    puStack_b0 = (undefined8 *)0x23c61cc1f;
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  *plVar14 = *plVar14 + -1;
  if (*plVar14 == 0) {
    puStack_b0 = (undefined8 *)0x23c61cc30;
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  puStack_b0 = (undefined8 *)0x23c61cc43;
  FUN_23a33aa70(param_1,plVar6,uStack_88,pcVar22);
  return (code *)0x0;
}
