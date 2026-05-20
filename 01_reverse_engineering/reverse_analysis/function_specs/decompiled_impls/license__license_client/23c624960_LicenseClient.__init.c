/* ===== 23c624960 license.license_client:79 ===== */
/* ghidra_name=FUN_23c624960 entry=23c624960 size=7396 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23c624960(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined1 auVar6 [16];
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  longlong *plVar21;
  undefined1 auVar22 [8];
  code *pcVar23;
  code *pcStack_120;
  code *pcStack_f8;
  undefined8 uStack_f0;
  undefined1 auStack_e8 [16];
  code *apcStack_d8 [2];
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  longlong *plStack_b8;
  undefined1 auStack_a8 [8];
  code *pcStack_a0;
  code *pcStack_98;
  longlong *plStack_88;
  code *pcStack_80;
  code *pcStack_78;
  
  plVar9 = _DAT_23ee29cd0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  pcStack_98 = (code *)0x0;
  auStack_a8 = (undefined1  [8])0x0;
  pcStack_a0 = (code *)0x0;
  if (_DAT_23ee29cd0 == (longlong *)0x0) {
LAB_23c6249c9:
    _DAT_23ee29cd0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29cc8,DAT_23ee29d18,0x30);
  }
  else {
    lVar14 = *_DAT_23ee29cd0;
    if (1 < lVar14) {
      *_DAT_23ee29cd0 = lVar14 + -1;
      goto LAB_23c6249c9;
    }
    if (_DAT_23ee29cd0[2] != 0) {
      *_DAT_23ee29cd0 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23c6249c9;
    }
  }
  plVar3 = _DAT_23ee29cd0;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23ee29cd0 + 9;
  lVar10 = *(longlong *)(lVar14 + 8);
  _DAT_23ee29cd0[0xf] = lVar10;
  *(longlong **)(lVar14 + 8) = plVar9;
  if ((lVar10 != 0) &&
     (((*(char *)(lVar10 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar10 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar10 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar10 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar10 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar13 = DAT_23ee283a0;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar9 == (longlong *)0x0) {
LAB_23c624a94:
    pcStack_98 = *(code **)(param_1 + 0x70);
    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_a0 = *(code **)(param_1 + 0x68);
    iVar8 = 0x53;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23c624ac3:
    plVar12 = (longlong *)0x0;
    plVar9 = (longlong *)0x0;
    pcStack_120 = _Py_NoneStruct_exref;
    plVar11 = (longlong *)0x0;
    pcVar20 = pcStack_98;
    auVar22 = auStack_a8;
    pcVar19 = pcStack_a0;
  }
  else {
    cVar7 = FUN_23a39bc50(param_1,plVar2,DAT_23ee28450,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if (cVar7 == '\0') goto LAB_23c624a94;
    lVar14 = FUN_23ead5df0();
    if (lVar14 == 0) {
      FUN_23e915740(param_1,auStack_a8,_DAT_23ee28458);
LAB_23c62519d:
      iVar8 = 0x54;
      goto LAB_23c624ac3;
    }
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23ee28460);
    if (plVar9 == (longlong *)0x0) {
      pcVar20 = *(code **)(param_1 + 0x70);
      auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
      plVar12 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      iVar8 = 0x54;
      pcStack_120 = _Py_NoneStruct_exref;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      pcVar19 = *(code **)(param_1 + 0x68);
      goto LAB_23c624ad7;
    }
    lVar14 = FUN_23ead5ca0();
    if (lVar14 == 0) {
      FUN_23e915740(param_1,auStack_a8,_DAT_23ee28468);
      *plVar9 = *plVar9 + -1;
      lVar14 = *plVar9;
joined_r0x00023c625f1b:
      if (lVar14 == 0) {
        (**(code **)(plVar9[1] + 0x30))();
      }
      goto LAB_23c62519d;
    }
    plVar11 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23ee28470);
    if (plVar11 == (longlong *)0x0) {
      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_a0 = *(code **)(param_1 + 0x68);
      pcStack_98 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar9 = *plVar9 + -1;
      lVar14 = *plVar9;
      goto joined_r0x00023c625f1b;
    }
    *(undefined4 *)(plVar3 + 5) = 0x54;
    plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    *plVar11 = *plVar11 + -1;
    if (*plVar11 == 0) {
      (**(code **)(plVar11[1] + 0x30))();
    }
    if (plVar12 == (longlong *)0x0) {
LAB_23c625174:
      pcStack_98 = *(code **)(param_1 + 0x70);
      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_a0 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23c62519d;
    }
    *(undefined4 *)(plVar3 + 5) = 0x54;
    plVar9 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23ee28478);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23c625174;
    cVar7 = FUN_23a39bc50(param_1,plVar2,_DAT_23ee28480,plVar9);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if (cVar7 == '\0') goto LAB_23c625174;
    lVar14 = FUN_23ead5b50();
    if (lVar14 == 0) {
      FUN_23e915740(param_1,auStack_a8,_DAT_23ee28488);
      plVar9 = (longlong *)0x0;
LAB_23c626028:
      plVar12 = (longlong *)0x0;
      iVar8 = 0x57;
      pcStack_120 = _Py_NoneStruct_exref;
      plVar11 = (longlong *)0x0;
      pcVar20 = pcStack_98;
      auVar22 = auStack_a8;
      pcVar19 = pcStack_a0;
    }
    else {
      *(undefined4 *)(plVar3 + 5) = 0x57;
      plVar9 = (longlong *)FUN_23e915840(param_1,lVar14,_DAT_23ee28490,plVar2);
      if (plVar9 == (longlong *)0x0) {
        pcStack_98 = *(code **)(param_1 + 0x70);
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c626028;
      }
      *(undefined4 *)(plVar3 + 5) = 0x58;
      plVar12 = (longlong *)FUN_23e915840(param_1,plVar1,_DAT_23ee28498,plVar9);
      if (plVar12 == (longlong *)0x0) {
        pcVar20 = *(code **)(param_1 + 0x70);
        auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar8 = 0x58;
        pcStack_120 = _Py_NoneStruct_exref;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar11 = (longlong *)0x0;
        pcVar19 = *(code **)(param_1 + 0x68);
      }
      else {
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee28358);
        pcStack_120 = _Py_NoneStruct_exref;
        if (plVar11 == (longlong *)0x0) {
          pcVar20 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          iVar8 = 0x5a;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar11 = (longlong *)0x0;
          pcVar19 = *(code **)(param_1 + 0x68);
        }
        else {
          plVar21 = (longlong *)FUN_23e91c870(param_1,plVar11,_DAT_23ee284a0,0);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          if (plVar21 == (longlong *)0x0) {
            auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar19 = *(code **)(param_1 + 0x68);
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          else {
            plVar16 = (longlong *)FUN_23e8d9880(plVar21,DAT_23ed6cd90);
            if (plVar16 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0x5a;
              plVar11 = (longlong *)FUN_23e91a870(param_1,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))();
              }
              if (plVar11 != (longlong *)0x0) {
                plVar16 = (longlong *)FUN_23e8d9880(plVar21,DAT_23ed6cd98);
                pcStack_120 = _Py_NoneStruct_exref;
                uVar13 = _DAT_23ee284a8;
                if (plVar16 == (longlong *)0x0) {
                  pcVar20 = *(code **)(param_1 + 0x70);
                  auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcVar19 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  iVar8 = 0x5a;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar15 = (longlong *)0x0;
                }
                else {
                  *plVar11 = *plVar11 + 1;
                  *(undefined4 *)(plVar3 + 5) = 0x5b;
                  plVar17 = (longlong *)FUN_23e915840(param_1,plVar11,uVar13);
                  plVar15 = plVar11;
                  if (plVar17 == (longlong *)0x0) {
                    uStack_c8 = *(undefined8 *)(param_1 + 0x60);
                    uStack_c0 = *(undefined8 *)(param_1 + 0x68);
                    plVar17 = *(longlong **)(param_1 + 0x70);
                    plVar4 = *(longlong **)(param_1 + 0x138);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_98 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    auStack_a8 = (undefined1  [8])0x0;
                    pcStack_a0 = (code *)0x0;
                    if (plVar4 != (longlong *)0x0) {
                      *plVar4 = *plVar4 + 1;
                    }
                    plStack_b8 = plVar17;
                    if (plVar17 == (longlong *)0x0) {
                      lVar14 = FUN_23e8d6280(plVar3,0x5b);
                    }
                    else {
                      lVar14 = FUN_23e8d6280(plVar3,0x5b);
                      *(longlong **)(lVar14 + 0x10) = plVar17;
                      *plVar17 = *plVar17 + 1;
                    }
                    if ((plStack_b8 != (longlong *)0x0) &&
                       (*plStack_b8 = *plStack_b8 + -1, *plStack_b8 == 0)) {
                      FUN_23a334bc0();
                    }
                    plStack_b8 = (longlong *)lVar14;
                    FUN_23a35ef40(param_1,&uStack_c8);
                    iVar8 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                   (*(longlong *)(param_1 + 0x138) + 8),
                                          *(undefined8 *)PyExc_BaseException_exref);
                    if (iVar8 == 0) {
                      cVar7 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
                      pcStack_78 = pcStack_98;
                      pcStack_80 = pcStack_a0;
                      plStack_88 = (longlong *)auStack_a8;
                      iVar8 = 0;
                      if (cVar7 == '\0') {
                        iVar8 = 0x5a;
                      }
                      if ((pcStack_98 != (code *)0x0) &&
                         (*(longlong **)(pcStack_98 + 0x18) == plVar3)) {
                        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcStack_98 + 0x24);
                      }
                      pcStack_98 = (code *)0x0;
                      _auStack_a8 = (undefined1  [16])0x0;
                      FUN_23ebf6ae0(param_1);
                      uVar13 = _DAT_23ee284b0;
                      *(undefined4 *)(plVar3 + 5) = 0x5a;
                      pcStack_98 = (code *)0x0;
                      _auStack_a8 = (undefined1  [16])0x0;
                      plVar17 = (longlong *)FUN_23e957a30(param_1,plVar16,uVar13);
                      if (plVar17 == (longlong *)0x0) {
                        pcStack_98 = *(code **)(param_1 + 0x70);
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        FUN_23a35d6b0(&plStack_88);
                        iVar8 = 0x5a;
                        pcStack_120 = _Py_NoneStruct_exref;
                        pcVar20 = pcStack_98;
                        auVar22 = auStack_a8;
                        pcVar19 = pcStack_a0;
                      }
                      else {
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0();
                          pcStack_120 = _Py_NoneStruct_exref;
                          pcVar20 = pcStack_78;
                          auVar22 = (undefined1  [8])plStack_88;
                          pcVar19 = pcStack_80;
                        }
                        else {
                          pcStack_120 = _Py_NoneStruct_exref;
                          pcVar20 = pcStack_78;
                          auVar22 = (undefined1  [8])plStack_88;
                          pcVar19 = pcStack_80;
                        }
                      }
                    }
                    else {
                      pcStack_80 = *(code **)(param_1 + 0x138);
                      plStack_88 = *(longlong **)(pcStack_80 + 8);
                      pcStack_78 = _Py_NoneStruct_exref;
                      if (*(code **)(pcStack_80 + 0x28) != (code *)0x0) {
                        pcStack_78 = *(code **)(pcStack_80 + 0x28);
                      }
                      pcStack_120 = _Py_NoneStruct_exref;
                      *(undefined4 *)(plVar3 + 5) = 0x5a;
                      plVar17 = (longlong *)FUN_23e956150(param_1,plVar16,&plStack_88);
                      if (plVar17 == (longlong *)0x0) {
LAB_23c62662a:
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        pcVar20 = *(code **)(param_1 + 0x70);
                        iVar8 = 0x5a;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        iVar8 = FUN_23a35f020();
                        *plVar17 = *plVar17 + -1;
                        if (*plVar17 == 0) {
                          FUN_23a334bc0();
                        }
                        if (iVar8 == -1) goto LAB_23c62662a;
                        if (iVar8 != 0) {
                          FUN_23ebf6ae0(param_1,plVar4);
                          goto LAB_23c625e62;
                        }
                        cVar7 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
                        iVar8 = 0;
                        if (cVar7 == '\0') {
                          iVar8 = 0x5a;
                        }
                        pcVar20 = pcStack_98;
                        if ((pcStack_98 != (code *)0x0) &&
                           (*(longlong **)(pcStack_98 + 0x18) == plVar3)) {
                          *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcStack_98 + 0x24);
                        }
                      }
                      pcVar19 = pcStack_a0;
                      auVar22 = auStack_a8;
                      pcStack_98 = (code *)0x0;
                      _auStack_a8 = (undefined1  [16])0x0;
                      FUN_23ebf6ae0(param_1,plVar4);
                      plStack_88 = (longlong *)auVar22;
                      pcStack_80 = pcVar19;
                      pcStack_78 = pcVar20;
                    }
                  }
                  else {
                    *plVar17 = *plVar17 + -1;
                    if (*plVar17 == 0) {
                      FUN_23a334bc0();
                    }
                    *(undefined4 *)(plVar3 + 5) = 0x5a;
                    plVar17 = (longlong *)FUN_23e957a30(param_1,plVar16,_DAT_23ee284b0);
                    if (plVar17 != (longlong *)0x0) {
                      *plVar17 = *plVar17 + -1;
                      pcStack_120 = _Py_NoneStruct_exref;
                      if (*plVar17 == 0) {
                        FUN_23a334bc0(plVar17);
                      }
LAB_23c625e62:
                      *plVar21 = *plVar21 + -1;
                      if (*plVar21 == 0) {
                        FUN_23a334bc0(plVar21);
                      }
                      lVar14 = *plVar11;
                      *plVar11 = lVar14 + -1;
                      if (lVar14 + -1 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                      lVar14 = *plVar16;
                      *plVar16 = lVar14 + -1;
                      if (lVar14 + -1 == 0) {
                        FUN_23a334bc0(plVar16);
                      }
                      lVar10 = FUN_23ead5f40();
                      lVar14 = _DAT_23ee284b8;
                      if (lVar10 == 0) {
                        FUN_23e915740(param_1,auStack_a8,DAT_23ee283f8);
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0x5d;
                        plVar21 = (longlong *)
                                  FUN_23e915840(param_1,lVar10,DAT_23ee28400,
                                                *(undefined8 *)(lVar14 + 0x18));
                        if (plVar21 != (longlong *)0x0) {
                          *plVar21 = *plVar21 + -1;
                          if (*plVar21 == 0) {
                            FUN_23a334bc0();
                          }
LAB_23c62544b:
                          lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar3 = *(longlong **)(lVar14 + 0x28);
                          plVar21 = (longlong *)plVar3[2];
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar14 + 0x30);
                          *(undefined4 *)(plVar3 + 8) = 0xffffffff;
                          if (plVar21 != (longlong *)0x0) {
                            plVar3[2] = 0;
                            *plVar21 = *plVar21 + -1;
                            if (*plVar21 == 0) {
                              (**(code **)(plVar21[1] + 0x30))();
                            }
                          }
                          *plVar3 = *plVar3 + -1;
                          if (*plVar3 == 0) {
                            (**(code **)(plVar3[1] + 0x30))(plVar3);
                          }
                          plVar3[0xf] = 0;
                          *(longlong *)pcStack_120 = *(longlong *)pcStack_120 + 1;
                          if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0))
                          {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          if ((plVar12 != (longlong *)0x0) &&
                             (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                            (**(code **)(plVar12[1] + 0x30))(plVar12);
                          }
                          if ((plVar11 != (longlong *)0x0) &&
                             (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                            (**(code **)(plVar11[1] + 0x30))(plVar11);
                          }
                          *plVar1 = *plVar1 + -1;
                          if (*plVar1 == 0) {
                            (**(code **)(plVar1[1] + 0x30))(plVar1);
                          }
                          *plVar2 = *plVar2 + -1;
                          if (*plVar2 != 0) {
                            return pcStack_120;
                          }
                          (**(code **)(plVar2[1] + 0x30))(plVar2);
                          return pcStack_120;
                        }
                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_a0 = *(code **)(param_1 + 0x68);
                        pcStack_98 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      iVar8 = 0x5d;
                      pcVar20 = pcStack_98;
                      auVar22 = auStack_a8;
                      pcVar19 = pcStack_a0;
                      goto LAB_23c624ad7;
                    }
                    auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    pcStack_120 = _Py_NoneStruct_exref;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    iVar8 = 0x5a;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar19 = *(code **)(param_1 + 0x68);
                  }
                }
                pcStack_98 = (code *)0x0;
                auStack_a8 = (undefined1  [8])0x0;
                pcStack_a0 = (code *)0x0;
                *plVar21 = *plVar21 + -1;
                if (*plVar21 == 0) {
                  (**(code **)(plVar21[1] + 0x30))(plVar21);
                }
                lVar14 = *plVar11;
                *plVar11 = lVar14 + -1;
                if (lVar14 + -1 == 0) {
                  (**(code **)(plVar11[1] + 0x30))();
                }
                plVar11 = plVar15;
                if ((plVar16 != (longlong *)0x0) &&
                   (lVar14 = *plVar16, *plVar16 = lVar14 + -1, lVar14 + -1 == 0)) {
                  (**(code **)(plVar16[1] + 0x30))();
                }
                goto LAB_23c624ad7;
              }
            }
            pcVar20 = *(code **)(param_1 + 0x70);
            auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcVar19 = *(code **)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_98 = (code *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            auStack_a8 = (undefined1  [8])0x0;
            pcStack_a0 = (code *)0x0;
            *plVar21 = *plVar21 + -1;
            if (*plVar21 == 0) {
              plVar11 = (longlong *)0x0;
              (**(code **)(plVar21[1] + 0x30))();
              iVar8 = 0x5a;
              pcStack_120 = _Py_NoneStruct_exref;
              goto LAB_23c624ad7;
            }
          }
          pcStack_120 = _Py_NoneStruct_exref;
          plVar11 = (longlong *)0x0;
          iVar8 = 0x5a;
        }
      }
    }
  }
LAB_23c624ad7:
  pcStack_a0 = pcVar19;
  auStack_a8 = auVar22;
  pcStack_98 = pcVar20;
  pcVar20 = pcStack_98;
  auStack_e8._8_8_ = pcStack_a0;
  auStack_e8._0_8_ = auStack_a8;
  pcStack_98 = (code *)0x0;
  auStack_a8 = (undefined1  [8])0x0;
  pcStack_a0 = (code *)0x0;
  apcStack_d8[0] = pcVar20;
  plVar21 = *(longlong **)(param_1 + 0x138);
  if (plVar21 != (longlong *)0x0) {
    *plVar21 = *plVar21 + 1;
  }
  pcVar19 = DAT_23ed6a4f8;
  if (pcVar20 == (code *)0x0) {
    if (iVar8 == 0) {
      iVar8 = (int)plVar3[5];
    }
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar20 = apcStack_d8[0];
    }
    else {
      pcVar20 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar20 = (code *)0x0;
    }
    pcVar18 = _PyRuntime_exref;
    *(longlong *)(pcVar19 + 0x10) = 0;
    *(longlong **)(pcVar19 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar14 = *(longlong *)(pcVar18 + 0x1f8);
    *(int *)(pcVar19 + 0x24) = iVar8;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar10 = *(longlong *)(pcVar19 + -8);
    plVar16 = *(longlong **)(lVar14 + 8);
    *plVar16 = (longlong)(pcVar19 + -0x10);
    *(longlong *)(pcVar19 + -0x10) = lVar14;
    *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)plVar16;
    *(code **)(lVar14 + 8) = pcVar19 + -0x10;
    pcVar18 = pcVar19;
    if ((pcVar20 != (code *)0x0) &&
       (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
      (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
    }
  }
  else {
    pcVar18 = apcStack_d8[0];
    if (iVar8 != 0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcVar18 = _PyRuntime_exref;
      *(longlong **)(pcVar19 + 0x18) = plVar3;
      *plVar3 = *plVar3 + 1;
      lVar14 = *(longlong *)(pcVar18 + 0x1f8);
      *(int *)(pcVar19 + 0x24) = iVar8;
      *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
      lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      lVar10 = *(longlong *)(pcVar19 + -8);
      plVar16 = *(longlong **)(lVar14 + 8);
      *plVar16 = (longlong)(pcVar19 + -0x10);
      *(longlong *)(pcVar19 + -0x10) = lVar14;
      *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)plVar16;
      *(code **)(lVar14 + 8) = pcVar19 + -0x10;
      *(code **)(pcVar19 + 0x10) = pcVar20;
      *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
      pcVar18 = pcVar19;
      if ((apcStack_d8[0] != (code *)0x0) &&
         (*(longlong *)apcStack_d8[0] = *(longlong *)apcStack_d8[0] + -1,
         *(longlong *)apcStack_d8[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_d8[0] + 8) + 0x30))();
      }
    }
  }
  apcStack_d8[0] = pcVar18;
  if (((code *)auStack_e8._0_8_ != (code *)0x0) && ((code *)auStack_e8._0_8_ != pcStack_120)) {
    FUN_23e91b1b0(param_1,auStack_e8,auStack_e8 + 8,apcStack_d8);
  }
  plVar16 = *(longlong **)(auStack_e8._8_8_ + 0x28);
  if (apcStack_d8[0] == pcStack_120) {
    pcVar20 = (code *)0x0;
  }
  else {
    pcVar20 = apcStack_d8[0];
    if (apcStack_d8[0] != (code *)0x0) {
      *(longlong *)apcStack_d8[0] = *(longlong *)apcStack_d8[0] + 1;
    }
  }
  *(code **)(auStack_e8._8_8_ + 0x28) = pcVar20;
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))();
  }
  plVar16 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = auStack_e8._8_8_;
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    (**(code **)(plVar16[1] + 0x30))();
  }
  *(longlong *)auStack_e8._0_8_ = *(longlong *)auStack_e8._0_8_ + -1;
  if (*(longlong *)auStack_e8._0_8_ == 0) {
    (**(code **)(*(longlong *)(auStack_e8._0_8_ + 8) + 0x30))();
  }
  if ((apcStack_d8[0] != (code *)0x0) &&
     (*(longlong *)apcStack_d8[0] = *(longlong *)apcStack_d8[0] + -1,
     *(longlong *)apcStack_d8[0] == 0)) {
    (**(code **)(*(longlong *)(apcStack_d8[0] + 8) + 0x30))();
  }
  pcVar20 = *(code **)(param_1 + 0x138);
  apcStack_d8[0] = (code *)0x0;
  auStack_e8 = (undefined1  [16])0x0;
  pcVar19 = *(code **)PyExc_Exception_exref;
  pcVar18 = *(code **)(pcVar20 + 8);
  if ((*(uint *)(*(longlong *)(pcVar19 + 8) + 0xa8) & 0x4000000) == 0) {
    if ((-1 < (int)*(uint *)(*(longlong *)(pcVar19 + 8) + 0xa8)) ||
       (((byte)pcVar19[0xab] & 0x40) == 0)) {
      plVar15 = *(longlong **)PyExc_TypeError_exref;
      uVar13 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar17 = *(longlong **)(param_1 + 0x60);
      plVar4 = *(longlong **)(param_1 + 0x68);
      plVar16 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar15;
      *plVar15 = *plVar15 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar13;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
      }
      if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
      }
LAB_23c625242:
      if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
LAB_23c625252:
      pcVar23 = *(code **)(param_1 + 0x138);
LAB_23c625259:
      *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
      lVar14 = FUN_23ead5f40();
      if (lVar14 == 0) {
        FUN_23e915740(param_1,auStack_a8,DAT_23ee283f8);
        pcVar20 = pcStack_a0;
        pcVar19 = pcStack_98;
        auVar22 = auStack_a8;
      }
      else {
        plVar15 = (longlong *)FUN_23e8bc2f0(lVar14,DAT_23ee284c0);
        plVar16 = _DAT_23ee284c8;
        if (plVar15 == (longlong *)0x0) {
LAB_23c6257d0:
          pcVar19 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          auVar22 = *(undefined1 (*) [8])(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          pcVar20 = *(code **)(param_1 + 0x68);
          goto LAB_23c6257ec;
        }
        lVar14 = *(longlong *)(param_1 + 0x10);
        pcVar18 = *(code **)(lVar14 + 0xe20);
        if (pcVar18 == (code *)0x0) {
          pcVar18 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
        }
        else {
          lVar10 = *(longlong *)(pcVar18 + 0x18);
          *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
          *(longlong *)(lVar14 + 0xe20) = lVar10;
          *(longlong *)pcVar18 = 1;
        }
        pcVar20 = _PyRuntime_exref;
        *(longlong *)(pcVar18 + 0x20) = 0;
        lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8);
        lVar10 = *(longlong *)(pcVar18 + -8);
        puVar5 = *(undefined8 **)(lVar14 + 8);
        *puVar5 = pcVar18 + -0x10;
        *(longlong *)(pcVar18 + -0x10) = lVar14;
        *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)puVar5;
        *(code **)(lVar14 + 8) = pcVar18 + -0x10;
        pcVar19 = DAT_23ed6a4c0;
        *plVar16 = *plVar16 + 1;
        *(longlong **)(pcVar18 + 0x18) = plVar16;
        uVar13 = DAT_23ed6cd28;
        if (pcVar19 == (code *)0x0) {
          pcVar19 = (code *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (pcVar19 != (code *)0x0) {
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
            DAT_23ed6a4c0 = pcVar19;
            goto LAB_23c625334;
          }
          PyErr_PrintEx(0);
          pcVar20 = (code *)Py_Exit(1);
LAB_23c625014:
          lVar14 = *(longlong *)(pcVar18 + 0x158);
          pcVar23 = pcVar20;
          if (lVar14 != 0) {
            if (*(longlong *)(lVar14 + 0x10) < 1) goto LAB_23c624cd7;
            lVar10 = 0;
            while (pcVar19 != *(code **)(lVar14 + 0x18 + lVar10 * 8)) {
              lVar10 = lVar10 + 1;
              if (*(longlong *)(lVar14 + 0x10) == lVar10) goto LAB_23c624cd7;
            }
            goto LAB_23c625259;
          }
          do {
            if (pcVar19 == pcVar18) goto LAB_23c625259;
            pcVar18 = *(code **)(pcVar18 + 0x100);
          } while (pcVar18 != (code *)0x0);
          if (pcVar19 == PyBaseObject_Type_exref) goto LAB_23c625259;
          goto LAB_23c624cd7;
        }
LAB_23c625334:
        uStack_f0 = uVar13;
        pcStack_f8 = pcVar23;
        lVar14 = FUN_23e94ed00(param_1,pcVar19,&pcStack_f8);
        if (lVar14 != 0) {
          *(longlong *)(pcVar18 + 0x20) = lVar14;
          plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar18);
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
          if (*(longlong *)pcVar18 == 0) {
            (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
          }
          if (plVar16 == (longlong *)0x0) {
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            pcStack_98 = *(code **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar15 = *plVar15 + -1;
            pcVar20 = pcStack_a0;
            pcVar19 = pcStack_98;
            auVar22 = auStack_a8;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
              pcVar20 = pcStack_a0;
              pcVar19 = pcStack_98;
              auVar22 = auStack_a8;
            }
            goto LAB_23c6257ec;
          }
          *(undefined4 *)(plVar3 + 5) = 0x5f;
          plVar17 = (longlong *)FUN_23e914090(param_1,plVar15);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          *plVar16 = *plVar16 + -1;
          if (*plVar16 == 0) {
            (**(code **)(plVar16[1] + 0x30))(plVar16);
          }
          if (plVar17 == (longlong *)0x0) goto LAB_23c6257d0;
          *plVar17 = *plVar17 + -1;
          if (*plVar17 == 0) {
            (**(code **)(plVar17[1] + 0x30))(plVar17);
          }
          *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
          if (*(longlong *)pcVar23 == 0) {
            (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
          }
          plVar3 = *(longlong **)(param_1 + 0x138);
          *(longlong **)(param_1 + 0x138) = plVar21;
          if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
            (**(code **)(plVar3[1] + 0x30))();
          }
          goto LAB_23c62544b;
        }
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        pcStack_98 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar15 = *plVar15 + -1;
        if (*plVar15 == 0) {
          (**(code **)(plVar15[1] + 0x30))(plVar15);
        }
        *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
        pcVar20 = pcStack_a0;
        pcVar19 = pcStack_98;
        auVar22 = auStack_a8;
        if (*(longlong *)pcVar18 == 0) {
          (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
          pcVar20 = pcStack_a0;
          pcVar19 = pcStack_98;
          auVar22 = auStack_a8;
        }
      }
LAB_23c6257ec:
      pcStack_98 = (code *)0x0;
      _auStack_a8 = (undefined1  [16])0x0;
      *(longlong *)pcVar23 = *(longlong *)pcVar23 + -1;
      if (*(longlong *)pcVar23 == 0) {
        (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
      }
      pcVar18 = *(code **)(param_1 + 0x138);
      iVar8 = 0x5f;
      goto LAB_23c625841;
    }
    pcVar23 = *(code **)(pcVar18 + 8);
    if ((*(uint *)(pcVar23 + 0xa8) & 0x40000000) == 0) {
      if (((int)*(uint *)(pcVar23 + 0xa8) < 0) && (((byte)pcVar18[0xab] & 0x40) != 0))
      goto LAB_23c625014;
    }
    else {
      pcVar18 = pcVar23;
      if (*(int *)(*(longlong *)(pcVar23 + 8) + 0xa8) < 0) goto LAB_23c625014;
    }
    pcVar23 = pcVar20;
    if (pcVar19 == pcVar18) goto LAB_23c625259;
  }
  else {
    lVar14 = *(longlong *)(pcVar19 + 0x10);
    if (0 < lVar14) {
      lVar10 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar19 + lVar10 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar19 + lVar10 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar15 = *(longlong **)PyExc_TypeError_exref;
          uVar13 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar17 = *(longlong **)(param_1 + 0x60);
          plVar16 = *(longlong **)(param_1 + 0x70);
          plVar4 = *(longlong **)(param_1 + 0x68);
          *(longlong **)(param_1 + 0x60) = plVar15;
          *plVar15 = *plVar15 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar13;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
            (**(code **)(plVar17[1] + 0x30))();
          }
          if ((plVar4 != (longlong *)0x0) && (*plVar4 = *plVar4 + -1, *plVar4 == 0)) {
            (**(code **)(plVar4[1] + 0x30))(plVar4);
          }
          goto LAB_23c625242;
        }
        lVar10 = lVar10 + 1;
      } while (lVar14 != lVar10);
      lVar10 = 0;
      do {
        iVar8 = FUN_23a35ebd0(param_1,pcVar18,*(undefined8 *)(pcVar19 + lVar10 * 8 + 0x18));
        if (iVar8 != 0) goto LAB_23c625252;
        lVar10 = lVar10 + 1;
      } while (lVar14 != lVar10);
      pcVar20 = *(code **)(param_1 + 0x138);
    }
  }
LAB_23c624cd7:
  pcStack_a0 = pcVar20;
  if ((pcVar20 == pcStack_120) || (pcVar20 == (code *)0x0)) {
    auVar22 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
    pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar19 = (code *)0x0;
    pcVar18 = *(code **)(param_1 + 0x138);
    iVar8 = 0x51;
    *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
LAB_23c625841:
    *(longlong **)(param_1 + 0x138) = plVar21;
    if (pcVar18 != (code *)0x0) goto LAB_23c624d50;
    pcStack_a0 = pcVar20;
    auStack_a8 = auVar22;
    pcStack_98 = pcVar19;
    if (pcVar19 == (code *)0x0) goto LAB_23c62588f;
LAB_23c624da7:
    pcVar20 = DAT_23ed6a4f8;
    if (*(longlong **)(pcVar19 + 0x18) == plVar3) goto LAB_23c624e64;
    if (iVar8 == 0) {
      iVar8 = (int)plVar3[5];
    }
    pcStack_98 = pcVar19;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar18 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar18 = _PyRuntime_exref;
    *(longlong **)(pcVar20 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar14 = *(longlong *)(pcVar18 + 0x1f8);
    *(int *)(pcVar20 + 0x24) = iVar8;
    *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
    lVar10 = *(longlong *)(pcVar20 + -8);
    plVar21 = *(longlong **)(lVar14 + 8);
    *plVar21 = (longlong)(pcVar20 + -0x10);
    *(longlong *)(pcVar20 + -0x10) = lVar14;
    *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)plVar21;
    *(code **)(lVar14 + 8) = pcVar20 + -0x10;
    *(code **)(pcVar20 + 0x10) = pcVar19;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    pcVar18 = pcStack_98;
  }
  else {
    auVar22 = *(undefined1 (*) [8])(pcVar20 + 8);
    pcVar19 = *(code **)(pcVar20 + 0x28);
    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
    *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
    pcVar18 = pcVar20;
    if (pcVar19 == (code *)0x0) {
      iVar8 = 0;
      *(longlong **)(param_1 + 0x138) = plVar21;
    }
    else {
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      if (*(longlong **)(pcVar19 + 0x18) == plVar3) {
        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar19 + 0x24);
      }
      iVar8 = 0;
      *(longlong **)(param_1 + 0x138) = plVar21;
    }
LAB_23c624d50:
    pcStack_98 = (code *)0x0;
    _auStack_a8 = (undefined1  [16])0x0;
    *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
    if (*(longlong *)pcVar18 == 0) {
      (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
    }
    pcStack_a0 = pcVar20;
    auStack_a8 = auVar22;
    if (pcVar19 != (code *)0x0) goto LAB_23c624da7;
    pcStack_98 = pcVar19;
    if (iVar8 == 0) {
      iVar8 = (int)plVar3[5];
    }
LAB_23c62588f:
    pcVar20 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar18 = pcStack_98;
    }
    else {
      pcVar19 = *(code **)DAT_23ed6a4f8;
      *(undefined8 *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar19;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar18 = (code *)0x0;
    }
    pcVar19 = _PyRuntime_exref;
    *(longlong *)(pcVar20 + 0x10) = 0;
    *(longlong **)(pcVar20 + 0x18) = plVar3;
    *plVar3 = *plVar3 + 1;
    lVar14 = *(longlong *)(pcVar19 + 0x1f8);
    *(int *)(pcVar20 + 0x24) = iVar8;
    lVar14 = *(longlong *)(lVar14 + 0x10);
    *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
    lVar14 = *(longlong *)(lVar14 + 0x2e8);
    lVar10 = *(longlong *)(pcVar20 + -8);
    plVar21 = *(longlong **)(lVar14 + 8);
    *plVar21 = (longlong)(pcVar20 + -0x10);
    *(longlong *)(pcVar20 + -0x10) = lVar14;
    *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar10 & 3) | (ulonglong)plVar21;
    *(code **)(lVar14 + 8) = pcVar20 + -0x10;
  }
  pcVar19 = pcVar20;
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
  }
LAB_23c624e64:
  pcStack_98 = pcVar19;
  FUN_23e8bba40(plVar3,"oooooo",plVar1,plVar2,plVar9,plVar12,plVar11,0);
  if (_DAT_23ee29cd0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ee29cd0 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar14 + 0x28);
  plVar21 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar21 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar21 = *plVar21 + -1;
    if (*plVar21 == 0) {
      (**(code **)(plVar21[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar20 = pcStack_98;
  auVar6 = _auStack_a8;
  plVar3[0xf] = 0;
  _auStack_a8 = (undefined1  [16])0x0;
  pcStack_98 = (code *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar1 = *plVar1 + -1;
  _auStack_a8 = auVar6;
  pcStack_98 = pcVar20;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_a8,pcStack_a0,pcStack_98);
  return (code *)0x0;
}
