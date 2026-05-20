/* ===== 23e163eb0 telegram.handlers.fishing_handle:104 ===== */
/* ghidra_name=FUN_23e163eb0 entry=23e163eb0 size=6958 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_23e163eb0(longlong param_1)

{
  undefined8 *puVar1;
  longlong *plVar2;
  undefined1 auVar3 [16];
  undefined8 uVar4;
  char cVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  code *pcVar15;
  longlong *plVar16;
  longlong lVar17;
  int iVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong *plVar21;
  undefined4 uVar22;
  undefined8 uVar23;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_98;
  code *pcStack_90;
  undefined1 auStack_88 [16];
  longlong *plStack_78;
  
  plVar14 = _DAT_23eeab148;
  plStack_78 = (longlong *)0x0;
  auStack_88 = (undefined1  [16])0x0;
  if (_DAT_23eeab148 == (longlong *)0x0) {
LAB_23e163f12:
    _DAT_23eeab148 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeab140,DAT_23eeab180,0x40);
  }
  else {
    lVar6 = *_DAT_23eeab148;
    if (1 < lVar6) {
      *_DAT_23eeab148 = lVar6 + -1;
      goto LAB_23e163f12;
    }
    if (_DAT_23eeab148[2] != 0) {
      *_DAT_23eeab148 = lVar6 + -1;
      if (lVar6 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e163f12;
    }
  }
  plVar21 = _DAT_23eeab148;
  lVar6 = *(longlong *)(param_1 + 0x38);
  plVar14 = _DAT_23eeab148 + 9;
  lVar17 = *(longlong *)(lVar6 + 8);
  _DAT_23eeab148[0xf] = lVar17;
  *(longlong **)(lVar6 + 8) = plVar14;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar21[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar21[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar21 = *plVar21 + 1;
  *(undefined4 *)(plVar21 + 8) = 0;
  lVar6 = FUN_23e9013c0();
  if (lVar6 == 0) {
    FUN_23e915740(param_1,auStack_88,DAT_23eea9210);
    plStack_c8 = (longlong *)0x0;
  }
  else {
    *(undefined4 *)(plVar21 + 5) = 0x6a;
    plStack_c8 = (longlong *)FUN_23e91bfe0(param_1,lVar6,DAT_23eea9218);
    if (plStack_c8 != (longlong *)0x0) {
      plVar7 = (longlong *)FUN_23e8bc2f0(plStack_c8,DAT_23ed6ce40);
      plVar14 = _DAT_23eea9418;
      lVar6 = DAT_23ed6cce8;
      if (plVar7 == (longlong *)0x0) {
        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_78 = *(longlong **)(param_1 + 0x70);
        plVar7 = (longlong *)0x0;
        plVar14 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar20 = (longlong *)0x0;
        plVar19 = (longlong *)0x0;
        uVar22 = 0x6b;
        plStack_c0 = (longlong *)0x0;
        plStack_e0 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plStack_d8 = (longlong *)0x0;
      }
      else {
        lVar17 = *(longlong *)(param_1 + 0x10);
        iVar18 = *(int *)(lVar17 + 0x1410);
        plVar19 = *(longlong **)(DAT_23ed6cce8 + 0x20);
        *plVar19 = *plVar19 + 1;
        if (iVar18 == 0) {
          pcVar15 = (code *)FUN_23a33a530(PyDict_Type_exref);
          plVar19 = *(longlong **)(lVar6 + 0x20);
        }
        else {
          iVar18 = iVar18 + -1;
          *(int *)(lVar17 + 0x1410) = iVar18;
          pcVar15 = *(code **)(lVar17 + 0x1190 + (longlong)iVar18 * 8);
          *(longlong *)pcVar15 = 1;
        }
        lVar6 = *(longlong *)(lVar6 + 0x28);
        *(longlong **)(pcVar15 + 0x20) = plVar19;
        *(longlong *)(pcVar15 + 0x28) = lVar6;
        *(longlong *)(pcVar15 + 0x10) = 0;
        *(longlong *)(pcVar15 + 0x18) = 1;
        *(undefined4 *)(plVar21 + 5) = 0x6b;
        plStack_98 = plVar14;
        pcStack_90 = pcVar15;
        plStack_e0 = (longlong *)FUN_23e94ed00(param_1,plVar7,&plStack_98);
        lVar6 = *plVar7;
        *plVar7 = lVar6 + -1;
        if (lVar6 + -1 == 0) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
        if (*(longlong *)pcVar15 == 0) {
          (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
        }
        if (plStack_e0 == (longlong *)0x0) {
          auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_78 = *(longlong **)(param_1 + 0x70);
          plVar7 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar20 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          uVar22 = 0x6b;
          plStack_c0 = (longlong *)0x0;
          plStack_d8 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        }
        else {
          plStack_d8 = (longlong *)
                       FUN_23e8d8bc0(*(undefined8 *)(param_1 + 0x10),_DAT_23eea9420,_DAT_23eea9428,
                                     _DAT_23eea9430);
          lVar6 = FUN_23e901140();
          if (lVar6 == 0) {
            FUN_23e915740(param_1,auStack_88,DAT_23eea92b0);
            plStack_c0 = (longlong *)0x0;
          }
          else {
            *(undefined4 *)(plVar21 + 5) = 0x74;
            plStack_c0 = (longlong *)FUN_23e91a870(param_1,lVar6);
            if (plStack_c0 != (longlong *)0x0) {
              plVar8 = (longlong *)FUN_23ebf7180(plStack_d8);
              if (plVar8 == (longlong *)0x0) {
LAB_23e1650b8:
                auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_78 = *(longlong **)(param_1 + 0x70);
                plVar7 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar20 = (longlong *)0x0;
                plVar19 = (longlong *)0x0;
                uVar22 = 0x76;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                plStack_b8 = (longlong *)0x0;
                plVar7 = (longlong *)0x0;
                plVar19 = (longlong *)0x0;
                plVar14 = (longlong *)0x0;
                plVar20 = (longlong *)0x0;
                do {
                  plVar9 = (longlong *)(**(code **)(plVar8[1] + 0xe0))();
                  if (plVar9 == (longlong *)0x0) {
                    cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                    if (cVar5 == '\0') {
                      plVar9 = *(longlong **)(param_1 + 0x70);
                      lVar6 = *(longlong *)(param_1 + 0x60);
                      uVar23 = *(undefined8 *)(param_1 + 0x68);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_78 = (longlong *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      auStack_88 = (undefined1  [16])0x0;
                      if (plStack_b8 != (longlong *)0x0) {
                        uVar22 = 0x76;
                        goto LAB_23e1647c0;
                      }
                      uVar22 = 0x76;
                      goto LAB_23e1647f4;
                    }
                    if ((plStack_b8 != (longlong *)0x0) &&
                       (*plStack_b8 = *plStack_b8 + -1, *plStack_b8 == 0)) {
                      (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    lVar6 = DAT_23eea9328;
                    *(undefined4 *)(plVar21 + 5) = 0x7e;
                    plVar8 = (longlong *)
                             FUN_23e915840(param_1,plStack_c0,DAT_23eea9320,
                                           *(undefined8 *)(lVar6 + 0x18));
                    if (plVar8 == (longlong *)0x0) {
                      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_78 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar22 = 0x7e;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e16481e;
                    }
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    plVar8 = (longlong *)FUN_23e8bc2f0(plStack_c0,_DAT_23eea9400);
                    if (plVar8 == (longlong *)0x0) {
LAB_23e165932:
                      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_78 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar22 = 0x7f;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e16481e;
                    }
                    lVar17 = FUN_23e900ff0();
                    lVar6 = _DAT_23eea9408;
                    if (lVar17 == 0) {
                      FUN_23e915740(param_1,auStack_88,DAT_23eea93e0);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        FUN_23a334bc0(plVar8);
                      }
                    }
                    else {
                      *(undefined4 *)(plVar21 + 5) = 0x7f;
                      plVar9 = (longlong *)FUN_23e9186b0(param_1,lVar17,lVar6 + 0x18,DAT_23eea92c8);
                      if (plVar9 != (longlong *)0x0) {
                        *(undefined4 *)(plVar21 + 5) = 0x7f;
                        plVar10 = (longlong *)FUN_23e914090(param_1,plVar8,plVar9);
                        *plVar8 = *plVar8 + -1;
                        if (*plVar8 == 0) {
                          (**(code **)(plVar8[1] + 0x30))(plVar8);
                        }
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                        if (plVar10 == (longlong *)0x0) goto LAB_23e165932;
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        *(undefined4 *)(plVar21 + 5) = 0x81;
                        lVar6 = FUN_23e91bfe0(param_1,plStack_c0,DAT_23eea9330);
                        if (lVar6 != 0) {
                          lVar17 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar21 = *(longlong **)(lVar17 + 0x28);
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar17 + 0x30);
                          plVar8 = (longlong *)plVar21[2];
                          *(undefined4 *)(plVar21 + 8) = 0xffffffff;
                          if (plVar8 != (longlong *)0x0) {
                            plVar21[2] = 0;
                            *plVar8 = *plVar8 + -1;
                            if (*plVar8 == 0) {
                              (**(code **)(plVar8[1] + 0x30))();
                            }
                          }
                          *plVar21 = *plVar21 + -1;
                          if (*plVar21 == 0) {
                            (**(code **)(plVar21[1] + 0x30))(plVar21);
                          }
                          plVar21[0xf] = 0;
                          lVar17 = *plStack_c8;
                          *plStack_c8 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            (**(code **)(plStack_c8[1] + 0x30))(plStack_c8);
                          }
                          lVar17 = *plStack_e0;
                          *plStack_e0 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            (**(code **)(plStack_e0[1] + 0x30))(plStack_e0);
                          }
                          lVar17 = *plStack_d8;
                          *plStack_d8 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                          }
                          lVar17 = *plStack_c0;
                          *plStack_c0 = lVar17 + -1;
                          if (lVar17 + -1 == 0) {
                            (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
                          }
                          if ((plVar19 != (longlong *)0x0) &&
                             (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
                            (**(code **)(plVar19[1] + 0x30))(plVar19);
                          }
                          if ((plVar20 != (longlong *)0x0) &&
                             (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
                            (**(code **)(plVar20[1] + 0x30))(plVar20);
                          }
                          if ((plVar14 != (longlong *)0x0) &&
                             (lVar17 = *plVar14, *plVar14 = lVar17 + -1, lVar17 + -1 == 0)) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          if (plVar7 == (longlong *)0x0) {
                            return lVar6;
                          }
                          *plVar7 = *plVar7 + -1;
                          if (*plVar7 != 0) {
                            return lVar6;
                          }
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                          return lVar6;
                        }
                        auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                        plStack_78 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar22 = 0x81;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        goto LAB_23e16481e;
                      }
                      auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                      plStack_78 = *(longlong **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 != 0) {
                        uVar22 = 0x7f;
                        goto LAB_23e16481e;
                      }
                      (**(code **)(plVar8[1] + 0x30))(plVar8);
                    }
                    uVar22 = 0x7f;
                    goto LAB_23e16481e;
                  }
                  if ((plStack_b8 != (longlong *)0x0) &&
                     (*plStack_b8 = *plStack_b8 + -1, *plStack_b8 == 0)) {
                    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
                  }
                  plVar10 = (longlong *)FUN_23a388310(plVar9);
                  plStack_b8 = plVar9;
                  if (plVar10 == (longlong *)0x0) {
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    lVar6 = *(longlong *)(param_1 + 0x60);
                    uVar23 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e164dc8:
                    uVar22 = 0x76;
                    goto LAB_23e1647c0;
                  }
                  plVar11 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
                  if ((plVar11 == (longlong *)0x0) &&
                     (plVar11 = (longlong *)FUN_23a3c1b70(param_1,auStack_88,0,2),
                     plVar11 == (longlong *)0x0)) {
                    plVar12 = (longlong *)0x0;
                    lVar17 = *plVar10;
LAB_23e164cfb:
                    plVar9 = plStack_78;
                    lVar6 = auStack_88._0_8_;
                    uVar23 = auStack_88._8_8_;
                    auStack_88 = (undefined1  [16])0x0;
                    plStack_78 = (longlong *)0x0;
                    *plVar10 = lVar17 + -1;
                    if (lVar17 + -1 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    plStack_78 = (longlong *)0x0;
                    auStack_88 = (undefined1  [16])0x0;
                    if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    goto LAB_23e164dc8;
                  }
                  plVar12 = (longlong *)(**(code **)(plVar10[1] + 0xe0))(plVar10);
                  if ((plVar12 == (longlong *)0x0) &&
                     (plVar12 = (longlong *)FUN_23a3c1b70(param_1,auStack_88,1,2),
                     plVar12 == (longlong *)0x0)) {
                    lVar17 = *plVar10;
                    goto LAB_23e164cfb;
                  }
                  cVar5 = FUN_23a3884a0(param_1,auStack_88,plVar10,2);
                  lVar17 = *plVar10;
                  if (cVar5 == '\0') goto LAB_23e164cfb;
                  *plVar10 = lVar17 + -1;
                  if (lVar17 + -1 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar6 = *plVar11;
                  *plVar11 = lVar6 + 1;
                  if (plVar19 != (longlong *)0x0) {
                    *plVar19 = *plVar19 + -1;
                    if (*plVar19 == 0) {
                      (**(code **)(plVar19[1] + 0x30))(plVar19);
                    }
                    lVar6 = *plVar11 + -1;
                  }
                  *plVar11 = lVar6;
                  if (lVar6 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  lVar6 = *plVar12;
                  *plVar12 = lVar6 + 1;
                  if (plVar20 != (longlong *)0x0) {
                    *plVar20 = *plVar20 + -1;
                    if (*plVar20 == 0) {
                      (**(code **)(plVar20[1] + 0x30))(plVar20);
                    }
                    lVar6 = *plVar12 + -1;
                  }
                  *plVar12 = lVar6;
                  if (lVar6 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plStack_e0,DAT_23ed6ce40);
                  plVar19 = plVar11;
                  plVar20 = plVar12;
                  if (plVar9 == (longlong *)0x0) {
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar22 = 0x77;
                    lVar6 = *(longlong *)(param_1 + 0x60);
                    uVar23 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e1647c0;
                  }
                  *(undefined4 *)(plVar21 + 5) = 0x77;
                  pcStack_90 = _Py_TrueStruct_exref;
                  plStack_98 = plVar11;
                  plVar10 = (longlong *)FUN_23e94ed00(param_1,plVar9,&plStack_98);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar10 == (longlong *)0x0) {
                    lVar6 = *(longlong *)(param_1 + 0x60);
                    uVar23 = *(undefined8 *)(param_1 + 0x68);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar22 = 0x77;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e1647c0;
                  }
                  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  iVar18 = FUN_23a35f020(plVar10);
                  if (iVar18 == -1) {
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    lVar6 = *(longlong *)(param_1 + 0x60);
                    uVar23 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar22 = 0x78;
                    plVar14 = plVar10;
                    goto LAB_23e1647c0;
                  }
                  plVar9 = _DAT_23eea9438;
                  if (iVar18 == 0) {
                    plVar9 = _DAT_23eea9440;
                  }
                  *plVar9 = *plVar9 + 1;
                  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                    (**(code **)(plVar7[1] + 0x30))(plVar7);
                  }
                  plVar13 = (longlong *)FUN_23e8bc2f0(plStack_c0,DAT_23eea92b8);
                  plVar7 = plVar9;
                  if (plVar13 == (longlong *)0x0) {
LAB_23e165050:
                    lVar6 = *(longlong *)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar22 = 0x79;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar14 = plVar10;
                    uVar23 = *(undefined8 *)(param_1 + 0x68);
                    goto LAB_23e1647c0;
                  }
                  lVar6 = *(longlong *)(param_1 + 0x10);
                  plVar16 = *(longlong **)(lVar6 + 0xe28);
                  if (plVar16 == (longlong *)0x0) {
                    plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar17 = plVar16[3];
                    *(int *)(lVar6 + 0xec0) = *(int *)(lVar6 + 0xec0) + -1;
                    *(longlong *)(lVar6 + 0xe28) = lVar17;
                    *plVar16 = 1;
                  }
                  pcVar15 = _PyRuntime_exref;
                  plVar16[5] = 0;
                  lVar6 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
                  lVar17 = plVar16[-1];
                  puVar1 = *(undefined8 **)(lVar6 + 8);
                  *puVar1 = plVar16 + -2;
                  plVar2 = _DAT_23eea93c0;
                  plVar16[-2] = lVar6;
                  plVar16[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar1;
                  *(longlong **)(lVar6 + 8) = plVar16 + -2;
                  *plVar9 = *plVar9 + 1;
                  plVar16[3] = (longlong)plVar9;
                  *plVar2 = *plVar2 + 1;
                  plVar16[4] = (longlong)plVar2;
                  pcVar15 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar9 != (longlong *)0x0) {
                      *plVar9 = *plVar9 + 1;
                      DAT_23ed6a4c0 = plVar9;
                      goto LAB_23e16444a;
                    }
LAB_23e1650a0:
                    PyErr_PrintEx(0);
                    Py_Exit(1);
                    plVar21 = plVar14;
                    goto LAB_23e1650b8;
                  }
LAB_23e16444a:
                  pcStack_90 = pcVar15;
                  plStack_98 = plVar12;
                  lVar6 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                  if (lVar6 == 0) {
                    auStack_88._0_8_ = *(longlong *)(param_1 + 0x60);
                    auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plStack_78 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      uVar22 = 0x7a;
                      (**(code **)(plVar16[1] + 0x30))(plVar16);
                      plVar9 = plStack_78;
                      plVar14 = plVar10;
                      lVar6 = auStack_88._0_8_;
                      uVar23 = auStack_88._8_8_;
                    }
                    else {
                      uVar22 = 0x7a;
                      plVar9 = plStack_78;
                      plVar14 = plVar10;
                      lVar6 = auStack_88._0_8_;
                      uVar23 = auStack_88._8_8_;
                    }
                    goto LAB_23e1647c0;
                  }
                  plVar16[5] = lVar6;
                  plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                  }
                  plVar9 = _DAT_23eea9448;
                  if (plVar14 == (longlong *)0x0) {
                    auStack_88._0_8_ = *(longlong *)(param_1 + 0x60);
                    auStack_88._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    plStack_78 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      uVar22 = 0x7a;
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                      plVar9 = plStack_78;
                      plVar14 = plVar10;
                      lVar6 = auStack_88._0_8_;
                      uVar23 = auStack_88._8_8_;
                    }
                    else {
                      uVar22 = 0x7a;
                      plVar9 = plStack_78;
                      plVar14 = plVar10;
                      lVar6 = auStack_88._0_8_;
                      uVar23 = auStack_88._8_8_;
                    }
                    goto LAB_23e1647c0;
                  }
                  lVar6 = *(longlong *)(param_1 + 0x10);
                  plVar12 = *(longlong **)(lVar6 + 0xe20);
                  if (plVar12 == (longlong *)0x0) {
                    plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                  }
                  else {
                    lVar17 = plVar12[3];
                    *(int *)(lVar6 + 0xebc) = *(int *)(lVar6 + 0xebc) + -1;
                    *(longlong *)(lVar6 + 0xe20) = lVar17;
                    *plVar12 = 1;
                  }
                  pcVar15 = _PyRuntime_exref;
                  plVar12[4] = 0;
                  lVar6 = *(longlong *)
                           (*(longlong *)(*(longlong *)(pcVar15 + 0x1f8) + 0x10) + 0x2e8);
                  lVar17 = plVar12[-1];
                  puVar1 = *(undefined8 **)(lVar6 + 8);
                  *puVar1 = plVar12 + -2;
                  plVar12[-2] = lVar6;
                  plVar12[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar1;
                  *(longlong **)(lVar6 + 8) = plVar12 + -2;
                  *plVar9 = *plVar9 + 1;
                  plVar12[3] = (longlong)plVar9;
                  pcVar15 = DAT_23ed6cd28;
                  if (DAT_23ed6a4c0 == (longlong *)0x0) {
                    plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                    if (plVar9 == (longlong *)0x0) goto LAB_23e1650a0;
                    *plVar9 = *plVar9 + 1;
                    DAT_23ed6a4c0 = plVar9;
                  }
                  pcStack_90 = pcVar15;
                  plStack_98 = plVar11;
                  lVar6 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_98);
                  if (lVar6 == 0) {
                    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_78 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
LAB_23e165759:
                      uVar22 = 0x7b;
                      plVar9 = plStack_78;
                      plVar14 = plVar10;
                      lVar6 = auStack_88._0_8_;
                      uVar23 = auStack_88._8_8_;
                    }
                    else {
LAB_23e165798:
                      uVar22 = 0x7b;
                      plVar9 = plStack_78;
                      plVar14 = plVar10;
                      lVar6 = auStack_88._0_8_;
                      uVar23 = auStack_88._8_8_;
                    }
                    goto LAB_23e1647c0;
                  }
                  plVar12[4] = lVar6;
                  pcVar15 = (code *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  uVar23 = DAT_23eea92c8;
                  if (pcVar15 == (code *)0x0) {
                    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
                    plStack_78 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 != 0) goto LAB_23e165798;
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                    goto LAB_23e165759;
                  }
                  *(undefined4 *)(plVar21 + 5) = 0x79;
                  plStack_98 = plVar14;
                  pcStack_90 = pcVar15;
                  plVar9 = (longlong *)FUN_23e9186b0(param_1,plVar13,&plStack_98,uVar23);
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
                  if (*(longlong *)pcVar15 == 0) {
                    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
                  }
                  if (plVar9 == (longlong *)0x0) goto LAB_23e165050;
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  lVar17 = *(longlong *)(param_1 + 0x10);
                  if ((((*(int *)(*(longlong *)(lVar17 + 0x28) + 0x160) != 0) ||
                       (*(int *)(lVar17 + 0x78) != 0)) &&
                      (iVar18 = Py_MakePendingCalls(), iVar18 < 0)) &&
                     (lVar6 = *(longlong *)(param_1 + 0x60), lVar6 != 0)) goto LAB_23e164785;
                  if (*(int *)(lVar17 + 0x68) == 0) {
                    plVar9 = *(longlong **)(param_1 + 0x90);
                  }
                  else {
                    PyEval_SaveThread();
                    PyEval_AcquireThread(param_1);
                    plVar9 = *(longlong **)(param_1 + 0x90);
                  }
                  plVar14 = plVar10;
                } while (plVar9 == (longlong *)0x0);
                plVar14 = *(longlong **)(param_1 + 0x60);
                plVar11 = *(longlong **)(param_1 + 0x68);
                *(undefined8 *)(param_1 + 0x90) = 0;
                plVar12 = *(longlong **)(param_1 + 0x70);
                *(longlong **)(param_1 + 0x60) = plVar9;
                *plVar9 = *plVar9 + 1;
                *(undefined8 *)(param_1 + 0x68) = 0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
                  (**(code **)(plVar14[1] + 0x30))();
                }
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if ((plVar12 == (longlong *)0x0) || (*plVar12 = *plVar12 + -1, *plVar12 != 0)) {
                  lVar6 = *(longlong *)(param_1 + 0x60);
                }
                else {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                  lVar6 = *(longlong *)(param_1 + 0x60);
                }
LAB_23e164785:
                plVar9 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar22 = 0x76;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar14 = plVar10;
                uVar23 = *(undefined8 *)(param_1 + 0x68);
LAB_23e1647c0:
                plStack_78 = (longlong *)0x0;
                auStack_88 = (undefined1  [16])0x0;
                lVar17 = *plStack_b8;
                *plStack_b8 = lVar17 + -1;
                if (lVar17 + -1 == 0) {
                  (**(code **)(plStack_b8[1] + 0x30))();
                }
LAB_23e1647f4:
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                auStack_88._8_8_ = uVar23;
                auStack_88._0_8_ = lVar6;
                plStack_78 = plVar9;
              }
              goto LAB_23e16481e;
            }
            plStack_78 = *(longlong **)(param_1 + 0x70);
            auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          plVar7 = (longlong *)0x0;
          plVar14 = (longlong *)0x0;
          plVar20 = (longlong *)0x0;
          plVar19 = (longlong *)0x0;
          uVar22 = 0x74;
        }
      }
      goto LAB_23e16481e;
    }
    plStack_78 = *(longlong **)(param_1 + 0x70);
    auStack_88 = *(undefined1 (*) [16])(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  plStack_c0 = (longlong *)0x0;
  plVar7 = (longlong *)0x0;
  plVar14 = (longlong *)0x0;
  plVar20 = (longlong *)0x0;
  plStack_d8 = (longlong *)0x0;
  plVar19 = (longlong *)0x0;
  uVar22 = 0x6a;
  plStack_e0 = (longlong *)0x0;
LAB_23e16481e:
  plVar9 = plStack_78;
  plVar8 = DAT_23ed6a4f8;
  if (plStack_78 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar9 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar9;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar8[2] = 0;
    plVar8[3] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    lVar6 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    lVar6 = *(longlong *)(lVar6 + 0x10);
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar22;
    lVar6 = *(longlong *)(lVar6 + 0x2e8);
    lVar17 = plVar8[-1];
    puVar1 = *(undefined8 **)(lVar6 + 8);
    *puVar1 = plVar8 + -2;
    plVar8[-2] = lVar6;
    plVar8[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar6 + 8) = plVar8 + -2;
    plVar9 = plVar8;
    if ((plStack_78 != (longlong *)0x0) && (*plStack_78 = *plStack_78 + -1, *plStack_78 == 0)) {
      (**(code **)(plStack_78[1] + 0x30))(plStack_78);
    }
  }
  else if ((longlong *)plStack_78[3] != plVar21) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar15 = _PyRuntime_exref;
    plVar8[3] = (longlong)plVar21;
    *plVar21 = *plVar21 + 1;
    lVar6 = *(longlong *)(pcVar15 + 0x1f8);
    *(undefined4 *)(plVar8 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar8 + 0x24) = uVar22;
    lVar6 = *(longlong *)(*(longlong *)(lVar6 + 0x10) + 0x2e8);
    lVar17 = plVar8[-1];
    puVar1 = *(undefined8 **)(lVar6 + 8);
    *puVar1 = plVar8 + -2;
    plVar8[-2] = lVar6;
    plVar8[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar1;
    *(longlong **)(lVar6 + 8) = plVar8 + -2;
    plVar8[2] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    plVar9 = plVar8;
    if ((plStack_78 != (longlong *)0x0) && (*plStack_78 = *plStack_78 + -1, *plStack_78 == 0)) {
      (**(code **)(plStack_78[1] + 0x30))();
    }
  }
  plStack_78 = plVar9;
  FUN_23e8bba40(plVar21,"oooooooo",plStack_c8,plStack_e0,plStack_d8,plStack_c0,plVar19,plVar20,
                plVar14,plVar7);
  if (_DAT_23eeab148 == plVar21) {
    *plVar21 = *plVar21 + -1;
    if (*plVar21 == 0) {
      (**(code **)(plVar21[1] + 0x30))(plVar21);
    }
    _DAT_23eeab148 = (longlong *)0x0;
  }
  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar21 = *(longlong **)(lVar6 + 0x28);
  plVar8 = (longlong *)plVar21[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar6 + 0x30);
  *(undefined4 *)(plVar21 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar21[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar21 = *plVar21 + -1;
  if (*plVar21 == 0) {
    (**(code **)(plVar21[1] + 0x30))(plVar21);
  }
  plVar8 = plStack_78;
  auVar3 = auStack_88;
  uVar23 = auStack_88._0_8_;
  uVar4 = auStack_88._8_8_;
  plVar21[0xf] = 0;
  auStack_88 = (undefined1  [16])0x0;
  plStack_78 = (longlong *)0x0;
  if ((plStack_c8 != (longlong *)0x0) &&
     (lVar6 = *plStack_c8, *plStack_c8 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_c8[1] + 0x30))();
  }
  if ((plStack_e0 != (longlong *)0x0) &&
     (lVar6 = *plStack_e0, *plStack_e0 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_e0[1] + 0x30))();
  }
  if ((plStack_d8 != (longlong *)0x0) &&
     (lVar6 = *plStack_d8, *plStack_d8 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
  }
  if ((plStack_c0 != (longlong *)0x0) &&
     (lVar6 = *plStack_c0, *plStack_c0 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_c0[1] + 0x30))(plStack_c0);
  }
  if ((plVar19 != (longlong *)0x0) && (*plVar19 = *plVar19 + -1, *plVar19 == 0)) {
    (**(code **)(plVar19[1] + 0x30))(plVar19);
  }
  if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
    (**(code **)(plVar20[1] + 0x30))(plVar20);
  }
  if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  auStack_88 = auVar3;
  plStack_78 = plVar8;
  FUN_23a33aa70(param_1,uVar23,uVar4,plVar8);
  return 0;
}
