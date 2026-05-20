/* ===== 23e754cd0 workers.fishing.fishing_bot:FishingBot._do_casting ===== */
/* ghidra_name=FUN_23e754cd0 entry=23e754cd0 size=13583 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e754cd0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong lVar2;
  double dVar3;
  double dVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  undefined1 auVar7 [16];
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined8 *puVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  longlong *plVar18;
  longlong *plVar19;
  longlong *plVar20;
  longlong lVar21;
  code *pcVar22;
  code *pcVar23;
  longlong *plVar24;
  longlong *plVar25;
  longlong lVar26;
  longlong *plVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  code *pcVar30;
  code *pcVar31;
  undefined8 uVar32;
  undefined8 uVar33;
  longlong *plStack_2b8;
  longlong *plStack_2b0;
  longlong *plStack_2a8;
  longlong *plStack_2a0;
  longlong *plStack_298;
  longlong *plStack_290;
  longlong *plStack_260;
  longlong *plStack_258;
  undefined1 auStack_250 [16];
  code *pcStack_240;
  longlong *plStack_230;
  longlong *plStack_228;
  longlong *plStack_218;
  longlong *plStack_210;
  longlong lStack_208;
  longlong *plStack_200;
  longlong *plStack_1f8;
  longlong *plStack_1f0;
  longlong *plStack_1e8;
  code *pcStack_1e0;
  longlong *plStack_1b8;
  longlong *plStack_1b0;
  longlong *plStack_1a8;
  longlong *plStack_1a0;
  code *pcStack_198;
  longlong *plStack_190;
  longlong *plStack_188;
  longlong *plStack_180;
  longlong *plStack_178;
  longlong *plStack_170;
  longlong *plStack_168;
  longlong *plStack_160;
  longlong *plStack_158;
  code *pcStack_148;
  longlong *plStack_140;
  longlong *plStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  longlong *plStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  code *pcStack_100;
  code *pcStack_f8;
  longlong *plStack_f0;
  longlong *plStack_e8;
  longlong *plStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  longlong *plStack_c0;
  longlong *plStack_b8;
  longlong *plStack_b0;
  longlong **pplStack_a8;
  longlong *plStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  longlong *plStack_70;
  longlong *plStack_68;
  
  plVar10 = _DAT_23eedae10;
  pcVar31 = (code *)*param_3;
  apcStack_88[0] = (code *)0x0;
  auStack_98._0_8_ = (code *)0x0;
  auStack_98._8_8_ = 0;
  if (_DAT_23eedae10 == (longlong *)0x0) {
LAB_23e754d2d:
    pcStack_1e0 = (code *)0x23e754d49;
    _DAT_23eedae10 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf80,DAT_23eedaeb8,0x78);
  }
  else {
    lVar12 = *_DAT_23eedae10;
    if (1 < lVar12) {
      *_DAT_23eedae10 = lVar12 + -1;
      goto LAB_23e754d2d;
    }
    if (_DAT_23eedae10[2] != 0) {
      *_DAT_23eedae10 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        pcStack_1e0 = (code *)0x23e755a22;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e754d2d;
    }
  }
  plVar25 = _DAT_23eedae10;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedae10 + 9;
  lVar21 = *(longlong *)(lVar12 + 8);
  _DAT_23eedae10[0xf] = lVar21;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar25[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar25[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar25 = *plVar25 + 1;
  uVar32 = DAT_23eed89b0;
  *(undefined4 *)(plVar25 + 8) = 0;
  pcStack_1e0 = (code *)0x23e754dbf;
  plVar10 = (longlong *)FUN_23e8bc2f0(pcVar31,uVar32);
  if (plVar10 == (longlong *)0x0) {
    apcStack_88[0] = *(code **)(param_1 + 0x70);
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    plVar24 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    uVar29 = 0x353;
    plStack_138 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    pcStack_148 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e755c16;
  }
  *(undefined4 *)(plVar25 + 5) = 0x353;
  pcStack_1e0 = (code *)0x23e754de4;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8d38);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    pcStack_1e0 = (code *)0x23e754eca;
    (**(code **)(plVar10[1] + 0x30))(plVar10);
    if (plVar11 == (longlong *)0x0) goto LAB_23e754ed3;
LAB_23e754dfa:
    pcStack_1e0 = (code *)0x23e754e02;
    iVar9 = FUN_23a35f020(plVar11);
    lVar12 = *plVar11 + -1;
    if (iVar9 == -1) {
      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
      apcStack_88[0] = *(code **)(param_1 + 0x70);
      uVar29 = 0x353;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar11 = lVar12;
      if (lVar12 == 0) {
        pcStack_1e0 = (code *)0x23e7561da;
        (**(code **)(plVar11[1] + 0x30))(plVar11);
        uVar29 = 0x353;
      }
LAB_23e7561e8:
      plStack_138 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plVar24 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      plVar16 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plStack_128 = (longlong *)0x0;
      plStack_118 = (longlong *)0x0;
      plStack_130 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      plStack_108 = (longlong *)0x0;
      plStack_120 = (longlong *)0x0;
    }
    else {
      *plVar11 = lVar12;
      if (lVar12 == 0) {
        pcStack_1e0 = (code *)0x23e754e28;
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      pcVar23 = _Py_NoneStruct_exref;
      if (iVar9 != 0) {
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        pcStack_100 = pcVar23;
        lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar10 = *(longlong **)(lVar12 + 0x28);
        plVar25 = (longlong *)plVar10[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
        *(undefined4 *)(plVar10 + 8) = 0xffffffff;
        if (plVar25 != (longlong *)0x0) {
          plVar10[2] = 0;
          *plVar25 = *plVar25 + -1;
          if (*plVar25 == 0) {
            pcStack_1e0 = (code *)0x23e754e7c;
            (**(code **)(plVar25[1] + 0x30))();
          }
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          pcStack_1e0 = (code *)0x23e755a4a;
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        plVar10[0xf] = 0;
LAB_23e754e8e:
        *(longlong *)pcVar31 = *(longlong *)pcVar31 + -1;
        if (*(longlong *)pcVar31 != 0) {
          return pcStack_100;
        }
        pcStack_1e0 = (code *)0x23e755a3a;
        (**(code **)(*(longlong *)(pcVar31 + 8) + 0x30))(pcVar31);
        return pcStack_100;
      }
      *(undefined4 *)(plVar25 + 5) = 0x356;
      pcStack_1e0 = (code *)0x23e755074;
      plVar10 = (longlong *)FUN_23e915840(param_1,pcVar31,DAT_23eed8b40);
      if (plVar10 == (longlong *)0x0) {
        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
        apcStack_88[0] = *(code **)(param_1 + 0x70);
        plVar24 = (longlong *)0x0;
        plVar16 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar13 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        uVar29 = 0x356;
        plStack_138 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        plStack_128 = (longlong *)0x0;
        plStack_118 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        plStack_108 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
      }
      else {
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          pcStack_1e0 = (code *)0x23e755a5a;
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        pcStack_1e0 = (code *)0x23e755099;
        plVar10 = (longlong *)FUN_23e8bc2f0(pcVar31,DAT_23eed8aa8);
        if (plVar10 == (longlong *)0x0) {
          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
          apcStack_88[0] = *(code **)(param_1 + 0x70);
          plVar24 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          plVar13 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          uVar29 = 0x359;
          plStack_138 = (longlong *)0x0;
          plStack_110 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          plStack_108 = (longlong *)0x0;
          plStack_120 = (longlong *)0x0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar10 = (longlong *)0x0;
        }
        else {
          pcStack_1e0 = (code *)0x23e7550b4;
          iVar9 = FUN_23e913250(plVar10,DAT_23eed90d8);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            pcStack_1e0 = (code *)0x23e755a6a;
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (iVar9 == -1) {
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            uVar29 = 0x359;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e7561e8;
          }
          lVar12 = *(longlong *)(DAT_23eed8950 + 0x20);
          if (iVar9 == 1) {
            if (*(char *)(lVar12 + 10) == '\0') {
              pcStack_1e0 = (code *)0x23e756758;
              puVar14 = (undefined8 *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed9210);
              if (puVar14 == (undefined8 *)0x0) goto LAB_23e756770;
              plVar10 = (longlong *)*puVar14;
LAB_23e756760:
              if (plVar10 == (longlong *)0x0) goto LAB_23e756770;
            }
            else {
              iVar9 = *(int *)(lVar12 + 0xc);
              if (*(int *)(lVar12 + 0xc) == 0) {
                *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                iVar9 = DAT_23ec1545c;
                DAT_23ec1545c = DAT_23ec1545c + 1;
              }
              if (_DAT_23ec15430 != iVar9) {
                pcStack_1e0 = (code *)0x23e756599;
                _DAT_23ec15430 = iVar9;
                _DAT_23eedadf0 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9210,*(undefined8 *)(_DAT_23eed9210 + 0x18));
              }
              if (-1 < _DAT_23eedadf0) {
                lVar21 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                plVar10 = *(longlong **)(lVar21 + 8 + _DAT_23eedadf0 * 0x10);
                if (plVar10 != (longlong *)0x0) goto LAB_23e755ad6;
                pcStack_1e0 = (code *)0x23e757b86;
                _DAT_23eedadf0 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9210,*(undefined8 *)(_DAT_23eed9210 + 0x18));
                if (-1 < _DAT_23eedadf0) {
                  plVar10 = *(longlong **)(lVar21 + 8 + _DAT_23eedadf0 * 0x10);
                  goto LAB_23e756760;
                }
              }
LAB_23e756770:
              pcStack_1e0 = (code *)0x23e756786;
              puVar14 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9210);
              if ((puVar14 == (undefined8 *)0x0) ||
                 (plVar10 = (longlong *)*puVar14, plVar10 == (longlong *)0x0)) {
                pcStack_1e0 = (code *)0x23e7567ae;
                FUN_23e915740(param_1,auStack_98,_DAT_23eed9210);
                uVar29 = 0x35a;
                goto LAB_23e7561e8;
              }
            }
LAB_23e755ad6:
            lVar21 = DAT_23eed8950;
            *plVar10 = *plVar10 + 1;
            lVar12 = *(longlong *)(lVar21 + 0x20);
            if (*(char *)(lVar12 + 10) != '\0') {
              iVar9 = *(int *)(lVar12 + 0xc);
              if (*(int *)(lVar12 + 0xc) == 0) {
                *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                iVar9 = DAT_23ec1545c;
                DAT_23ec1545c = DAT_23ec1545c + 1;
              }
              if (_DAT_23ec15434 != iVar9) {
                pcStack_1e0 = (code *)0x23e7567e1;
                _DAT_23ec15434 = iVar9;
                _DAT_23eedadf8 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9218,*(undefined8 *)(_DAT_23eed9218 + 0x18));
              }
              if (-1 < _DAT_23eedadf8) {
                lVar21 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                plVar11 = *(longlong **)(lVar21 + 8 + _DAT_23eedadf8 * 0x10);
                if (plVar11 != (longlong *)0x0) goto LAB_23e755b4f;
                pcStack_1e0 = (code *)0x23e757bb7;
                _DAT_23eedadf8 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9218,*(undefined8 *)(_DAT_23eed9218 + 0x18));
                if (-1 < _DAT_23eedadf8) {
                  plVar11 = *(longlong **)(lVar21 + 8 + _DAT_23eedadf8 * 0x10);
                  goto LAB_23e756801;
                }
              }
LAB_23e756810:
              pcStack_1e0 = (code *)0x23e756826;
              puVar14 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9218);
              if ((puVar14 != (undefined8 *)0x0) &&
                 (plVar11 = (longlong *)*puVar14, plVar11 != (longlong *)0x0)) goto LAB_23e755b4f;
              pcStack_1e0 = (code *)0x23e75684e;
              FUN_23e915740(param_1,auStack_98,_DAT_23eed9218);
              uVar29 = 0x35b;
LAB_23e7563fc:
              plStack_138 = (longlong *)0x0;
              plVar24 = (longlong *)0x0;
              plVar11 = (longlong *)0x0;
              plVar16 = (longlong *)0x0;
              plStack_110 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              plStack_128 = (longlong *)0x0;
              plStack_118 = (longlong *)0x0;
              plStack_130 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              pcStack_148 = (code *)0x0;
              plStack_108 = (longlong *)0x0;
              plStack_120 = (longlong *)0x0;
              goto LAB_23e755c16;
            }
            pcStack_1e0 = (code *)0x23e7567f9;
            puVar14 = (undefined8 *)FUN_23a37a020(lVar21,_DAT_23eed9218);
            if (puVar14 == (undefined8 *)0x0) goto LAB_23e756810;
            plVar11 = (longlong *)*puVar14;
LAB_23e756801:
            if (plVar11 == (longlong *)0x0) goto LAB_23e756810;
LAB_23e755b4f:
            plVar13 = DAT_23eed9220;
            plStack_120 = DAT_23eed9220;
            *plVar11 = *plVar11 + 1;
            *plVar13 = *plVar13 + 1;
          }
          else {
            if (*(char *)(lVar12 + 10) == '\0') {
              pcStack_1e0 = (code *)0x23e7562fc;
              puVar14 = (undefined8 *)FUN_23a37a020(DAT_23eed8950,_DAT_23eed9228);
              if (puVar14 == (undefined8 *)0x0) goto LAB_23e756310;
              plVar10 = (longlong *)*puVar14;
LAB_23e756304:
              if (plVar10 == (longlong *)0x0) goto LAB_23e756310;
            }
            else {
              iVar9 = *(int *)(lVar12 + 0xc);
              if (*(int *)(lVar12 + 0xc) == 0) {
                *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                iVar9 = DAT_23ec1545c;
                DAT_23ec1545c = DAT_23ec1545c + 1;
              }
              if (_DAT_23ec15438 != iVar9) {
                pcStack_1e0 = (code *)0x23e756289;
                _DAT_23ec15438 = iVar9;
                _DAT_23eedae00 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9228,*(undefined8 *)(_DAT_23eed9228 + 0x18));
              }
              if (-1 < _DAT_23eedae00) {
                lVar21 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                plVar10 = *(longlong **)(lVar21 + 8 + _DAT_23eedae00 * 0x10);
                if (plVar10 != (longlong *)0x0) goto LAB_23e755149;
                pcStack_1e0 = (code *)0x23e757648;
                _DAT_23eedae00 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9228,*(undefined8 *)(_DAT_23eed9228 + 0x18));
                if (-1 < _DAT_23eedae00) {
                  plVar10 = *(longlong **)(lVar21 + 8 + _DAT_23eedae00 * 0x10);
                  goto LAB_23e756304;
                }
              }
LAB_23e756310:
              pcStack_1e0 = (code *)0x23e756326;
              puVar14 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9228);
              if ((puVar14 == (undefined8 *)0x0) ||
                 (plVar10 = (longlong *)*puVar14, plVar10 == (longlong *)0x0)) {
                pcStack_1e0 = (code *)0x23e75634e;
                FUN_23e915740(param_1,auStack_98,_DAT_23eed9228);
                uVar29 = 0x35e;
                goto LAB_23e7561e8;
              }
            }
LAB_23e755149:
            lVar21 = DAT_23eed8950;
            *plVar10 = *plVar10 + 1;
            lVar12 = *(longlong *)(lVar21 + 0x20);
            if (*(char *)(lVar12 + 10) == '\0') {
              pcStack_1e0 = (code *)0x23e75639c;
              puVar14 = (undefined8 *)FUN_23a37a020(lVar21,_DAT_23eed9230);
              if (puVar14 == (undefined8 *)0x0) goto LAB_23e7563b0;
              plVar11 = (longlong *)*puVar14;
LAB_23e7563a4:
              if (plVar11 == (longlong *)0x0) goto LAB_23e7563b0;
            }
            else {
              iVar9 = *(int *)(lVar12 + 0xc);
              if (*(int *)(lVar12 + 0xc) == 0) {
                *(int *)(lVar12 + 0xc) = DAT_23ec1545c;
                iVar9 = DAT_23ec1545c;
                DAT_23ec1545c = DAT_23ec1545c + 1;
              }
              if (_DAT_23ec1543c != iVar9) {
                pcStack_1e0 = (code *)0x23e756381;
                _DAT_23ec1543c = iVar9;
                _DAT_23eedae08 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9230,*(undefined8 *)(_DAT_23eed9230 + 0x18));
              }
              if (-1 < _DAT_23eedae08) {
                lVar21 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                plVar11 = *(longlong **)(lVar21 + 8 + _DAT_23eedae08 * 0x10);
                if (plVar11 != (longlong *)0x0) goto LAB_23e7551c2;
                pcStack_1e0 = (code *)0x23e757679;
                _DAT_23eedae08 =
                     FUN_23e8cbd60(lVar12,_DAT_23eed9230,*(undefined8 *)(_DAT_23eed9230 + 0x18));
                if (-1 < _DAT_23eedae08) {
                  plVar11 = *(longlong **)(lVar21 + 8 + _DAT_23eedae08 * 0x10);
                  goto LAB_23e7563a4;
                }
              }
LAB_23e7563b0:
              pcStack_1e0 = (code *)0x23e7563c6;
              puVar14 = (undefined8 *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eed9230);
              if ((puVar14 == (undefined8 *)0x0) ||
                 (plVar11 = (longlong *)*puVar14, plVar11 == (longlong *)0x0)) {
                pcStack_1e0 = (code *)0x23e7563ee;
                FUN_23e915740(param_1,auStack_98,_DAT_23eed9230);
                uVar29 = 0x35f;
                goto LAB_23e7563fc;
              }
            }
LAB_23e7551c2:
            plStack_120 = _DAT_23eed9238;
            *plVar11 = *plVar11 + 1;
            *plStack_120 = *plStack_120 + 1;
          }
          pcStack_1e0 = (code *)0x23e7551df;
          lVar12 = FUN_23e8e0270();
          if (lVar12 == 0) {
            pcStack_1e0 = (code *)0x23e756ac7;
            FUN_23e915740(param_1,auStack_98,_DAT_23eed9160);
            plVar13 = (longlong *)0x0;
          }
          else {
            *(undefined4 *)(plVar25 + 5) = 0x363;
            plStack_68 = plStack_120;
            pplStack_a8 = &plStack_78;
            pcStack_1e0 = (code *)0x23e755230;
            plStack_78 = plVar10;
            plStack_70 = plVar11;
            plVar13 = (longlong *)FUN_23e956150(param_1,lVar12,pplStack_a8);
            if (plVar13 != (longlong *)0x0) {
              pcStack_1e0 = (code *)0x23e755241;
              plStack_108 = (longlong *)FUN_23e8e0ba0();
              if (plStack_108 == (longlong *)0x0) {
                pcStack_1e0 = (code *)0x23e756ae8;
                FUN_23e915740(param_1,auStack_98,DAT_23eed8c70);
LAB_23e756af0:
                plStack_138 = (longlong *)0x0;
                plVar24 = (longlong *)0x0;
                plVar16 = (longlong *)0x0;
                uVar29 = 0x368;
                plStack_110 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_118 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcStack_148 = (code *)0x0;
              }
              else {
                *(undefined4 *)(plVar25 + 5) = 0x368;
                pcStack_1e0 = (code *)0x23e75526b;
                puVar14 = (undefined8 *)FUN_23e91bfe0(param_1,plStack_108);
                pcVar23 = PyFloat_Type_exref;
                if (puVar14 == (undefined8 *)0x0) {
                  auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  apcStack_88[0] = *(code **)(param_1 + 0x70);
                  plVar24 = (longlong *)0x0;
                  plVar16 = (longlong *)0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar29 = 0x368;
                  plStack_138 = (longlong *)0x0;
                  plStack_110 = (longlong *)0x0;
                  plStack_128 = (longlong *)0x0;
                  plStack_118 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  plStack_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcStack_148 = (code *)0x0;
                  goto LAB_23e755c16;
                }
                pcStack_148 = (code *)puVar14;
                if ((code *)puVar14[1] == PyFloat_Type_exref) {
                  dVar3 = (double)puVar14[2];
                  dVar4 = *(double *)(DAT_23eed8b20 + 0x10);
                  lVar12 = *(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10);
                  plStack_108 = *(longlong **)(lVar12 + 0xe08);
                  if (plStack_108 == (longlong *)0x0) {
                    pcStack_1e0 = (code *)0x23e757be5;
                    plStack_108 = (longlong *)(*DAT_23ed6ccd0)(0,0x18);
                  }
                  else {
                    lVar21 = plStack_108[1];
                    *(int *)(lVar12 + 0xe00) = *(int *)(lVar12 + 0xe00) + -1;
                    *(longlong *)(lVar12 + 0xe08) = lVar21;
                  }
                  pcVar22 = pcStack_148;
                  plStack_108[1] = (longlong)pcVar23;
                  *plStack_108 = 1;
                  plStack_108[2] = (longlong)(dVar4 + dVar3);
                  pcVar23 = *(code **)pcStack_148;
                  *(code **)pcStack_148 = pcVar23 + -1;
                  if (pcVar23 + -1 == (code *)0x0) {
                    plVar16 = (longlong *)((longlong)pcStack_148 + 8);
                    pcStack_1e0 = (code *)0x23e7574c4;
                    pcStack_148 = pcVar23;
                    (**(code **)(*plVar16 + 0x30))(pcVar22);
                    pcVar23 = pcStack_148;
                  }
                }
                else {
                  pcStack_1e0 = (code *)0x23e75529f;
                  plStack_108 = (longlong *)FUN_23e8bfcd0(puVar14);
                  pcStack_148 = (code *)*puVar14;
                  *puVar14 = pcStack_148 + -1;
                  if (pcStack_148 + -1 == (code *)0x0) {
                    pcStack_1e0 = (code *)0x23e7564db;
                    (**(code **)(puVar14[1] + 0x30))(puVar14);
                  }
                  pcVar23 = pcStack_148;
                  if (plStack_108 == (longlong *)0x0) {
                    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                    apcStack_88[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e756af0;
                  }
                }
                pcStack_148 = pcVar23;
                if (pcVar31 == (code *)0x0) {
                  pcStack_1e0 = (code *)0x23e75775f;
                  auStack_98._8_8_ =
                       PyUnicode_FromFormat
                                 ("cannot access local variable \'%U\' where it is not associated with a value"
                                  ,DAT_23eed8d30);
                  auStack_98._0_8_ = *(undefined8 *)PyExc_UnboundLocalError_exref;
                  *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + 1;
                  apcStack_88[0] = (code *)0x0;
                  if ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) {
                    pcStack_1e0 = (code *)0x23e7577bb;
                    FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
                  }
                  plVar24 = (longlong *)0x0;
                  plVar16 = (longlong *)0x0;
                  pcStack_1e0 = (code *)0x23e7577d5;
                  FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),auStack_98._8_8_);
                  plStack_138 = (longlong *)0x0;
                  uVar29 = 0x369;
                  plStack_110 = (longlong *)0x0;
                  plStack_128 = (longlong *)0x0;
                  plStack_118 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  pcStack_148 = (code *)0x0;
                }
                else {
                  plStack_138 = (longlong *)0x0;
                  plStack_110 = (longlong *)0x0;
                  plStack_128 = (longlong *)0x0;
                  plStack_118 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  plStack_d8 = (longlong *)0x0;
                  plStack_d0 = (longlong *)0x0;
                  pcVar23 = (code *)0x0;
                  pcStack_f8 = pcVar31;
                  plStack_c0 = plVar13;
                  plStack_b8 = plVar10;
                  plStack_b0 = plVar11;
                  while( true ) {
                    pcStack_1e0 = (code *)0x23e755377;
                    plVar10 = (longlong *)FUN_23e8bc2f0(pcStack_f8,DAT_23eed89b0);
                    if (plVar10 == (longlong *)0x0) break;
                    *(undefined4 *)(plVar25 + 5) = 0x369;
                    pcStack_1e0 = (code *)0x23e75539d;
                    plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8d38);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      pcStack_1e0 = (code *)0x23e7553b0;
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar11 == (longlong *)0x0) break;
                    pcStack_1e0 = (code *)0x23e7553c1;
                    iVar9 = FUN_23a35f020(plVar11);
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      pcStack_1e0 = (code *)0x23e7553d3;
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (iVar9 == -1) break;
                    pcVar31 = _Py_FalseStruct_exref;
                    if (iVar9 == 0) {
                      pcVar31 = _Py_TrueStruct_exref;
                    }
                    pcStack_1e0 = (code *)0x23e7553f5;
                    iVar9 = FUN_23a35f020(pcVar31);
                    if (iVar9 == 1) {
                      pcStack_1e0 = (code *)0x23e7565ad;
                      lVar12 = FUN_23e8e0ba0();
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar13 = plStack_c0;
                      plVar24 = plStack_d0;
                      plVar16 = plStack_d8;
                      pcVar31 = pcStack_f8;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e75788a;
                        pcStack_148 = pcVar23;
                        FUN_23e915740(param_1,auStack_98,DAT_23eed8c70);
                        uVar29 = 0x369;
                        goto LAB_23e755c16;
                      }
                      *(undefined4 *)(plVar25 + 5) = 0x369;
                      pcStack_1e0 = (code *)0x23e7565d0;
                      plVar10 = (longlong *)FUN_23e91bfe0(param_1,lVar12);
                      if (plVar10 == (longlong *)0x0) break;
                      pcStack_1e0 = (code *)0x23e7565e8;
                      pcVar31 = (code *)FUN_23e8d09c0(plVar10,plStack_108);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        pcStack_1e0 = (code *)0x23e7565fb;
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      if (pcVar31 == (code *)0x0) break;
                    }
                    else {
                      *(longlong *)pcVar31 = *(longlong *)pcVar31 + 1;
                    }
                    pcStack_1e0 = (code *)0x23e75540a;
                    iVar9 = FUN_23a35f020(pcVar31);
                    *(longlong *)pcVar31 = *(longlong *)pcVar31 + -1;
                    if (*(longlong *)pcVar31 == 0) {
                      pcStack_1e0 = (code *)0x23e75541c;
                      (**(code **)(*(longlong *)(pcVar31 + 8) + 0x30))(pcVar31);
                    }
                    if (iVar9 == -1) break;
                    if (iVar9 == 0) {
                      pcStack_100 = _Py_NoneStruct_exref;
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar25 = plStack_d8;
                      plVar13 = plStack_c0;
                      pcVar31 = pcStack_f8;
LAB_23e7578e2:
                      plVar15 = plStack_d0;
                      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar16 = *(longlong **)(lVar12 + 0x28);
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar12 + 0x30);
                      plVar24 = (longlong *)plVar16[2];
                      *(undefined4 *)(plVar16 + 8) = 0xffffffff;
                      pcStack_148 = pcVar23;
                      if (plVar24 != (longlong *)0x0) {
                        plVar16[2] = 0;
                        *plVar24 = *plVar24 + -1;
                        if (*plVar24 == 0) {
                          pcStack_1e0 = (code *)0x23e757923;
                          (**(code **)(plVar24[1] + 0x30))();
                        }
                      }
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        pcStack_1e0 = (code *)0x23e757943;
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      plVar16[0xf] = 0;
                      *(longlong *)pcStack_100 = *(longlong *)pcStack_100 + 1;
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        pcStack_1e0 = (code *)0x23e757c04;
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                        *plVar11 = *plVar11 + -1;
                        lVar12 = *plVar11;
                      }
                      else {
                        *plVar11 = *plVar11 + -1;
                        lVar12 = *plVar11;
                      }
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e757982;
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      lVar12 = *plStack_120;
                      *plStack_120 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        pcStack_1e0 = (code *)0x23e7579bb;
                        (**(code **)(plStack_120[1] + 0x30))(plStack_120);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        pcStack_1e0 = (code *)0x23e7579db;
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      pcVar22 = (code *)*plStack_108;
                      pcVar23 = pcVar22 + -1;
                      *plStack_108 = (longlong)pcVar23;
                      pcVar30 = pcStack_148;
                      if (pcVar23 == (code *)0x0) {
                        pcStack_1e0 = (code *)0x23e757a11;
                        (**(code **)(plStack_108[1] + 0x30))();
                        pcVar30 = pcStack_148;
                        pcVar22 = pcStack_148;
                      }
                      pcStack_148 = pcVar22;
                      if ((pcVar30 != (code *)0x0) &&
                         (*(longlong *)pcVar30 = *(longlong *)pcVar30 + -1,
                         *(longlong *)pcVar30 == 0)) {
                        pcStack_1e0 = (code *)0x23e757a2e;
                        (**(code **)(*(longlong *)(pcVar30 + 8) + 0x30))(pcVar30);
                      }
                      if ((plVar25 != (longlong *)0x0) && (*plVar25 = *plVar25 + -1, *plVar25 == 0))
                      {
                        pcStack_1e0 = (code *)0x23e757a44;
                        (**(code **)(plVar25[1] + 0x30))(plVar25);
                      }
                      if (plStack_140 != (longlong *)0x0) {
                        pcStack_148 = (code *)*plStack_140;
                        *plStack_140 = (longlong)(pcStack_148 + -1);
                        if (pcStack_148 + -1 == (code *)0x0) {
                          pcStack_1e0 = (code *)0x23e757a75;
                          (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                        }
                      }
                      if (plStack_130 != (longlong *)0x0) {
                        pcStack_148 = (code *)*plStack_130;
                        *plStack_130 = (longlong)(pcStack_148 + -1);
                        if (pcStack_148 + -1 == (code *)0x0) {
                          pcStack_1e0 = (code *)0x23e757aa3;
                          (**(code **)(plStack_130[1] + 0x30))();
                        }
                      }
                      if (plStack_118 != (longlong *)0x0) {
                        pcStack_148 = (code *)*plStack_118;
                        *plStack_118 = (longlong)(pcStack_148 + -1);
                        if (pcStack_148 + -1 == (code *)0x0) {
                          pcStack_1e0 = (code *)0x23e757ace;
                          (**(code **)(plStack_118[1] + 0x30))(plStack_118);
                        }
                      }
                      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0))
                      {
                        pcStack_1e0 = (code *)0x23e757ae5;
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      if (plStack_128 != (longlong *)0x0) {
                        pcStack_148 = (code *)*plStack_128;
                        *plStack_128 = (longlong)(pcStack_148 + -1);
                        if (pcStack_148 + -1 == (code *)0x0) {
                          pcStack_1e0 = (code *)0x23e757b10;
                          (**(code **)(plStack_128[1] + 0x30))(plStack_128);
                        }
                      }
                      if (plStack_110 != (longlong *)0x0) {
                        pcStack_148 = (code *)*plStack_110;
                        *plStack_110 = (longlong)(pcStack_148 + -1);
                        if (pcStack_148 + -1 == (code *)0x0) {
                          pcStack_1e0 = (code *)0x23e757b3b;
                          (**(code **)(plStack_110[1] + 0x30))(plStack_110);
                        }
                      }
                      if (plStack_138 != (longlong *)0x0) {
                        pcStack_148 = (code *)*plStack_138;
                        *plStack_138 = (longlong)(pcStack_148 + -1);
                        if (pcStack_148 + -1 == (code *)0x0) {
                          pcStack_1e0 = (code *)0x23e757b6e;
                          (**(code **)(plStack_138[1] + 0x30))(plStack_138);
                        }
                      }
                      goto LAB_23e754e8e;
                    }
                    pcStack_1e0 = (code *)0x23e755441;
                    plVar10 = (longlong *)FUN_23e8bc2f0(pcStack_f8,DAT_23eed8a98);
                    if (plVar10 == (longlong *)0x0) {
LAB_23e7575c0:
                      auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                      auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                      apcStack_88[0] = *(code **)(param_1 + 0x70);
                      uVar29 = 0x36a;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar24 = plStack_d0;
                      plVar16 = plStack_d8;
                      plVar13 = plStack_c0;
                      pcVar31 = pcStack_f8;
                      pcStack_148 = pcVar23;
                      goto LAB_23e755c16;
                    }
                    *(undefined4 *)(plVar25 + 5) = 0x36a;
                    pcStack_1e0 = (code *)0x23e755467;
                    pcStack_148 = (code *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8a98);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      pcStack_1e0 = (code *)0x23e75547f;
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (pcStack_148 == (code *)0x0) goto LAB_23e7575c0;
                    if ((pcVar23 != (code *)0x0) &&
                       (*(longlong *)pcVar23 = *(longlong *)pcVar23 + -1, *(longlong *)pcVar23 == 0)
                       ) {
                      pcStack_1e0 = (code *)0x23e7554a3;
                      (**(code **)(*(longlong *)(pcVar23 + 8) + 0x30))(pcVar23);
                    }
                    pcStack_100 = _Py_NoneStruct_exref;
                    if (pcStack_148 == _Py_NoneStruct_exref) {
                      pcStack_1e0 = (code *)0x23e75629d;
                      lVar21 = FUN_23e8e0ba0();
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar13 = plStack_c0;
                      plVar24 = plStack_d0;
                      plVar16 = plStack_d8;
                      pcVar31 = pcStack_f8;
                      lVar12 = _DAT_23eed9178;
                      if (lVar21 == 0) {
                        pcStack_1e0 = (code *)0x23e7576e4;
                        FUN_23e915740(param_1,auStack_98,DAT_23eed8c70);
                        uVar29 = 0x36c;
                        goto LAB_23e755c16;
                      }
                      *(undefined4 *)(plVar25 + 5) = 0x36c;
                      pcStack_1e0 = (code *)0x23e7562cb;
                      plVar10 = (longlong *)
                                FUN_23e915840(param_1,lVar21,DAT_23eed8d40,
                                              *(undefined8 *)(lVar12 + 0x18));
                      if (plVar10 == (longlong *)0x0) {
                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        apcStack_88[0] = *(code **)(param_1 + 0x70);
                        uVar29 = 0x36c;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar11 = plStack_b0;
                        plVar10 = plStack_b8;
                        plVar24 = plStack_d0;
                        plVar16 = plStack_d8;
                        plVar13 = plStack_c0;
                        pcVar31 = pcStack_f8;
                        goto LAB_23e755c16;
                      }
                      *plVar10 = *plVar10 + -1;
                      pcVar23 = pcStack_148;
                      if (*plVar10 == 0) {
                        pcStack_1e0 = (code *)0x23e7562e8;
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                        pcVar23 = pcStack_148;
                      }
                    }
                    else {
                      *(undefined4 *)(plVar25 + 5) = 0x36f;
                      pcStack_1e0 = (code *)0x23e7554e9;
                      plVar10 = (longlong *)
                                FUN_23e915840(param_1,plStack_c0,DAT_23eed9108,pcStack_148);
                      if (plVar10 == (longlong *)0x0) {
LAB_23e7576f7:
                        pcVar22 = *(code **)(param_1 + 0x60);
                        uVar32 = *(undefined8 *)(param_1 + 0x68);
                        pcVar23 = *(code **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plVar11 = plStack_b0;
                        plVar10 = plStack_b8;
                        plVar24 = plStack_d0;
                        plVar16 = plStack_d8;
                        plVar13 = plStack_c0;
                        pcVar31 = pcStack_f8;
LAB_23e756e46:
                        uVar29 = 0x36f;
                        apcStack_88[0] = pcVar23;
                        auStack_98._0_8_ = pcVar22;
                        auStack_98._8_8_ = uVar32;
                        goto LAB_23e755c16;
                      }
                      pcStack_1e0 = (code *)0x23e7554fd;
                      plVar15 = (longlong *)FUN_23a388310(plVar10);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        pcStack_1e0 = (code *)0x23e755510;
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      if (plVar15 == (longlong *)0x0) goto LAB_23e7576f7;
                      pcStack_1e0 = (code *)0x23e755526;
                      plVar16 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      plStack_c8 = (longlong *)auStack_98;
                      if (plVar16 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e756b6c;
                        plVar16 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,0,8);
                        plVar10 = plStack_b8;
                        plVar24 = plStack_d0;
                        plVar27 = plStack_d8;
                        if (plVar16 != (longlong *)0x0) goto LAB_23e755542;
                        plStack_e0 = (longlong *)0x0;
                        plStack_e8 = (longlong *)0x0;
                        lVar12 = *plVar15;
                        plStack_f0 = (longlong *)0x0;
                        plStack_d0 = (longlong *)0x0;
                        plStack_c8 = (longlong *)0x0;
                        plStack_d8 = (longlong *)0x0;
                        plStack_b8 = (longlong *)0x0;
                        plVar18 = plStack_d8;
                        plVar20 = plStack_d0;
                        plVar19 = plStack_c8;
                        plVar17 = plStack_b8;
LAB_23e756c10:
                        plStack_a0 = plVar16;
                        plStack_b8 = plVar17;
                        plStack_c8 = plVar19;
                        plStack_d0 = plVar20;
                        plStack_d8 = plVar18;
                        pcVar23 = apcStack_88[0];
                        uVar32 = auStack_98._8_8_;
                        pcVar22 = (code *)auStack_98._0_8_;
                        plVar11 = plStack_b0;
                        plVar13 = plStack_c0;
                        pcVar31 = pcStack_f8;
                        auStack_98 = (undefined1  [16])0x0;
                        apcStack_88[0] = (code *)0x0;
                        *plVar15 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          pcStack_100 = pcVar23;
                          pcStack_1e0 = (code *)0x23e756c54;
                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                          pcVar23 = pcStack_100;
                        }
                        apcStack_88[0] = (code *)0x0;
                        auStack_98._0_8_ = 0;
                        auStack_98._8_8_ = 0;
                        if (plStack_a0 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_a0;
                          *plStack_a0 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756ca4;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_a0[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        if (plStack_b8 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_b8;
                          *plStack_b8 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756cdc;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_b8[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        if (plStack_d8 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_d8;
                          *plStack_d8 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756d14;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_d8[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        if (plStack_c8 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_c8;
                          *plStack_c8 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756d52;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_c8[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        if (plStack_d0 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_d0;
                          *plStack_d0 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756d90;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_d0[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        if (plStack_f0 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_f0;
                          *plStack_f0 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756dce;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_f0[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        if (plStack_e8 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_e8;
                          *plStack_e8 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756e06;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_e8[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        plVar16 = plVar27;
                        if (plStack_e0 != (longlong *)0x0) {
                          pcStack_100 = (code *)*plStack_e0;
                          *plStack_e0 = (longlong)(pcStack_100 + -1);
                          if (pcStack_100 + -1 == (code *)0x0) {
                            pcStack_1e0 = (code *)0x23e756e3e;
                            pcStack_100 = pcVar23;
                            (**(code **)(plStack_e0[1] + 0x30))();
                            pcVar23 = pcStack_100;
                          }
                        }
                        goto LAB_23e756e46;
                      }
LAB_23e755542:
                      pcStack_1e0 = (code *)0x23e75554f;
                      plVar17 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plVar17 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e756e84;
                        plVar17 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,1,8);
                        plVar24 = plStack_d0;
                        plVar27 = plStack_d8;
                        if (plVar17 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plStack_e0 = (longlong *)0x0;
                          plStack_e8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plStack_d0 = (longlong *)0x0;
                          plStack_c8 = (longlong *)0x0;
                          plStack_d8 = (longlong *)0x0;
                          plVar10 = plStack_b8;
                          plVar18 = plStack_d8;
                          plVar20 = plStack_d0;
                          plVar19 = plStack_c8;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e755568;
                      plVar18 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plVar18 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e756f4c;
                        plVar18 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,2,8);
                        plVar24 = plStack_d0;
                        if (plVar18 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plStack_e0 = (longlong *)0x0;
                          plStack_e8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plStack_d0 = (longlong *)0x0;
                          plStack_c8 = (longlong *)0x0;
                          plVar10 = plStack_b8;
                          plVar27 = plStack_d8;
                          plVar20 = plStack_d0;
                          plVar19 = plStack_c8;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e755581;
                      plVar19 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plVar19 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e75700c;
                        plVar19 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,3,8);
                        plVar24 = plStack_d0;
                        if (plVar19 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plStack_e0 = (longlong *)0x0;
                          plStack_e8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plStack_d0 = (longlong *)0x0;
                          plVar10 = plStack_b8;
                          plVar27 = plStack_d8;
                          plVar20 = plStack_d0;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e75559a;
                      plVar20 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plVar20 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e7570cc;
                        plVar20 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,4,8);
                        if (plVar20 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plStack_e0 = (longlong *)0x0;
                          plStack_e8 = (longlong *)0x0;
                          plStack_f0 = (longlong *)0x0;
                          plVar10 = plStack_b8;
                          plVar24 = plStack_d0;
                          plVar27 = plStack_d8;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e7555b3;
                      plStack_f0 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plStack_f0 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e757184;
                        plStack_f0 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,5,8);
                        if (plStack_f0 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plStack_e0 = (longlong *)0x0;
                          plStack_e8 = (longlong *)0x0;
                          plVar10 = plStack_b8;
                          plVar24 = plStack_d0;
                          plVar27 = plStack_d8;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e7555d1;
                      plStack_e8 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plStack_e8 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e75723c;
                        plStack_e8 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,6,8);
                        if (plStack_e8 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plStack_e0 = (longlong *)0x0;
                          plVar10 = plStack_b8;
                          plVar24 = plStack_d0;
                          plVar27 = plStack_d8;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e7555ef;
                      plStack_e0 = (longlong *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                      if (plStack_e0 == (longlong *)0x0) {
                        pcStack_1e0 = (code *)0x23e7572e4;
                        plStack_e0 = (longlong *)FUN_23a3c1b70(param_1,plStack_c8,7,8);
                        if (plStack_e0 == (longlong *)0x0) {
                          lVar12 = *plVar15;
                          plVar10 = plStack_b8;
                          plVar24 = plStack_d0;
                          plVar27 = plStack_d8;
                          goto LAB_23e756c10;
                        }
                      }
                      pcStack_1e0 = (code *)0x23e755619;
                      cVar8 = FUN_23a3884a0(param_1,plStack_c8,plVar15,8);
                      lVar12 = *plVar15;
                      plVar10 = plStack_b8;
                      plVar24 = plStack_d0;
                      plVar27 = plStack_d8;
                      if (cVar8 == '\0') goto LAB_23e756c10;
                      *plVar15 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        pcStack_1e0 = (code *)0x23e75563e;
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      lVar12 = *plVar16;
                      *plVar16 = lVar12 + 1;
                      if (plStack_d8 != (longlong *)0x0) {
                        plStack_a0 = (longlong *)*plStack_d8;
                        *plStack_d8 = (longlong)plStack_a0 + -1;
                        if ((longlong)plStack_a0 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e75657a;
                          (**(code **)(plStack_d8[1] + 0x30))(plStack_d8);
                        }
                        lVar12 = *plVar16 + -1;
                      }
                      *plVar16 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e755686;
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      lVar12 = *plVar17;
                      *plVar17 = lVar12 + 1;
                      if (plStack_140 != (longlong *)0x0) {
                        plStack_d8 = (longlong *)*plStack_140;
                        *plStack_140 = (longlong)plStack_d8 + -1;
                        if ((longlong)plStack_d8 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e75656a;
                          (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                        }
                        lVar12 = *plVar17 + -1;
                      }
                      *plVar17 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e7556ce;
                        (**(code **)(plVar17[1] + 0x30))(plVar17);
                      }
                      lVar12 = *plVar18;
                      *plVar18 = lVar12 + 1;
                      if (plStack_130 != (longlong *)0x0) {
                        plStack_140 = (longlong *)*plStack_130;
                        *plStack_130 = (longlong)plStack_140 + -1;
                        if ((longlong)plStack_140 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e75655a;
                          (**(code **)(plStack_130[1] + 0x30))(plStack_130);
                        }
                        lVar12 = *plVar18 + -1;
                      }
                      *plVar18 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e75571a;
                        (**(code **)(plVar18[1] + 0x30))(plVar18);
                      }
                      lVar12 = *plVar19;
                      *plVar19 = lVar12 + 1;
                      if (plStack_118 != (longlong *)0x0) {
                        plStack_140 = (longlong *)*plStack_118;
                        *plStack_118 = (longlong)plStack_140 + -1;
                        if ((longlong)plStack_140 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e75654a;
                          (**(code **)(plStack_118[1] + 0x30))(plStack_118);
                        }
                        lVar12 = *plVar19 + -1;
                      }
                      *plVar19 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e755767;
                        (**(code **)(plVar19[1] + 0x30))(plVar19);
                      }
                      lVar12 = *plVar20;
                      *plVar20 = lVar12 + 1;
                      if (plStack_d0 != (longlong *)0x0) {
                        plStack_140 = (longlong *)*plStack_d0;
                        *plStack_d0 = (longlong)plStack_140 + -1;
                        if ((longlong)plStack_140 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e756532;
                          (**(code **)(plStack_d0[1] + 0x30))(plStack_d0);
                        }
                        lVar12 = *plVar20 + -1;
                      }
                      *plVar20 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e7557af;
                        (**(code **)(plVar20[1] + 0x30))(plVar20);
                      }
                      lVar12 = *plStack_f0;
                      *plStack_f0 = lVar12 + 1;
                      if (plStack_128 != (longlong *)0x0) {
                        plStack_140 = (longlong *)*plStack_128;
                        *plStack_128 = (longlong)plStack_140 + -1;
                        if ((longlong)plStack_140 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e7557ed;
                          (**(code **)(plStack_128[1] + 0x30))();
                          plStack_140 = (longlong *)*plStack_f0;
                          lVar12 = (longlong)plStack_140 + -1;
                        }
                        else {
                          plStack_140 = (longlong *)*plStack_f0;
                          lVar12 = (longlong)plStack_140 + -1;
                        }
                      }
                      *plStack_f0 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e75581b;
                        (**(code **)(plStack_f0[1] + 0x30))();
                      }
                      lVar12 = *plStack_e8;
                      *plStack_e8 = lVar12 + 1;
                      if (plStack_110 != (longlong *)0x0) {
                        plStack_140 = (longlong *)*plStack_110;
                        *plStack_110 = (longlong)plStack_140 + -1;
                        if ((longlong)plStack_140 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e75585c;
                          (**(code **)(plStack_110[1] + 0x30))(plStack_110);
                          plStack_140 = (longlong *)*plStack_e8;
                          lVar12 = (longlong)plStack_140 + -1;
                        }
                        else {
                          plStack_140 = (longlong *)*plStack_e8;
                          lVar12 = (longlong)plStack_140 + -1;
                        }
                      }
                      *plStack_e8 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e75588a;
                        (**(code **)(plStack_e8[1] + 0x30))();
                      }
                      lVar12 = *plStack_e0;
                      *plStack_e0 = lVar12 + 1;
                      if (plStack_138 != (longlong *)0x0) {
                        plStack_140 = (longlong *)*plStack_138;
                        *plStack_138 = (longlong)plStack_140 + -1;
                        if ((longlong)plStack_140 + -1 == 0) {
                          pcStack_1e0 = (code *)0x23e7558c8;
                          (**(code **)(plStack_138[1] + 0x30))();
                          plStack_140 = (longlong *)*plStack_e0;
                          lVar12 = (longlong)plStack_140 + -1;
                        }
                        else {
                          plStack_140 = (longlong *)*plStack_e0;
                          lVar12 = (longlong)plStack_140 + -1;
                        }
                      }
                      *plStack_e0 = lVar12;
                      if (lVar12 == 0) {
                        pcStack_1e0 = (code *)0x23e7558f6;
                        (**(code **)(plStack_e0[1] + 0x30))();
                      }
                      pcStack_1e0 = (code *)0x23e7558fe;
                      iVar9 = FUN_23a35f020(plVar20);
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar13 = plStack_c0;
                      pcVar31 = pcStack_f8;
                      plVar24 = plVar20;
                      if (iVar9 == -1) {
                        uVar29 = 0x370;
                        plStack_138 = plStack_e0;
                        plStack_110 = plStack_e8;
                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        plStack_128 = plStack_f0;
                        apcStack_88[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plStack_140 = plVar17;
                        plStack_130 = plVar18;
                        plStack_118 = plVar19;
                        plStack_d8 = plVar18;
                        plStack_d0 = plVar20;
                        plStack_c8 = plVar19;
                        plStack_b8 = plVar17;
                        plStack_a0 = plVar16;
                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        goto LAB_23e755c16;
                      }
                      if (iVar9 != 0) {
                        pcStack_1e0 = (code *)0x23e757dd1;
                        plStack_d8 = plVar18;
                        plStack_d0 = plVar20;
                        plStack_c8 = plVar19;
                        plStack_b8 = plVar17;
                        plStack_a0 = plVar16;
                        plVar24 = (longlong *)FUN_23e8bc2f0(pcStack_f8,DAT_23eed8b40);
                        plVar16 = _DAT_23eed9168;
                        if (plVar24 == (longlong *)0x0) {
LAB_23e758138:
                          apcStack_88[0] = *(code **)(param_1 + 0x70);
                          auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                          auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        }
                        else {
                          lVar12 = *(longlong *)(param_1 + 0x10);
                          plVar15 = *(longlong **)(lVar12 + 0xe28);
                          if (plVar15 == (longlong *)0x0) {
                            plStack_140 = _DAT_23eed9168;
                            pcStack_1e0 = (code *)0x23e758128;
                            plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                            plVar16 = plStack_140;
                          }
                          else {
                            lVar21 = plVar15[3];
                            *(int *)(lVar12 + 0xec0) = *(int *)(lVar12 + 0xec0) + -1;
                            *(longlong *)(lVar12 + 0xe28) = lVar21;
                            *plVar15 = 1;
                          }
                          plVar27 = plStack_f0;
                          pcVar23 = _PyRuntime_exref;
                          *(undefined1 (*) [16])(plVar15 + 4) = (undefined1  [16])0x0;
                          puVar14 = *(undefined8 **)
                                     (*(longlong *)(*(longlong *)(pcVar23 + 0x1f8) + 0x10) + 0x2e8);
                          lVar12 = plVar15[-1];
                          puVar6 = (undefined8 *)puVar14[1];
                          *puVar6 = plVar15 + -2;
                          plVar15[-2] = (longlong)puVar14;
                          plVar15[-1] = (ulonglong)((uint)lVar12 & 3) | (ulonglong)puVar6;
                          puVar14[1] = plVar15 + -2;
                          *plVar16 = *plVar16 + 1;
                          plVar15[3] = (longlong)plVar16;
                          plVar16 = DAT_23ed6cd28;
                          if (DAT_23ed6a4c0 == (longlong *)0x0) {
                            pcStack_1e0 = (code *)0x23e758245;
                            plVar18 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                            if (plVar18 == (longlong *)0x0) {
                              pcStack_1e0 = (code *)0x23e7582b0;
                              PyErr_PrintEx(0);
                              lVar12 = 1;
                              pcStack_1e0 = (code *)0x23e7582bb;
                              Py_Exit();
                              plVar18 = DAT_23eedade8;
                              pcStack_1e0 = pcVar31;
                              plStack_1e8 = plVar13;
                              plStack_200 = plVar11;
                              plStack_210 = plVar10;
                              plStack_230 = plVar27;
                              plStack_228 = plVar16;
                              plVar10 = (longlong *)*puVar14;
                              pcStack_240 = (code *)0x0;
                              auStack_250 = (undefined1  [16])0x0;
                              plStack_218 = plVar25;
                              lStack_208 = param_1;
                              plStack_1f8 = plVar15;
                              plStack_1f0 = plVar24;
                              if (DAT_23eedade8 == (longlong *)0x0) {
LAB_23e75831d:
                                DAT_23eedade8 =
                                     (longlong *)
                                     FUN_23e91f3b0(lVar12,DAT_23eedaf90,DAT_23eedaeb8,0x60);
                              }
                              else {
                                lVar21 = *DAT_23eedade8;
                                if (1 < lVar21) {
                                  *DAT_23eedade8 = lVar21 + -1;
                                  goto LAB_23e75831d;
                                }
                                if (DAT_23eedade8[2] != 0) {
                                  *DAT_23eedade8 = lVar21 + -1;
                                  if (lVar21 + -1 == 0) {
                                    (**(code **)(plVar18[1] + 0x30))(plVar18);
                                  }
                                  goto LAB_23e75831d;
                                }
                              }
                              plVar11 = DAT_23eedade8;
                              lVar21 = *(longlong *)(lVar12 + 0x38);
                              plVar25 = DAT_23eedade8 + 9;
                              lVar26 = *(longlong *)(lVar21 + 8);
                              DAT_23eedade8[0xf] = lVar26;
                              *(longlong **)(lVar21 + 8) = plVar25;
                              if ((lVar26 != 0) &&
                                 (((*(char *)(lVar26 + 0x45) == '\x01' ||
                                   ((ulonglong)
                                    (*(longlong *)(lVar26 + 0x20) + 0xb8 +
                                    (longlong)*(int *)(*(longlong *)(lVar26 + 0x20) + 0xa8) * 2) <=
                                    *(ulonglong *)(lVar26 + 0x38))) && (plVar11[0xe] != 0)))) {
                                plVar25 = *(longlong **)(lVar26 + 0x28);
                                *(longlong **)(plVar11[0xe] + 0x10) = plVar25;
                                if (plVar25 != (longlong *)0x0) {
                                  *plVar25 = *plVar25 + 1;
                                }
                              }
                              *plVar11 = *plVar11 + 1;
                              uVar32 = DAT_23eed89b0;
                              *(undefined4 *)(plVar11 + 8) = 0;
                              plVar25 = (longlong *)FUN_23e8bc2f0(plVar10,uVar32);
                              if (plVar25 == (longlong *)0x0) {
                                pcStack_240 = *(code **)(lVar12 + 0x70);
                                auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                plVar24 = (longlong *)0x0;
                                plVar16 = (longlong *)0x0;
                                *(undefined8 *)(lVar12 + 0x70) = 0;
                                pcVar31 = (code *)0x0;
                                plVar13 = (longlong *)0x0;
                                uVar29 = 0x378;
                                plStack_2a8 = (longlong *)0x0;
                                plStack_290 = (longlong *)0x0;
                                plStack_2a0 = (longlong *)0x0;
                                plStack_2b8 = (longlong *)0x0;
                                plStack_298 = (longlong *)0x0;
                                plStack_2b0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(lVar12 + 0x60) = (undefined1  [16])0x0;
                                plVar25 = (longlong *)0x0;
                                goto LAB_23e758dff;
                              }
                              *(undefined4 *)(plVar11 + 5) = 0x378;
                              plVar13 = (longlong *)FUN_23e91bfe0(lVar12,plVar25,DAT_23eed8d38);
                              *plVar25 = *plVar25 + -1;
                              if (*plVar25 == 0) {
                                (**(code **)(plVar25[1] + 0x30))(plVar25);
                                if (plVar13 == (longlong *)0x0) goto LAB_23e758b73;
LAB_23e7583ea:
                                iVar9 = FUN_23a35f020(plVar13);
                                lVar21 = *plVar13 + -1;
                                if (iVar9 == -1) {
                                  auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                  *(undefined1 (*) [16])(lVar12 + 0x60) = (undefined1  [16])0x0;
                                  *plVar13 = lVar21;
                                  if (lVar21 == 0) {
                                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                                  }
                                  plStack_2b8 = (longlong *)0x0;
                                  plVar24 = (longlong *)0x0;
                                  plVar13 = (longlong *)0x0;
                                  plVar25 = (longlong *)0x0;
                                  plStack_2a8 = (longlong *)0x0;
                                  plVar16 = (longlong *)0x0;
                                  uVar29 = 0x378;
                                  pcVar31 = (code *)0x0;
                                  plStack_290 = (longlong *)0x0;
                                  plStack_2a0 = (longlong *)0x0;
                                  plStack_298 = (longlong *)0x0;
                                  plStack_2b0 = (longlong *)0x0;
                                  goto LAB_23e758dff;
                                }
                                *plVar13 = lVar21;
                                if (lVar21 == 0) {
                                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                                }
                                pcVar23 = _Py_NoneStruct_exref;
                                if (iVar9 != 0) {
                                  lVar12 = *(longlong *)(lVar12 + 0x38);
                                  lVar21 = *(longlong *)(lVar12 + 8);
                                  *(longlong *)_Py_NoneStruct_exref =
                                       *(longlong *)_Py_NoneStruct_exref + 1;
                                  plVar25 = *(longlong **)(lVar21 + 0x28);
                                  plVar11 = (longlong *)plVar25[2];
                                  *(undefined8 *)(lVar12 + 8) = *(undefined8 *)(lVar21 + 0x30);
                                  *(undefined4 *)(plVar25 + 8) = 0xffffffff;
                                  if (plVar11 != (longlong *)0x0) {
                                    plVar25[2] = 0;
                                    *plVar11 = *plVar11 + -1;
                                    if (*plVar11 == 0) {
                                      (**(code **)(plVar11[1] + 0x30))();
                                    }
                                  }
                                  *plVar25 = *plVar25 + -1;
                                  if (*plVar25 == 0) {
                                    (**(code **)(plVar25[1] + 0x30))(plVar25);
                                  }
                                  plVar25[0xf] = 0;
LAB_23e758d12:
                                  *plVar10 = *plVar10 + -1;
                                  lVar12 = *plVar10;
joined_r0x00023e758d17:
                                  if (lVar12 != 0) {
                                    return pcVar23;
                                  }
                                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                                  return pcVar23;
                                }
                                lVar26 = FUN_23e8e0ba0();
                                lVar21 = DAT_23eed8c58;
                                if (lVar26 == 0) {
                                  FUN_23e915740(lVar12,auStack_250,DAT_23eed8c70);
LAB_23e7594d7:
                                  plVar25 = (longlong *)0x0;
                                  plStack_2b8 = (longlong *)0x0;
                                  plVar24 = (longlong *)0x0;
                                  plVar16 = (longlong *)0x0;
                                  plVar13 = (longlong *)0x0;
                                  plStack_2a8 = (longlong *)0x0;
                                  pcVar31 = (code *)0x0;
                                  uVar29 = 0x37c;
                                  plStack_290 = (longlong *)0x0;
                                  plStack_2a0 = (longlong *)0x0;
                                  plStack_298 = (longlong *)0x0;
                                  plStack_2b0 = (longlong *)0x0;
                                }
                                else {
                                  *(undefined4 *)(plVar11 + 5) = 0x37c;
                                  plVar25 = (longlong *)
                                            FUN_23e915840(lVar12,lVar26,DAT_23eed8d40,
                                                          *(undefined8 *)(lVar21 + 0x18));
                                  if (plVar25 == (longlong *)0x0) {
                                    auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                    *(undefined1 (*) [16])(lVar12 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e7594d7;
                                  }
                                  *plVar25 = *plVar25 + -1;
                                  if (*plVar25 == 0) {
                                    (**(code **)(plVar25[1] + 0x30))(plVar25);
                                  }
                                  plVar13 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23eed8968);
                                  if (plVar13 == (longlong *)0x0) {
                                    auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                    plVar24 = (longlong *)0x0;
                                    plVar16 = (longlong *)0x0;
                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                    pcVar31 = (code *)0x0;
                                    plVar25 = (longlong *)0x0;
                                    uVar29 = 0x37e;
                                    plStack_2a8 = (longlong *)0x0;
                                    plStack_290 = (longlong *)0x0;
                                    plStack_2a0 = (longlong *)0x0;
                                    plStack_2b8 = (longlong *)0x0;
                                    plStack_298 = (longlong *)0x0;
                                    plStack_2b0 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(lVar12 + 0x60) = (undefined1  [16])0x0;
                                    plVar13 = (longlong *)0x0;
                                  }
                                  else {
                                    *(undefined4 *)(plVar11 + 5) = 0x37e;
                                    plVar25 = (longlong *)
                                              FUN_23e91bfe0(lVar12,plVar13,DAT_23eed9248);
                                    *plVar13 = *plVar13 + -1;
                                    if (*plVar13 == 0) {
                                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                                    }
                                    if (plVar25 == (longlong *)0x0) {
                                      auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                      plVar24 = (longlong *)0x0;
                                      plVar16 = (longlong *)0x0;
                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                      pcVar31 = (code *)0x0;
                                      plVar13 = (longlong *)0x0;
                                      uVar29 = 0x37e;
                                      plStack_2a8 = (longlong *)0x0;
                                      plStack_290 = (longlong *)0x0;
                                      plStack_2a0 = (longlong *)0x0;
                                      plStack_2b8 = (longlong *)0x0;
                                      plStack_298 = (longlong *)0x0;
                                      plStack_2b0 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(lVar12 + 0x60) = (undefined1  [16])0x0;
                                    }
                                    else {
                                      plVar16 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23eed8968);
                                      if (plVar16 == (longlong *)0x0) {
                                        auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                        plVar24 = (longlong *)0x0;
                                        plVar16 = (longlong *)0x0;
                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                        plVar13 = (longlong *)0x0;
                                        uVar29 = 0x37f;
                                        plStack_2a8 = (longlong *)0x0;
                                        plStack_290 = (longlong *)0x0;
                                        plStack_2a0 = (longlong *)0x0;
                                        plStack_2b8 = (longlong *)0x0;
                                        plStack_298 = (longlong *)0x0;
                                        plStack_2b0 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                             (undefined1  [16])0x0;
                                        pcVar31 = (code *)0x0;
                                      }
                                      else {
                                        *(undefined4 *)(plVar11 + 5) = 0x37f;
                                        plVar13 = (longlong *)
                                                  FUN_23e91bfe0(lVar12,plVar16,DAT_23eed9250);
                                        *plVar16 = *plVar16 + -1;
                                        if (*plVar16 == 0) {
                                          (**(code **)(plVar16[1] + 0x30))(plVar16);
                                        }
                                        if (plVar13 == (longlong *)0x0) {
                                          auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                          plVar24 = (longlong *)0x0;
                                          plVar16 = (longlong *)0x0;
                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                          pcVar31 = (code *)0x0;
                                          uVar29 = 0x37f;
                                          plStack_2a8 = (longlong *)0x0;
                                          plStack_290 = (longlong *)0x0;
                                          plStack_2a0 = (longlong *)0x0;
                                          plStack_2b8 = (longlong *)0x0;
                                          plStack_298 = (longlong *)0x0;
                                          plStack_2b0 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          plVar16 = (longlong *)FUN_23e8bd600(lVar12,plVar25);
                                          if (plVar16 == (longlong *)0x0) {
LAB_23e759690:
                                            pcVar31 = (code *)0x0;
                                            auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                            pcStack_240 = *(code **)(lVar12 + 0x70);
                                            plVar24 = (longlong *)0x0;
                                            plVar16 = (longlong *)0x0;
                                            *(undefined8 *)(lVar12 + 0x70) = 0;
                                            uVar29 = 0x380;
                                            plStack_2a8 = (longlong *)0x0;
                                            plStack_290 = (longlong *)0x0;
                                            plStack_2a0 = (longlong *)0x0;
                                            plStack_2b8 = (longlong *)0x0;
                                            plStack_298 = (longlong *)0x0;
                                            plStack_2b0 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          else {
                                            lVar21 = *plVar16 + -1;
                                            *plVar16 = lVar21;
                                            if (plVar16[2] == 0) {
                                              pcVar31 = _Py_TrueStruct_exref;
                                              if (lVar21 == 0) {
                                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                                                pcVar31 = _Py_TrueStruct_exref;
                                              }
                                            }
                                            else {
                                              pcVar31 = _Py_FalseStruct_exref;
                                              if (lVar21 == 0) {
                                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                                                pcVar31 = _Py_FalseStruct_exref;
                                              }
                                            }
                                            iVar9 = FUN_23a35f020(pcVar31);
                                            if (iVar9 == 1) {
                                              plVar16 = (longlong *)FUN_23e8bd600(lVar12,plVar13);
                                              if (plVar16 == (longlong *)0x0) goto LAB_23e759690;
                                              lVar21 = plVar16[2];
                                              lVar26 = *plVar16 + -1;
                                              *plVar16 = lVar26;
                                              if (lVar21 == 0) {
                                                if (lVar26 == 0) {
                                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                                }
                                              }
                                              else {
                                                if (lVar26 == 0) {
                                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                                }
                                                pcVar31 = _Py_TrueStruct_exref;
                                                if (0 < lVar21) goto LAB_23e75855a;
                                              }
                                              pcVar31 = _Py_FalseStruct_exref;
                                            }
LAB_23e75855a:
                                            lVar26 = DAT_23eed8950;
                                            *(longlong *)pcVar31 = *(longlong *)pcVar31 + 1;
                                            lVar21 = *(longlong *)(lVar26 + 0x20);
                                            if (*(char *)(lVar21 + 10) == '\0') {
                                              plVar16 = (longlong *)
                                                        FUN_23a37a020(lVar26,DAT_23eed9258);
                                              if (plVar16 == (longlong *)0x0) goto LAB_23e759370;
                                              lVar26 = *plVar16;
LAB_23e759364:
                                              if (lVar26 == 0) goto LAB_23e759370;
                                            }
                                            else {
                                              iVar9 = *(int *)(lVar21 + 0xc);
                                              if (*(int *)(lVar21 + 0xc) == 0) {
                                                *(int *)(lVar21 + 0xc) = DAT_23ec1545c;
                                                iVar9 = DAT_23ec1545c;
                                                DAT_23ec1545c = DAT_23ec1545c + 1;
                                              }
                                              if (DAT_23ec15428 != iVar9) {
                                                DAT_23ec15428 = iVar9;
                                                DAT_23eedadd8 =
                                                     FUN_23e8cbd60(lVar21,DAT_23eed9258,
                                                                   *(undefined8 *)
                                                                    (DAT_23eed9258 + 0x18));
                                              }
                                              if (-1 < DAT_23eedadd8) {
                                                lVar2 = lVar21 + 0x20 +
                                                        (1L << (*(byte *)(lVar21 + 9) & 0x3f));
                                                lVar26 = *(longlong *)
                                                          (lVar2 + 8 + DAT_23eedadd8 * 0x10);
                                                if (lVar26 != 0) goto LAB_23e7585d0;
                                                DAT_23eedadd8 =
                                                     FUN_23e8cbd60(lVar21,DAT_23eed9258,
                                                                   *(undefined8 *)
                                                                    (DAT_23eed9258 + 0x18));
                                                if (-1 < DAT_23eedadd8) {
                                                  lVar26 = *(longlong *)
                                                            (lVar2 + 8 + DAT_23eedadd8 * 0x10);
                                                  goto LAB_23e759364;
                                                }
                                              }
LAB_23e759370:
                                              plVar16 = (longlong *)
                                                        FUN_23a37a020(DAT_23ed6ccc0,DAT_23eed9258);
                                              if ((plVar16 == (longlong *)0x0) ||
                                                 (lVar26 = *plVar16, lVar26 == 0)) {
                                                plVar24 = (longlong *)0x0;
                                                plVar16 = (longlong *)0x0;
                                                FUN_23e915740(lVar12,auStack_250,DAT_23eed9258);
                                                plStack_2a8 = (longlong *)0x0;
                                                uVar29 = 0x382;
                                                plStack_290 = (longlong *)0x0;
                                                plStack_2a0 = (longlong *)0x0;
                                                plStack_2b8 = (longlong *)0x0;
                                                plStack_298 = (longlong *)0x0;
                                                plStack_2b0 = (longlong *)0x0;
                                                goto LAB_23e758dff;
                                              }
                                            }
LAB_23e7585d0:
                                            plVar16 = (longlong *)
                                                      FUN_23e8bc2f0(plVar10,DAT_23eed8aa8);
                                            if (plVar16 == (longlong *)0x0) {
                                              auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                              pcStack_240 = *(code **)(lVar12 + 0x70);
                                              plVar24 = (longlong *)0x0;
                                              plVar16 = (longlong *)0x0;
                                              *(undefined8 *)(lVar12 + 0x70) = 0;
                                              uVar29 = 0x382;
                                              plStack_2a8 = (longlong *)0x0;
                                              plStack_290 = (longlong *)0x0;
                                              plStack_2a0 = (longlong *)0x0;
                                              plStack_2b8 = (longlong *)0x0;
                                              plStack_2b0 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_298 = (longlong *)0x0;
                                            }
                                            else {
                                              plStack_2b0 = (longlong *)
                                                            FUN_23a38cc10(lVar12,lVar26,plVar16);
                                              lVar21 = *plVar16;
                                              *plVar16 = lVar21 + -1;
                                              if (lVar21 + -1 == 0) {
                                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                                              }
                                              if (plStack_2b0 == (longlong *)0x0) {
                                                auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                                pcStack_240 = *(code **)(lVar12 + 0x70);
                                                plVar24 = (longlong *)0x0;
                                                plVar16 = (longlong *)0x0;
                                                *(undefined8 *)(lVar12 + 0x70) = 0;
                                                uVar29 = 0x382;
                                                plStack_2a8 = (longlong *)0x0;
                                                plStack_290 = (longlong *)0x0;
                                                plStack_2a0 = (longlong *)0x0;
                                                plStack_2b8 = (longlong *)0x0;
                                                plStack_298 = (longlong *)0x0;
                                                *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                     (undefined1  [16])0x0;
                                              }
                                              else {
                                                lVar21 = *(longlong *)(DAT_23eed8950 + 0x20);
                                                if (*(char *)(lVar21 + 10) == '\0') {
                                                  plVar16 = (longlong *)
                                                            FUN_23a37a020(DAT_23eed8950,
                                                                          DAT_23eed9260);
                                                  if (plVar16 == (longlong *)0x0)
                                                  goto LAB_23e759600;
                                                  lVar26 = *plVar16;
LAB_23e7595f5:
                                                  if (lVar26 == 0) goto LAB_23e759600;
                                                }
                                                else {
                                                  iVar9 = *(int *)(lVar21 + 0xc);
                                                  if (*(int *)(lVar21 + 0xc) == 0) {
                                                    *(int *)(lVar21 + 0xc) = DAT_23ec1545c;
                                                    iVar9 = DAT_23ec1545c;
                                                    DAT_23ec1545c = DAT_23ec1545c + 1;
                                                  }
                                                  if (DAT_23ec1542c != iVar9) {
                                                    DAT_23ec1542c = iVar9;
                                                    DAT_23eedade0 =
                                                         FUN_23e8cbd60(lVar21,DAT_23eed9260,
                                                                       *(undefined8 *)
                                                                        (DAT_23eed9260 + 0x18));
                                                  }
                                                  if (-1 < DAT_23eedade0) {
                                                    lVar2 = lVar21 + 0x20 +
                                                            (1L << (*(byte *)(lVar21 + 9) & 0x3f));
                                                    lVar26 = *(longlong *)
                                                              (lVar2 + 8 + DAT_23eedade0 * 0x10);
                                                    if (lVar26 != 0) goto LAB_23e7586a4;
                                                    DAT_23eedade0 =
                                                         FUN_23e8cbd60(lVar21,DAT_23eed9260,
                                                                       *(undefined8 *)
                                                                        (DAT_23eed9260 + 0x18));
                                                    if (-1 < DAT_23eedade0) {
                                                      lVar26 = *(longlong *)
                                                                (lVar2 + 8 + DAT_23eedade0 * 0x10);
                                                      goto LAB_23e7595f5;
                                                    }
                                                  }
LAB_23e759600:
                                                  plVar16 = (longlong *)
                                                            FUN_23a37a020(DAT_23ed6ccc0,
                                                                          DAT_23eed9260);
                                                  if ((plVar16 == (longlong *)0x0) ||
                                                     (lVar26 = *plVar16, lVar26 == 0)) {
                                                    plVar24 = (longlong *)0x0;
                                                    plVar16 = (longlong *)0x0;
                                                    FUN_23e915740(lVar12,auStack_250,DAT_23eed9260);
                                                    plStack_2a8 = (longlong *)0x0;
                                                    uVar29 = 899;
                                                    plStack_290 = (longlong *)0x0;
                                                    plStack_2a0 = (longlong *)0x0;
                                                    plStack_2b8 = (longlong *)0x0;
                                                    plStack_298 = (longlong *)0x0;
                                                    goto LAB_23e758dff;
                                                  }
                                                }
LAB_23e7586a4:
                                                plVar16 = (longlong *)
                                                          FUN_23e8bc2f0(plVar10,DAT_23eed8aa8);
                                                if (plVar16 == (longlong *)0x0) {
                                                  auStack_250 = *(undefined1 (*) [16])
                                                                 (lVar12 + 0x60);
                                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                                  plStack_2a8 = (longlong *)0x0;
                                                  plVar24 = (longlong *)0x0;
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  uVar29 = 899;
                                                  plStack_290 = (longlong *)0x0;
                                                  plStack_2a0 = (longlong *)0x0;
                                                  plStack_2b8 = (longlong *)0x0;
                                                  plStack_298 = (longlong *)0x0;
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plVar16 = (longlong *)0x0;
                                                }
                                                else {
                                                  plStack_298 = (longlong *)
                                                                FUN_23a38cc10(lVar12,lVar26,plVar16)
                                                  ;
                                                  *plVar16 = *plVar16 + -1;
                                                  if (*plVar16 == 0) {
                                                    (**(code **)(plVar16[1] + 0x30))(plVar16);
                                                  }
                                                  if (plStack_298 == (longlong *)0x0) {
                                                    auStack_250 = *(undefined1 (*) [16])
                                                                   (lVar12 + 0x60);
                                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                                    plVar24 = (longlong *)0x0;
                                                    plVar16 = (longlong *)0x0;
                                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                                    uVar29 = 899;
                                                    plStack_2a8 = (longlong *)0x0;
                                                    plStack_290 = (longlong *)0x0;
                                                    plStack_2a0 = (longlong *)0x0;
                                                    plStack_2b8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar24 = (longlong *)
                                                              FUN_23e8bc2f0(plVar10,DAT_23eed8af8);
                                                    plVar16 = (longlong *)0x0;
                                                    if (plVar24 == (longlong *)0x0) {
LAB_23e759950:
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      plStack_2a8 = (longlong *)0x0;
                                                      plVar24 = (longlong *)0x0;
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      uVar29 = 0x386;
                                                      plStack_290 = (longlong *)0x0;
                                                      plStack_2a0 = (longlong *)0x0;
                                                      plStack_2b8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)
                                                                FUN_23e8bc2f0(plVar24,DAT_23eed9268)
                                                      ;
                                                      *plVar24 = *plVar24 + -1;
                                                      if (*plVar24 == 0) {
                                                        (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                      }
                                                      lVar21 = DAT_23eed9270;
                                                      if (plVar15 == (longlong *)0x0) {
                                                        auStack_250 = *(undefined1 (*) [16])
                                                                       (lVar12 + 0x60);
                                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                                        plStack_2a8 = (longlong *)0x0;
                                                        plVar16 = (longlong *)0x0;
                                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                                        uVar29 = 0x386;
                                                        plStack_290 = (longlong *)0x0;
                                                        plStack_2a0 = (longlong *)0x0;
                                                        plStack_2b8 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plVar24 = (longlong *)0x0;
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar11 + 5) = 0x386;
                                                        plVar16 = (longlong *)
                                                                  FUN_23e9186b0(lVar12,plVar15,
                                                                                lVar21 + 0x18,
                                                                                DAT_23eed8ce8);
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                                                        }
                                                        if (plVar16 == (longlong *)0x0)
                                                        goto LAB_23e759950;
                                                        iVar9 = FUN_23a35f020(plVar16);
                                                        if (iVar9 == -1) {
LAB_23e75a60d:
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          uVar29 = 0x388;
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
LAB_23e75a63c:
                                                          plStack_2a8 = (longlong *)0x0;
                                                          plVar24 = (longlong *)0x0;
                                                          plStack_290 = (longlong *)0x0;
                                                          plStack_2a0 = (longlong *)0x0;
                                                          plStack_2b8 = (longlong *)0x0;
                                                        }
                                                        else if (iVar9 == 0) {
LAB_23e75879d:
                                                          iVar9 = FUN_23a35f020(pcVar31);
                                                          lVar26 = DAT_23eed92d8;
                                                          lVar21 = DAT_23eed92d0;
                                                          uVar32 = DAT_23eed8b40;
                                                          if (iVar9 == -1) {
                                                            auStack_250 = *(undefined1 (*) [16])
                                                                           (lVar12 + 0x60);
                                                            pcStack_240 = *(code **)(lVar12 + 0x70);
                                                            uVar29 = 0x39c;
                                                            *(undefined8 *)(lVar12 + 0x70) = 0;
                                                            *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                                 (undefined1  [16])0x0;
                                                            goto LAB_23e75a63c;
                                                          }
                                                          if (iVar9 == 0) {
                                                            *(undefined4 *)(plVar11 + 5) = 0x3a1;
                                                            plVar24 = (longlong *)
                                                                      FUN_23e915840(lVar12,plVar10,
                                                                                    uVar32,*(
                                                  undefined8 *)(lVar26 + 0x18));
                                                  if (plVar24 == (longlong *)0x0) {
                                                    auStack_250 = *(undefined1 (*) [16])
                                                                   (lVar12 + 0x60);
                                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                                    plStack_2a8 = (longlong *)0x0;
                                                    plStack_290 = (longlong *)0x0;
                                                    plStack_2a0 = (longlong *)0x0;
                                                    plStack_2b8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plVar24 = (longlong *)0x0;
                                                    uVar29 = 0x3a1;
                                                  }
                                                  else {
LAB_23e7588d7:
                                                    *plVar24 = *plVar24 + -1;
                                                    if (*plVar24 == 0) {
                                                      (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                    }
                                                    plStack_2a8 = (longlong *)0x0;
                                                    plVar24 = (longlong *)0x0;
                                                    plStack_290 = (longlong *)0x0;
                                                    plStack_2a0 = (longlong *)0x0;
                                                    plStack_2b8 = (longlong *)0x0;
LAB_23e758917:
                                                    lVar21 = FUN_23e8e0e20();
                                                    if (lVar21 == 0) {
                                                      FUN_23e915740(lVar12,auStack_250,DAT_23eed8988
                                                                   );
                                                      uVar29 = 0x3a3;
                                                    }
                                                    else {
                                                      plVar15 = (longlong *)
                                                                FUN_23e8bc2f0(lVar21,DAT_23eed8990);
                                                      if (plVar15 != (longlong *)0x0) {
                                                        cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed8998,
                                                                              plVar15);
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                                                        }
                                                        if (cVar8 != '\0') {
                                                          lVar21 = *(longlong *)
                                                                    (*(longlong *)(lVar12 + 0x38) +
                                                                    8);
                                                          plVar11 = *(longlong **)(lVar21 + 0x28);
                                                          plVar15 = (longlong *)plVar11[2];
                                                          *(undefined8 *)
                                                           (*(longlong *)(lVar12 + 0x38) + 8) =
                                                               *(undefined8 *)(lVar21 + 0x30);
                                                          *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                                                          if (plVar15 != (longlong *)0x0) {
                                                            plVar11[2] = 0;
                                                            *plVar15 = *plVar15 + -1;
                                                            if (*plVar15 == 0) {
                                                              (**(code **)(plVar15[1] + 0x30))();
                                                            }
                                                          }
                                                          *plVar11 = *plVar11 + -1;
                                                          if (*plVar11 == 0) {
                                                            (**(code **)(plVar11[1] + 0x30))
                                                                      (plVar11);
                                                          }
                                                          plVar11[0xf] = 0;
                                                          pcVar23 = _Py_NoneStruct_exref;
                                                          *(longlong *)_Py_NoneStruct_exref =
                                                               *(longlong *)_Py_NoneStruct_exref + 1
                                                          ;
                                                          *plVar25 = *plVar25 + -1;
                                                          if (*plVar25 == 0) {
                                                            (**(code **)(plVar25[1] + 0x30))
                                                                      (plVar25);
                                                          }
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            (**(code **)(plVar13[1] + 0x30))
                                                                      (plVar13);
                                                          }
                                                          *(longlong *)pcVar31 =
                                                               *(longlong *)pcVar31 + -1;
                                                          if (*(longlong *)pcVar31 == 0) {
                                                            (**(code **)(*(longlong *)(pcVar31 + 8)
                                                                        + 0x30))(pcVar31);
                                                          }
                                                          lVar12 = *plStack_2b0;
                                                          *plStack_2b0 = lVar12 + -1;
                                                          if (lVar12 + -1 == 0) {
                                                            (**(code **)(plStack_2b0[1] + 0x30))
                                                                      (plStack_2b0);
                                                          }
                                                          lVar12 = *plStack_298;
                                                          *plStack_298 = lVar12 + -1;
                                                          if (lVar12 + -1 == 0) {
                                                            (**(code **)(plStack_298[1] + 0x30))();
                                                          }
                                                          *plVar16 = *plVar16 + -1;
                                                          if (*plVar16 == 0) {
                                                            (**(code **)(plVar16[1] + 0x30))
                                                                      (plVar16);
                                                          }
                                                          if ((plVar24 != (longlong *)0x0) &&
                                                             (*plVar24 = *plVar24 + -1,
                                                             *plVar24 == 0)) {
                                                            (**(code **)(plVar24[1] + 0x30))
                                                                      (plVar24);
                                                          }
                                                          if ((plStack_2b8 != (longlong *)0x0) &&
                                                             (lVar12 = *plStack_2b8,
                                                             *plStack_2b8 = lVar12 + -1,
                                                             lVar12 + -1 == 0)) {
                                                            (**(code **)(plStack_2b8[1] + 0x30))
                                                                      (plStack_2b8);
                                                          }
                                                          if ((plStack_2a0 != (longlong *)0x0) &&
                                                             (lVar12 = *plStack_2a0,
                                                             *plStack_2a0 = lVar12 + -1,
                                                             lVar12 + -1 == 0)) {
                                                            (**(code **)(plStack_2a0[1] + 0x30))();
                                                          }
                                                          if ((plStack_290 != (longlong *)0x0) &&
                                                             (lVar12 = *plStack_290,
                                                             *plStack_290 = lVar12 + -1,
                                                             lVar12 + -1 == 0)) {
                                                            (**(code **)(plStack_290[1] + 0x30))
                                                                      (plStack_290);
                                                          }
                                                          if ((plStack_2a8 != (longlong *)0x0) &&
                                                             (lVar12 = *plStack_2a8,
                                                             *plStack_2a8 = lVar12 + -1,
                                                             lVar12 + -1 == 0)) {
                                                            (**(code **)(plStack_2a8[1] + 0x30))
                                                                      (plStack_2a8);
                                                            *plVar10 = *plVar10 + -1;
                                                            lVar12 = *plVar10;
                                                            goto joined_r0x00023e758d17;
                                                          }
                                                          goto LAB_23e758d12;
                                                        }
                                                      }
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      uVar29 = 0x3a3;
                                                    }
                                                  }
                                                  }
                                                  else {
                                                    *(undefined4 *)(plVar11 + 5) = 0x39d;
                                                    plVar24 = (longlong *)
                                                              FUN_23e915840(lVar12,plVar10,uVar32,
                                                                            *(undefined8 *)
                                                                             (lVar21 + 0x18));
                                                    if (plVar24 == (longlong *)0x0) {
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      plStack_2a8 = (longlong *)0x0;
                                                      plStack_290 = (longlong *)0x0;
                                                      plStack_2a0 = (longlong *)0x0;
                                                      plStack_2b8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar24 = (longlong *)0x0;
                                                      uVar29 = 0x39d;
                                                    }
                                                    else {
                                                      *plVar24 = *plVar24 + -1;
                                                      if (*plVar24 == 0) {
                                                        (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                      }
                                                      plVar24 = (longlong *)
                                                                FUN_23e8bc2f0(plVar10,DAT_23eed8a98)
                                                      ;
                                                      if (plVar24 == (longlong *)0x0) {
                                                        auStack_250 = *(undefined1 (*) [16])
                                                                       (lVar12 + 0x60);
                                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                                        plVar24 = (longlong *)0x0;
                                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                                        plStack_2a8 = (longlong *)0x0;
                                                        plStack_290 = (longlong *)0x0;
                                                        plStack_2a0 = (longlong *)0x0;
                                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        plStack_2b8 = (longlong *)0x0;
                                                        uVar29 = 0x39e;
                                                      }
                                                      else {
                                                        plVar15 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar24,
                                                  DAT_23eed92c0);
                                                  lVar21 = *plVar24;
                                                  *plVar24 = lVar21 + -1;
                                                  if (lVar21 + -1 == 0) {
                                                    (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                  }
                                                  if (plVar15 != (longlong *)0x0) {
                                                    *plStack_298 = *plStack_298 + 1;
                                                    plStack_260 = plVar15;
                                                    plStack_258 = plStack_298;
                                                    plVar24 = (longlong *)
                                                              FUN_23ab01810(lVar12,&plStack_260);
                                                    if (plVar24 != (longlong *)0x0) {
                                                      *plVar24 = *plVar24 + -1;
                                                      if (*plVar24 == 0) {
                                                        (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                      }
                                                      lVar21 = FUN_23e8e0ba0();
                                                      if (lVar21 == 0) {
                                                        FUN_23e915740(lVar12,auStack_250);
                                                      }
                                                      else {
                                                        *(undefined4 *)(plVar11 + 5) = 0x39f;
                                                        plVar24 = (longlong *)
                                                                  FUN_23e915840(lVar12,lVar21);
                                                        if (plVar24 != (longlong *)0x0)
                                                        goto LAB_23e7588d7;
                                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                                        auStack_250 = *(undefined1 (*) [16])
                                                                       (lVar12 + 0x60);
                                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                      }
                                                      plVar24 = (longlong *)0x0;
                                                      plStack_2a8 = (longlong *)0x0;
                                                      plStack_290 = (longlong *)0x0;
                                                      plStack_2a0 = (longlong *)0x0;
                                                      plStack_2b8 = (longlong *)0x0;
                                                      uVar29 = 0x39f;
                                                      goto LAB_23e758dff;
                                                    }
                                                  }
                                                  plVar24 = (longlong *)0x0;
                                                  auStack_250 = *(undefined1 (*) [16])
                                                                 (lVar12 + 0x60);
                                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                                  plStack_2a8 = (longlong *)0x0;
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  plStack_290 = (longlong *)0x0;
                                                  plStack_2a0 = (longlong *)0x0;
                                                  plStack_2b8 = (longlong *)0x0;
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  uVar29 = 0x39e;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    plVar24 = (longlong *)
                                                              FUN_23e8bc2f0(plVar10,DAT_23eed89b0);
                                                    if (plVar24 == (longlong *)0x0) {
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      plStack_2a8 = (longlong *)0x0;
                                                      uVar29 = 0x388;
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      plStack_290 = (longlong *)0x0;
                                                      plStack_2a0 = (longlong *)0x0;
                                                      plStack_2b8 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plVar24 = (longlong *)0x0;
                                                    }
                                                    else {
                                                      *(undefined4 *)(plVar11 + 5) = 0x388;
                                                      plVar15 = (longlong *)
                                                                FUN_23e91bfe0(lVar12,plVar24,
                                                                              DAT_23eed8d38);
                                                      *plVar24 = *plVar24 + -1;
                                                      if (*plVar24 == 0) {
                                                        (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                      }
                                                      if (plVar15 != (longlong *)0x0) {
                                                        iVar9 = FUN_23a35f020(plVar15);
                                                        lVar21 = *plVar15;
                                                        *plVar15 = lVar21 + -1;
                                                        if (lVar21 + -1 == 0) {
                                                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                                                        }
                                                        if (iVar9 == -1) goto LAB_23e75a60d;
                                                        if (iVar9 != 0) goto LAB_23e75879d;
                                                        plVar15 = (longlong *)FUN_23a388310(plVar16)
                                                        ;
                                                        if (plVar15 == (longlong *)0x0) {
                                                          uVar32 = *(undefined8 *)(lVar12 + 0x60);
                                                          uVar33 = *(undefined8 *)(lVar12 + 0x68);
                                                          pcVar23 = *(code **)(lVar12 + 0x70);
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          plVar24 = (longlong *)
                                                                    (**(code **)(plVar15[1] + 0xe0))
                                                                              (plVar15);
                                                          if ((plVar24 == (longlong *)0x0) &&
                                                             (plVar24 = (longlong *)
                                                                        FUN_23a3c1b70(lVar12,
                                                  auStack_250,0), plVar24 == (longlong *)0x0)) {
                                                    plStack_2a0 = (longlong *)0x0;
                                                    plStack_2b8 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    plStack_2b8 = (longlong *)
                                                                  (**(code **)(plVar15[1] + 0xe0))
                                                                            (plVar15);
                                                    if ((plStack_2b8 == (longlong *)0x0) &&
                                                       (plStack_2b8 = (longlong *)
                                                                      FUN_23a3c1b70(lVar12,
                                                  auStack_250,1,3), plStack_2b8 == (longlong *)0x0))
                                                  {
                                                    plStack_2a0 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    plStack_2a0 = (longlong *)
                                                                  (**(code **)(plVar15[1] + 0xe0))
                                                                            (plVar15);
                                                    if (((plStack_2a0 != (longlong *)0x0) ||
                                                        (plStack_2a0 = (longlong *)
                                                                       FUN_23a3c1b70(lVar12,
                                                  auStack_250,2,3), plStack_2a0 != (longlong *)0x0))
                                                  && (cVar8 = FUN_23a3884a0(lVar12,auStack_250,
                                                                            plVar15,3),
                                                     cVar8 != '\0')) {
                                                    *plVar15 = *plVar15 + -1;
                                                    if (*plVar15 == 0) {
                                                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                                                    }
                                                    if (*plVar24 == 0) {
                                                      (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                    }
                                                    if (*plStack_2b8 == 0) {
                                                      (**(code **)(plStack_2b8[1] + 0x30))();
                                                    }
                                                    if (*plStack_2a0 == 0) {
                                                      (**(code **)(plStack_2a0[1] + 0x30))();
                                                    }
                                                    plVar27 = (longlong *)
                                                              FUN_23e8bc2f0(plVar10,DAT_23eed8b40);
                                                    plVar15 = DAT_23eed9278;
                                                    if (plVar27 == (longlong *)0x0) {
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      uVar29 = 0x38a;
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      plStack_290 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      plStack_2a8 = (longlong *)0x0;
                                                      goto LAB_23e758dff;
                                                    }
                                                    lVar21 = *(longlong *)(lVar12 + 0x10);
                                                    plVar18 = *(longlong **)(lVar21 + 0xe38);
                                                    if (plVar18 == (longlong *)0x0) {
                                                      plVar18 = (longlong *)
                                                                FUN_23e916a20(PyTuple_Type_exref,5);
                                                    }
                                                    else {
                                                      lVar26 = plVar18[3];
                                                      *(int *)(lVar21 + 0xec8) =
                                                           *(int *)(lVar21 + 0xec8) + -1;
                                                      *(longlong *)(lVar21 + 0xe38) = lVar26;
                                                      *plVar18 = 1;
                                                    }
                                                    pcVar23 = _PyRuntime_exref;
                                                    *(undefined1 (*) [16])(plVar18 + 4) =
                                                         (undefined1  [16])0x0;
                                                    lVar21 = *(longlong *)(pcVar23 + 0x1f8);
                                                    *(undefined1 (*) [16])(plVar18 + 6) =
                                                         (undefined1  [16])0x0;
                                                    lVar21 = *(longlong *)
                                                              (*(longlong *)(lVar21 + 0x10) + 0x2e8)
                                                    ;
                                                    lVar26 = plVar18[-1];
                                                    puVar14 = *(undefined8 **)(lVar21 + 8);
                                                    *puVar14 = plVar18 + -2;
                                                    plVar18[-2] = lVar21;
                                                    plVar18[-1] = (ulonglong)((uint)lVar26 & 3) |
                                                                  (ulonglong)puVar14;
                                                    *(longlong **)(lVar21 + 8) = plVar18 + -2;
                                                    *plVar15 = *plVar15 + 1;
                                                    plVar18[3] = (longlong)plVar15;
                                                    plVar15 = DAT_23ed6cd28;
                                                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                      plVar20 = (longlong *)
                                                                PyDict_GetItemString
                                                                          (DAT_23ed6ccc0,"format");
                                                      if (plVar20 != (longlong *)0x0) {
                                                        *plVar20 = *plVar20 + 1;
                                                        DAT_23ed6a4c0 = plVar20;
                                                        goto LAB_23e759d0b;
                                                      }
LAB_23e75b151:
                                                      PyErr_PrintEx(0);
                                                      Py_Exit(1);
LAB_23e75b164:
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      uVar29 = 0x38a;
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      plStack_2a8 = (longlong *)0x0;
                                                      plStack_290 = (longlong *)0x0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      goto LAB_23e758dff;
                                                    }
LAB_23e759d0b:
                                                    plStack_260 = plStack_2b8;
                                                    plStack_258 = plVar15;
                                                    lVar21 = FUN_23e94ed00(lVar12,DAT_23ed6a4c0,
                                                                           &plStack_260);
                                                    if (lVar21 != 0) {
                                                      plVar18[4] = lVar21;
                                                      plVar15 = DAT_23eed9280;
                                                      *DAT_23eed9280 = *DAT_23eed9280 + 1;
                                                      plVar18[5] = (longlong)plVar15;
                                                      plVar15 = DAT_23ed6cd28;
                                                      if (DAT_23ed6a4c0 == (longlong *)0x0) {
                                                        plVar20 = (longlong *)
                                                                  PyDict_GetItemString
                                                                            (DAT_23ed6ccc0,"format")
                                                        ;
                                                        if (plVar20 == (longlong *)0x0)
                                                        goto LAB_23e75b151;
                                                        *plVar20 = *plVar20 + 1;
                                                        DAT_23ed6a4c0 = plVar20;
                                                      }
                                                      plStack_260 = plStack_2a0;
                                                      plStack_258 = plVar15;
                                                      lVar21 = FUN_23e94ed00(lVar12,DAT_23ed6a4c0,
                                                                             &plStack_260);
                                                      if (lVar21 != 0) {
                                                        plVar18[6] = lVar21;
                                                        plVar15 = DAT_23eed9288;
                                                        *DAT_23eed9288 = *DAT_23eed9288 + 1;
                                                        plVar18[7] = (longlong)plVar15;
                                                        plVar15 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar18);
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        if (plVar15 == (longlong *)0x0) {
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          lVar21 = *plVar27;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar27 = lVar21 + -1;
                                                          plStack_290 = (longlong *)0x0;
                                                          if (lVar21 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                            uVar29 = 0x38a;
                                                            plStack_2a8 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            uVar29 = 0x38a;
                                                            plStack_2a8 = (longlong *)0x0;
                                                          }
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar11 + 5) = 0x38a;
                                                          plVar18 = (longlong *)
                                                                    FUN_23e914090(lVar12,plVar27);
                                                          lVar21 = *plVar27;
                                                          *plVar27 = lVar21 + -1;
                                                          if (lVar21 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          lVar21 = *plVar15;
                                                          *plVar15 = lVar21 + -1;
                                                          if (lVar21 + -1 == 0) {
                                                            FUN_23a334bc0();
                                                          }
                                                          if (plVar18 == (longlong *)0x0)
                                                          goto LAB_23e75b164;
                                                          *plVar18 = *plVar18 + -1;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          plStack_290 = (longlong *)
                                                                        FUN_23e8bc2f0(plVar10,
                                                  DAT_23eed8a60);
                                                  if (plStack_290 == (longlong *)0x0) {
                                                    auStack_250 = *(undefined1 (*) [16])
                                                                   (lVar12 + 0x60);
                                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                                    uVar29 = 0x38d;
                                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                                    plStack_2a8 = (longlong *)0x0;
                                                    *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    plStack_290 = (longlong *)0x0;
                                                  }
                                                  else {
                                                    plStack_260 = plStack_290;
                                                    cVar8 = FUN_23e8c72f0(&plStack_260,DAT_23ed6ccf8
                                                                         );
                                                    plVar15 = plStack_260;
                                                    if (cVar8 != '\0') {
                                                      plStack_290 = plStack_260;
                                                      cVar8 = FUN_23e8d9ac0(plVar10,DAT_23eed8a60);
                                                      if (cVar8 != '\0') {
                                                        lVar21 = *plVar15;
                                                        *plVar15 = lVar21 + -1;
                                                        if (lVar21 + -1 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        *(undefined4 *)(plVar11 + 5) = 0x38e;
                                                        plStack_290 = (longlong *)
                                                                      FUN_23e91bfe0(lVar12,plVar10,
                                                                                    DAT_23eed9290);
                                                        if (plStack_290 == (longlong *)0x0) {
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          uVar29 = 0x38e;
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          plStack_2a8 = (longlong *)0x0;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          lVar21 = FUN_23e8e07b0();
                                                          if (lVar21 == 0) {
                                                            FUN_23e915740(lVar12,auStack_250,
                                                                          DAT_23eed8f68);
                                                            uVar29 = 0x38f;
                                                            plStack_2a8 = (longlong *)0x0;
                                                          }
                                                          else {
                                                            *(undefined4 *)(plVar11 + 5) = 0x38f;
                                                            plStack_2a8 = (longlong *)
                                                                          FUN_23e91a870(lVar12,
                                                  lVar21);
                                                  if (plStack_2a8 == (longlong *)0x0) {
                                                    auStack_250 = *(undefined1 (*) [16])
                                                                   (lVar12 + 0x60);
                                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                                    uVar29 = 0x38f;
                                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar15 = (longlong *)
                                                              FUN_23e8bc2f0(plStack_2a8,
                                                                            DAT_23eed9298);
                                                    if (plVar15 == (longlong *)0x0) {
LAB_23e75b0b3:
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      uVar29 = 0x390;
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      lVar21 = FUN_23e94f9d0(lVar12,plStack_2b8,
                                                                             DAT_23ed6cd28);
                                                      if (lVar21 == 0) {
LAB_23e75b057:
                                                        auStack_250 = *(undefined1 (*) [16])
                                                                       (lVar12 + 0x60);
                                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                                        uVar29 = 0x390;
                                                        uVar28 = 0x390;
                                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar15 = *plVar15 + -1;
                                                        lVar21 = *plVar15;
joined_r0x00023e75b088:
                                                        if (lVar21 == 0) {
LAB_23e75b08e:
                                                          FUN_23a334bc0(plVar15);
                                                          uVar29 = uVar28;
                                                        }
                                                      }
                                                      else {
                                                        plVar18 = (longlong *)
                                                                  FUN_23e916ad0(*(undefined8 *)
                                                                                 (lVar12 + 0x10),4);
                                                        plVar18[3] = lVar21;
                                                        plVar27 = DAT_23eed92a0;
                                                        *DAT_23eed92a0 = *DAT_23eed92a0 + 1;
                                                        plVar18[4] = (longlong)plVar27;
                                                        lVar21 = FUN_23e94f9d0(lVar12,plStack_2a0,
                                                                               DAT_23ed6cd28);
                                                        if (lVar21 == 0) {
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          *plVar18 = *plVar18 + -1;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          uVar29 = 0x390;
                                                        }
                                                        else {
                                                          plVar18[5] = lVar21;
                                                          plVar27 = DAT_23eed92a8;
                                                          *DAT_23eed92a8 = *DAT_23eed92a8 + 1;
                                                          plVar18[6] = (longlong)plVar27;
                                                          plVar27 = (longlong *)
                                                                    PyUnicode_Join(DAT_23ed6cd28,
                                                                                   plVar18);
                                                          *plVar18 = *plVar18 + -1;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          if (plVar27 == (longlong *)0x0)
                                                          goto LAB_23e75b057;
                                                          *(undefined4 *)(plVar11 + 5) = 0x390;
                                                          plStack_260 = plVar27;
                                                          plStack_258 = plStack_290;
                                                          plVar18 = (longlong *)
                                                                    FUN_23e94ed00(lVar12,plVar15);
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          *plVar27 = *plVar27 + -1;
                                                          if (*plVar27 == 0) {
                                                            FUN_23a334bc0(plVar27);
                                                          }
                                                          if (plVar18 == (longlong *)0x0)
                                                          goto LAB_23e75b0b3;
                                                          *plVar18 = *plVar18 + -1;
                                                          if (*plVar18 == 0) {
                                                            FUN_23a334bc0(plVar18);
                                                          }
                                                          iVar9 = PySequence_Contains(plVar13,
                                                  plVar24);
                                                  if (iVar9 == -1) {
LAB_23e75b2bb:
                                                    auStack_250 = *(undefined1 (*) [16])
                                                                   (lVar12 + 0x60);
                                                    pcStack_240 = *(code **)(lVar12 + 0x70);
                                                    uVar29 = 0x393;
                                                    *(undefined8 *)(lVar12 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e758dff;
                                                  }
                                                  if (iVar9 == 1) {
LAB_23e75a1db:
                                                    plVar15 = (longlong *)
                                                              FUN_23e8bc2f0(plVar10,DAT_23eed8b40);
                                                    plVar27 = DAT_23eed92b0;
                                                    if (plVar15 == (longlong *)0x0) {
LAB_23e75b349:
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      uVar29 = 0x394;
                                                    }
                                                    else {
                                                      plVar18 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (lVar12 + 0x10),3);
                                                      *plVar27 = *plVar27 + 1;
                                                      plVar18[3] = (longlong)plVar27;
                                                      lVar21 = FUN_23e94f9d0(lVar12,plStack_2b8,
                                                                             DAT_23ed6cd28);
                                                      if (lVar21 == 0) {
                                                        auStack_250 = *(undefined1 (*) [16])
                                                                       (lVar12 + 0x60);
                                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        uVar29 = 0x394;
                                                      }
                                                      else {
                                                        plVar18[4] = lVar21;
                                                        plVar27 = DAT_23eed92b8;
                                                        *DAT_23eed92b8 = *DAT_23eed92b8 + 1;
                                                        plVar18[5] = (longlong)plVar27;
                                                        plVar27 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar18);
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        if (plVar27 == (longlong *)0x0) {
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          uVar28 = 0x394;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar15 = *plVar15 + -1;
                                                          uVar29 = 0x394;
                                                          if (*plVar15 != 0) goto LAB_23e758dff;
                                                          goto LAB_23e75b08e;
                                                        }
                                                        *(undefined4 *)(plVar11 + 5) = 0x394;
                                                        plVar18 = (longlong *)
                                                                  FUN_23e914090(lVar12,plVar15);
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        *plVar27 = *plVar27 + -1;
                                                        if (*plVar27 == 0) {
                                                          FUN_23a334bc0(plVar27);
                                                        }
                                                        if (plVar18 == (longlong *)0x0)
                                                        goto LAB_23e75b349;
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        plVar15 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar10,
                                                  DAT_23eed8a98);
                                                  if (plVar15 != (longlong *)0x0) {
                                                    plVar27 = (longlong *)
                                                              FUN_23e8bc2f0(plVar15,DAT_23eed92c0);
                                                    *plVar15 = *plVar15 + -1;
                                                    if (*plVar15 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar27 != (longlong *)0x0) {
                                                      *plStack_298 = *plStack_298 + 1;
                                                      plStack_260 = plVar27;
                                                      plStack_258 = plStack_298;
                                                      plVar15 = (longlong *)
                                                                FUN_23ab01810(lVar12,&plStack_260);
                                                      if (plVar15 != (longlong *)0x0) {
LAB_23e75a40e:
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        lVar26 = FUN_23e8e0ba0();
                                                        lVar21 = DAT_23eed8ce0;
                                                        if (lVar26 == 0) {
                                                          FUN_23e915740(lVar12,auStack_250,
                                                                        DAT_23eed8c70);
                                                          uVar29 = 0x39a;
                                                        }
                                                        else {
                                                          *(undefined4 *)(plVar11 + 5) = 0x39a;
                                                          plVar15 = (longlong *)
                                                                    FUN_23e915840(lVar12,lVar26,
                                                                                  DAT_23eed8d40,
                                                                                  *(undefined8 *)
                                                                                   (lVar21 + 0x18));
                                                          if (plVar15 != (longlong *)0x0) {
                                                            *plVar15 = *plVar15 + -1;
                                                            if (*plVar15 == 0) {
                                                              FUN_23a334bc0(plVar15);
                                                            }
                                                            goto LAB_23e758917;
                                                          }
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          uVar29 = 0x39a;
                                                        }
                                                        goto LAB_23e758dff;
                                                      }
                                                    }
                                                  }
                                                  auStack_250 = *(undefined1 (*) [16])
                                                                 (lVar12 + 0x60);
                                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  uVar29 = 0x395;
                                                  }
                                                  }
                                                  }
                                                  else {
                                                    iVar9 = FUN_23a35f020(pcVar31);
                                                    if (iVar9 == -1) goto LAB_23e75b2bb;
                                                    if (iVar9 != 0) {
                                                      iVar9 = PySequence_Contains(plVar25,plVar24);
                                                      if (iVar9 == -1) goto LAB_23e75b2bb;
                                                      if (iVar9 == 0) goto LAB_23e75a1db;
                                                    }
                                                    plVar15 = (longlong *)
                                                              FUN_23e8bc2f0(plVar10,DAT_23eed8b40);
                                                    plVar27 = DAT_23eed92b0;
                                                    if (plVar15 == (longlong *)0x0) {
LAB_23e75b41e:
                                                      auStack_250 = *(undefined1 (*) [16])
                                                                     (lVar12 + 0x60);
                                                      pcStack_240 = *(code **)(lVar12 + 0x70);
                                                      uVar29 = 0x397;
                                                      *(undefined8 *)(lVar12 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
                                                    else {
                                                      plVar18 = (longlong *)
                                                                FUN_23e916ad0(*(undefined8 *)
                                                                               (lVar12 + 0x10),3);
                                                      *plVar27 = *plVar27 + 1;
                                                      plVar18[3] = (longlong)plVar27;
                                                      lVar21 = FUN_23e94f9d0(lVar12,plStack_2b8,
                                                                             DAT_23ed6cd28);
                                                      if (lVar21 == 0) {
                                                        auStack_250 = *(undefined1 (*) [16])
                                                                       (lVar12 + 0x60);
                                                        pcStack_240 = *(code **)(lVar12 + 0x70);
                                                        *(undefined8 *)(lVar12 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        uVar29 = 0x397;
                                                      }
                                                      else {
                                                        plVar18[4] = lVar21;
                                                        plVar27 = DAT_23eed92c8;
                                                        *DAT_23eed92c8 = *DAT_23eed92c8 + 1;
                                                        plVar18[5] = (longlong)plVar27;
                                                        plVar27 = (longlong *)
                                                                  PyUnicode_Join(DAT_23ed6cd28,
                                                                                 plVar18);
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        if (plVar27 == (longlong *)0x0) {
                                                          auStack_250 = *(undefined1 (*) [16])
                                                                         (lVar12 + 0x60);
                                                          pcStack_240 = *(code **)(lVar12 + 0x70);
                                                          uVar29 = 0x397;
                                                          uVar28 = 0x397;
                                                          *(undefined8 *)(lVar12 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar15 = *plVar15 + -1;
                                                          lVar21 = *plVar15;
                                                          goto joined_r0x00023e75b088;
                                                        }
                                                        *(undefined4 *)(plVar11 + 5) = 0x397;
                                                        plVar18 = (longlong *)
                                                                  FUN_23e914090(lVar12,plVar15);
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        *plVar27 = *plVar27 + -1;
                                                        if (*plVar27 == 0) {
                                                          FUN_23a334bc0(plVar27);
                                                        }
                                                        if (plVar18 == (longlong *)0x0)
                                                        goto LAB_23e75b41e;
                                                        *plVar18 = *plVar18 + -1;
                                                        if (*plVar18 == 0) {
                                                          FUN_23a334bc0(plVar18);
                                                        }
                                                        plVar15 = (longlong *)
                                                                  FUN_23e8bc2f0(plVar10,
                                                  DAT_23eed8a98);
                                                  if (plVar15 != (longlong *)0x0) {
                                                    plVar27 = (longlong *)
                                                              FUN_23e8bc2f0(plVar15,DAT_23eed92c0);
                                                    *plVar15 = *plVar15 + -1;
                                                    if (*plVar15 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plVar27 != (longlong *)0x0) {
                                                      *plStack_2b0 = *plStack_2b0 + 1;
                                                      plStack_260 = plVar27;
                                                      plStack_258 = plStack_2b0;
                                                      plVar15 = (longlong *)
                                                                FUN_23ab01810(lVar12,&plStack_260);
                                                      if (plVar15 != (longlong *)0x0)
                                                      goto LAB_23e75a40e;
                                                    }
                                                  }
                                                  auStack_250 = *(undefined1 (*) [16])
                                                                 (lVar12 + 0x60);
                                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                                  uVar29 = 0x398;
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  goto LAB_23e758dff;
                                                  }
                                                  }
                                                  auVar7 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  pcVar23 = *(code **)(lVar12 + 0x70);
                                                  pcStack_240 = (code *)0x0;
                                                  lVar21 = *plStack_290;
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  auStack_250 = (undefined1  [16])0x0;
                                                  *plStack_290 = lVar21 + -1;
                                                  if (lVar21 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  uVar29 = 0x38d;
                                                  plStack_2a8 = (longlong *)0x0;
                                                  plStack_290 = (longlong *)0x0;
                                                  auStack_250 = auVar7;
                                                  pcStack_240 = pcVar23;
                                                  }
                                                  }
                                                  goto LAB_23e758dff;
                                                  }
                                                  }
                                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                                  auStack_250 = *(undefined1 (*) [16])
                                                                 (lVar12 + 0x60);
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  lVar21 = *plVar27;
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar27 = lVar21 + -1;
                                                  if (lVar21 + -1 == 0) {
                                                    FUN_23a334bc0(plVar27);
                                                  }
                                                  *plVar18 = *plVar18 + -1;
                                                  if (*plVar18 == 0) {
                                                    FUN_23a334bc0(plVar18);
                                                  }
                                                  uVar29 = 0x38a;
                                                  plStack_2a8 = (longlong *)0x0;
                                                  plStack_290 = (longlong *)0x0;
                                                  goto LAB_23e758dff;
                                                  }
                                                  }
                                                  }
                                                  pcVar23 = pcStack_240;
                                                  uVar32 = auStack_250._0_8_;
                                                  uVar33 = auStack_250._8_8_;
                                                  pcStack_240 = (code *)0x0;
                                                  auStack_250 = (undefined1  [16])0x0;
                                                  *plVar15 = *plVar15 + -1;
                                                  if (*plVar15 == 0) {
                                                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                                                  }
                                                  pcStack_240 = (code *)0x0;
                                                  auStack_250 = (undefined1  [16])0x0;
                                                  if ((plVar24 != (longlong *)0x0) &&
                                                     (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
                                                    (**(code **)(plVar24[1] + 0x30))(plVar24);
                                                  }
                                                  if ((plStack_2b8 != (longlong *)0x0) &&
                                                     (lVar21 = *plStack_2b8,
                                                     *plStack_2b8 = lVar21 + -1, lVar21 + -1 == 0))
                                                  {
                                                    (**(code **)(plStack_2b8[1] + 0x30))();
                                                  }
                                                  if ((plStack_2a0 != (longlong *)0x0) &&
                                                     (lVar21 = *plStack_2a0,
                                                     *plStack_2a0 = lVar21 + -1, lVar21 + -1 == 0))
                                                  {
                                                    (**(code **)(plStack_2a0[1] + 0x30))();
                                                  }
                                                  }
                                                  uVar29 = 0x389;
                                                  auStack_250._8_8_ = uVar33;
                                                  auStack_250._0_8_ = uVar32;
                                                  pcStack_240 = pcVar23;
                                                  goto LAB_23e75a63c;
                                                  }
                                                  auStack_250 = *(undefined1 (*) [16])
                                                                 (lVar12 + 0x60);
                                                  pcStack_240 = *(code **)(lVar12 + 0x70);
                                                  plStack_2a8 = (longlong *)0x0;
                                                  plVar24 = (longlong *)0x0;
                                                  *(undefined8 *)(lVar12 + 0x70) = 0;
                                                  uVar29 = 0x388;
                                                  plStack_290 = (longlong *)0x0;
                                                  plStack_2a0 = (longlong *)0x0;
                                                  *(undefined1 (*) [16])(lVar12 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  plStack_2b8 = (longlong *)0x0;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
LAB_23e758dff:
                                if (pcStack_240 == (code *)0x0) {
LAB_23e758c00:
                                  pcVar23 = DAT_23ed6a4f8;
                                  if (DAT_23ed6a4f8 == (code *)0x0) {
                                    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                  }
                                  else {
                                    pcVar22 = *(code **)DAT_23ed6a4f8;
                                    *(longlong *)DAT_23ed6a4f8 = 1;
                                    DAT_23ed6a4f8 = pcVar22;
                                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                  }
                                  pcVar22 = _PyRuntime_exref;
                                  *(longlong *)(pcVar23 + 0x10) = 0;
                                  *(longlong **)(pcVar23 + 0x18) = plVar11;
                                  *plVar11 = *plVar11 + 1;
                                  lVar21 = *(longlong *)(pcVar22 + 0x1f8);
                                  *(undefined4 *)(pcVar23 + 0x24) = uVar29;
                                  lVar21 = *(longlong *)(lVar21 + 0x10);
                                  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
                                  lVar21 = *(longlong *)(lVar21 + 0x2e8);
                                  lVar26 = *(longlong *)(pcVar23 + -8);
                                  puVar14 = *(undefined8 **)(lVar21 + 8);
                                  *puVar14 = pcVar23 + -0x10;
                                  *(longlong *)(pcVar23 + -0x10) = lVar21;
                                  *(ulonglong *)(pcVar23 + -8) =
                                       (ulonglong)((uint)lVar26 & 3) | (ulonglong)puVar14;
                                  *(code **)(lVar21 + 8) = pcVar23 + -0x10;
                                  if ((pcStack_240 != (code *)0x0) &&
                                     (*(longlong *)pcStack_240 = *(longlong *)pcStack_240 + -1,
                                     *(longlong *)pcStack_240 == 0)) {
                                    (**(code **)(*(longlong *)(pcStack_240 + 8) + 0x30))
                                              (pcStack_240);
                                  }
                                  goto LAB_23e758ecb;
                                }
                              }
                              else {
                                if (plVar13 != (longlong *)0x0) goto LAB_23e7583ea;
LAB_23e758b73:
                                auStack_250 = *(undefined1 (*) [16])(lVar12 + 0x60);
                                pcStack_240 = *(code **)(lVar12 + 0x70);
                                plVar24 = (longlong *)0x0;
                                plVar16 = (longlong *)0x0;
                                *(undefined8 *)(lVar12 + 0x70) = 0;
                                pcVar31 = (code *)0x0;
                                plVar25 = (longlong *)0x0;
                                uVar29 = 0x378;
                                plStack_2a8 = (longlong *)0x0;
                                plStack_290 = (longlong *)0x0;
                                plStack_2a0 = (longlong *)0x0;
                                plStack_2b8 = (longlong *)0x0;
                                plStack_298 = (longlong *)0x0;
                                plStack_2b0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(lVar12 + 0x60) = (undefined1  [16])0x0;
                                if (pcStack_240 == (code *)0x0) {
                                  pcStack_240 = (code *)0x0;
                                  goto LAB_23e758c00;
                                }
                              }
                              pcVar23 = pcStack_240;
                              pcVar22 = DAT_23ed6a4f8;
                              if (*(longlong **)(pcStack_240 + 0x18) != plVar11) {
                                if (DAT_23ed6a4f8 == (code *)0x0) {
                                  pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                                }
                                else {
                                  pcVar30 = *(code **)DAT_23ed6a4f8;
                                  *(longlong *)DAT_23ed6a4f8 = 1;
                                  DAT_23ed6a4f8 = pcVar30;
                                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                                }
                                pcVar30 = _PyRuntime_exref;
                                *(longlong **)(pcVar22 + 0x18) = plVar11;
                                *plVar11 = *plVar11 + 1;
                                lVar21 = *(longlong *)(pcVar30 + 0x1f8);
                                *(undefined4 *)(pcVar22 + 0x24) = uVar29;
                                *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
                                lVar21 = *(longlong *)(*(longlong *)(lVar21 + 0x10) + 0x2e8);
                                lVar26 = *(longlong *)(pcVar22 + -8);
                                puVar14 = *(undefined8 **)(lVar21 + 8);
                                *puVar14 = pcVar22 + -0x10;
                                *(longlong *)(pcVar22 + -0x10) = lVar21;
                                *(ulonglong *)(pcVar22 + -8) =
                                     (ulonglong)((uint)lVar26 & 3) | (ulonglong)puVar14;
                                *(code **)(lVar21 + 8) = pcVar22 + -0x10;
                                *(code **)(pcVar22 + 0x10) = pcVar23;
                                *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
                                pcVar23 = pcVar22;
                                if ((pcStack_240 != (code *)0x0) &&
                                   (*(longlong *)pcStack_240 = *(longlong *)pcStack_240 + -1,
                                   *(longlong *)pcStack_240 == 0)) {
                                  (**(code **)(*(longlong *)(pcStack_240 + 8) + 0x30))(pcStack_240);
                                }
                              }
LAB_23e758ecb:
                              pcStack_240 = pcVar23;
                              FUN_23e8bba40(plVar11,"oooooooooooo",plVar10,plVar25,plVar13,pcVar31,
                                            plStack_2b0,plStack_298,plVar16,plVar24,plStack_2b8,
                                            plStack_2a0,plStack_290,plStack_2a8);
                              if (DAT_23eedade8 == plVar11) {
                                *plVar11 = *plVar11 + -1;
                                if (*plVar11 == 0) {
                                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                                }
                                DAT_23eedade8 = (longlong *)0x0;
                              }
                              lVar21 = *(longlong *)(*(longlong *)(lVar12 + 0x38) + 8);
                              plVar11 = *(longlong **)(lVar21 + 0x28);
                              plVar15 = (longlong *)plVar11[2];
                              *(undefined8 *)(*(longlong *)(lVar12 + 0x38) + 8) =
                                   *(undefined8 *)(lVar21 + 0x30);
                              *(undefined4 *)(plVar11 + 8) = 0xffffffff;
                              if (plVar15 != (longlong *)0x0) {
                                plVar11[2] = 0;
                                *plVar15 = *plVar15 + -1;
                                if (*plVar15 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))();
                                }
                              }
                              *plVar11 = *plVar11 + -1;
                              if (*plVar11 == 0) {
                                (**(code **)(plVar11[1] + 0x30))(plVar11);
                              }
                              pcVar23 = pcStack_240;
                              plVar11[0xf] = 0;
                              uVar32 = auStack_250._0_8_;
                              uVar33 = auStack_250._8_8_;
                              auStack_250 = (undefined1  [16])0x0;
                              pcStack_240 = (code *)0x0;
                              if ((plVar25 != (longlong *)0x0) &&
                                 (*plVar25 = *plVar25 + -1, *plVar25 == 0)) {
                                (**(code **)(plVar25[1] + 0x30))(plVar25);
                              }
                              if ((plVar13 != (longlong *)0x0) &&
                                 (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                                (**(code **)(plVar13[1] + 0x30))(plVar13);
                              }
                              if ((pcVar31 != (code *)0x0) &&
                                 (*(longlong *)pcVar31 = *(longlong *)pcVar31 + -1,
                                 *(longlong *)pcVar31 == 0)) {
                                (**(code **)(*(longlong *)(pcVar31 + 8) + 0x30))(pcVar31);
                              }
                              if ((plStack_2b0 != (longlong *)0x0) &&
                                 (lVar21 = *plStack_2b0, *plStack_2b0 = lVar21 + -1,
                                 lVar21 + -1 == 0)) {
                                (**(code **)(plStack_2b0[1] + 0x30))(plStack_2b0);
                              }
                              if ((plStack_298 != (longlong *)0x0) &&
                                 (lVar21 = *plStack_298, *plStack_298 = lVar21 + -1,
                                 lVar21 + -1 == 0)) {
                                (**(code **)(plStack_298[1] + 0x30))(plStack_298);
                              }
                              if ((plVar16 != (longlong *)0x0) &&
                                 (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                (**(code **)(plVar16[1] + 0x30))(plVar16);
                              }
                              if ((plVar24 != (longlong *)0x0) &&
                                 (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
                                (**(code **)(plVar24[1] + 0x30))(plVar24);
                              }
                              if ((plStack_2b8 != (longlong *)0x0) &&
                                 (lVar21 = *plStack_2b8, *plStack_2b8 = lVar21 + -1,
                                 lVar21 + -1 == 0)) {
                                (**(code **)(plStack_2b8[1] + 0x30))(plStack_2b8);
                              }
                              if ((plStack_2a0 != (longlong *)0x0) &&
                                 (lVar21 = *plStack_2a0, *plStack_2a0 = lVar21 + -1,
                                 lVar21 + -1 == 0)) {
                                (**(code **)(plStack_2a0[1] + 0x30))(plStack_2a0);
                              }
                              if ((plStack_290 != (longlong *)0x0) &&
                                 (lVar21 = *plStack_290, *plStack_290 = lVar21 + -1,
                                 lVar21 + -1 == 0)) {
                                (**(code **)(plStack_290[1] + 0x30))(plStack_290);
                              }
                              if ((plStack_2a8 != (longlong *)0x0) &&
                                 (lVar21 = *plStack_2a8, *plStack_2a8 = lVar21 + -1,
                                 lVar21 + -1 == 0)) {
                                (**(code **)(plStack_2a8[1] + 0x30))(plStack_2a8);
                              }
                              *plVar10 = *plVar10 + -1;
                              pcStack_240 = pcVar23;
                              auStack_250._0_8_ = uVar32;
                              auStack_250._8_8_ = uVar33;
                              if (*plVar10 == 0) {
                                (**(code **)(plVar10[1] + 0x30))(plVar10);
                              }
                              FUN_23a33aa70(lVar12,auStack_250._0_8_,auStack_250._8_8_,pcStack_240);
                              return (code *)0x0;
                            }
                            *plVar18 = *plVar18 + 1;
                            DAT_23ed6a4c0 = plVar18;
                          }
                          plStack_78 = plVar27;
                          plStack_70 = plVar16;
                          pcStack_1e0 = (code *)0x23e757ead;
                          lVar12 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_a8);
                          if (lVar12 == 0) {
                            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            apcStack_88[0] = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar24 = *plVar24 + -1;
                            if (*plVar24 == 0) {
                              pcStack_1e0 = (code *)0x23e758212;
                              FUN_23a334bc0(plVar24);
                            }
                            *plVar15 = *plVar15 + -1;
                            if (*plVar15 == 0) {
                              pcStack_1e0 = (code *)0x23e758221;
                              FUN_23a334bc0(plVar15);
                            }
                          }
                          else {
                            plVar15[4] = lVar12;
                            plVar16 = _DAT_23eed9170;
                            *_DAT_23eed9170 = *_DAT_23eed9170 + 1;
                            plVar15[5] = (longlong)plVar16;
                            pcStack_1e0 = (code *)0x23e757edf;
                            plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                            *plVar15 = *plVar15 + -1;
                            if (*plVar15 == 0) {
                              pcStack_1e0 = (code *)0x23e757ef9;
                              plStack_140 = plVar16;
                              FUN_23a334bc0(plVar15);
                              plVar16 = plStack_140;
                            }
                            if (plVar16 != (longlong *)0x0) {
                              *(undefined4 *)(plVar25 + 5) = 0x371;
                              pcStack_1e0 = (code *)0x23e757f24;
                              plStack_140 = plVar16;
                              plVar16 = (longlong *)FUN_23e914090(param_1,plVar24);
                              *plVar24 = *plVar24 + -1;
                              if (*plVar24 == 0) {
                                pcStack_1e0 = (code *)0x23e757f3e;
                                FUN_23a334bc0(plVar24);
                              }
                              *plStack_140 = *plStack_140 + -1;
                              if (*plStack_140 == 0) {
                                pcStack_1e0 = (code *)0x23e757f54;
                                FUN_23a334bc0(plStack_140);
                              }
                              if (plVar16 != (longlong *)0x0) {
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  pcStack_1e0 = (code *)0x23e757f6c;
                                  FUN_23a334bc0(plVar16);
                                }
                                plStack_138 = plStack_e0;
                                plStack_110 = plStack_e8;
                                plStack_128 = plStack_f0;
                                plStack_118 = plStack_c8;
                                plStack_130 = plStack_d8;
                                plStack_140 = plStack_b8;
                                pcVar23 = pcStack_148;
                                plVar25 = plStack_a0;
                                goto LAB_23e7578e2;
                              }
                              goto LAB_23e758138;
                            }
                            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                            apcStack_88[0] = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            *plVar24 = *plVar24 + -1;
                            if (*plVar24 == 0) {
                              pcStack_1e0 = (code *)0x23e75829b;
                              FUN_23a334bc0(plVar24);
                            }
                          }
                        }
                        uVar29 = 0x371;
                        plStack_138 = plStack_e0;
                        plStack_110 = plStack_e8;
                        plStack_128 = plStack_f0;
                        plStack_118 = plStack_c8;
                        plStack_130 = plStack_d8;
                        plStack_140 = plStack_b8;
                        plVar24 = plStack_d0;
                        plVar16 = plStack_a0;
                        goto LAB_23e755c16;
                      }
                      pcStack_1e0 = (code *)0x23e755914;
                      lVar21 = FUN_23e8e0ba0();
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar13 = plStack_c0;
                      pcVar31 = pcStack_f8;
                      lVar12 = _DAT_23eed9178;
                      if (lVar21 == 0) {
                        pcStack_1e0 = (code *)0x23e7573bb;
                        plStack_d8 = plVar18;
                        plStack_b8 = plVar17;
                        plStack_a0 = plVar16;
                        FUN_23e915740(param_1,plStack_c8,DAT_23eed8c70);
LAB_23e7573f6:
                        uVar29 = 0x374;
                        plStack_130 = plStack_d8;
                        plStack_140 = plStack_b8;
                        plVar16 = plStack_a0;
                        plStack_138 = plStack_e0;
                        plStack_128 = plStack_f0;
                        plStack_118 = plVar19;
                        plStack_110 = plStack_e8;
                        goto LAB_23e755c16;
                      }
                      *(undefined4 *)(plVar25 + 5) = 0x374;
                      pcStack_1e0 = (code *)0x23e755942;
                      plVar10 = (longlong *)
                                FUN_23e915840(param_1,lVar21,DAT_23eed8d40,
                                              *(undefined8 *)(lVar12 + 0x18));
                      if (plVar10 == (longlong *)0x0) {
                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        apcStack_88[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar11 = plStack_b0;
                        plVar10 = plStack_b8;
                        plVar13 = plStack_c0;
                        pcVar31 = pcStack_f8;
                        plStack_d8 = plVar18;
                        plStack_d0 = plVar20;
                        plStack_c8 = plVar19;
                        plStack_b8 = plVar17;
                        plStack_a0 = plVar16;
                        goto LAB_23e7573f6;
                      }
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        pcStack_1e0 = (code *)0x23e7564c7;
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      lVar12 = *(longlong *)(param_1 + 0x10);
                      if ((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) != 0) ||
                         (*(int *)(lVar12 + 0x78) != 0)) {
                        pcStack_1e0 = (code *)0x23e756086;
                        iVar9 = Py_MakePendingCalls();
                        if ((-1 < iVar9) ||
                           (plVar11 = plStack_b0, plVar10 = plStack_b8, plVar13 = plStack_c0,
                           pcVar31 = pcStack_f8, *(longlong *)(param_1 + 0x60) == 0))
                        goto LAB_23e75597a;
LAB_23e7560f0:
                        plStack_a0 = plVar16;
                        plStack_b8 = plVar17;
                        plStack_c8 = plVar19;
                        plStack_d0 = plVar20;
                        plStack_d8 = plVar18;
                        auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                        plStack_138 = plStack_e0;
                        uVar29 = 0x369;
                        apcStack_88[0] = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plStack_110 = plStack_e8;
                        plStack_128 = plStack_f0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar24 = plStack_d0;
                        plVar16 = plStack_a0;
                        plStack_140 = plStack_b8;
                        plStack_130 = plStack_d8;
                        plStack_118 = plStack_c8;
                        auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                        goto LAB_23e755c16;
                      }
LAB_23e75597a:
                      if (*(int *)(lVar12 + 0x68) != 0) {
                        pcStack_1e0 = (code *)0x23e75673e;
                        PyEval_SaveThread();
                        pcStack_1e0 = (code *)0x23e756747;
                        PyEval_AcquireThread(param_1);
                      }
                      plVar11 = plStack_b0;
                      plVar10 = plStack_b8;
                      plVar13 = plStack_c0;
                      pcVar31 = pcStack_f8;
                      plVar24 = *(longlong **)(param_1 + 0x90);
                      if (plVar24 != (longlong *)0x0) {
                        plVar15 = *(longlong **)(param_1 + 0x60);
                        plVar27 = *(longlong **)(param_1 + 0x68);
                        plVar5 = *(longlong **)(param_1 + 0x70);
                        *(longlong **)(param_1 + 0x60) = plVar24;
                        *(undefined8 *)(param_1 + 0x90) = 0;
                        *plVar24 = *plVar24 + 1;
                        *(undefined8 *)(param_1 + 0x68) = 0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        plStack_d8 = plVar18;
                        plStack_d0 = plVar20;
                        plStack_c8 = plVar19;
                        plStack_b8 = plVar17;
                        plStack_a0 = plVar16;
                        if ((plVar15 != (longlong *)0x0) &&
                           (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                          pcStack_1e0 = (code *)0x23e757558;
                          (**(code **)(plVar15[1] + 0x30))();
                        }
                        if ((plVar27 != (longlong *)0x0) &&
                           (*plVar27 = *plVar27 + -1, *plVar27 == 0)) {
                          pcStack_1e0 = (code *)0x23e75756e;
                          (**(code **)(plVar27[1] + 0x30))(plVar27);
                        }
                        plVar18 = plStack_d8;
                        plVar20 = plStack_d0;
                        plVar19 = plStack_c8;
                        plVar17 = plStack_b8;
                        plVar16 = plStack_a0;
                        if ((plVar5 != (longlong *)0x0) && (*plVar5 = *plVar5 + -1, *plVar5 == 0)) {
                          pcStack_1e0 = (code *)0x23e75758d;
                          (**(code **)(plVar5[1] + 0x30))(plVar5);
                          plVar18 = plStack_d8;
                          plVar20 = plStack_d0;
                          plVar19 = plStack_c8;
                          plVar17 = plStack_b8;
                          plVar16 = plStack_a0;
                        }
                        goto LAB_23e7560f0;
                      }
                      plStack_138 = plStack_e0;
                      plStack_110 = plStack_e8;
                      plStack_128 = plStack_f0;
                      pcVar23 = pcStack_148;
                      plStack_140 = plVar17;
                      plStack_130 = plVar18;
                      plStack_118 = plVar19;
                      plStack_d8 = plVar16;
                      plStack_d0 = plVar20;
                    }
                  }
                  auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
                  auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
                  apcStack_88[0] = *(code **)(param_1 + 0x70);
                  uVar29 = 0x369;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar11 = plStack_b0;
                  plVar10 = plStack_b8;
                  plVar24 = plStack_d0;
                  plVar16 = plStack_d8;
                  plVar13 = plStack_c0;
                  pcVar31 = pcStack_f8;
                  pcStack_148 = pcVar23;
                }
              }
              goto LAB_23e755c16;
            }
            apcStack_88[0] = *(code **)(param_1 + 0x70);
            auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
            auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          plStack_138 = (longlong *)0x0;
          plVar24 = (longlong *)0x0;
          plVar16 = (longlong *)0x0;
          uVar29 = 0x363;
          plStack_110 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          plStack_118 = (longlong *)0x0;
          plStack_130 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          plStack_108 = (longlong *)0x0;
        }
      }
    }
LAB_23e755c16:
    uVar28 = uVar29;
    if (apcStack_88[0] != (code *)0x0) {
LAB_23e755c1f:
      pcVar22 = DAT_23ed6a4f8;
      pcVar23 = apcStack_88[0];
      if (*(longlong **)(apcStack_88[0] + 0x18) != plVar25) {
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcStack_100 = (code *)CONCAT44(pcStack_100._4_4_,uVar28);
          pcStack_1e0 = (code *)0x23e75649c;
          pcStack_f8 = apcStack_88[0];
          pcVar22 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          uVar28 = SUB84(pcStack_100,0);
          pcVar23 = pcStack_f8;
        }
        else {
          pcVar23 = *(code **)DAT_23ed6a4f8;
          *(longlong *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar23;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          pcVar23 = apcStack_88[0];
        }
        pcVar30 = _PyRuntime_exref;
        *(longlong **)(pcVar22 + 0x18) = plVar25;
        *plVar25 = *plVar25 + 1;
        lVar12 = *(longlong *)(pcVar30 + 0x1f8);
        *(undefined4 *)(pcVar22 + 0x24) = uVar28;
        *(undefined4 *)(pcVar22 + 0x20) = 0xffffffff;
        lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
        lVar21 = *(longlong *)(pcVar22 + -8);
        puVar14 = *(undefined8 **)(lVar12 + 8);
        *puVar14 = pcVar22 + -0x10;
        *(longlong *)(pcVar22 + -0x10) = lVar12;
        *(ulonglong *)(pcVar22 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar14;
        *(code **)(lVar12 + 8) = pcVar22 + -0x10;
        *(code **)(pcVar22 + 0x10) = pcVar23;
        *(longlong *)pcVar23 = *(longlong *)pcVar23 + 1;
        pcVar23 = pcVar22;
        if ((apcStack_88[0] != (code *)0x0) &&
           (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
           *(longlong *)apcStack_88[0] == 0)) {
          pcStack_1e0 = (code *)0x23e755cd2;
          pcStack_100 = pcVar22;
          (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
          pcVar23 = pcStack_100;
        }
      }
      goto LAB_23e755ce2;
    }
  }
  else {
    if (plVar11 != (longlong *)0x0) goto LAB_23e754dfa;
LAB_23e754ed3:
    auStack_98._0_8_ = *(undefined8 *)(param_1 + 0x60);
    auStack_98._8_8_ = *(undefined8 *)(param_1 + 0x68);
    apcStack_88[0] = *(code **)(param_1 + 0x70);
    plVar24 = (longlong *)0x0;
    plVar16 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar13 = (longlong *)0x0;
    plVar10 = (longlong *)0x0;
    uVar28 = 0x353;
    uVar29 = 0x353;
    plStack_138 = (longlong *)0x0;
    plStack_110 = (longlong *)0x0;
    plStack_128 = (longlong *)0x0;
    plStack_118 = (longlong *)0x0;
    plStack_130 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    pcStack_148 = (code *)0x0;
    plStack_108 = (longlong *)0x0;
    plStack_120 = (longlong *)0x0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (apcStack_88[0] != (code *)0x0) goto LAB_23e755c1f;
    apcStack_88[0] = (code *)0x0;
  }
  pcVar23 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcStack_100 = (code *)CONCAT44(pcStack_100._4_4_,uVar29);
    pcStack_1e0 = (code *)0x23e756a04;
    pcVar23 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    uVar29 = SUB84(pcStack_100,0);
  }
  else {
    pcVar22 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar22;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  pcVar22 = _PyRuntime_exref;
  *(longlong *)(pcVar23 + 0x10) = 0;
  *(longlong **)(pcVar23 + 0x18) = plVar25;
  *plVar25 = *plVar25 + 1;
  lVar12 = *(longlong *)(pcVar22 + 0x1f8);
  *(undefined4 *)(pcVar23 + 0x24) = uVar29;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  *(undefined4 *)(pcVar23 + 0x20) = 0xffffffff;
  lVar12 = *(longlong *)(lVar12 + 0x2e8);
  lVar21 = *(longlong *)(pcVar23 + -8);
  puVar14 = *(undefined8 **)(lVar12 + 8);
  *puVar14 = pcVar23 + -0x10;
  *(longlong *)(pcVar23 + -0x10) = lVar12;
  *(ulonglong *)(pcVar23 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar14;
  *(code **)(lVar12 + 8) = pcVar23 + -0x10;
  if ((apcStack_88[0] != (code *)0x0) &&
     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
     *(longlong *)apcStack_88[0] == 0)) {
    pcStack_1e0 = (code *)0x23e75503f;
    pcStack_100 = pcVar23;
    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
    pcVar23 = pcStack_100;
  }
LAB_23e755ce2:
  apcStack_88[0] = pcVar23;
  plStack_158 = plStack_138;
  plStack_160 = plStack_110;
  plStack_168 = plStack_128;
  plStack_178 = plStack_118;
  plStack_180 = plStack_130;
  plStack_188 = plStack_140;
  pcStack_198 = pcStack_148;
  plStack_1a0 = plStack_108;
  plStack_1b0 = plStack_120;
  pcStack_1e0 = (code *)0x23e755d83;
  plStack_1b8 = plVar11;
  plStack_1a8 = plVar13;
  plStack_190 = plVar16;
  plStack_170 = plVar24;
  FUN_23e8bba40(plVar25,"ooooooooooooooo",pcVar31,plVar10);
  if (_DAT_23eedae10 == plVar25) {
    *plVar25 = *plVar25 + -1;
    if (*plVar25 == 0) {
      pcStack_1e0 = (code *)0x23e756068;
      (**(code **)(plVar25[1] + 0x30))(plVar25);
    }
    _DAT_23eedae10 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar25 = *(longlong **)(lVar12 + 0x28);
  plVar15 = (longlong *)plVar25[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar25 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar25[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      pcStack_1e0 = (code *)0x23e755dc9;
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar25 = *plVar25 + -1;
  if (*plVar25 == 0) {
    pcStack_1e0 = (code *)0x23e755dd9;
    (**(code **)(plVar25[1] + 0x30))(plVar25);
  }
  pcVar23 = apcStack_88[0];
  uVar33 = auStack_98._8_8_;
  uVar32 = auStack_98._0_8_;
  plVar25[0xf] = 0;
  auStack_98 = (undefined1  [16])0x0;
  apcStack_88[0] = (code *)0x0;
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    pcStack_1e0 = (code *)0x23e755e1f;
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    pcStack_1e0 = (code *)0x23e755e35;
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  plVar25 = plStack_120;
  plVar10 = plStack_120;
  if (plStack_120 != (longlong *)0x0) {
    plVar10 = (longlong *)*plStack_120;
    *plStack_120 = (longlong)plVar10 + -1;
    if ((longlong)plVar10 + -1 == 0) {
      plVar11 = plStack_120 + 1;
      pcStack_1e0 = (code *)0x23e755e60;
      plStack_120 = plVar10;
      (**(code **)(*plVar11 + 0x30))(plVar25);
      plVar10 = plStack_120;
    }
  }
  plStack_120 = plVar10;
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    pcStack_1e0 = (code *)0x23e755e75;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  if (plStack_108 != (longlong *)0x0) {
    plStack_120 = (longlong *)*plStack_108;
    *plStack_108 = (longlong)plStack_120 + -1;
    if ((longlong)plStack_120 + -1 == 0) {
      pcStack_1e0 = (code *)0x23e755ea0;
      (**(code **)(plStack_108[1] + 0x30))(plStack_108);
    }
  }
  pcVar30 = pcStack_148;
  pcVar22 = pcStack_148;
  if (pcStack_148 != (code *)0x0) {
    pcVar22 = *(code **)pcStack_148;
    *(code **)pcStack_148 = pcVar22 + -1;
    if (pcVar22 + -1 == (code *)0x0) {
      pcVar1 = pcStack_148 + 8;
      pcStack_1e0 = (code *)0x23e755ecb;
      pcStack_148 = pcVar22;
      (**(code **)(*(longlong *)pcVar1 + 0x30))(pcVar30);
      pcVar22 = pcStack_148;
    }
  }
  pcStack_148 = pcVar22;
  if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
    pcStack_1e0 = (code *)0x23e755ee1;
    (**(code **)(plVar16[1] + 0x30))(plVar16);
  }
  if (plStack_140 != (longlong *)0x0) {
    pcStack_148 = (code *)*plStack_140;
    *plStack_140 = (longlong)(pcStack_148 + -1);
    if (pcStack_148 + -1 == (code *)0x0) {
      pcStack_1e0 = (code *)0x23e755f0c;
      (**(code **)(plStack_140[1] + 0x30))(plStack_140);
    }
  }
  if (plStack_130 != (longlong *)0x0) {
    pcStack_148 = (code *)*plStack_130;
    *plStack_130 = (longlong)(pcStack_148 + -1);
    if (pcStack_148 + -1 == (code *)0x0) {
      pcStack_1e0 = (code *)0x23e755f37;
      (**(code **)(plStack_130[1] + 0x30))(plStack_130);
    }
  }
  if (plStack_118 != (longlong *)0x0) {
    pcStack_148 = (code *)*plStack_118;
    *plStack_118 = (longlong)(pcStack_148 + -1);
    if (pcStack_148 + -1 == (code *)0x0) {
      pcStack_1e0 = (code *)0x23e755f62;
      (**(code **)(plStack_118[1] + 0x30))(plStack_118);
    }
  }
  if ((plVar24 != (longlong *)0x0) && (*plVar24 = *plVar24 + -1, *plVar24 == 0)) {
    pcStack_1e0 = (code *)0x23e755f79;
    (**(code **)(plVar24[1] + 0x30))(plVar24);
  }
  if (plStack_128 != (longlong *)0x0) {
    pcStack_148 = (code *)*plStack_128;
    *plStack_128 = (longlong)(pcStack_148 + -1);
    if (pcStack_148 + -1 == (code *)0x0) {
      pcStack_1e0 = (code *)0x23e755fa4;
      (**(code **)(plStack_128[1] + 0x30))(plStack_128);
    }
  }
  if (plStack_110 != (longlong *)0x0) {
    pcStack_148 = (code *)*plStack_110;
    *plStack_110 = (longlong)(pcStack_148 + -1);
    if (pcStack_148 + -1 == (code *)0x0) {
      pcStack_1e0 = (code *)0x23e755fcf;
      (**(code **)(plStack_110[1] + 0x30))(plStack_110);
    }
  }
  if (plStack_138 != (longlong *)0x0) {
    pcStack_148 = (code *)*plStack_138;
    *plStack_138 = (longlong)(pcStack_148 + -1);
    if (pcStack_148 + -1 == (code *)0x0) {
      pcStack_1e0 = (code *)0x23e755ffa;
      (**(code **)(plStack_138[1] + 0x30))(plStack_138);
    }
  }
  *(longlong *)pcVar31 = *(longlong *)pcVar31 + -1;
  apcStack_88[0] = pcVar23;
  auStack_98._0_8_ = uVar32;
  auStack_98._8_8_ = uVar33;
  if (*(longlong *)pcVar31 == 0) {
    pcStack_1e0 = (code *)0x23e75603a;
    (**(code **)(*(longlong *)(pcVar31 + 8) + 0x30))(pcVar31);
  }
  pcStack_1e0 = (code *)0x23e756028;
  FUN_23a33aa70(param_1,auStack_98._0_8_,auStack_98._8_8_,apcStack_88[0]);
  return (code *)0x0;
}
